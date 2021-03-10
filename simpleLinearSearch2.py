T = int(input())
for i in range(T):
    l1 = input().split()
    #print(l1)
    N = int(l1[0])
    X = int(l1[1])
    counter=0
    l2 = input().split()
    for k in l2:
        if int(k)>X:
            counter=counter+1
    print(counter)