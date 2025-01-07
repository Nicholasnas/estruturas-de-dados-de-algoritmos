from dataclasses import dataclass
from typing import List

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

def minerar(pedras: List[Pedra], carrinho: Carrinho, index: int, num_pedras: int, escolhidas: List[int]) -> float:
    # Caso base: sem pedras ou sem capacidade no carrinho
    if index >= num_pedras or carrinho.capacidade_peso <= 0 or carrinho.capacidade_volume <= 0:
        return 0

    # Não pegar a pedra atual
    escolhidos_nao_pegar = escolhidas.copy()
    nao_pegar_pedra = minerar(pedras, carrinho, index + 1, num_pedras, escolhidos_nao_pegar)

    # Tentar pegar a pedra atual
    escolhidos_pegar = escolhidas.copy()
    pegar_pedra = 0
    if carrinho.capacidade_peso >= pedras[index].peso and carrinho.capacidade_volume >= pedras[index].volume:
        novo_carrinho = Carrinho(
            capacidade_peso=carrinho.capacidade_peso - pedras[index].peso,
            capacidade_volume=carrinho.capacidade_volume - pedras[index].volume
        )
        escolhidos_pegar.append(pedras[index].id)
        pegar_pedra = pedras[index].preco + minerar(pedras, novo_carrinho, index + 1, num_pedras, escolhidos_pegar)

    # Decisão: pegar ou não pegar a pedra
    if pegar_pedra > nao_pegar_pedra:
        escolhidas.clear()
        escolhidas.extend(escolhidos_pegar)
        return pegar_pedra
    else:
        escolhidas.clear()
        escolhidas.extend(escolhidos_nao_pegar)
        return nao_pegar_pedra

def main():
    qtd_pedras = 5
    carrinho = Carrinho(400, 1)
    pedras: List[Pedra] = []

    # Entrada dos dados
    for i in range(qtd_pedras):
        print(f"Entre com os dados da pedra {i + 1}:")
        new_pedra = Pedra(
            id=i,
            nome=input("Nome da pedra: "),
            volume=float(input("Volume da pedra (m³): ")),
            peso=float(input("Peso da pedra (kg): ")),
            preco=float(input("Preço da pedra (R$): ")),
        )
        pedras.append(new_pedra)

    escolhidas: List[int] = []
    resultado = minerar(pedras, carrinho, 0, qtd_pedras, escolhidas)

    # Exibição do resultado
    print(f"O maior valor que pode ser minerado é R$ {resultado:.2f}")
    print("Pedras escolhidas:")
    for id in escolhidas:
        print(f"- {pedras[id].nome}")

if __name__ == "__main__":
    main()
