def isPalindrome(str, i):
    if(i >= len(str)/2):
        return True
    if(str[i] != str[len(str) - i - 1]):
        return False
    return isPalindrome(str, i + 1)

if __name__ == "__main__":
    print(isPalindrome("wow", 0))