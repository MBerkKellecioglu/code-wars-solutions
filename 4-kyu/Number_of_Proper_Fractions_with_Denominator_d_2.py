def proper_fractions(n):
    
    if n > 1:
        res = n
    else:
        return 0
    
    for i in range(2, int(n ** .5) + 1):
        
        if n % i == 0:
            
            res -= res // i
            
            while n % i == 0:
                
                n = n // i
    if n > 1:
        res -= res // n
        
    return res
        