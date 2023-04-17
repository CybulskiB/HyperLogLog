import matplotlib.pyplot as plt

# m = 2^b 
# m = 5bit
# 64bit = 12m = 2^3 - za malo 
# 96bit = 19m = 2^4 
# 320bit = 64m = 2^6
# 3200bit = 640m =2^8 
# 12800bit = 2569m = 2^11  
# b = 6 - 64b
# b = 


def toB(bytes):
    if bytes == "96" : return "4"
    if bytes == "320" : return "6"
    if bytes == "3200" : return "8"
    if bytes == "12800" : return "11"

def createplot(bytes):
    resultMinCount = []
    resultHyperLogLog = []
    n =[]
    for i in range(1 , 10001):
        n.append(i)

    with open('MinCount/Results/MinCount_' + bytes +'Bytes.txt',"r") as file:
        for line in file:
            resultMinCount.append(float(line))

    with open('Results/SHA256/Res' + toB(bytes) +'.csv',"r") as file:
        for line in file:
            x,  y = line.split(";")
            resultHyperLogLog.append(int(x)/int(y))

    plt.figure(figsize=(30,10))
    plt.title("Red = HyperLogLog b=" + str(5 * pow(2,int(toB(bytes)))) + " bytes " + " vs Blue =MinCount " + bytes + " bytes")
    plt.xlabel("n")
    plt.ylabel("res/n")
    plt.scatter(n,resultMinCount,c="blue")
    plt.scatter(n,resultHyperLogLog,c="red")
    plt.savefig('Histograms/MinCountCompare/Plot' + bytes + 'Bytes.png')


maxbits =["96","320","3200","12800"]

for b in maxbits:
    createplot(b)