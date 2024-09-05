

def busca_qualquer(hash, key):
    if hash.get(key):
        return 1
    else:
        return 1
    

def inserir_por_tamanho(hash, value):
    tam = len(value)
    hash[f'{tam}'] = value
    return tam

def inserir_por_caracter(hash, value):
    first_caracter = value[0]
    hash[f'{first_caracter}'] = value
    return first_caracter


def is_primo(num):
    "Primo deve ser divisivel por 1 e por ele mesmo"
    "num % 2 == 0 and num % num == 0"
    divisores = 0
    for n in range(2, num):
        if num % n == 0:
            divisores += 1
    
    if divisores == 0:
        return True
    else:
        return False

def numeros_primos_50():
    primos = [i for i in range(1,51) if is_primo(i) ]
    return primos




if __name__ == "__main__":
    hash = dict()
    print(numeros_primos_50())
