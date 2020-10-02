from sys import stdin
from decimal import Decimal as D
def input(): return stdin.readline().rstrip()

for _ in range(int(input())):
    h,m,s=map(D,input().split())

    h_angle=h*30 + m/2 + s/120
    m_angle=m*6 + s/10
    s_angle=s*6

    hm_diff=min(abs(h_angle-m_angle),360-abs(h_angle-m_angle))
    hs_diff=min(abs(h_angle-s_angle),360-abs(h_angle-s_angle))
    ms_diff=min(abs(m_angle-s_angle),360-abs(m_angle-s_angle))

    print(min([hm_diff,hs_diff,ms_diff]))