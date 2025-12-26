byte = int(input())

num_long = byte // 4
output = ''
for i in range(num_long):
    output += 'long '
print(output + 'int')