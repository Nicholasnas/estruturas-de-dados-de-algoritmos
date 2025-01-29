"Fibonacci top down - iterativo -> do menor para o maior"

def fibonacci_botton_up(n:int):
    # 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89

    if n <= 2:
        return 1
    
    fib: dict = {}
    fib[1] = 1
    fib[2] = 1
    for i in range(3, n+1):
        fib[i] = fib[i-1] + fib[i-2]
    
    return fib[n]

if __name__ == "__main__":
    # 1  2  3  4  5  6  7   8   9   10  11   
    # 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
    print(f'fibonacci: 4: ', fibonacci_botton_up(4))
    print(f'fibonacci: 7: ', fibonacci_botton_up(7))
    print(f'fibonacci: 8: ', fibonacci_botton_up(8))
    print(f'fibonacci: 9: ', fibonacci_botton_up(9))
    print(f'fibonacci: 10: ',fibonacci_botton_up(10))
