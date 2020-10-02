from sys import stdin
def input(): return stdin.readline().rstrip()

class dir:
    pathCnt = 0

    def __init__(self, hierarchy): # new directory
        self.name = hierarchy[0]   # name
        self.id = dir.pathCnt      # unique ID
        self.subDir = []           # dir's subDirs
        dir.pathCnt += 1
        if len(hierarchy) > 1: self.appendSubDir(hierarchy[1:])

    def appendSubDir(self, hierarchy):
        req = self.getSubDirByName(hierarchy[0])
        if not req: self.getSubDir().append(dir(hierarchy))
        elif len(hierarchy) > 1: req.appendSubDir(hierarchy[1:])

    def search(self, name):
        req = self.getSubDirByName(name)
        if not req: return False
        else: return req

    def getName(self): return self.name
    def getSubDir(self): return self.subDir
    def getId(self): return self.id
    def getSubDirByName(self, s):
        for i in range(len(self.getSubDir())):
            if self.subDir[i].getName() == s:
                return self.subDir[i]
        return False

# __func__
def parseDirInput(dir):
    req = root
    history = [req]

    for i in range(len(dir)):
        # access denied
        if len(req.getSubDir()) == 0: return -1
        # restore omitted index.html
        if dir[i] == "":
            tmp = history[-1].getSubDirByName("index.html")
            if not tmp:
                return -1
            else:
                if len(tmp.getSubDir()) == 0:
                    history.append(tmp)
                else:
                    return -1
            continue
        # directory itself
        if dir[i] == ".": continue
        # parent directory
        if dir[i] == "..":
            if len(history) > 1: history.pop()
            else: return -1 # root has no parent directory
            continue

        req = history[-1].search(dir[i])
        # 404
        if req == False: return -1
        history.append(req)

    tmp = history[-1].getSubDirByName("index.html")
    if not tmp:
        if len(history[-1].getSubDir()) == 0:
            return history[-1].getId()
        else:
            return -1
    else:
        return tmp.getId()


# __main__
root = dir(["__root__"])

while 1:
    del root
    root = dir(["__root__"])

    N, M = map(int, input().split())
    if N == 0 and M == 0: break

    for n in range(N):
        s = input()[1:].split("/")
        root.appendSubDir(s)

    for m in range(M):
        q1 = parseDirInput(input().split("/")[1:])
        q2 = parseDirInput(input().split("/")[1:])

        if q1==-1 or q2==-1:
            print("not found")
        elif q1 == q2:
            print("yes")
        else:
            print("no")
