class AFD:

    def __init__(self, estados, alfabeto, transicoes, estado_inicial, estados_finais):
        self.estados = estados
        self.alfabeto = alfabeto
        self.transicoes = transicoes
        self.estado_inicial = estado_inicial
        self.estados_finais = estados_finais

    def processar(self, cadeia):
        estado_atual = self.estado_inicial

        for simbolo in cadeia:
            if simbolo not in self.alfabeto:
                return False

            estado_atual = self.transicoes[estado_atual][simbolo]

        return estado_atual in self.estados_finais

#Parte 1 da atividade
def questao2():
    transicoes = {
        'q0': {'0': 'q0', '1': 'q1'},
        'q1': {'0': 'q0', '1': 'q2'},
        'q2': {'0': 'q0', '1': 'q2'}
    }

    afd = AFD(
        estados = {'q0', 'q1', 'q2'},
        alfabeto = {'0', '1'},
        transicoes = transicoes,
        estado_inicial = 'q0',
        estados_finais = {'q2'}
    )

 # Troque os valores nas aspas simples e parênteses para testar outras cadeias
    print("Termina em 11?: '0101011' ->", afd.processar("0101011"))  # retorna True ou False, dependendo da cadeia testada


#Parte 2 da atividade
def questao11():
    transicoes = {
        'q0': {'0': 'q0', '1': 'q1'},
        'q1': {'0': 'q2', '1': 'q0'},
        'q2': {'0': 'q1', '1': 'q2'}
    }

    afd = AFD(
        estados = {'q0', 'q1', 'q2'},
        alfabeto = {'0', '1'},
        transicoes = transicoes,
        estado_inicial = 'q0',
        estados_finais = {'q0'}
    )

    
    print("Divisível por 3?: '111' ->", afd.processar("111")) 


def questao12():
    transicoes = {
        'q0': {'0': 'q0', '1': 'q1'},
        'q1': {'0': 'q2', '1': 'q3'},
        'q2': {'0': 'q4', '1': 'q0'},
        'q3': {'0': 'q1', '1': 'q2'},
        'q4': {'0': 'q3', '1': 'q4'}
    }

    afd = AFD(
        estados = {'q0', 'q1', 'q2', 'q3'},
        alfabeto = {'0', '1'},
        transicoes = transicoes,
        estado_inicial = 'q0',
        estados_finais = {'q2'}
    )
   
    print("Deixa resto 2 na divisão 5?: '1101' ->", afd.processar("1101"))


# Parte 3 da atividade

# Funções auxiliares para categorização das questões 21 e 22
def categorizar_char(c):
    if c.isalpha():
        return 'L'  # Letra
    if c.isdigit():
        return 'D'  # Dígito
    if c in '+-':
        return 'S'  # Sinal
    if c == '.':
        return 'P'  # Ponto
    if c in 'eE':
        return 'E'  # Exponencial
    return 'X'      # Outros/Inválido

def questao21():
    transicoes = {

        'q0':   {'L': 'q1', 'D': 'erro', 'X': 'erro', 'S': 'erro', 'P': 'erro', 'E': 'q1'},
        'q1':   {'L': 'q1', 'D': 'q1', 'X': 'erro', 'S': 'erro', 'P': 'erro', 'E': 'q1'},
        'erro': {'L': 'erro', 'D': 'erro', 'X': 'erro', 'S': 'erro', 'P': 'erro', 'E': 'erro'}
    }
    
    afd = AFD(
        estados = {'q0', 'q1', 'erro'},
        alfabeto = {'L', 'D', 'X', 'S', 'P', 'E'},
        transicoes = transicoes,
        estado_inicial = 'q0',
        estados_finais = {'q1'}
    )

    cadeia = "var123"
    cadeia_categorizada = [categorizar_char(c) for c in cadeia]
    print(f"Q21 (Identificador): '{cadeia}' ->", afd.processar(cadeia_categorizada))  # Retorna True

    cadeia_invalida = "123var"
    cadeia_categorizada_inv = [categorizar_char(c) for c in cadeia_invalida]
    print(f"Q21 (Identificador): '{cadeia_invalida}' ->", afd.processar(cadeia_categorizada_inv))  # Retorna False


def questao22():
    transicoes = {

        'q0': {'D': 'q2', 'S': 'q1', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'q1': {'D': 'q2', 'S': 'erro', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'q2': {'D': 'q2', 'S': 'erro', 'P': 'q3', 'E': 'q5', 'L': 'erro', 'X': 'erro'},
        'q3': {'D': 'q4', 'S': 'erro', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'q4': {'D': 'q4', 'S': 'erro', 'P': 'erro', 'E': 'q5', 'L': 'erro', 'X': 'erro'},
        'q5': {'D': 'q7', 'S': 'q6', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'q6': {'D': 'q7', 'S': 'erro', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'q7': {'D': 'q7', 'S': 'erro', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'},
        'erro': {'D': 'erro', 'S': 'erro', 'P': 'erro', 'E': 'erro', 'L': 'erro', 'X': 'erro'}
    }
    
    afd = AFD(
        
        estados = {'q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q6', 'q7', 'erro'},
        alfabeto = {'D', 'S', 'P', 'E', 'L', 'X'},
        transicoes = transicoes,
        estado_inicial = 'q0',
        estados_finais = {'q4', 'q7'}
    )

    testes = ["3.14", "-0.5", "2.0e10"]
    for t in testes:
        categorizada = [categorizar_char(c) for c in t]
        print(f"Validando ponto flutuante: '{t}' ->", afd.processar(categorizada))


# Testar atividades (tire a cerquilha/hash no começo para testar uma questão)
if __name__ == "__main__":
    questao2()
    #questao11()
    #questao12()
    #questao21()
    #questao22()
