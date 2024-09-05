

grafo = dict()
grafo['voce'] = ['alice', 'bob', 'claire']

# Aresta inicio
grafo['inicio'] = {}
grafo['inicio']['a'] = 6
grafo['inicio']['b'] = 2
print(grafo['inicio'] )

# Aresta a
grafo['a'] = {}
grafo['a']['fim'] = 1

# Aresta b
grafo['b'] = {}
grafo['b']['a'] = 3
grafo['b']['fim'] = 5


# aresta fim
grafo['fim'] = {}
print(grafo)

# tabela de custos

custos = dict()
infinito = float('inf')

custos['a'] = 6
custos['b'] = 2
custos['fim'] = infinito

# tabela hash para pais- parente
pais = dict()
pais['a'] = 'inicio'
pais['b'] = 'inicio'
pais['fim'] = None  # Vazio

# manter um array para todos os vertices processados
processados = []

def ache_no_custo_mais_baixo(custos):
    custo_mais_baixo = float('inf')
    nodo_custo_mais_baixo = None
    for nodo in custos:
        custo = custos[nodo]
        if custo < custo_mais_baixo and nodo not in processados:
            '''Se for o vertice de menos custo até o momento, e ainda nao tiver sido processado]m m  '''
            custo_mais_baixo = custo
            nodo_custo_mais_baixo = nodo
    return nodo_custo_mais_baixo

def main():

    # Encontrar o custo mais baixo que ainda não foi processado
    nodo = ache_no_custo_mais_baixo(custos)
    # Percorrer até que todos os vertices tenha sido processado
    while nodo is not None:
        custo = custo[nodo]
        vizinhos = grafo[nodo]
        for n in vizinhos.keys: # percorrer todos os vizinhos do vertice
            novo_custo = custo + vizinhos[n]
            if custo[n] > novo_custo: #  caso seja mais facil chegar ao vizinho apartir desse novo nodo
                # atualizar o custo 
                custo[n] = novo_custo
                # vertice se torna pai do vizinho pois o custo para chegar a ele é menor
                pais[n] = nodo
        # marcar o no como processado
        processados.append(nodo)
        # Encontrar o proximo vertice para ser processado
        nodo = ache_no_custo_mais_baixo(custos)

main()
    