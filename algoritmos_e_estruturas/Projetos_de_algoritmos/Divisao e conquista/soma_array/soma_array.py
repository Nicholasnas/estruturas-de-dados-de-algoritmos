
def sum_array(array:list, tam:int, index:int):
    if tam == index:
        return 0
    
    return array[index] + sum_array(array, tam, index+1)


def main():
    tam = int(input("Tamanho array: "))

    array = [int(input("Entre com valor: ")) for _ in range(tam)]

    print(f'Array: {array}')

    print(f'A soma do elementos do array: {sum_array(array, tam, 0)}')

main()
