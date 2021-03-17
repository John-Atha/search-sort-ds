# K consecutive odd elements after sorting
def solve():
    l1 = input().split()
    N = int(l1[0])
    K = int(l1[1])
    prev = 0
    consCounter = 0
    l = map(lambda x: int(x), input().split())
    l2 = sorted(l)
    for x in l2:
        if x%2!=0:
            if (prev%2==1 or prev==0):
                consCounter = consCounter + 1
                if consCounter>=K:
                    return "yes"
            else:
                consCounter = 1
                if consCounter>=K:
                    return "yes"
        else:
            consCounter = 0
        prev = x
    return "no"

T = int(input())
for i in range(T):
    print(solve())
