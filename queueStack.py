import heapq
from queue import Queue, LifoQueue

T = int(input())
for i in range(T):
    priorQueue = []
    heapq.heapify(priorQueue)
    q = Queue()
    stack = LifoQueue()
    N = int(input())
    for j in range(N):
        L0 = input().split()
        L = list(map(lambda x :int(x), L0))
        if L[0]==1:
            heapq.heappush(priorQueue, -1*L[1])
        elif L[0]==2:
            q.put(L[1])
        else:
            stack.put(L[1])
    while len(priorQueue):
        print((-1*heapq.heappop(priorQueue)), end=' ')
    while q.qsize():
        print(q.get(), end=' ')
    while stack.qsize():
        print(stack.get(), end=' ')
    print()