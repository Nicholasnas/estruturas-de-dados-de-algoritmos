import re

text = """
Viver é acalentar sonhos e esperanças, fazendo da fé a nossa inspiração
maior. É buscar nas pequenas coisas, um grande motivo para ser feliz
"""

match = re.search(r'sonhos', text)
if match:
    print('Encontrado!')
else:
    print('Não encontrado!')

"""
Código que retorne uma lista apenas das palavras terminadas com “as”; 

(Atenção, a classe de caracteres [a-zA-Z] naturalmente não aceita caracteres da língua portuguesa, por
isso, você deve adicioná-los manualmente dentro da classe. Ex: [a-zA-Zç]

"""

match2 = re.findall(r'\b[a-zA-Zç]*as\b', text)
print(match2)

"""
Código que em um único REGEX, troque as palavras “maior” e
“grande” pela palavra “surreal” e mostre a nova frase após as trocas;

"""
print("Exercicio 3!")
match3 = re.sub(r'(maior|grande)', 'surreal', text)
print( match3)

"""Código que retorna a posição inicial e final da palavra “inspiração”
dentro do texto;"""

match4 = re.search(r'\binspiração\b', text)
print(f'Posição inicial: {match4.start()}')
print(f'Posição final: {match4.end()}')



"""Padrao de cpf 000.000.000-00"""
string = "padrao de cpf 118.072.118-93"
match5 = re.search(r'\d{3}[.]\d{3}[.]\d{3}[-]\d{2}', string)

print('CPF')
print(match5.group())
print('posição inicial cpf:',match5.start())
print('posição final cpf:', match5.end(), end='\n')






