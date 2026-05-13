def isEven(n: int) -> bool:
    if n < 0:
        return isEven(-n)
    if n == 0:
        return True
    return not isEven(n - 1)

def isOdd(n: int) -> bool:
    return not isEven(n)
