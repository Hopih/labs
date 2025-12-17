def pas (flag):
    password=str(input("Придумайте пароль "))
    a="!“#$%&"
    for k in a:
        if k in password:
            flag=True
    if flag==True:
        print("Пароль принят ")
    else:
        print("Нет спец символов ")
    return [flag,password]

x=pas(False)
z=True
d=0
while z==True:
    if x[0]==True:
        newpas=str(input("Введите пароль "))
        if newpas==x[1]:
            print("Пароль совпал ")
            break
        else:
            print("Пароль не совпал")
            d=d+1  
    else:
        d=0
        x=pas(False)
    if d%3==0 and d!=0:
        print("Поменять пароль? Да/Нет ")
        answ=str(input())
        if answ=="Да":
            x=pas(False)





   
            


    


























    













