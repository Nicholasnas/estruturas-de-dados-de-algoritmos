from collections import deque # lista

grafo = dict()
grafo['voce'] = ['alice', 'bob', 'claire']
grafo['bob'] = ['anuj', 'peggy']
grafo['alice'] = ['peggy']
grafo['claire'] = ['thom', 'jonny']


def pesquisa():
    fila_de_pesquisa = deque()  
    fila_de_pesquisa += grafo['voce']
    verificadas = []
    while fila_de_pesquisa:
        pessoa = fila_de_pesquisa.popleft()
        if not pessoa in verificadas:
            if pessoa_e_vendedor(pessoa):
                print(f'{pessoa} é um vendedor de manga')
                return True
            else:
                fila_de_pesquisa += grafo[f'{pessoa}']
                verificadas.append(pessoa)
    return False

def pessoa_e_vendedor(nome):
    return nome[-1] == 'm'