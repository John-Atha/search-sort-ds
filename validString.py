# T test cases with ove binary string at each one
# string is valid if 1) #'0's==#'1's
#                    2) at every suffix: #'0's>=#'1's
T = int(input())
for i in range(T):
    N = int(input())
    s = input()
    count0 = 0
    over = False
    for c in s:
        if c=="0":
            count0+=1
        else:
            count0-=1
            if count0<0:
                print("no")
                over=True
                break
    if count0==0:
        print("yes")
    elif not over:
        print("no")    