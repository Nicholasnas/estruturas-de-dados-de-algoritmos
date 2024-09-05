


def quicksort_v1(array):
    if len(array) < 2:
        return array
    else:
        pivo = array[0]
        menores = [i for i in array[1:] if i <= pivo]
        maiores = [i for i in array[1:] if i > pivo]
        return quicksort_v1(menores) + [pivo] + quicksort_v1(maiores)
    

def quicksort(array, inicio, fim):
    if inicio < fim:
        # pegar o pivo, pegar o pivo e separar o array em left e right
        pivo = partition(array, inicio, fim)
        quicksort(array, pivo +1, fim) # lado direito - right
        quicksort(array, inicio, pivo - 1) # lado esquerdo - left

def partition(array, inicio, fim):
    pivo = array[fim] # ultimo elemento
    i = inicio -1 # index - comeca apontando para nada
    
    for j in range(inicio, fim):
        if array[j] <= pivo:
            i = i + 1 # Avançar barra amarela
            array[j], array[i] = array[i],array[j] 

    # colocar o pivo no lugar correto
    array[i+1], array[fim] = array[fim], array[i+1]

    return i +1 ## posição do pivo


inicio = 0
lista = [2,1,10,5,7]

print(lista)
tamanho = len(lista)
quicksort(lista, 0, tamanho-1)
print(lista)
