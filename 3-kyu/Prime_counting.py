import bisect 
import math
from functools import lru_cache

def sieve_of_eratosthenes(n):
    
    prime = [True] * (n+1)
    prime[0], prime[1] = False, False
    
    p = 2

    while p * p <= n:
        if prime[p]:
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    primes = [num for num, is_prime in enumerate(prime) if is_prime]

    return primes

primes = sieve_of_eratosthenes(10**7)

@lru_cache(maxsize = None)         
def phi(x, a):
    
    if(a == 1): return (x + 1) // 2
    
    return phi(x, a - 1) - phi(x // primes[a - 1], a - 1)

@lru_cache(maxsize = None)
def Meissel(x):

    if x <= 10**7:
        return bisect.bisect(primes, x)
    
    b = bisect.bisect(primes, int(math.sqrt(x)))
    c = bisect.bisect(primes, int(math.cbrt(x)))
    a = bisect.bisect(primes, int(x**0.25))
    
    pi = phi(x, a) + (a + b - 2)*(b - a + 1) // 2
    
    for i in range(a, b):
        pi -= Meissel(x // primes[i])
        
        if i <= c:
            for j in range(i, Meissel(int(math.sqrt(x // primes[i]))) ):
                pi -= Meissel(x // (primes[i] * primes[j]) ) - j
            
    return pi
            
def count_primes_less_than(n:int) -> int:
    
    print(n)
    return Meissel(n)