from collections import deque
from math import floor
last = None
def outLeft(qu, K):
    #print("I am outleft")
    global last
    for i in range(K):
        if len(qu):
            #print("left")
            last = qu.popleft()
        else:
            break
def outRight(qu, K):
    #print("I am outright")
    global last
    for i in range(K):
        if len(qu):
            #print("right")
            last = qu.pop()
        else:
            break

T = int(input())
for i in range(T):
    last = None
    q = deque()
    nk = list(input().split())
    N = int(nk[0])
    K = int(nk[1])
    #print(f"N: {N}, K: {K}")
    if K==1:
        print(floor(N/2)+1)
    else:
        for i in range(1,N+1):
            q.append(i)
        #print(q)
        counter = 0
        while len(q):
            if counter==0:   # odd
                outLeft(q, K)
                counter=1
            else:
                outRight(q, K)
                counter=0
        print(last)       

