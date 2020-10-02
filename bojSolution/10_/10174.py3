for _ in range(int(input())):
    s=input().upper()
    print(["No","Yes"][s==s[::-1]])