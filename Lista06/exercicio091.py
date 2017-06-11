# Resposta A: Dado a tabela
# |   | 01 | 02 | 03 | 04 | 05 |
# | x | 10 | 08 | 07 | 04 | 02 |
# | s | 09 | 07 | 05 | 03 | 01 |
# Caso  nao seja reiniciado temos 9 + 7 + 5 + 3 + 1 = 25
# Isso e o maximo que o computador pode processar caso ele seja reiniciado
# ele perdera processamento.


# let OPT[0...n] be a new array of n+1 elements
# OPT[0] = 0, OPT[1] = min(s[1], x[1])
# for i = 2 to n
#   m = -infinity
#   for j = 1 to i-1
#     l = 0
#     for k = j+1 to i do l = l + min(s[k-j], x[k])
#     l = l + OPT[j-1]
#     if l > m then m = l
#   OPT[i] = m
# return OPT[n]

def maxPlan(valuesX, valuesS, allSum, quantity):
    allSum[0] = 0
    allSum[1] = min(valuesS[0], valuesX[0])

    print(allSum)
    for i in range(1, quantity + 1):
        m = 0
        for j in range(0, i):
            l = 0
            for k in range(j, i):
                l = l + min(valuesS[k - j], valuesX[k])
            l = l + allSum[j - 1]
            if l > m:
                m = l
        allSum[i] = m
    return allSum[quantity]

valuesX = [1, 7, 3, 4]
valuesS = [10, 8, 6, 5]
# 15^ 19v
# valuesX = [10, 1, 7, 7]
# valuesS = [8, 4, 2, 1]
quantity = len(valuesS)
allSum = (quantity + 1)*[0]

optimalPlan = maxPlan(valuesX, valuesS, allSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))


# def maxPlan(valuesX, valuesS, opt, n, j):
#     j = 0
#     for i in range(0, n + 1):
#             opt[i][j] = min(valuesX[n-1], valuesS[j-1])
#             j += 1
#
#     print(opt)
#     for i in range(n - 1, 1, -1):
#         for j in range(1, i):
#                 aux = min(valuesX[i], valuesS[j])
#                 print(str(aux))
#                 opt[i][j] = max(opt[i + 1][0], aux + opt[i + 1][j + 1])
#
#     return opt[quantity][quantity]
#
# valuesX = [10, 1, 7, 7]
# valuesS = [8, 4, 2, 1]
# quantity = len(valuesS)
# allSum = [(quantity + 1)*[0] for count in range(quantity + 1)]
#
# optimalPlan = maxPlan(valuesX, valuesS, allSum, quantity, quantity)
# print('Partial plans: ' + str(allSum))
# print('Value of an optimal plan: ' + str(optimalPlan))
