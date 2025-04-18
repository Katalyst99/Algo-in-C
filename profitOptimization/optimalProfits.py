#!/usr/bin/env python3
"""The module for Best Time to Buy and Sell Stock 1"""


def profitMaximization(prices):
    """Computes the maximum profit by summing all upward price movements."""
    maxProfit = 0
    for i in range(1, len(prices)):
        diff = prices[i] - prices[i - 1]
        if diff > 0:
            maxProfit += diff
    return maxProfit


if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]
    print("Maximum Profit:", profitMaximization(prices))
