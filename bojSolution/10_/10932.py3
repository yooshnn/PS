from hashlib import sha512
print(sha512(input().encode("utf-8")).hexdigest())