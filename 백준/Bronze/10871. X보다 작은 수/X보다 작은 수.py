import sys
N, X = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
answer = []
for num in nums:
    if num < X:
        print(num, end=' ')