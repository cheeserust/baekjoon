def solution(a, b):
    add=int(str(a)+str(b))
    mul = 2*a*b
    if(add == mul):
        return add
    if(add>mul):
        return add
    elif(add<mul):
        return mul