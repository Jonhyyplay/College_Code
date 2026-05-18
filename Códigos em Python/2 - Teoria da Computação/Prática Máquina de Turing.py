# Classe Máquina de Turing
class maquinaTuring:

    def __init__(self, estados, alfabeto_entrada, alfabeto_fita, transicoes, estado_inicial, estado_aceitacao, branco=' '):
        self.estados = estados
        self.alfabeto_entrada = alfabeto_entrada
        self.alfabeto_fita = alfabeto_fita
        self.transicoes = transicoes
        self.estado_inicial = estado_inicial
        self.estado_aceitacao = estado_aceitacao
        self.branco = branco

    def processar(self, entrada):
        fita = list(entrada) if entrada else [self.branco]
        cabecote = 0
        estado_atual = self.estado_inicial

        while True:
            if cabecote < 0:
                fita.insert(0, self.branco)
                cabecote = 0
            elif cabecote >= len(fita):
                fita.append(self.branco)

            simbolo_atual = fita[cabecote]

            if estado_atual == self.estado_aceitacao:
                resultado_fita = "".join(fita).strip(self.branco)
                return True, resultado_fita

            if estado_atual not in self.transicoes or simbolo_atual not in self.transicoes[estado_atual]:
                return False, "".join(fita).strip(self.branco)

            novo_estado, simbolo_escrever, direcao = self.transicoes[estado_atual][simbolo_atual]

            fita[cabecote] = simbolo_escrever
            estado_atual = novo_estado

            cabecote += 1 if direcao == 'R' else -1


# ==========================================
# PARTE 1: Atividades Básicas
# ==========================================

