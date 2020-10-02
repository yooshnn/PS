from hashlib import sha384
print(sha384(input().encode("utf-8")).hexdigest())