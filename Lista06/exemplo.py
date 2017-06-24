def maxWeight(values, weights, valuesSum, quantity, weight):
    if quantity == 0:
        return 0

    for i in range(1, quantity + 1):
        print(i)
        for j in range(1, weight + 1):
            if weights[i-1] > j:
                valuesSum[i][j] = valuesSum[i-1][j]
            else:
                valuesSum[i][j] = max(valuesSum[i - 1][j], values[i-1] + valuesSum[i - 1][j - weights[i-1]])

    return valuesSum[quantity][weight]

values = [3, 9, 18, 22]
weights = [1, 2, 5, 6]

quantity = len(values)
weight = 8
valuesSum = [(weight + 1)*[0] for count in range(quantity + 1)]

max_weight = maxWeight(values, weights, valuesSum, quantity, weight)
print('Partial weight: ' + str(valuesSum))
print('Max weight: ' + str(max_weight))
