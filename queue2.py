from queue import Queue

def printQueue(q):
    q2 = Queue()
    while not q.empty():
        x = q.get()
        q2.put(x)
        print(x, end=' ')
    print()
    while not q2.empty():
        q.put(q2.get())

T = int(input())
for i in range(T):
    N = int(input())
    q = Queue()
    for j in range(1, N+1):
        q.put(j)
    for k in range(N-1):
        printQueue(q)
        q.put(q.get())
        q.get()
    print(q.get()) 