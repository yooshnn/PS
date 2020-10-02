from hashlib import sha224
print(sha224(input().encode("utf-8")).hexdigest())