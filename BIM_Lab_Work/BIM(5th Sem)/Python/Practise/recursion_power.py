def power(b, p):
    if p == 0:
        return 1
    elif p < 0:
        return 1 / power(b, -p)
    else:
        return b * power(b, p - 1)

print(power(2, 3))    # 8
print(power(2, -2))   # 0.25