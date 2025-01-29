
def fatorial_button_up(n):
    arr_fatorial:dict = {}
    arr_fatorial[0] = 1
    arr_fatorial[1] = 1

    for i in range(2, n+1):
        arr_fatorial[i] = arr_fatorial[i-1] * i

    print(arr_fatorial)
    return arr_fatorial[n]

if __name__ == "__main__":
    # print(f'O fatorial de 4! = {fatorial_button_up(4)}') # 24
    # print(f'O fatorial de 3! = {fatorial_button_up(3)}') # 6
    # print(f'O fatorial de 2! = {fatorial_button_up(2)}') # 2
    # print(f'O fatorial de 1! = {fatorial_button_up(1)}') # 1
    # print(f'O fatorial de 5! = {fatorial_button_up(5)}') # 120

    assert fatorial_button_up(4) ==  24    
    assert fatorial_button_up(3) ==  6 
    assert fatorial_button_up(2) ==  2    
    assert fatorial_button_up(1) ==  1    
    assert fatorial_button_up(5) ==  120    

 