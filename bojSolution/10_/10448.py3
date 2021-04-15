import sys; input = sys.stdin.readline
from itertools import combinations_with_replacement

li = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820, 861, 903, 946, 990]
pool = set()

for p in combinations_with_replacement(li, 3):
    if sum(p)<=1000: pool.add(sum(p))

for TEST in range(int(input())):
    print(1 if int(input()) in pool else 0)