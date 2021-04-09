from queue import LifoQueue
T = int(input())
for i in range(T):
    N = int(input())
    stack = LifoQueue()
    for j in range(N):
        s = input()
        if s.startswith('place'):
            l = s.split(' ')
            x = l[1]
            print(x)
            stack.put(x)
        elif stack.qsize():
            print("remove: ", end=' ')
            print(stack.get(), end= ' ')
        else:
            print("-1", end=' ')
    print()