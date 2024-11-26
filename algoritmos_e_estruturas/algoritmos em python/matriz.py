from array import array

lista = []
contador = 1
for i in range(4):
    lista_2 = []
    for j in range(4):
        lista_2.append(contador)
        contador += 1
    lista.append(lista_2)
    
matriz = array([lista])
print(matriz)
print(lista, sep=4)