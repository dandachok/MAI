import math

def f1(x)->float:
    return (x[0]**2 + 16)*x[1] - 64

def f2(x)->float:
    return (x[0] - 2)**2 + (x[1] - 2)**2 - 16

def f1x1(x)->float:
    return 2*x[0]*x[1]

def f2x1(x)->float:
    return 2*x[0] - 4

def f1x2(x)->float:
    return x[0]**2 + 16

def f2x2(x)->float:
    return 2*x[1] - 4

def detJ(x)->float:
    return f1x1(x)*f2x2(x) - f1x2(x)*f2x1(x)

def detA1(x)->float:
    return f1(x)*f2x2(x) - f1x2(x)*f2(x)

def detA2(x)->float:
    return f1x1(x)*f2(x) - f1(x)*f2x1(x)

def methodNewton(e)->float:
    prev = (100, 100)
    cur = (6, 2)
    while max(abs(prev[0] - cur[0]), abs(prev[1] - cur[1])) > e:
        prev = cur
        cur = (prev[0] - detA1(prev) / detJ(prev), prev[1] - detA2(prev) / detJ(prev))
    return cur

def phi1(x)->float:
    return math.sqrt(16-(x[1] - 2)**2) + 2

def phi2(x)->float:
    return 64 / (x[0]**2 + 16)

def detPhi1(x)->float:
    return -2*(x[1] - 2) / math.sqrt(16 - (x[1] - 2)**2)

def detPhi2(x)->float:
    return -4*x[0]/(x[0]**2 + 16)**2

def methodIter(e)->float:
    q = 0.5
    prev = (100, 100)
    cur = (6, 2)
    while q / (1 - q) * max(abs(prev[0] - cur[0]), abs(prev[1] - cur[1])) > e:
        prev = cur
        cur = (phi1(prev), phi2(prev))
    
    return cur
    