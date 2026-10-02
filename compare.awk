awk
function nom(s) { sub(/: *[0-9.e+-]+ useconds.*$/, "", s); return s }

BEGIN { RED = "\033[31m"; GREEN = "\033[32m"; RESET = "\033[0m" }

!/useconds *$/ { if (NR != FNR) print; next }

NR == FNR { t_std[FNR] = $(NF-1); next }   # 1er fichier = std
{
    ft = $(NF-1); std = t_std[FNR]
    n = nom($0)

    if (std <= 0) {
        printf "%-35s ft=%6d  std=%6d  x?      N/A\n", n, ft, std
        next
    }

    ratio = ft / std
    if (ratio > seuil) { col = RED;   etat = "KO"; found = 1 }
    else               { col = GREEN; etat = "OK" }

    printf "%-45s ft=%10d  std=%10d  x%-7.2f %s%s%s\n", n, ft, std, ratio, col, etat, RESET
}

END { exit found }