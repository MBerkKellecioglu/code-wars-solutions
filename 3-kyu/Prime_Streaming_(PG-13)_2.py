import math

class Primes:
    @staticmethod
    def stream():
        
        limit, count = (10**7)*2, 0
        
        sieve = [False, True] * (limit // 2)
        
        sieve[1] , sieve[2] = False, True
        
        for i in range(3,math.isqrt(limit) + 1, 2):
            if sieve[i]:
                sieve[i*i:limit:2*i] = [False] * math.ceil((limit - (i*i)) / (2*i))
                
        
        prime_generator = (prime for prime, is_prime in enumerate(sieve) if is_prime)
        
        for i in prime_generator:
            yield i
        
    
        
            
    
        

        
        
        
        
        