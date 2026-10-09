# usage: awk -f compare.awk output.ft.time output.std.time
#   ratio = ft_time / std_time
#   NOISE : both times < NOISE
#   KO    : ratio > THRESHOLD (subject requirement)
#   CHECK : ratio < LOW (suspiciously fast, verify the bench)
#   OK    : ratio < GOOD, leave it alone (bold green)
#   OPTIM : GOOD <= ratio <= THRESHOLD, worth optimizing
#           (colored yellow -> orange -> red on a log scale)

# strip the ": 1234 nseconds" suffix to keep only the test name
function name(s) { sub(/: *[0-9.e+-]+ nseconds.*$/, "", s); return s }

# 256-color escape for a ratio: first color at x GOOD, last at x THRESHOLD
function gradient(r,    pos, idx) {
    if (r <= GOOD) return pal[1]
    pos = log(r / GOOD) / log(THRESHOLD / GOOD)   # 0 at x GOOD, 1 at x THRESHOLD
    if (pos > 1) pos = 1
    idx = int(pos * (NPAL - 1)) + 1
    return pal[idx]
}

BEGIN {
    THRESHOLD = 20    # fixed by the subject
    GOOD      = 2     # below this ratio, nothing to do
    LOW       = 0.5   # ratio below which ft is "too fast to be true"
    NOISE     = 10000 # time (in nseconds) below which a measure is just noise

    RESET     = "\033[0m"
    GREY      = "\033[90m"
    GOOD_COL  = "\033[1;38;5;46m"       # bold bright green: untouched
    CHECK_COL = "\033[1;5;38;5;201m"    # bold blinking magenta: verify the bench
    KO_COL    = "\033[1;97;41m"         # bold white on red background

    # yellow -> orange -> red (gradient for tests to optimize)
    NPAL = split("226 220 214 208 202 196", codes, " ")
    for (i = 1; i <= NPAL; i++)
        pal[i] = "\033[38;5;" codes[i] "m"
}

# lines that are not measurements (separators, titles): copy them as is
!/nseconds *$/ { if (NR != FNR) print; next }

# 1st file = ft
NR == FNR { t_ft[FNR] = $(NF-1); next }

# 2nd file = std: compare ft against it
{
    std = $(NF-1)
    ft  = t_ft[FNR]
    n   = name($0)

    # invalid reference time: avoid a division by zero
    if (std <= 0) {
        printf "%-55s ft=%10d  std=%10d  x?       N/A\n", n, ft, std
        next
    }

    ratio = ft / std

    if (ft < NOISE && std < NOISE)  { col = GREY;      state = "NOISE" }
    else if (ratio > THRESHOLD)     { col = KO_COL;    state = "KO";    ko++ }
    else if (ratio < LOW)           { col = CHECK_COL; state = "CHECK"; check++ }
    else if (ratio < GOOD)          { col = GOOD_COL;  state = "OK";    ok++ }
    else                            { col = gradient(ratio); state = "OPTIM"; optim++ }

	if (state != "OK")
	{
    	printf "%-55s ft=%10d  std=%10d  x%-7.2f %s%s%s\n", n, ft, std, ratio, col, state, RESET
	}
}

# only KO makes the script fail (CHECK and OPTIM are hints, not errors)
END {
    printf "%s%d OK%s, %d OPTIM, %d CHECK, %s%d KO%s\n", \
        GOOD_COL, ok+0, RESET, optim+0, check+0, (ko > 0 ? KO_COL : ""), ko+0, RESET
    exit (ko > 0)
}