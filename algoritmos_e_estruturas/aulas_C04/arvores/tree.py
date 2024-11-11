

class Node:
    def __init__(self, dado):
        self.dado = dado
        self.left = None
        self.right = None
    def __str__(self) -> str:
        return str(self.dado)


class Binarytree:
    def __init__(self, dado) -> None:
        node = Node(dado)
        self.root = node

    def insert(self, dado):
        pass


if __name__ == "__main__":
    tree = Binarytree(7)
    tree.root.left = Node(2)
    tree.root.right = Node(10)

    print(tree.root)
    print(tree.root.left)
    print(tree.root.right)
