import hashlib

import numpy as np
  
def count(M):
    acc =0 
    for m in M:
        if m != 1:
            acc = acc +1
    return acc


def MinCount(Mult,h,k):
    M = np.ones(k)
    for x in Mult:
        if h(x) < M[k-1] and  not h(x) in M:
            M[k-1] = h(x)
            M.sort()
    if M[k-1] == 1:
        return count(M)
    else:
        return (k-1)/M[k-1]

def myHash(x):
    return (int(hashlib.sha256(str(x).encode("utf-8")).hexdigest(),16))/2**256

testData = [2, 3, 10, 100, 400]


def getByteSize(k):
    if k == 2   :  return "64"
    if k == 3   :  return "96"
    if k == 10  :  return "320"
    if k == 100 :  return "3200"
    if k == 400 :  return "12800"


for k in testData:
    result = []
    for i in range (1, 10001):
        M = []
        with open("testData/Mult" + str(i) + "txt", "r") as file:
            for line in file:
                M.append(int(line))
        result.append(MinCount(M, myHash, k)/i)
    
    with open("Results/MinCount_" + getByteSize(k) + "Bytes.txt","w") as resfile:
        for x in result:
            resfile.write(str(x) + '\n')
    