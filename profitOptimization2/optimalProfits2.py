#!/usr/bin/env python3
"""The module for Best Time to Buy and Sell Stock 2"""


def profitMaximization(prices):
    """Computes the maximum profit with at most two transactions."""
    # Initialize:
    # cost1 = min price to buy first share
    # profit1 = best profit after selling first share
    # cost2nd = min cost to buy second share
    # profit2nd = best profit after selling second share
    cost1 = float('inf')
    profit1 = 0
    cost2nd = float('inf')
    profit2nd = 0

    for price in prices:
        cost1 = min(cost1, price)
        profit1 = max(profit1, price - cost1)
        cost2nd = min(cost2nd, price - profit1)
        profit2nd = max(profit2nd, price - cost2nd)
    return profit2nd


if __name__ == "__main__":
    prices = [3, 3, 5, 0, 0, 3.5, 1, 4.2]
    print('Max Profit with up to 2 transactions:', profitMaximization(prices))
