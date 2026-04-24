# ================================
# PYTHON LOOPS — COMPLETE GUIDE
# ================================


# --------------------------------
# 1. BASIC FOR LOOP (MOST COMMON)
# --------------------------------
# Iterates over elements of an iterable (list, string, etc.)
nums = [1, 2, 3]

for x in nums:
    # x is the VALUE, not index
    print(x)


# --------------------------------
# 2. FOR LOOP WITH RANGE
# --------------------------------
# Used when you need numbers (like a counter)
for i in range(5):
    # range(5) → 0,1,2,3,4
    print(i)

# range(start, stop, step)
for i in range(1, 10, 2):
    # 1,3,5,7,9
    print(i)


# --------------------------------
# 3. RANGE + LEN (INDEX-BASED LOOP)
# --------------------------------
arr = [10, 20, 30]

for i in range(len(arr)):
    # i = index
    # arr[i] = value
    print(i, arr[i])

# NOTE:
# Less Pythonic, only use when index is required


# --------------------------------
# 4. ENUMERATE (BEST OF BOTH WORLDS)
# --------------------------------
arr = [10, 20, 30]

for i, x in enumerate(arr):
    # i = index
    # x = value
    print(i, x)

# Optional start index
for i, x in enumerate(arr, start=1):
    print(i, x)


# --------------------------------
# 5. ZIP (MULTIPLE LISTS TOGETHER)
# --------------------------------
names = ["A", "B", "C"]
scores = [90, 80, 70]

for name, score in zip(names, scores):
    # Iterates in parallel
    print(name, score)

# Stops at shortest list


# --------------------------------
# 6. LOOPING OVER STRINGS
# --------------------------------
s = "hello"

for ch in s:
    # ch = each character
    print(ch)


# --------------------------------
# 7. LOOPING OVER DICTIONARIES
# --------------------------------
d = {"a": 1, "b": 2}

# Keys
for key in d:
    print(key)

# Values
for value in d.values():
    print(value)

# Key-value pairs
for key, value in d.items():
    print(key, value)


# --------------------------------
# 8. NESTED LOOPS
# --------------------------------
# Loop inside another loop
for i in range(2):
    for j in range(2):
        print(i, j)

# Used in:
# matrices, grids, combinations


# --------------------------------
# 9. WHILE LOOP
# --------------------------------
# Runs while condition is True
i = 0

while i < 5:
    print(i)
    i += 1  # IMPORTANT: update condition variable

# Infinite loop
while True:
    break  # prevent actual infinite execution


# --------------------------------
# 10. BREAK
# --------------------------------
# Exits loop immediately
for x in [1, 2, 3, 4]:
    if x == 3:
        break
    print(x)


# --------------------------------
# 11. CONTINUE
# --------------------------------
# Skips current iteration
for x in [1, 2, 3, 4]:
    if x == 2:
        continue
    print(x)


# --------------------------------
# 12. PASS
# --------------------------------
# Placeholder (does nothing)
for x in [1, 2, 3]:
    pass


# --------------------------------
# 13. FOR-ELSE
# --------------------------------
# else runs ONLY if loop did NOT break
for x in [1, 2, 3]:
    if x == 5:
        break
else:
    print("Loop completed without break")


# --------------------------------
# 14. WHILE-ELSE
# --------------------------------
i = 0
while i < 3:
    i += 1
else:
    print("While completed normally")


# --------------------------------
# 15. LIST COMPREHENSION
# --------------------------------
# Compact loop for creating lists
nums = [1, 2, 3]

squared = [x * x for x in nums]
print(squared)

# With condition
even = [x for x in nums if x % 2 == 0]


# --------------------------------
# 16. SET COMPREHENSION
# --------------------------------
s = {x for x in [1, 2, 2, 3]}
print(s)  # duplicates removed


# --------------------------------
# 17. DICTIONARY COMPREHENSION
# --------------------------------
d = {x: x * x for x in range(3)}
print(d)


# --------------------------------
# 18. GENERATOR EXPRESSION
# --------------------------------
# Like list comprehension but lazy (memory efficient)
gen = (x * x for x in range(3))

for x in gen:
    print(x)


# --------------------------------
# 19. REVERSED LOOP
# --------------------------------
arr = [1, 2, 3]

for x in reversed(arr):
    print(x)


# --------------------------------
# 20. SORTED LOOP
# --------------------------------
arr = [3, 1, 2]

for x in sorted(arr):
    print(x)


# --------------------------------
# 21. ITERATOR (UNDER THE HOOD)
# --------------------------------
arr = [1, 2, 3]

it = iter(arr)   # create iterator

print(next(it))  # 1
print(next(it))  # 2
print(next(it))  # 3
# next(it) again → StopIteration error


# --------------------------------
# 22. CUSTOM ITERATOR (ADVANCED)
# --------------------------------
class Counter:
    def __init__(self, limit):
        self.limit = limit
        self.current = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < self.limit:
            val = self.current
            self.current += 1
            return val
        else:
            raise StopIteration


for x in Counter(3):
    print(x)


# ==================================
# FINAL RULES (IMPORTANT)
# ==================================
# 1. Default → for x in iterable
# 2. Need index → use enumerate()
# 3. Need numbers → use range()
# 4. Multiple lists → use zip()
# 5. Condition-based → use while
# 6. Transform data → use comprehensions
# 7. Memory efficiency → use generators