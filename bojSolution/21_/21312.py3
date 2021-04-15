import sys; input = sys.stdin.readline

A, B, C = map(int, input().split())

hasOdd = False
answerOdd, answerEven = 1, 1

if A%2 == 1:
    answerOdd *= A
    hasOdd = True
else:
    answerEven *= A

if B%2 == 1:
    answerOdd *= B
    hasOdd = True
else:
    answerEven *= B

if C%2 == 1:
    answerOdd *= C
    hasOdd = True
else:
    answerEven *= C

if hasOdd:
    print(answerOdd)
else:
    print(answerEven)
