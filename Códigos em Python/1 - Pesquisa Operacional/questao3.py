import pulp

# 1. Criar o problema de Maximização
modelo_frota = pulp.LpProblem("Maximizacao_Frota_Veiculos", pulp.LpMaximize)

# 2. Definir as Variáveis de Decisão
x1 = pulp.LpVariable("carros_Medios", lowBound=0, cat='Integer')
x2 = pulp.LpVariable("carros_Grandes", lowBound=0, cat='Integer')

# 3. Função Objetivo
modelo_frota += 500 * x1 + 750 * x2, "Lucro_Mensal"

# 4. Restrições Técnicas
modelo_frota += 10000 * x1 + 15000 * x2 <= 540000, "limite_Orcamento"
modelo_frota += 1 * x1 + 1 * x2 <= 50, "limite_Gerencial"
modelo_frota += 1 * x1 + 2 * x2 <= 70, "limite_Infraestrutura"

# 5. Resolver o Problema
modelo_frota.solve()

# 6. Exibir Resultados
print(f"Status da Solução: {pulp.LpStatus[modelo_frota.status]}")
print(f"Quantidade de Carros Médios: {x1.varValue}")
print(f"Quantidade de Carros Grandes: {x2.varValue}")
print(f"Lucro Mensal (Máximo): R$ {pulp.value(modelo_frota.objective)}")