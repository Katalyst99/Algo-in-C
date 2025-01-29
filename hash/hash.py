#!/usr/bin/env python3
"""The module for the Hash from Two Arrays"""


def create_hash(keys, vals):
    """Function that returns the object containing the key-value pairs,
    from the 2 arrays."""
    hashMap = {}
    n = min(len(keys), len(vals))

    for i in range(n):
        hashMap[keys[i]] = vals[i]

    for i in range(n, len(keys)):
        hashMap[keys[i]] = None

    return hashMap


keys = ["name", "age", "city"]
values = ["Alice", 25, "New York"]
print(create_hash(keys, values))
