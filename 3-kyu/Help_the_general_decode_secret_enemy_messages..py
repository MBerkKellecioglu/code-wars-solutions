def decode(s):
    
    main_dict, index_diff = dict(), dict()
    result, j, pattern, symbols = "", 1,"bdhpF,82QsLirJejtNmzZKgnB3SwTyXG ?.6YIcflxVC5WE94UA1OoD70MkvRuPqHa", "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ0123456789.? "
    
    pattern = pattern * 2
    
    for i in s:
        if i in "!@#$%^&*()_+-=/":
            result += i
            j += 1
        else:    
            result += pattern[pattern.find(i) - j]
            j += 1
    
    return result