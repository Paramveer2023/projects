x = int(input("write operand1"))
y = int(input("write operand2"))
c = input("choose your operand")
if c=='+':
    if x==56 and y==9:
        print(77)
    else:
        print(x+y)
elif c=="-":
    print(x-y)
elif c=="*":
    if x==45 and y==3:
        print(555)
    else:
        print(x*y)
elif c=="/":
    if x==56 and y==6:
        print(4)
    else:
        print(x/y)

