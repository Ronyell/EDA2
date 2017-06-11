# Resposta A: Dado a tabela
# |   | 01 | 02 | 03 | 04 | 05 |
# | x | 10 | 08 | 07 | 04 | 02 |
# | s | 09 | 07 | 05 | 03 | 01 |
# Caso  nao seja reiniciado temos 9 + 7 + 5 + 3 + 1 = 25
# Isso e o maximo que o computador pode processar caso ele seja reiniciado
# ele perdera processamento.


def maxPlan(values, allSum, quantity):
    if quantity == 0:
        return 0

    for i in range(1, quantity + 1):
        for j in range(1, 12):
            if values[i-1][1] > j:
                allSum[i][j] = allSum[i - 1][j]
            else:
                allSum[i][j] = max(allSum[i - 1][j], values[i - 1][0] + allSum[i - 1][j - values[i - 1][1]])

    return allSum[quantity][11]

values = [[1, 1], [6, 2], [18, 5], [22, 6], [28, 7]]
quantity = len(values)
allSum = [(12)*[0] for count in range(quantity + 1)]

optimalPlan = maxPlan(values, allSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))
