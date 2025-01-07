# 1 2 3 4 5 6 7  8  9 10 11 12
# 0 1 1 2 3 5 8 13 21 34 55 89 

def fibonacci(n:int):
    if n == 1:
        return 0
    if n == 2:
        return 1
    
    return fibonacci(n-1) + fibonacci(n-2)

def main():
    
    numero = int(input("Entre com o valor a ser calculado: "))
    print(f'Fibonacci {numero} é {fibonacci(numero)}')

main()