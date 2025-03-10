#!/usr/bin/env python3
"""The module for Restore IP Addresses"""


def restoreIpAddresses(s):
    """Returns all possible valid IP addresses"""
    def backtrack(start, path):
        """Recursive Backtracking"""
        if len(path) == 4 and start == len(s):
            output.append(".".join(path))
            return

        if len(path) >= 4:
            return

        for length in range(1, 4):
            if start + length > len(s):
                break

            seg = s[start:start+length]

            if (len(seg) > 1 and seg[0] == "0") or int(seg) > 255:
                continue

            backtrack(start + length, path + [seg])

    output = []
    backtrack(0, [])
    return output


print(restoreIpAddresses("25525511135"))
print(restoreIpAddresses("0000"))
print(restoreIpAddresses("1111"))
print(restoreIpAddresses("101023"))
