def maxWeight(values, valuesSum, quantity):
    if quantity == 0:
        return 0

    for i in range(0, quantity):
        valuesSum[i] = max(valuesSum[i-1], values[i] + valuesSum[i - 2])

    return valuesSum[quantity - 1]

values = [3, 9, 18, 22]
weights = [1, 2, 5, 6]

quantity = len(values)
valuesSum = [0] * quantity

max_weight = maxWeight(values, valuesSum, quantity)
print('Partial weight: ' + str(valuesSum))
print('Max weight: ' + str(max_weight))
