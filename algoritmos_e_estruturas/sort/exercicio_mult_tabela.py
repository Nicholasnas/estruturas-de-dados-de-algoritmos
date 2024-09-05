


def multiplicacao(lista):
    #        2,3,7,8,10
    # criando a matria de multiplicação
    tabela = [[0,0,0,0,0] for _ in range(5)]

    print(tabela)
    
    for i in range(5):
        for j in range(5):
            if j == 0:
                tabela[i][j] = lista[i] * lista[0]
            elif j == 1:
                tabela[i][j] = lista[i] * lista[1]
            elif   j == 2:
                tabela[i][j] = lista[i] * lista[2]
            elif j == 3:
                tabela[i][j] = lista[i] * lista[3]
            elif j == 4:
                tabela[i][j] = lista[i] * lista[4]
    return tabela



if __name__ == "__main__":

    lista = [2,3,7,8,10]
    resultado = multiplicacao(lista)
    for linha in resultado:
        print(linha)
