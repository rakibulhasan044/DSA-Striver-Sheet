
s = str(input("Enter a string: ")).strip()

hash = [0] * 256

for char in s:
    hash[ord(char)] += 1

q = int(input("Enter number of queries: "))

for _ in range(q):
    c = input("Enter a single character :")
    print(hash[ord(c)])

