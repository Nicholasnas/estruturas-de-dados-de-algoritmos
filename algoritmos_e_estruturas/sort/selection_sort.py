from random import randint



def ordenacao_por_selecao(arr):
    for i in range(len(arr)):
        menor_index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[menor_index]:
                menor_index = j
        arr[i], arr[menor_index] = arr[menor_index],arr[i]
        



array = list(range(10,-10,-2))
print(array)
ordenacao_por_selecao(array)
print(array)
