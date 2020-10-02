import os
import shutil
from pathlib import Path

def getF(dir):
    ret = []
    for p in Path(dir).iterdir():
        if p.is_file():
            ext = str(p).split(".")[-1]
            if ext in ["txt"]:
                ret.append(str(p))
    return ret

def getN(fp):
    ret = []
    for p in fp:
        ret.append(str(p).split("\\")[-1])
    return ret

fLi = getF(Path.cwd())
nLi = getN(fLi)

# for i in range(10, 100):
#     f = str(i) + "_"
#     d = Path.cwd() / f
#     os.mkdir(d)

for i, p in enumerate(fLi):
    mid = str(nLi[i][:2]) + "_"
    newDir = Path.cwd() / mid / str(nLi[i])
    os.makedirs(os.path.dirname(newDir), exist_ok=True)
    shutil.copy(str(p), str(newDir))
