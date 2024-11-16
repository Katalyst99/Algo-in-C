#!/usr/bin/env python3
print('\n'.join(
    [''.join(
        [('circle'[(x - y) % 6]
          if (x * 0.05) ** 2 + (y * 0.1) ** 2 <= 1 else ' ')
         for x in range(-30, 30)])
     for y in range(15, -15, -1)]
))
