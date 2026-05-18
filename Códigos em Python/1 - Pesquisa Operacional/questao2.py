import pulp

# 1. Criar o problema de Maximização
modelo = pulp.LpProblem("Maximizacao_Resultado", pulp.LpMaximize)

# 2. Definir as Variáveis de Decisão
x1 = pulp.LpVariable("variael_1", lowBound=0, cat='Integer')
x2 = pulp.LpVariable("variael_2", lowBound=0, cat='Integer')
x3 = pulp.LpVariable("variael_3", lowBound=0, cat='Integer')
x4 = pulp.LpVariable("variael_4", lowBound=0, cat='Integer')

# 3. Função Objetivo
modelo += 4 * x1 + 5 * x2 + 9 * x3 + 11 * x4, "Função Objetivo"

# 4. Restrições Técnicas
modelo += 1 * x1 + 1 * x2 + 1 * x3 + 1 * x4 <= 15, "Restrição_1"
modelo += 7 * x1 + 5 * x2 + 3 * x3 + 2 * x4 <= 120, "Restrição_2"
modelo += 3 * x1 + 5 * x2 + 10 * x3 + 15 * x4<= 100, "Restrição_3"

# 5. Resolver o Problema
modelo.solve()

# 6. Exibir Resultados
print(f"Status da Solução: {pulp.LpStatus[modelo.status]}")
print(f"Valor variável 1: {x1.varValue}")
print(f"Valor variável 2: {x2.varValue}")
print(f"Valor variável 3: {x3.varValue}")
print(f"Valor variável 4: {x4.varValue}")
print(f"Função Objetivo: R$ {pulp.value(modelo.objective)}")
