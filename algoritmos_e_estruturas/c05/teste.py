import re


text = """Viver é acalentar sonhos e esperanças,
 fazendo da fé a nossa inspiração maior. É buscar nas pequenas coisas,
   um grande motivo para ser feliz."""
lista_maior_6 = re.findall(r'\w{2,6}\b', text)

print(lista_maior_6)

# Expressão regular para dividir o texto toda vez que encontrar uma letra maiúscula
partes = re.split(r'(?[A-E][Á-É])', text)

partes = [parte.strip() for parte in partes if parte.strip()]

print(partes)

palavras_com_vogais = re.findall(r'\b\w*[aeiouáéíóúãõâêîôûàèìòùäëïöüååáéíóúàèìòù]+\w*\b', text, re.IGNORECASE)

print(palavras_com_vogais)

palavras_com_vogais = re.findall(r'\b\w*[aeiouáéíóúãõâêîôûàèìòù]+\w*\b', text, re.IGNORECASE)

print(palavras_com_vogais)