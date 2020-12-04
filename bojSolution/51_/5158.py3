import sys
input = sys.stdin.readline

for TEST in range(int(input())):
    raw = []
    assessment = []
    company = {}; cio = []
    quality = {}
    modifier = {"not": 0, "very": 2, "extremely": 3, "slightly": 0.5}

    C, Q, L = map(int, input().split())
    for _ in range(C):
        t = input().rstrip()
        cio.append(t)
        company[t] = 0
    for _ in range(Q):
        t = input().split()
        quality[t[0].lower()] = float(t[1])
    for _ in range(L):
        raw.extend(input().split())

    for sentence in " ".join(raw).split("."):
        temp = sentence.split()
        if temp: assessment.append(temp)

    curCompany = ""
    for sentence in assessment:
        multiplier = 1
        companyInSent = {}

        for word in sentence:
            if word in company:
                curCompany = word
                try:
                    companyInSent[curCompany] = companyInSent[curCompany]
                except:
                    companyInSent[curCompany] = 0
            else:
                if not curCompany: continue
                if word.lower() in modifier:
                    multiplier *= modifier[word.lower()]
                if word.lower() in quality:
                    try: companyInSent[curCompany] += quality[word.lower()]
                    except: companyInSent[curCompany] = quality[word.lower()]

        for keys in companyInSent:
            company[keys] += companyInSent[keys] * multiplier

    print("Data Set %d:"%(TEST+1))
    for i in cio:
        print("%.2f"%company[i])
    print()