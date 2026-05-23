def sum_all(*args):
    sum=0
    for num in args:
        sum+=num
    return sum

print(sum_all(1, 2, 3, 4))  # Output: 10