import sys
input = sys.stdin.readline
N, M = map(int, input().split())
nums = list(map(int, input().split()))

prefix_sum = [0] # 부분합 배열
temp = 0
for num in nums:
    temp = temp + num
    prefix_sum.append(temp)

for _ in range(M):
    i, j = map(int, input().split())
    print(prefix_sum[j] - prefix_sum[i-1])