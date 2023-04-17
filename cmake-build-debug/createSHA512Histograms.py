import matplotlib.pyplot as plt

def createplot(b):
    resultSmall = []
    resultIntermediate = []
    resultLarge =[]
    nSmall =[]
    nIntermediate =[]
    nLarge = []

    i =0
    with open('Results/SHA512/Res' + b +'.csv',"r") as file:
        for line in file:
            i += 1
            x,  y, z = line.split(";")
            if z == "small\n":
                nSmall.append(i)
                resultSmall.append(int(x)/int(y))
            if z == "intermediate\n":
                nIntermediate.append(i)
                resultIntermediate.append(int(x)/int(y))
            if z == "large\n":
                nLarge.append(i)
                resultLarge.append(int(x)/int(y))

    plt.figure(figsize=(30,10))
    plt.title("SHA512, b = "+ b + " Small correction- yellow, Intermediate correction- blue, Large correction -red")
    plt.xlabel("n")
    plt.ylabel("res/n")
    plt.scatter(nSmall,resultSmall, c="yellow")
    plt.scatter(nIntermediate,resultIntermediate,c="blue")
    plt.scatter(nLarge,resultLarge,c="red")
    plt.savefig('Histograms/SHA512/Plot' + b + '.png')

bs =['4','5','6','7','8','9','10','11','12','13','14','15','16']

for b in bs:
    createplot(b)
