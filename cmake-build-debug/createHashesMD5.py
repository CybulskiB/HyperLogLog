import hashlib
def toBinary(somestring):
     result =""
     for c in somestring:
          if c == '0': result += "0000"
          elif c == '1' : result += "0001"
          elif c == '2' : result += "0010"
          elif c == '3' : result += "0011"
          elif c == '4' : result += "0100"
          elif c == '5' : result += "0101"
          elif c == '6' : result += "0110"
          elif c == '7' : result += "0111"
          elif c == '8' : result += "1000"
          elif c == '9' : result += "1001"
          elif c == 'A' : result += "1010"
          elif c == 'B' : result += "1011"
          elif c == 'C' : result += "1100"
          elif c == 'D' : result += "1101"
          elif c == 'E' : result += "1110"
          elif c == 'F' : result += "1111"
     return result[0:32]
     
def myhash(x):
     a = hashlib.md5(x.to_bytes(14,'little')).hexdigest()
     x = int(a,base=16)
     x = x% int(pow(2,32))
     return bin(x)[2:].zfill(32)

for i in range (1, 10001):
        result =[]
        with open("TestData/Mult" + str(i) + "txt", "r") as file:
            for line in file:
                result.append(myhash(int(line)))
        with open("TestDataMD5/Hashes" + str(i) + ".txt", "w") as resfile:
             for x in result:
                  resfile.write(str(x) + '\n')
             