# Resposta A: Dado a tabela
# |   | 01 | 02 | 03 | 04 | 05 |
# | x | 10 | 08 | 07 | 04 | 02 |
# | s | 09 | 07 | 05 | 03 | 01 |
# Caso  nao seja reiniciado temos 9 + 7 + 5 + 3 + 1 = 25
# Isso e o maximo que o computador pode processar caso ele seja reiniciado
# ele perdera processamento.


def maxPlan(valuesX, valuesS, allSum, quantity):
    allSum[0] = 0
    allSum[1] = min(valuesS[0], valuesX[0])

    print(allSum)
    for i in range(1, quantity + 1):
        auxSum = 0
        for j in range(0, i):
            minMax = 0
            for k in range(j, i):
                minMax = minMax + min(valuesS[k - j], valuesX[k])
            minMax = minMax + allSum[j - 1]
            if minMax > auxSum:
                auxSum = minMax
        allSum[i] = auxSum
        print(allSum)
    return allSum[quantity]

# valuesX = [1, 7, 3, 4]
# valuesS = [10, 8, 6, 5]
# 15^ 19v
valuesX = [10, 1, 7, 7]
valuesS = [8, 4, 2, 1]
quantity = len(valuesS)
allSum = (quantity + 1)*[0]

optimalPlan = maxPlan(valuesX, valuesS, allSum, quantity)
print('Partial proccess: ' + str(allSum))
print('Value of an optimal proccess: ' + str(optimalPlan))
