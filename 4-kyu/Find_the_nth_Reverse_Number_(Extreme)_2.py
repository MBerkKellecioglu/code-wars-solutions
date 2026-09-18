def find_n_lower(n):
    
    flag = 0
    lower_limit = 0
    digit = 1
    while True:
        if digit % 2 == 0:
            temp_limit = 9 * pow(10, ((digit - 2) / 2))
        else:
            temp_limit = 9 * pow(10, ((digit - 1) / 2))
        
        if flag == 0:
            temp_limit += 1
            flag = 1

        if n <= lower_limit + temp_limit: break

        lower_limit += temp_limit

        digit += 1
    
    return digit, lower_limit

def find_reverse_number(n):
    digit, lower_limit = find_n_lower(n)

    lower_limit += 1

    temp_digit, temp_digit2, k, number_itself = digit - 1, 0, 0, 0

    if digit % 2 == 0:

        temp_power = (digit - 2) / 2
    else:
        temp_power = (digit - 1) / 2
    
    temp_hundred = pow(10, temp_power)

    distinc = abs(n - lower_limit)

    list_num = distinc / temp_hundred

    main_list = list(str(list_num).replace('.', ''))

    if (len(main_list) != temp_power + 1):

        main_list = main_list + ['0' for i in range ((int(temp_power) + 1)  - len(main_list))]

    while(temp_digit > temp_digit2):

        number_itself += (int(main_list[k])) * pow(10, temp_digit) + (int(main_list[k])) * pow(10, temp_digit2)
        
        temp_digit -= 1
        temp_digit2 += 1
        k += 1
    
    if digit % 2 == 1:

        number_itself += (int(main_list[k])) * pow(10, temp_digit)
        
    if digit > 1:
        
        number_itself += pow(10, digit - 1) + 1
    
    return number_itself

    