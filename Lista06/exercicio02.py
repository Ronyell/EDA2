# Resposta A: A


def maxPlan(values, allSum, lowSum, hightSum, quantity):
    if quantity == 0:
        return 0

    for i in range(0, quantity):
        if i == 0:
            allSum[i] = 0
        else:
            lowSum[i] = values[i][0] + max(lowSum[i-1], hightSum[i-1])
            hightSum[i] = values[i][1] + max(lowSum[i-1], hightSum[i-1])
            allSum[i] = max(lowSum[i], hightSum[i])

    return allSum[quantity - 1]

values = [[10, 5], [1, 50], [10, 5], [10, 1], [1, 9]]
quantity = len(values)
lowSum = [0] * quantity
hightSum = [0] * quantity
allSum = [0] * quantity

optimalPlan = maxPlan(values, allSum, lowSum, hightSum, quantity)
print('Partial plans: ' + str(allSum))
print('Value of an optimal plan: ' + str(optimalPlan))
