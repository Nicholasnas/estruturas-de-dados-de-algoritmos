
def len_array(array:list, tam:int, index:int):
    # Caso base => Tamanho do array atingido
    if tam == index:
        return 0
    # Caso recursivo 
    return 1 + len_array(array, tam, index+1)

if __name__ == "__main__":

    while True:
        array = []
        while True:
            try:

                valor = int(input("Entre com valor: "))
            except ValueError:
                print("Valor inválido!")
                continue

            if valor == -1:
                break

            array.append(valor)

        resultado = len_array(array, len(array), 0)
        print("Tamanho do array: ", resultado)

        if len(array) == resultado:
            print('Resultado correto!')
        else:
            print("Resultado Incorreto!")
        
        entrada = input("Deseja continuar(S ou N): ")
        if entrada == "S" or entrada == 's':
            continue
        else:
            break

        
        