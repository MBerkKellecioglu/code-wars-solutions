import math

def lcm(*args):
    
    if len(args) == 0: return 1
    
    if len(args) == 1: return args[0]
    
    for i in args:
        
        if i == 0: return 0
    
    lc = args[0] * args[1] / GCD(args[0], args[1])
    
    for i in range (2,len(args)):
        
        lc = lc * args[i] / GCD(lc, args[i])
        
    
    return lc


def GCD(a,b):
    
    while(b):
        
        a,b = b, a % b
    
    return abs(a)
        
        
        
        
        
            
    
    