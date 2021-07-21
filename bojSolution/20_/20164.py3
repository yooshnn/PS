def countOdds(n: int):
    ret = 0
    s = str(n)
    for i in s:
        if i in "13579": ret += 1
    return ret

def solve1(n: int):
    cur = countOdds(n)
    n = str(n)

    if len(n)==1:
        return cur
    if len(n)==2:
        nxt = int(n[0]) + int(n[1])
        return cur + solve1(nxt)

    ret = 2e8
    for i in range(1, len(n)-1):
        for j in range(i+1, len(n)):
            p1, p2, p3 = n[:i], n[i:j], n[j:]
            nxt = int(p1)+int(p2)+int(p3)
            ret = min(ret, solve1(nxt))

    return cur + ret

def solve2(n: int):
    cur = countOdds(n)
    n = str(n)

    if len(n)==1:
        return cur
    if len(n)==2:
        nxt = int(n[0]) + int(n[1])
        return cur + solve2(nxt)

    ret = 0
    for i in range(1, len(n)-1):
        for j in range(i+1, len(n)):
            p1, p2, p3 = n[:i], n[i:j], n[j:]
            nxt = int(p1)+int(p2)+int(p3)
            ret = max(ret, cur + solve2(nxt))
    return ret

N = int(input())
print(solve1(N), solve2(N))