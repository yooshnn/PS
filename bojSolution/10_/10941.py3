import sys
import base64
input = sys.stdin.readline

print(str(base64.b16decode(input().rstrip()))[2:-1])