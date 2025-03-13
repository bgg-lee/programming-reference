# a = 0b1101 #13
# b = 0b1111 #15
# print(a & b)
# print(a and b)
# print(a | b)
# print(a or b)
# # print(1)
# print(a<<2)

# num1 = 5
# num2 = 16
# num3 = 0
# num2 = 12
lst=[5,16,0,12,1,-1]
for num2 in lst :
    if num2 <= 0 : print("NO~")
    if num2 & (num2-1) == 0:
        print("Power of 2")
    else : print("NOT")