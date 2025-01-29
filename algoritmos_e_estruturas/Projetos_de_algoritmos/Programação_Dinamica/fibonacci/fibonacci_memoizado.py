
def fib_memoizado(n, memoria:dict={}):
    if n <= 2:
        return 1

    if n not in memoria:
        memoria[n] = fib_memoizado(n-1, memoria) + fib_memoizado(n-2, memoria)
    
    return memoria[n]

if __name__ == "__main__":
    # 1  2  3  4  5  6  7   8   9   10  11   
    # 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89
    print(f'fibonacci: 4: ', fib_memoizado(4))
    print(f'fibonacci: 7: ', fib_memoizado(7))
    print(f'fibonacci: 8: ', fib_memoizado(8))
    print(f'fibonacci: 9: ', fib_memoizado(9))
    print(f'fibonacci: 10: ', fib_memoizado(10))
