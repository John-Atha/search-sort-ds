# K larger distinct values

T = int(input())
for i in range(T):
    line1 = input().split(' ')
    N = int(line1[0])
    K = int(line1[1])
    l = map(lambda x: int(x), input().split())
    l2 = sorted(l)
    copy = []
    for a in l2:
        if a not in copy:
            copy.append(a)
    print(copy)
    n2 = len(copy)
    if n2<K:
        print("-1")
    else : 
        for x in copy[:n2-K:-1]:
            print(x, end=" ")
        print(copy[n2-K])
