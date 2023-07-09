def count(lst):
    even=0
    odd=0
    for i in lst:
        if i%2==0:
            even+=1

        else:
            odd+=1
        return even,odd
lst = [25,84,57,65,12,35,34,94,65,56,59,1664,4446,65656,597,789]
eve,od = count(lst)
print(eve)
print(od)