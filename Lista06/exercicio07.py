def maxPlan(values, quantity, partial):
    buy_price = values[0]
    partial[0] = 0
    buy = 0
    sale = 0
    answer = []

    for i in range(1, quantity):
        partial[i] = max(partial[i - 1], values[i] - buy_price)
        if partial[i - 1] < partial[i]:
            sale = i
        buy_price = min(buy_price, values[i])
        print(partial)

    for i in range(sale - 1, 0, -1):
        if (partial[sale] - partial[i]) == partial[quantity - 1] and sale > i:
            buy = i

    if partial[quantity - 1]:
        answer.append(buy)
        answer.append(sale)

    return answer


values = [65, 9, 12, 8, 14, 6]
quantity = len(values)
partial = quantity*[0]
buy_price = 10

optimal = maxPlan(values, quantity, partial)
if partial[quantity - 1]:
    print('Value buy: ' + str(values[optimal[0]]) + '\nDay buy: ' + str(optimal[0]))
    print('Value sale: ' + str(values[optimal[1]]) + '\nDay sale: ' + str(optimal[1]))
    print('Value profit: ' + str(partial[quantity - 1]))
else:
    print('Stock did not make a profit.')
