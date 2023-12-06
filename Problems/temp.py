import random

# Generate an array of size 1000 with single-digit numbers
single_digit_array = [random.randint(0,1000) for _ in range(5000)]

# Now, 'single_digit_array' contains 1000 random single-digit numbers.
print('[',end='')
for i in single_digit_array:
    print(i,end=',')
print(']',end='')