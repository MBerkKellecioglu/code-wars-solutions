def diamond(n):
    
    count = n
    
    blank = ""
    
    ast_ct = 1
    
    ast = ""
    
    s = ""
    
    main_s = ""
    
    if n % 2 == 0 or n < 0:
        return 
    
    if n == 1:
        return "*\n"
    
    for i in range(n // 2):
        for j in range(count // 2):
            
            blank += " "
        
        count -= 2
        
        for j in range(ast_ct):
            
            ast += "*"
            
        ast_ct += 2
        
        ast += "\n"
        
        s = blank + ast
        
        blank = ""
        ast = ""
    
        main_s += s
        
    for i in range(n):
            
        main_s += "*"
        
    main_s += "\n"
        
    count = 1
        
    ast_ct = n - 2
        
    for i in range(n // 2):
        for j in range(count):
                
            blank += " "
            
        count += 1
            
        for j in range(ast_ct):
                
            ast += "*"
            
        ast_ct -= 2
        
        ast += "\n"
        
        s = blank + ast
        
        blank = ""
        ast = ""
        
        main_s += s
        
        
        
    return main_s