def diagnostic(sec1, sec2):
    print(sec1)
    print(sec2)

def section(N):
    sec = []
    for j in range(N):
        curr = input().split()
        sec.append({
            "name": curr[0],
            "price": int(curr[1]),
        })
    return sorted(sec, key=lambda prod : (prod['price'], prod['name']))

def minProd(obj1, obj2):
    if obj1['price']<obj2['price']:
        return obj1
    elif obj1['price']>obj2['price']:
        return obj2
    else:
        if obj1['name']<obj2['name']:
            return obj1
        else:
            return obj2

def printProd(obj):
    print(obj['name'], end= ' ')
    #print(obj['price'])

def merge(sec1, sec2, P, Q):
    while(P and Q):
        #diagnostic(sec1, sec2)
        minim = minProd(sec1[0], sec2[0])
        if minim==sec1[0]:
            printProd(sec1[0])
            sec1 = sec1[1:]
            P = P-1
        else:
            printProd(sec2[0])
            sec2 = sec2[1:]
            Q = Q-1
    #print("out of the while, with:")
    #diagnostic(sec1, sec2)
    #print("P: " + str(P))
    #print("Q: " + str(Q))
    if (not Q):
        while(P):
            #diagnostic(sec1, sec2)
            if P==1:
                print(sec1[0]['name'])
            else:
                printProd(sec1[0])
            sec1 = sec1[1:]
            P = P-1
    elif (not P):
        while(Q):
            #diagnostic(sec1, sec2)
            if Q==1:
                print(sec2[0]['name'])
            else:
                printProd(sec2[0])
            sec2 = sec2[1:]
            Q = Q-1

def solve(kind, prevInput = ''):
    if kind=="right test case":
        l = input().split()
    else:
        l = prevInput.split()
    N = int(l[0])
    M = int(l[1])
    P = int(l[2])
    Q = int(l[3])
    sec1 = section(N)
    sec2 = section(M)
    #diagnostic(sec1, sec2)
    merge(sec1, sec2, P, Q)

def answer():
    ambiguous = input()
    if len(ambiguous.split())==1:
        T = int(ambiguous[0])
        for i in range(T):
            solve("right test case")
    else:
        solve("wrong test case", ambiguous)


answer()