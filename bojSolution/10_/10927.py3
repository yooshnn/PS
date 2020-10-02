from hashlib import md5
print(md5(input().encode("utf-8")).hexdigest())