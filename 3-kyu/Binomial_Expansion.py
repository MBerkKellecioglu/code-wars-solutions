import re
import math

def expand(expr):
    
    s = ""
    
    if expr[-1] == "0": return "1"
    
    a = re.findall("\-?[0-9]+|[a-z]",expr)
    
    lst = Pascal(int(a[-1]))
    
    if a[0].isalpha():
        
        if expr[1] == "-": a.insert(0,"-1")
        else: a.insert(0,"1")
    
    
    for i in range(int(a[-1])):
        
        p = lst[i] * pow(int(a[0]), int(a[-1]) - i) * pow(int(a[2]), i)
        
        if p == 1:
            
            if int(a[-1]) - i == 1: s += a[1]
            
            else: s += a[1] + "^" + str(int(a[-1]) - i)
        
        else:
            
            if int(a[-1]) - i == 1: s += str(p) + a[1]
            
            else: s += str(p) + a[1] + "^" + str(int(a[-1]) - i) 
        
        
        t = lst[i] * pow(int(a[0]) , int(a[-1]) - i - 1) * pow(int(a[2]), i + 1)
        
        if t > 0: s += "+"
        
        
    t = pow(int(a[2]) , int(a[-1]) )
    
    s += str(t)
    

    
    if s[0] == "-" and s[1] == "1":
        
        if s[2].isalpha():
        
            s = s[:1] + s[1 + 1:]
    
    
    return s
            
        
    
    
def Pascal(k):
    
    lst = [[1], [1,1]]
    
    for i in range(1,k):
        
        row = []
        
        row.append(1)
        
        for j in range(len(lst[i]) - 1):
            
            row.append(lst[i][j] + lst[i][j + 1])
            
        row.append(1)
        
        lst.append(row)
        
    
    return lst[-1]