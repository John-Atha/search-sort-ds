# test cases
T = int(input())

# for each test case
for i in range(T):
    L = input().split(' ')
    N = int(L[0])
    K = int(L[1])
    # list of dictionaries
    Products = []
    for j in range(N):
        L2 = input().split(' ')
        Products.append(
            {
                'name': L2[0],
                'price': int(L2[1])
            }
        )
    # sort the list by price, name
    Prods = sorted(Products, key = lambda prod : (prod['price'], prod['name']))
    # pick the first K products 
    for item in Prods[:K-1]:
       print(item['name'], end=' ')
    print(Prods[K-1]['name'])
     