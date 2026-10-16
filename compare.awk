# Usage:
# awk -f compare.awk output.ft.time output.std.time
#
# Options:
#   -v show_ok=1       Afficher aussi les tests OK
#   -v show_time=1     Afficher les temps moyens par iteration
#   -v show_iter=1     Afficher les nombres d'iterations
#   -v show_ratio=1    Afficher le ratio
#   -v show_status=1   Afficher le statut
#   -v show_all=1      Afficher toutes les informations
#
# ratio = (ft_time / ft_iterations) / (std_time / std_iterations)
# KO    : ratio > THRESHOLD
# CHECK : ratio < LOW
# OK    : ratio < GOOD
# OPTIM : GOOD <= ratio <= THRESHOLD

function name(s) {
    sub(/: *[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)? nseconds.*$/, "", s)
    return s
}

function gradient(r,    pos, idx) {
    if (r <= GOOD) return GOOD_COL

    pos = log(r / GOOD) / log(THRESHOLD / GOOD)
    if (pos > 1) pos = 1

    idx = int(pos * (NPAL - 1)) + 1
    return pal[idx]
}

BEGIN {
    THRESHOLD = 20
    GOOD      = 2
    LOW       = 0.5

    RESET     = "\033[0m"
    ORANGE    = "\033[38;5;208m"
    GOOD_COL  = "\033[1;38;5;46m"
    CHECK_COL = "\033[1;5;38;5;201m"
    KO_COL    = "\033[1;97;41m"

    NPAL = split("226 220 214 208 202 196", codes, " ")
    for (i = 1; i <= NPAL; i++)
        pal[i] = "\033[38;5;" codes[i] "m"

    if (show_all) {
        show_time = 1
        show_iter = 1
        show_ratio = 1
        show_status = 1
    }

    # Default: ratio + status
    if (!show_time && !show_iter && !show_ratio && !show_status) {
        show_ratio = 1
        show_status = 1
    }
}

# First file: ft
NR == FNR {
    if ($0 !~ /nseconds/) next

    n = name($0)
    ft_time[n] = $(NF-3)
    ft_iter[n] = $(NF-1)
    next
}

# Second file: std
{
    if ($0 !~ /nseconds/) next

    n = name($0)
    std = $(NF-3)
    std_iter = $(NF-1)

    if (!(n in ft_time)) {
        printf "%-45s MISSING in ft output\n", n
        missing++
        next
    }

    ft = ft_time[n]
    iterations_ft = ft_iter[n]

    if (ft <= 0 || std <= 0 || iterations_ft <= 0 || std_iter <= 0) {
        printf "%-45s INVALID time or iteration count\n", n
        invalid++
        next
    }

    # Average time per iteration
    ft_avg = ft / iterations_ft
    std_avg = std / std_iter
    ratio = ft_avg / std_avg

    if (ratio > THRESHOLD) {
        col = KO_COL
        state = "KO"
        ko++
    } else if (ratio < LOW) {
        col = CHECK_COL
        state = "CHECK"
        check++
    } else if (ratio < GOOD) {
        col = GOOD_COL
        state = "OK"
        ok++
    } else {
        col = gradient(ratio)
        state = "OPTIM"
        optim++
    }

    if (state == "OK" && !show_ok) next

    line = sprintf("%-45s", n)

    if (show_time)
        line = line sprintf(" ft=%9.2f std=%9.2f", ft_avg, std_avg)

    if (show_iter)
        line = line sprintf(" iter=%s/%s", iterations_ft, std_iter)

    if (show_ratio)
        line = line sprintf(" x%-7.2f", ratio)

    if (show_status)
        line = line sprintf(" %s%s%s", col, state, RESET)

    print line
}

END {
    printf "\n%s%d OK%s | %s%d OPTIM%s | %s%d CHECK%s | %s%d KO%s",
        GOOD_COL, ok+0, RESET,
        ORANGE, optim+0, RESET,
        CHECK_COL, check+0, RESET,
        (ko > 0 ? KO_COL : ""), ko+0, RESET

    if (missing || invalid)
        printf " | %d MISSING | %d INVALID", missing+0, invalid+0

    print ""
    exit (ko > 0 || missing > 0 || invalid > 0)
}
