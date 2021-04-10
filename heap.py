import heapq
# acts as min heap by default so we mult with -1 to have a max heap
def solve():
    T = int(input())
    for i in range(T):
        N = int(input())
        l0 = list(input().split())
        l = []
        index=1
        for x in l0:
            l.append((-1*int(x),-1*index))
            index+=1
        #print(l0)
        #print(l)
        heapq.heapify(l)
        while len(l):
            curr = heapq.heappop(l)
            print(-1*curr[1], end=' ')
        print()

solve()