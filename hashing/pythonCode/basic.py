hash = {}

n = int(input("Enter the number of elements: "))
arr = list(map(int, input(f"Enter {n} elements: ").split()))

for i in arr:
    if i in hash:
        hash[i] += 1
    else:
        hash[i] = 1

q = int(input("Enter number of queries: "))

for _ in range(q):
    number = int(input("Enter a number to query: "))
    print(hash.get(number, 0))