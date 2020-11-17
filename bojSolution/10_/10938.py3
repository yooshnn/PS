import sys
import base64
input = sys.stdin.readline

print(str(base64.b32encode(input().rstrip().encode("UTF-8")))[2:-1])