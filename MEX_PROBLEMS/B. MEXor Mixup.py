t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    A = a
    a=a-1
    
    if a < 0:
        curr = 0
    elif a % 4 == 0:
        curr = a
    elif a % 4 == 1:
        curr = 1
    elif a % 4 == 2:
        curr = a + 1
    else:
        curr = 0
        
    
    if curr == b:
        print(A)
    else:
        if (curr^b)!=A:
            print(A+1)
        else:
            print(A+2)
