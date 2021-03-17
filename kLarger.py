T = int(input())
for i in range(T):
    line1 = input().split(' ')
    N = int(line1[0])
    K = int(line1[1])
    l = map(lambda x: int(x), input().split())
    l2 = sorted(l)
    for x in l2[N-1:N-K:-1]:
        print(x, end=" ")
    print(l2[N-K])
