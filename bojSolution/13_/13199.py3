from sys import stdin

T=int(stdin.readline())
for _ in range(T):
    P,M,F,C=map(int,stdin.readline().split())
    money=M//P
    do=money
    sang=money
    do+=((money)*C)//F # 돈으로 시킨 치킨 * 치킨당쿠폰 // 필요쿠폰수
    t=money*C # 획득 쿠폰 수
    if t>=F:
        sang+=(t-F)//(F-C)+1
    print(sang-do)