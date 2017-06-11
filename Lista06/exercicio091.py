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
                allSum[i][j] = max(allSum[i][i], aux + allSum[i - 1][i - 1])

    return allSum[quantity][quantity]

valuesX = [10, 1, 7, 7]
valuesS = [8, 4, 2, 1]
quantity = len(valuesS)
allSum = [(quantity + 1)*[0] for count in range(quantity + 1)]

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