def questao1():
    print("\n--- TESTES DA QUESTÃO 1 (Palíndromos) ---")
    regras_q1 = {
        'q0': {'0': ('q1a', '_', 'R'), '1': ('q1b', '_', 'R'), '_': ('q_aceita', '_', 'R')},
        'q1a': {'0': ('q1a', '0', 'R'), '1': ('q1a', '1', 'R'), '_': ('q2a', '_', 'L')},
        'q1b': {'0': ('q1b', '0', 'R'), '1': ('q1b', '1', 'R'), '_': ('q2b', '_', 'L')},
        'q2a': {'0': ('q3', '_', 'L'), '_': ('q_aceita', '_', 'R')},
        'q2b': {'1': ('q3', '_', 'L'), '_': ('q_aceita', '_', 'R')},
        'q3': {'0': ('q3', '0', 'L'), '1': ('q3', '1', 'L'), '_': ('q0', '_', 'R')}
    }

    mt_q1 = maquinaTuring(
        estados=['q0', 'q1a', 'q1b', 'q2a', 'q2b', 'q3', 'q_aceita'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', '_'],
        transicoes=regras_q1,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q1 = ["1001", "010", "111", "11", "10", "01100", ""]
    for palavra in palavras_teste_q1:
        sucesso, fita_final = mt_q1.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        display_palavra = palavra if palavra != "" else "<vazia>"
        print(f"Palavra: {display_palavra:<10} | Resultado: {resultado}")


def questao2():
    print("\n--- TESTES DA QUESTÃO 2 (Blocos 0^n 1^n) ---")
    regras_q2 = {
        'q0': {'0': ('q1', 'X', 'R'), 'Y': ('q4', 'Y', 'R')},
        'q1': {'0': ('q1', '0', 'R'), 'Y': ('q1', 'Y', 'R'), '1': ('q2', 'Y', 'L')},
        'q2': {'Y': ('q2', 'Y', 'L'), '0': ('q2', '0', 'L'), 'X': ('q0', 'X', 'R')},
        'q4': {'Y': ('q4', 'Y', 'R'), '_': ('q_aceita', '_', 'R')}
    }

    mt_q2 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q4', 'q_aceita'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', 'X', 'Y', '_'],
        transicoes=regras_q2,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q2 = ["01", "0011", "000111",
                         "00001111", "0", "1", "001", "011", "10", "0101"]
    for palavra in palavras_teste_q2:
        sucesso, fita_final = mt_q2.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        display_palavra = palavra if palavra != "" else "<vazia>"
        print(f"Palavra: {display_palavra:<10} | Resultado: {resultado}")


def questao3():
    print("\n--- TESTES DA QUESTÃO 3 (w#w) ---")
    regras_q3 = {
        'q0': {'a': ('q1a', 'A', 'R'), 'b': ('q1b', 'B', 'R'), '#': ('q5', '#', 'R')},
        'q1a': {'a': ('q1a', 'a', 'R'), 'b': ('q1a', 'b', 'R'), '#': ('q2a', '#', 'R')},
        'q1b': {'a': ('q1b', 'a', 'R'), 'b': ('q1b', 'b', 'R'), '#': ('q2b', '#', 'R')},
        'q2a': {'A': ('q2a', 'A', 'R'), 'B': ('q2a', 'B', 'R'), 'a': ('q3', 'A', 'L')},
        'q2b': {'A': ('q2b', 'A', 'R'), 'B': ('q2b', 'B', 'R'), 'b': ('q3', 'B', 'L')},
        'q3': {'A': ('q3', 'A', 'L'), 'B': ('q3', 'B', 'L'), '#': ('q4', '#', 'L')},
        'q4': {'a': ('q4', 'a', 'L'), 'b': ('q4', 'b', 'L'), 'A': ('q0', 'A', 'R'), 'B': ('q0', 'B', 'R')},
        'q5': {'A': ('q5', 'A', 'R'), 'B': ('q5', 'B', 'R'), '_': ('q_aceita', '_', 'R')}
    }

    mt_q3 = maquinaTuring(
        estados=['q0', 'q1a', 'q1b', 'q2a',
                 'q2b', 'q3', 'q4', 'q5', 'q_aceita'],
        alfabeto_entrada=['a', 'b', '#'],
        alfabeto_fita=['a', 'b', '#', 'A', 'B', '_'],
        transicoes=regras_q3,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste = ["a#a", "bb#bb", "baba#baba", "aba#abb", "aa#a", "ab#"]
    for palavra in palavras_teste:
        sucesso, fita = mt_q3.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(f"Palavra: {palavra:<15} | Resultado: {resultado}")


def questao4():
    print("\n--- TESTES DA QUESTÃO 4 (Potências de 2) ---")
    regras_q4 = {
        'q0': {'0': ('q1', '_', 'R')},
        'q1': {'x': ('q1', 'x', 'R'), '_': ('q_aceita', '_', 'R'), '0': ('q2', 'x', 'R')},
        'q2': {'x': ('q2', 'x', 'R'), '0': ('q3', '0', 'R'), '_': ('q4', '_', 'L')},
        'q3': {'x': ('q3', 'x', 'R'), '0': ('q2', 'x', 'R')},
        'q4': {'0': ('q4', '0', 'L'), 'x': ('q4', 'x', 'L'), '_': ('q1', '_', 'R')}
    }

    mt_q4 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4', 'q_aceita'],
        alfabeto_entrada=['0'],
        alfabeto_fita=['0', 'x', '_'],
        transicoes=regras_q4,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q4 = ["0", "00", "0000",
                         "00000000", "000", "00000", "000000"]
    for palavra in palavras_teste_q4:
        sucesso, fita = mt_q4.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(f"Entrada: {palavra:<10} | Resultado: {resultado}")


def questao5():
    print("\n--- TESTES DA QUESTÃO 5 (Sucessor Unário) ---")
    regras_q5 = {
        'q0': {'1': ('q0', '1', 'R'), '_': ('q_aceita', '1', 'R')}
    }

    mt_q5 = maquinaTuring(
        estados=['q0', 'q_aceita'],
        alfabeto_entrada=['1'],
        alfabeto_fita=['1', '_'],
        transicoes=regras_q5,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q5 = ["1", "111", "11111"]
    for palavra in palavras_teste_q5:
        sucesso, fita = mt_q5.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada: {palavra:<10} | Resultado: {resultado:<10} | Fita Final: {fita}")


def questao6():
    print("\n--- TESTES DA QUESTÃO 6 (Soma Unária) ---")
    regras_q6 = {
        'q0': {'1': ('q0', '1', 'R'), '0': ('q1', '1', 'R')},
        'q1': {'1': ('q1', '1', 'R'), '_': ('q2', '_', 'L')},
        'q2': {'1': ('q_aceita', '_', 'R')}
    }

    mt_q6 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q_aceita'],
        alfabeto_entrada=['1', '0'],
        alfabeto_fita=['1', '0', '_'],
        transicoes=regras_q6,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q6 = ["110111", "1011", "111101"]
    for palavra in palavras_teste_q6:
        sucesso, fita = mt_q6.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada (m0n): {palavra:<10} | Resultado: {resultado:<10} | Fita Final: {fita}")


def questao7():
    print("\n--- TESTES DA QUESTÃO 7 (Subtração Própria) ---")
    regras_q7 = {
        'q0': {'1': ('q0', '1', 'R'), '-': ('q0', '-', 'R'), '_': ('q1', '_', 'L')},
        'q1': {'1': ('q2', '_', 'L'), '-': ('q_aceita', '_', 'L')},
        'q2': {'1': ('q2', '1', 'L'), '-': ('q2', '-', 'L'), '_': ('q3', '_', 'R')},
        'q3': {'1': ('q0', '_', 'R')}
    }

    mt_q7 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q_aceita'],
        alfabeto_entrada=['1', '-'],
        alfabeto_fita=['1', '-', '_'],
        transicoes=regras_q7,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q7 = ["1111-11", "111-101", "11-1", "11111-11"]
    for palavra in palavras_teste_q7:
        sucesso, fita = mt_q7.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada: {palavra:<10} | Resultado: {resultado:<10} | Fita: {fita}")


def questao8():
    print("\n--- TESTES DA QUESTÃO 8 (Multiplicação Unária) ---")
    regras_q8 = {
        'q0': {'1': ('q1', 'X', 'R'), '*': ('q6', '_', 'L')},
        'q1': {'1': ('q1', '1', 'R'), '*': ('q2', '*', 'R')},
        'q2': {'Y': ('q2', 'Y', 'R'), '1': ('q3', 'Y', 'R'), 'Z': ('q5', 'Z', 'L'), '_': ('q5', '_', 'L')},
        'q3': {'1': ('q3', '1', 'R'), 'Z': ('q3', 'Z', 'R'), '_': ('q4', 'Z', 'L')},
        'q4': {'Z': ('q4', 'Z', 'L'), '1': ('q4', '1', 'L'), 'Y': ('q2', 'Y', 'R')},
        'q5': {'Y': ('q5', '1', 'L'), '*': ('q5', '*', 'L'), '1': ('q5', '1', 'L'), 'X': ('q0', 'X', 'R')},
        'q6': {'X': ('q6', '_', 'L'), '_': ('q7', '_', 'R')},
        'q7': {'_': ('q7', '_', 'R'), '1': ('q7', '_', 'R'), 'Z': ('q8', '1', 'R')},
        'q8': {'Z': ('q8', '1', 'R'), '_': ('q_aceita', '_', 'L')}
    }

    mt_q8 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4',
                 'q5', 'q6', 'q7', 'q8', 'q_aceita'],
        alfabeto_entrada=['1', '*'],
        alfabeto_fita=['1', '*', 'X', 'Y', 'Z', '_'],
        transicoes=regras_q8,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q8 = ["111*11", "11*111", "01*11", "1*11"]
    for palavra in palavras_teste_q8:
        sucesso, fita = mt_q8.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada: {palavra:<10} | Resultado: {resultado:<10} | Fita: {fita}")


def questao9():
    print("\n--- TESTES DA QUESTÃO 9 (Complemento de 2) ---")
    transicoes = {
        'q0': {'0': ('q_fwd', '0', 'R'), '1': ('q_fwd', '1', 'R')},
        'q_fwd': {'0': ('q_fwd', '0', 'R'), '1': ('q_fwd', '1', 'R'), '_': ('q_rev1', '_', 'L')},
        'q_rev1': {'0': ('q_rev1', '0', 'L'), '1': ('q_inv', '1', 'L'), '_': ('q_acc', '_', 'R')},
        'q_inv': {'0': ('q_inv', '1', 'L'), '1': ('q_inv', '0', 'L'), '_': ('q_acc', '_', 'R')}
    }

    mt_complemento2 = maquinaTuring(
        estados=['q0', 'q_fwd', 'q_rev1', 'q_inv', 'q_acc'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', '_'],
        transicoes=transicoes,
        estado_inicial='q0',
        estado_aceitacao='q_acc',
        branco='_'
    )

    entradas_teste = ["0110", "0000", "1111", "1000", "101"]
    for cadeia in entradas_teste:
        sucesso, resultado = mt_complemento2.processar(cadeia)
        print(
            f"Entrada original: {cadeia:<6} | Cálculo concluído: {sucesso} | Resultado: {resultado}")


def questao10():
    print("\n--- TESTES DA QUESTÃO 10 (Paridade Binária) ---")
    transicoes = {
        'q_par': {'0': ('q_par', '0', 'R'), '1': ('q_impar', '1', 'R'), '_': ('q_acc', '_', 'R')},
        'q_impar': {'0': ('q_impar', '0', 'R'), '1': ('q_par', '1', 'R')}
    }

    mt_paridade = maquinaTuring(
        estados=['q_par', 'q_impar', 'q_acc'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', '_'],
        transicoes=transicoes,
        estado_inicial='q_par',
        estado_aceitacao='q_acc',
        branco='_'
    )

    entradas_teste = ["0000", "1010", "1111", "1000", "0111", ""]
    for cadeia in entradas_teste:
        sucesso, resultado = mt_paridade.processar(cadeia)
        status = "ACEITA" if sucesso else "REJEITADA"
        print(f"Entrada: '{cadeia:<4}' | Status: {status}")


# ==========================================
# PARTE 2: Desafios Avançados
# ==========================================

def questao11():
    print("\n--- TESTES DA QUESTÃO 11 (Quadrados Perfeitos) ---")
    regras_q11 = {
        'q0': {'X': ('q0', 'X', 'R'), 'Y': ('q0', 'Y', 'R'), '1': ('q1', '1', 'L'), '_': ('q_aceita', '_', 'R')},
        'q1': {'1': ('q1', '1', 'L'), 'X': ('q1', 'X', 'L'), 'Y': ('q1', 'Y', 'L'), 'Z': ('q1', 'Z', 'L'), '_': ('q2', '_', 'R')},
        'q2': {'Z': ('q2', 'Z', 'R'), 'X': ('q2', 'X', 'R'), 'Y': ('q3', 'Z', 'R'), '1': ('q5', 'Y', 'L')},
        'q3': {'X': ('q3', 'X', 'R'), '1': ('q4', 'X', 'R')},
        'q4': {'X': ('q4', 'X', 'R'), '1': ('q1', 'X', 'L')},
        'q5': {'Z': ('q5', 'Y', 'L'), 'X': ('q5', 'X', 'L'), 'Y': ('q5', 'Y', 'L'), '1': ('q5', '1', 'L'), '_': ('q0', '_', 'R')}
    }

    mt_q11 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q_aceita'],
        alfabeto_entrada=['1'],
        alfabeto_fita=['1', 'X', 'Y', 'Z', '_'],
        transicoes=regras_q11,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q11 = ["1", "11", "111", "1111",
                          "11111", "11111111", "111111111", "1111111111111111"]
    for palavra in palavras_teste_q11:
        tamanho = len(palavra)
        sucesso, fita_final = mt_q11.processar(palavra)
        resultado = "ACEITO (Quadrado Perfeito)" if sucesso else "REJEITADO"
        print(f"N = {tamanho:<2} | Fita: {palavra:<16} | Resultado: {resultado}")


def questao12():
    print("\n--- TESTES DA QUESTÃO 12 (Divisão com Resto) ---")
    regras_q12 = {
        'q0': {'X': ('q0', 'X', 'R'), '1': ('q0', '1', 'R'), '/': ('q0_div', '/', 'R')},
        'q0_div': {'Y': ('q0_div', 'Y', 'R'), '1': ('q_rewind', 'Y', 'L'), '_': ('q_block', '_', 'L'), 'q': ('q_block', 'q', 'L')},
        'q_rewind': {'Y': ('q_rewind', 'Y', 'L'), '/': ('q_rewind', '/', 'L'), '1': ('q_rewind', '1', 'L'), 'X': ('q_rewind', 'X', 'L'), '_': ('q_find_divi', '_', 'R')},
        'q_find_divi': {'X': ('q_find_divi', 'X', 'R'), '1': ('q0', 'X', 'R'), '/': ('q_undo_Y', '/', 'R')},
        'q_block': {'Y': ('q_block', 'Y', 'R'), 'q': ('q_block', 'q', 'R'), '_': ('q_restore', 'q', 'L')},
        'q_restore': {'q': ('q_restore', 'q', 'L'), 'Y': ('q_restore', '1', 'L'), '/': ('q_restore', '/', 'L'), '1': ('q_restore', '1', 'L'), 'X': ('q_restore', 'X', 'L'), '_': ('q0', '_', 'R')},
        'q_undo_Y': {'Y': ('q_undo_Y', 'Y', 'R'), '1': ('q_change_Y', '1', 'L'), 'q': ('q_change_Y', 'q', 'L'), '_': ('q_change_Y', '_', 'L')},
        'q_change_Y': {'Y': ('q_cleanup_L', '1', 'L')},
        'q_cleanup_L': {'Y': ('q_cleanup_L', 'Y', 'L'), '/': ('q_cleanup_L', '/', 'L'), 'X': ('q_cleanup_L', 'X', 'L'), '1': ('q_cleanup_L', '1', 'L'), '_': ('q_format', '_', 'R')},
        'q_format': {'X': ('q_format', '_', 'R'), '/': ('q_format', '_', 'R'), 'Y': ('q_format', 'r', 'R'), '1': ('q_format', '_', 'R'), 'q': ('q_format', 'q', 'R'), '_': ('q_aceita', '_', 'L')}
    }

    mt_q12 = maquinaTuring(
        estados=['q0', 'q0_div', 'q_rewind', 'q_find_divi', 'q_block', 'q_restore',
                 'q_undo_Y', 'q_change_Y', 'q_cleanup_L', 'q_format', 'q_aceita'],
        alfabeto_entrada=['1', '/'],
        alfabeto_fita=['1', '/', 'X', 'Y', 'q', 'r', '_'],
        transicoes=regras_q12,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q12 = ["11111/11", "1111/11",
                          "1/11", "111/1", "1111111/111"]
    for palavra in palavras_teste_q12:
        sucesso, fita_final = mt_q12.processar(palavra)
        print(f"Entrada (m/n): {palavra:<15} | Fita Final: {fita_final}")


def questao13():
    print("\n--- TESTES DA QUESTÃO 13 (Ordenação Binária) ---")
    regras_q13 = {
        'q0': {'0': ('q0', '0', 'R'), '1': ('q1', '1', 'R'), '_': ('q_aceita', '_', 'R')},
        'q1': {'1': ('q1', '1', 'R'), '0': ('q2', '1', 'L'), '_': ('q_aceita', '_', 'R')},
        'q2': {'1': ('q3', '0', 'L')},
        'q3': {'0': ('q3', '0', 'L'), '1': ('q3', '1', 'L'), '_': ('q0', '_', 'R')}
    }

    mt_q13 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q_aceita'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', '_'],
        transicoes=regras_q13,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q13 = ["000", "111", "10", "11010", "1010101", "001100"]
    for palavra in palavras_teste_q13:
        sucesso, fita_final = mt_q13.processar(palavra)
        if fita_final == "":
            fita_final = palavra
        print(f"Original: {palavra:<10} | Ordenada: {fita_final}")


def questao14():
    print("\n--- TESTES DA QUESTÃO 14 (Números Primos) ---")
    regras_q14 = {
        'q0': {'_': ('q_rejeita', '_', 'R'), '1': ('q1', 'c', 'R')},
        'q1': {'_': ('q_rejeita', '_', 'R'), '1': ('q_rewind', 'c', 'L')},
        'q_rewind': {'c': ('q_rewind', 'c', 'L'), 'C': ('q_rewind', 'C', 'L'), 'x': ('q_rewind', 'x', 'L'), '1': ('q_rewind', '1', 'L'), '_': ('q_div_start', '_', 'R')},
        'q_div_start': {'C': ('q_div_start', 'C', 'R'), 'c': ('q_find_1', 'C', 'R'), 'x': ('q_check_end', 'x', 'R'), '1': ('q_check_end', '1', 'R')},
        'q_find_1': {'c': ('q_find_1', 'c', 'R'), 'x': ('q_find_1', 'x', 'R'), '1': ('q_rewind', 'x', 'L'), '_': ('q_restore', '_', 'L')},
        'q_check_end': {'x': ('q_check_end', 'x', 'R'), '1': ('q_reset_C', '1', 'L'), '_': ('q_rejeita', '_', 'R')},
        'q_reset_C': {'C': ('q_reset_C', 'c', 'L'), 'x': ('q_reset_C', 'x', 'L'), 'c': ('q_reset_C', 'c', 'L'), '_': ('q_div_start', '_', 'R')},
        'q_restore': {'x': ('q_restore', '1', 'L'), 'C': ('q_restore', 'c', 'L'), 'c': ('q_restore', 'c', 'L'), '_': ('q_increment', '_', 'R')},
        'q_increment': {'c': ('q_increment', 'c', 'R'), '1': ('q_rewind', 'c', 'L'), '_': ('q_aceita', '_', 'R')}
    }

    mt_q14 = maquinaTuring(
        estados=['q0', 'q1', 'q_rewind', 'q_div_start', 'q_find_1',
                 'q_check_end', 'q_reset_C', 'q_restore', 'q_increment', 'q_aceita'],
        alfabeto_entrada=['1'],
        alfabeto_fita=['1', 'c', 'C', 'x', '_'],
        transicoes=regras_q14,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q14 = ["1", "11", "111", "1111",
                          "11111", "111111", "1111111", "11111111", "111111111"]
    for palavra in palavras_teste_q14:
        sucesso, fita = mt_q14.processar(palavra)
        resultado = "ACEITO (É Primo)" if sucesso else "REJEITADO (Não é Primo)"
        tamanho = len(palavra)
        print(
            f"Número {tamanho:<2} (Fita: {palavra:<9}) | Resultado: {resultado}")


def questao15():
    print("\n--- TESTES DA QUESTÃO 15 (Marcação) ---")
    regras_q15 = {
        'q0': {'0': ('q0', '0', 'R'), '1': ('q0', '1', 'R'), 'X': ('q0', 'X', 'R'), '#': ('q1', '#', 'R')},
        'q1': {'1': ('q2', 'X', 'R'), 'X': ('q1', 'X', 'R'), '_': ('q_aceita', '_', 'R')},
        'q2': {'0': ('q2', '0', 'R'), '1': ('q2', '1', 'R'), 'X': ('q2', 'X', 'R'), '_': ('q_v', '_', 'L')},
        'q_v': {'0': ('q_v', '0', 'L'), '1': ('q_v', '1', 'L'), '#': ('q_v', '#', 'L'), 'X': ('q_v', 'X', 'L'), '_': ('q0', '_', 'R')}
    }

    mt_q15 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q_v', 'q_aceita'],
        alfabeto_entrada=['0', '1', '#'],
        alfabeto_fita=['0', '1', '#', 'X', '_'],
        transicoes=regras_q15,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q15 = ["11#111", "10#10"]
    for palavra in palavras_teste_q15:
        sucesso, fita = mt_q15.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada: {palavra:<10} | Resultado: {resultado:<10} | Fita Final: {fita}")


def questao16():
    print("\n--- TESTES DA QUESTÃO 16 (Logaritmo Unário) ---")
    regras_q16 = {
        'q0': {'X': ('q0', 'X', 'R'), '1': ('q1', '1', 'R'), 'Y': ('q5', 'Y', 'L'), '_': ('q5', '_', 'L')},
        'q1': {'X': ('q1', 'X', 'R'), '1': ('q2', 'X', 'R'), 'Y': ('q5', 'Y', 'L'), '_': ('q5', '_', 'L')},
        'q2': {'X': ('q2', 'X', 'R'), '1': ('q3', '1', 'R'), 'Y': ('q4', 'Y', 'R'), '_': ('q_v', 'Y', 'L')},
        'q3': {'X': ('q3', 'X', 'R'), '1': ('q2', 'X', 'R'), 'Y': ('q4', 'Y', 'R'), '_': ('q_v', 'Y', 'L')},
        'q4': {'Y': ('q4', 'Y', 'R'), '_': ('q_v', 'Y', 'L')},
        'q_v': {'1': ('q_v', '1', 'L'), 'X': ('q_v', 'X', 'L'), 'Y': ('q_v', 'Y', 'L'), '_': ('q0', '_', 'R')},
        'q5': {'1': ('q5', '1', 'L'), 'X': ('q5', 'X', 'L'), 'Y': ('q5', 'Y', 'L'), '_': ('q6', '_', 'R')},
        'q6': {'1': ('q6', '_', 'R'), 'X': ('q6', '_', 'R'), 'Y': ('q6', '1', 'R'), '_': ('q_aceita', '_', 'R')}
    }

    mt_q16 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4', 'q_v', 'q5', 'q6', 'q_aceita'],
        alfabeto_entrada=['1'],
        alfabeto_fita=['1', 'X', 'Y', '_'],
        transicoes=regras_q16,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q16 = ["11", "1111", "11111111"]
    for palavra in palavras_teste_q16:
        sucesso, fita = mt_q16.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada (n={len(palavra)}): {palavra:<10} | Resultado: {resultado:<10} | Fita (Log2): {fita}")


def questao17():
    print("\n--- TESTES DA QUESTÃO 17 (Duplicação de Cadeia) ---")
    regras_q17 = {
        'q0': {'A': ('q0', 'A', 'R'), 'B': ('q0', 'B', 'R'), '0': ('q1', 'A', 'R'), '1': ('q2', 'B', 'R'),
               'C': ('q4', 'C', 'L'), 'D': ('q4', 'D', 'L'), '_': ('q4', '_', 'L')},
        'q1': {'0': ('q1', '0', 'R'), '1': ('q1', '1', 'R'), 'C': ('q1', 'C', 'R'), 'D': ('q1', 'D', 'R'), '_': ('q3', 'C', 'L')},
        'q2': {'0': ('q2', '0', 'R'), '1': ('q2', '1', 'R'), 'C': ('q2', 'C', 'R'), 'D': ('q2', 'D', 'R'), '_': ('q3', 'D', 'L')},
        'q3': {'0': ('q3', '0', 'L'), '1': ('q3', '1', 'L'), 'C': ('q3', 'C', 'L'), 'D': ('q3', 'D', 'L'),
               'A': ('q3', 'A', 'L'), 'B': ('q3', 'B', 'L'), '_': ('q0', '_', 'R')},
        'q4': {'A': ('q4', 'A', 'L'), 'B': ('q4', 'B', 'L'), '_': ('q5', '_', 'R')},
        'q5': {'A': ('q5', '0', 'R'), 'B': ('q5', '1', 'R'), 'C': ('q5', '0', 'R'), 'D': ('q5', '1', 'R'), '_': ('q_aceita', '_', 'L')}
    }

    mt_q17 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q_aceita'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', 'A', 'B', 'C', 'D', '_'],
        transicoes=regras_q17,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q17 = ["010", "11", "001", "1", "1.1", "020"]
    for palavra in palavras_teste_q17:
        sucesso, fita = mt_q17.processar(palavra)
        resultado = "ACEITO" if sucesso else "REJEITADO"
        print(
            f"Entrada: {palavra:<10} | Resultado: {resultado:<10} | Fita duplicada: {fita}")


def questao18():
    print("\n--- TESTES DA QUESTÃO 18 (Parênteses Balanceados) ---")
    regras_q18 = {
        'q0': {'(': ('q0', '(', 'R'), '[': ('q0', '[', 'R'), '{': ('q0', '{', 'R'), 'X': ('q0', 'X', 'R'),
               ')': ('q1', 'X', 'L'), ']': ('q2', 'X', 'L'), '}': ('q3', 'X', 'L'), '_': ('q5', '_', 'L')},
        'q1': {'X': ('q1', 'X', 'L'), '(': ('q4', 'X', 'L')},
        'q2': {'X': ('q2', 'X', 'L'), '[': ('q4', 'X', 'L')},
        'q3': {'X': ('q3', 'X', 'L'), '{': ('q4', 'X', 'L')},
        'q4': {'X': ('q4', 'X', 'L'), '(': ('q4', '(', 'L'), '[': ('q4', '[', 'L'), '{': ('q4', '{', 'L'), '_': ('q0', '_', 'R')},
        'q5': {'X': ('q5', 'X', 'L'), '_': ('q_aceita', '_', 'R')}
    }

    mt_q18 = maquinaTuring(
        estados=['q0', 'q1', 'q2', 'q3', 'q4', 'q5', 'q_aceita'],
        alfabeto_entrada=['(', ')', '[', ']', '{', '}'],
        alfabeto_fita=['(', ')', '[', ']', '{', '}', 'X', '_'],
        transicoes=regras_q18,
        estado_inicial='q0',
        estado_aceitacao='q_aceita',
        branco='_'
    )

    palavras_teste_q18 = ["{[()]}", "([{}])", "()[]{}",
                          "[{()()}]", "{[(])}", "((())", "()]"]
    for palavra in palavras_teste_q18:
        sucesso, fita = mt_q18.processar(palavra)
        resultado = "VÁLIDA" if sucesso else "INVÁLIDA"
        print(f"Sintaxe: {palavra:<10} | Resultado: {resultado}")


def questao19():
    print("\n--- TESTES DA QUESTÃO 19 (Inversão In-Place) ---")
    transicoes = {
        'q_start': {'0': ('q_hold_0_R', 'L', 'R'), '1': ('q_hold_1_R', 'L', 'R'), 'X': ('q_cleanup_L', 'X', 'L'), 'Y': ('q_cleanup_L', 'Y', 'L'), '_': ('q_acc', '_', 'R')},
        'q_hold_0_R': {'0': ('q_hold_0_R', '0', 'R'), '1': ('q_hold_0_R', '1', 'R'), 'X': ('q_turn_0_L', 'X', 'L'), 'Y': ('q_turn_0_L', 'Y', 'L'), '_': ('q_turn_0_L', '_', 'L')},
        'q_hold_1_R': {'0': ('q_hold_1_R', '0', 'R'), '1': ('q_hold_1_R', '1', 'R'), 'X': ('q_turn_1_L', 'X', 'L'), 'Y': ('q_turn_1_L', 'Y', 'L'), '_': ('q_turn_1_L', '_', 'L')},
        'q_turn_0_L': {'0': ('q_bring_0_L', 'X', 'L'), '1': ('q_bring_1_L', 'X', 'L'), 'L': ('q_cleanup_L', 'X', 'L')},
        'q_turn_1_L': {'0': ('q_bring_0_L', 'Y', 'L'), '1': ('q_bring_1_L', 'Y', 'L'), 'L': ('q_cleanup_L', 'Y', 'L')},
        'q_bring_0_L': {'0': ('q_bring_0_L', '0', 'L'), '1': ('q_bring_0_L', '1', 'L'), 'L': ('q_start', 'X', 'R')},
        'q_bring_1_L': {'0': ('q_bring_1_L', '0', 'L'), '1': ('q_bring_1_L', '1', 'L'), 'L': ('q_start', 'Y', 'R')},
        'q_cleanup_L': {'X': ('q_cleanup_L', 'X', 'L'), 'Y': ('q_cleanup_L', 'Y', 'L'), '_': ('q_cleanup_R', '_', 'R')},
        'q_cleanup_R': {'X': ('q_cleanup_R', '0', 'R'), 'Y': ('q_cleanup_R', '1', 'R'), '_': ('q_acc', '_', 'R')}
    }

    mt_inversao = maquinaTuring(
        estados=['q_start', 'q_hold_0_R', 'q_hold_1_R', 'q_turn_0_L', 'q_turn_1_L',
                 'q_bring_0_L', 'q_bring_1_L', 'q_cleanup_L', 'q_cleanup_R', 'q_acc'],
        alfabeto_entrada=['0', '1'],
        alfabeto_fita=['0', '1', 'X', 'Y', 'L', '_'],
        transicoes=transicoes,
        estado_inicial='q_start',
        estado_aceitacao='q_acc',
        branco='_'
    )

    entradas_teste = ["011", "0011", "10101", "0", ""]
    for cadeia in entradas_teste:
        sucesso, resultado = mt_inversao.processar(cadeia)
        print(f"Entrada original: '{cadeia}' | Resultado fita: '{resultado}'")


# Função auxiliar da Questão 20
def executar_mt_universal(fita_universal):
    try:
        codigo_m, w = fita_universal.split('#')
        metadados, bloco_transicoes = codigo_m.split('$')
        estado_inicial, estado_aceitacao = metadados.split('|')

        transicoes_decodificadas = {}
        regras = bloco_transicoes.split(';')

        for regra in regras:
            if not regra:
                continue
            q_atual, simb_lido, q_novo, simb_esc, direcao = regra.split(',')
            if q_atual not in transicoes_decodificadas:
                transicoes_decodificadas[q_atual] = {}
            transicoes_decodificadas[q_atual][simb_lido] = (
                q_novo, simb_esc, direcao)

        mt_simulada = maquinaTuring(
            estados=[],
            alfabeto_entrada=[],
            alfabeto_fita=[],
            transicoes=transicoes_decodificadas,
            estado_inicial=estado_inicial,
            estado_aceitacao=estado_aceitacao,
            branco='_'
        )

        return mt_simulada.processar(w)

    except Exception as e:
        return False, f"Erro de sintaxe na Máquina Universal: {str(e)}"


def questao20():
    print("\n=== TESTES DA QUESTÃO 20 (Máquina de Turing Universal) ===")
    codigo_M = "q_par|q_acc$q_par,0,q_par,0,R;q_par,1,q_impar,1,R;q_par,_,q_acc,_,R;q_impar,0,q_impar,0,R;q_impar,1,q_par,1,R"
    entradas = ["0000", "1010", "111", "100"]

    for w in entradas:
        fita_U = f"{codigo_M}#{w}"
        sucesso, resultado = executar_mt_universal(fita_U)
        status = "ACEITO" if sucesso else "REJEITADO"
        print(f"Entrada (w): {w:<6} | Status da Simulação: {status}")


# ==========================================
# TESTES DAS ATIVIDADES
# ==========================================

if __name__ == "__main__":
    # Tire a cerquilha/hash (#) no começo da função para testar uma questão específica

    # questao1()
     questao2()
    # questao3()
    # questao4()
    # questao5()
    # questao6()
    # questao7()
    # questao8()
    # questao9()
    # questao10()
    # questao11()
    # questao12()
    # questao13()
    # questao14()
    # questao15()
    # questao16()
    # questao17()
    # questao18()
    # questao19()
    # questao20()