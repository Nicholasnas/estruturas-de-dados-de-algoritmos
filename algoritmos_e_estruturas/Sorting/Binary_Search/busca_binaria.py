
def busca_binaria(lista:list[int], target:int):
    
    baixo = 0
    alto = len(lista) - 1
    while baixo <= alto:
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == target:
            return chute
        if chute > target:
            alto = meio - 1
        else:
            baixo = meio + 1 
    return None      

def main():
    lista = [num for num in range(10) if num % 2 != 0]
    print(lista)
    print(busca_binaria(lista, 3))
    
main()