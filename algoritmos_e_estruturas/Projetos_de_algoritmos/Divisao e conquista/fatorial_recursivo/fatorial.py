
def fatorial(n:int) -> int:
    # Caso base
    if n == 1 or n == 0:
        return 1
    
    # Caso recursivo
    return n * fatorial(n-1)


def main():
    while True:
        try:
            numero = int(input("Entre com o número: "))
            if numero < 0:
                print('Não é possivel calcular o fatorial de número negativo!')
                continue
        except ValueError:
            print("Valor inválido!")
            continue

        print(f'O fatorial de {numero} é {fatorial(numero)}')

        continuar = int(input("Deseja continuar (1 para continuar e qualquer outro numero para sair): "))
        if continuar == 1:
            continue
        else: 
            print("Encerrando o programa!")
            break


if __name__ == "__main__":
    main()


