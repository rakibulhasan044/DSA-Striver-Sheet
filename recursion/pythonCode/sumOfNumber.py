def sumOfNum(n):
    if(n < 1): return 0
    return n + sumOfNum(n - 1)

def parameterizedSum(i, sum):
    if i < 1 :
        print(sum)
        return
    parameterizedSum(i - 1, sum + i)

def factorial(n):
    if n == 0: return 1
    return n * factorial(n - 1)

if __name__ == "__main__":
    print(sumOfNum(3))
    parameterizedSum(5, 0)
    print(factorial(5))