
def min_CAD_coins(money):
    """
    12. (5 points) Suppose that a cashier in Canada owes a customer some change and that the
    cashier only has coins ie. toonies, loonies, quarters, dimes, and nickels. Write a
    function that determines the minimum number of coins that the cashier can return. In
    particular, write a function min_CAD_coins(price,payment) that returns five numbers
    (t,l,q,d,n) that represent the smallest number of coins (toonies, loonies, quarters,
    dimes, and nickels) that add up to the amount owed to the customer (here price and
    payment are defined as in the previous question). Your program must first call the
    cad_cashier function, from question 11, to determine the amount of change that
    needs to be returned. Then before doing anything else, you may want to convert this
    amount entirely to cents (that selfhould be of type int). Once you have the total number
    of cents here are some hints on how to find the minimum number of coins.
    """

    # Using greedy algo

    # Dictionary to represent number of coins to return
    coins =	{
        2: 0, # toonies
        1: 0, # loonies
        0.25: 0, # quarters
        0.10: 0, # dimes
        0.05: 0, # nickels
    }

    balance = 0
    count = 0

    for coin in coins:
        # How much of the money can be returned with this particular coin
        count = int(money//coin)
        coins[coin] = count
        balance = money%coin
        # if the decimal part of the division is 0, then no more checking need to be done.
        # otherwise substract the amount we covered with the bigger coin
        if(balance==0):
            break
        else:
            money = money-(count*coin)

    print(coins)
    return

min_CAD_coins(10.50)
min_CAD_coins(3.80)
