import sys

N = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))
v = int(sys.stdin.readline())

count = 0
for n in nums:
    if n == v:
        count += 1
print(count)
