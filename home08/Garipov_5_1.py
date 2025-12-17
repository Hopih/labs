s=[5,8,2,7,8,8,2,4]
d=""
x=int(input())
if x in s:
    for k in range (len(s)):
        if s[k]==x:
            d=d+str(k)+" "
    print(d)
else:
    print("Число отсутсвует")














