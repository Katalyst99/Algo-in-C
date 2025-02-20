#!/usr/bin/env python3
"""The module for Deepcopy Algorithm"""


def deepCopy(obj):
    """Returns a deep copy of the given object."""
    if isinstance(obj, (int, float, str, bool, type(None))):
        return obj

    elif isinstance(obj, list):
        return [deepCopy(item) for item in obj]

    elif isinstance(obj, dict):
        return {key: deepCopy(value) for key, value in obj.items()}

    elif isinstance(obj, tuple):
        return tuple(deepCopy(item) for item in obj)
    else:
        raise TypeError(f'Unsupported data type: {type(obj)}')


original = {"name": "Alice", "info": {"age": 25, "city": "New York"}, "scores": [85, 90, 95]}
copied = deepCopy(original)

copied["info"]["age"] = 30
copied["scores"][0] = 100

print(original["info"]["age"])
print(original["scores"][0])
