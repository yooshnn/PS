import sys; input = sys.stdin.readline

for TEST in range(int(input())):
    s = input().rstrip()
    r = s.count('a')+s.count('i')+s.count('u')+s.count('e')+s.count('o')
    print("The number of vowels in %s is %d."%(s, r))