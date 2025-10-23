from functools import lru_cache

def fibonacci(n:int):
    assert n > 0
    a1 = 1
    a2 = 2
    # base case
    if n == 1:
        return a1
    elif n == 2:
        return a2
    # recursive case
    else:
        return fibonacci(n-1) + fibonacci(n-2)
    
def factorial(a, n:int):
    assert n > 0
    if n == 0:
        return 1
    if n == 1:
        return a
    else:
        return a * factorial(a, n-1)

@lru_cache(maxsize=None)
def combinatorial(n, k):
    # Pascal Identity
    assert 0 <= k <= n
    # base case
    if (n == k) or (k==0):
        return 1
    return combinatorial(n-1, k-1) + combinatorial(n-1, k)

