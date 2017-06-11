# Resposta A: Dado a tabela
# |   | 01 | 02 | 03 | 04 | 05 |
# | x | 10 | 08 | 07 | 04 | 02 |
# | s | 09 | 07 | 05 | 03 | 01 |
# Caso  nao seja reiniciado temos 9 + 7 + 5 + 3 + 1 = 25
# Isso e o maximo que o computador pode processar caso ele seja reiniciado
# ele perdera processamento.


def maxPlan(valuesX, valuesS, allSum, quantity):
    if quantity == 0:
        return 0

    for i in range(1, quantity + 1):
        for j in range(1, quantity + 1):
            if i > j:
                allSum[i][j] = allSum[i - 1][j]
                pass
            else:
                aux = min(valuesX[i - 1], valuesS[i - 1])
                allSum[i][j] = max(allSum[i - 1][j], aux + allSum[i - 1][j - 1])

    return allSum[quantity][quantity]

valuesX = [10, 1, 7, 7]
valuesS = [8, 4, 2, 1]
quantity = len(valuesS)
allSum = [(quantity + 1)*[0] for count in range(quantity + 1)]

optimalPlan = maxPlan(valuesX, valuesS, allSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))
