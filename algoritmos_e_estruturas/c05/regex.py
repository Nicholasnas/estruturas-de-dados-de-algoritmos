import re


# 1
word_sonho = re.search('sonhos', text)

print('Deu match no texto para sonhos') if word_sonho else print('sem match')
# 2
word_as = re.findall('[a-zA-Zç]*as', text)
print(word_as)

#3
# word_sub = re.sub('maior', 'surreal', text)
# word_sub2 = re.sub('grande', 'surreal', word_sub)
replace = re.sub('(maior|grande)', 'surreal', text)
print('final: ', replace)
print(text)

# 4

inspiracao = re.search('inspiração', text)
print(f'pos inicial e final de inspiracao: {inspiracao.span()}')

#5

lista_nove_letras = re.findall('[a-zA-Zç]{9,} ', text)
print(lista_nove_letras)


# 6
lista_ponto_virgula = re.split('[.,]', text)
for frase in lista_ponto_virgula:
    print(frase)
    
#7
lista_e = re.findall('[a-zA-Zç]*[É|é][a-zA-Zç]*', text)
print(lista_e)


# 8 - qtd de palavras

# usando split
text_split = re.split('[\s]', text)

print(len(text_split))


print('tamanho do texto: ', )
#subs 
text_new = re.sub('(.|,|\s)', ' ', text)
print(len(text_new))

