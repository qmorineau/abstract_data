# usage: awk -v threshold=1.5 \
#            -f compare.awk output.ft.time output.std.time
#   threshold : ratio above which ft is a KO (ft_time / std_time)
#   low       : ratio below which ft is "too fast to be true"
#   noise     : time (in the file's units) below which a measure is just noise

# strip the ": 1234 useconds" suffix to keep only the test name
function name(s) { sub(/: *[0-9.e+-]+ useconds.*$/, "", s); return s }

BEGIN {
    RED = "\033[31m"; GREEN = "\033[32m"; YELLOW = "\033[33m"; GREY = "\033[90m"
    RESET = "\033[0m"

    low   = 0.5   # ratio below which ft is "too fast to be true"
    noise = 5     # time (in useconds) below which a measure is just noise
    if (threshold == "") threshold = 1.5   # still overridable from the Makefile
}

# lines that are not measurements (separators, titles): copy them as is
!/useconds *$/ { if (NR != FNR) print; next }

# 1st file = ft: store times and names by line number
NR == FNR { t_ft[FNR] = $(NF-1); next }

# 2nd file = std: compare ft against it
{
    std = $(NF-1)
    ft  = t_ft[FNR]
    n   = name($0)

    # invalid reference time: avoid a division by zero
    if (std <= 0) {
        printf "%-45s ft=%10d  std=%10d  x?       N/A\n", n, ft, std
        next
    }

    ratio = ft / std

    if (ft < noise && std < noise)           { col = GREY;   state = "NOISE" }               # too short to be meaningful
    else if (ratio > threshold)              { col = RED;    state = "KO";    ko++ }         # ft noticeably slower
    else if (ratio < low)                    { col = YELLOW; state = "CHECK"; check++ }      # suspiciously fast: verify the bench
    else                                     { col = GREEN;  state = "OK" }

    printf "%-45s ft=%10d  std=%10d  x%-7.2f %s%s%s\n", n, ft, std, ratio, col, state, RESET
}

# only KO makes the script fail (CHECK is a hint, not an error)
END {
    print ko+0 " KO, " check+0 " to check"
    exit (ko > 0)
}