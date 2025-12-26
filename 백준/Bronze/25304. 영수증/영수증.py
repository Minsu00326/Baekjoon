X = int(input())
N = int(input())
a,b = [0]*N, [0]*N

for i in range(N):
    a[i], b[i] = map(int, input().split())
    
sum = 0
for i in range(N):
    sum += a[i]*b[i]
    
if sum == X:
    print('Yes')
else:
    print('No')