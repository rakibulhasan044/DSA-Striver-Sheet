def reverseArray(list1, l, r):
    if(l >= r): return
    list1[l], list[r] = list[r], list[l]
    reverseArray(list1, l + 1, r - 1)

if __name__ == "__main__":
    list = [10, 20, 30, 40]

    reverseArray(list, 0, len(list) - 1)
    for i in list:
        print(i, end=" ")
    print()