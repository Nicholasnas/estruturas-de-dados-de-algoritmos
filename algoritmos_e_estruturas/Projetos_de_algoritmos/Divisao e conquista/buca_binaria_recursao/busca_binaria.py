

def busca_binaria(array:list, target:int, low:int, high:int) ->int:
    if low > high:
        return -1
    
    meio = (low + high) // 2
    chute = array[meio]

    if target == chute:
        return meio
    
    if target < chute:
        return busca_binaria(array, target, low, meio-1)
    
    if target > chute:
        return busca_binaria(array, target, meio+1, high)
    

def main():

    while(True):
        try:
            tam = int(input("Digite o tamanho do array (-1 para sair): "))
        except ValueError:
            print("Valor inválido!")
            continue

        if tam == -1:
            break
        if tam <= 0:
            print("Tamanho inválido!")
            continue

        array = [int(input("Entre com o valor: ")) for i in range(tam)]
        target = int(input("Entre com o valor a ser buscado: "))

        array.sort()
        print(array)

        resultado = busca_binaria(array, target, 0, len(array)-1)

        if resultado != -1:
            print(f"Valor encontrado na posição {resultado}.")
        else:
            print("Valor não encontrado.")

if __name__ == "__main__":
    main()

