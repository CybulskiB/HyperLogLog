import matplotlib.pyplot as plt

def createplot(b):
    result = []
    n =[]
    for i in range(1 , 10001):
        n.append(i)

    with open('Results/MD5/Res' + b +'.csv',"r") as file:
        for line in file:
            x,  y = line.split(";")
            result.append(int(x)/int(y))

    plt.figure(figsize=(30,10))
    plt.title("MD5, b="+b)
    plt.xlabel("n")
    plt.ylabel("res/n")
    plt.scatter(n,result)
    plt.savefig('Histograms/MD5/Plot' + b + '.png')

bs =['4','5','6','7','8','9','10','11','12','13','14','15','16']

for b in bs:
    createplot(b)
