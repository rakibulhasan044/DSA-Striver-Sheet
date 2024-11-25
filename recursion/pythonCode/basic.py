cnt = 0

def func():
    global cnt
    if cnt == 4:
        return
    print(cnt, end=" ")
    cnt += 1
    func()

# if __name__ == "__main__":
#     func()
#     print()

func()
