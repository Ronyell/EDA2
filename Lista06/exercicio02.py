# Resposta A: Dado a tabela
# |   | 1 | 2 | 3 | 4 |
# | l | 5 | 2 | 1 | 2 |
# | h | 4 | 8 | 9 | 3 |
# Ele tera a solucao  0 + 8 + 1 + 2 = 11
# Enquanto a solucao otima seria 5 + 0 + 9 + 2 = 16


def maxPlan(values, allSum, quantity):
    if quantity == 0:
        return 0

    for i in range(0, quantity):
        if i == 0:
            allSum[i] = max(values[i][0], values[i][1])
        else:
            allSum[i] = max(values[i][0] + allSum[i - 1], values[i][1] + allSum[i - 2])

    return allSum[quantity - 1]

values = [[5, 4], [2, 8], [1, 9], [2, 3]]
quantity = len(values)
allSum = [0] * quantity

optimalPlan = maxPlan(values, allSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))
