
def fatorial_memo(n, memo={}):
    if n == 0:
        return 1
    if n == 1:
        return 1
    if n not in memo:
        print(f'fatorial: {n}')
        memo[n] =  n * fatorial_memo(n-1, memo)
    
    return memo[n]

if __name__ == "__main__":
    print(fatorial_memo(4)) # 24
    print("#"*20)
    print(fatorial_memo(5)) # 120
    print(fatorial_memo(7))
