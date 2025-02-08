#!/usr/bin/env python3
"""The module for Count and Say"""


def countAndSay(n: int) -> str:
    """
    Takes a positive integer n as input and recursively computes,
    the nth term of the count-and-say sequence.
    """
    if n == 1:
        return "1"

    prev = countAndSay(n - 1)
    output = []
    count = 1

    for i in range(1, len(prev)):
        if prev[i] == prev[i - 1]:
            count += 1
        else:
            output.append(str(count))
            output.append(prev[i - 1])
            count = 1

    output.append(str(count))
    output.append(prev[-1])

    return "".join(output)


n = 5
print(f"countAndSay({n}) =", countAndSay(n))
