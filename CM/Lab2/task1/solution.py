import math

def f(x:float)->float:
    return math.sqrt(1 - x**2) - math.e**x + 0.1

def df(x:float)->float:
    return - x / math.sqrt(1 - x**2) - math.e**x

def methodNewton(e:float)->float:
    prev = 100
    cur = 0.2
    while abs(prev - cur) > e:
        prev = cur
        cur = prev - f(prev) / df(prev)

    return cur

def p(x:float)->float:
    return math.log(math.sqrt(1 - x**2) + 0.1)

def dp(x:float)->float:
    return x / (x**2 - 0.1 * math.sqrt(1 - x**2) - 1)

def simpleIter(e:float):
    q = 0.2
    prev = 100
    cur = 0.1
    while q / (1 - q) * abs(prev - cur) > e:
        prev = cur
        cur = p(prev)
    
    return cur