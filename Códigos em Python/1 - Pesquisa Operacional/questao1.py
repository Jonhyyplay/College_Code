import pulp

# 1. Criar o problema de Maximização
modelo_fabrica = pulp.LpProblem("Maximizacao_Lucro_Fabrica", pulp.LpMaximize)

# 2. Definir as Variáveis de Decisão
x1 = pulp.LpVariable("Artigo_A", lowBound=0, cat='Integer')
x2 = pulp.LpVariable("Artigo_B", lowBound=0, cat='Integer')

# 3. Função Objetivo
modelo_fabrica += 60 * x1 + 70 * x2, "Lucro_Total"

# 4. Restrições Técnicas
modelo_fabrica += 2 * x1 + 3 * x2 <= 12, "Capacidade_M1"
modelo_fabrica += 2 * x1 + 1 * x2 <= 5, "Capacidade_M2"

# 5. Resolver o Problema
modelo_fabrica.solve()

# 6. Exibir Resultados
print(f"Status da Solução: {pulp.LpStatus[modelo_fabrica.status]}")
print(f"Quantidade de Artigo A: {x1.varValue}")
print(f"Quantidade de Artigo B: {x2.varValue}")
print(f"Lucro Máximo: R$ {pulp.value(modelo_fabrica.objective)}")
