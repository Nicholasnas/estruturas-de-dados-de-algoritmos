from time import time

def recursion_fibonacci(max=100):
    if max == 0:
        return [0]
    elif max == 1:
        return [0,1]
    else:
        sequencia = [0,1]
        for i in range(max):
            sequencia.append(sequencia[-1]+sequencia[-2])
    
    return sequencia
def fibonacci(max=100):
    atual_numero, prox_numero = 0, 1
    
    while atual_numero < max:
        yield atual_numero
        
        atual_numero, prox_numero = prox_numero, atual_numero + prox_numero


def main():
    antes = time()
    fib = fibonacci()
    for num in fib:
        print(num)
    depois = time()
        
    print('Tempo: ', depois-antes)
    print('Fibonacci recursão')
    antes_recursao = time()
    print(recursion_fibonacci(100))
    depois_recursao = time()
    print('Tempo: ',depois_recursao-antes_recursao)

    
main()