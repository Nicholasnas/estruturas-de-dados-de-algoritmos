from dataclasses import dataclass
from typing import List, Tuple

@dataclass
class Pedra:
    id: int
    nome: str
    preco: float
    peso: float
    volume: float

@dataclass
class Carrinho:
    capacidade_peso: float
    capacidade_volume: float

def minerar(pedras: List[Pedra], carrinho: Carrinho, index: int) -> Tuple[float, List[int]]:
    # Caso base: sem pedras ou sem capacidade no carrinho
    if index == len(pedras) or carrinho.capacidade_peso <= 0 or carrinho.capacidade_volume <= 0:
        return 0, []

    # Opção 1: Não pegar a pedra atual
    valor_nao_pegar, escolhidas_nao_pegar = minerar(pedras, carrinho, index + 1)

    # Opção 2: Pegar a pedra atual (se couber no carrinho)
    pedra = pedras[index]
    if pedra.peso <= carrinho.capacidade_peso and pedra.volume <= carrinho.capacidade_volume:
        novo_carrinho = Carrinho(
            capacidade_peso=carrinho.capacidade_peso - pedra.peso,
            capacidade_volume=carrinho.capacidade_volume - pedra.volume
        )
        valor_pegar, escolhidas_pegar = minerar(pedras, novo_carrinho, index + 1)
        valor_pegar += pedra.preco
        escolhidas_pegar = [pedra.id] + escolhidas_pegar
    else:
        valor_pegar, escolhidas_pegar = 0, []

    # Retornar a melhor opção
    return max((valor_nao_pegar, escolhidas_nao_pegar), (valor_pegar, escolhidas_pegar), key=lambda x: x[0])

def main():
    qtd_pedras = 5
    carrinho = Carrinho(400, 1)
    pedras: List[Pedra] = []

    # Entrada dos dados
    for i in range(qtd_pedras):
        print(f"Entre com os dados da pedra {i + 1}:")
        pedras.append(Pedra(
            id=i,
            nome=input("Nome da pedra: "),
            preco=float(input("Preço da pedra (R$): ")),
            volume=float(input("Volume da pedra (m³): ")),
            peso=float(input("Peso da pedra (kg): "))
        ))

    # Chamar função de mineração
    maior_valor, escolhidas = minerar(pedras, carrinho, 0)

    # Exibir resultados
    print(f"\nO maior valor que pode ser minerado é R$ {maior_valor:.2f}")
    print("Pedras escolhidas:")
    for id in escolhidas:
        print(f"- {pedras[id].nome}")

if __name__ == "__main__":
    main()
