
def toInt(line):
    if line ==   "00000" : return 0
    elif line == "00001" : return 1
    elif line == "00010" : return 2
    elif line == "00011" : return 3 
    elif line == "00100" : return 4
    elif line == "00101" : return 5
    elif line == "00110" : return 6
    elif line == "00111" : return 7
    elif line == "01000" : return 8
    elif line == "01001" : return 9
    elif line == "01010" : return 10
    elif line == "01011" : return 11
    elif line == "01100" : return 12
    elif line == "01101" : return 13
    elif line == "01110" : return 14
    elif line == "01111" : return 15
    elif line == "10000" : return 16
    elif line == "10001" : return 17
    elif line == "10010" : return 18
    elif line == "10011" : return 19
    elif line == "10100" : return 20
    elif line == "10101" :return 21
    elif line == "10110" : return 22
    elif line == "10111" : return 23
    elif line == "11000" : return 24
    elif line == "11001" : return 25
    elif line == "11010" : return 26
    elif line == "11011" : return 27
    elif line == "11100" : return 28
    elif line == "11101" : return 29
    elif line == "11110" : return 30
    elif line == "11111" : return 31

sum = 0
with open("TestDataSHA256/Hashes7000.txt", "r") as file:
    for line in file:
        sum += toInt(line[0:5])
print(sum)