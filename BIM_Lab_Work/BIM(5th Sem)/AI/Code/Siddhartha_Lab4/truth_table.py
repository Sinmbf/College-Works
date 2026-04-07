import itertools

# INPUT
expr = input("Enter expression: ").replace(" ", "")

# FIND VARIABLES
vars = sorted(set(c for c in expr if c.isalpha() and c != 'v'))

# IMPLIES
def implies(p, q):
    return (not p) or q

# BASIC CONVERSION
def convert(e):
    e = e.replace("^", " and ")
    e = e.replace("v", " or ")
    e = e.replace("~", " not ")
    e = e.replace("!", " not ")
    
    if "->" in e:
        left, right = e.split("->", 1)
        e = f"implies({left},{right})"
    
    return e

# -------- EXTRACT SUB-EXPRESSIONS --------
subs = []

# find expressions inside brackets
temp = ""
stack = []

for ch in expr:
    if ch == '(':
        stack.append("")
    elif ch == ')':
        sub = stack.pop()
        subs.append(sub)
        if stack:
            stack[-1] += f"({sub})"
    else:
        if stack:
            stack[-1] += ch

# add full expression at end
subs.append(expr)

# remove duplicates, keep order
seen = set()
subs = [x for x in subs if not (x in seen or seen.add(x))]

# -------- PRINT HEADER --------
print("\nTruth Table:")
print(*vars, *subs, sep="\t")

# -------- GENERATE TABLE --------
for values in itertools.product([True, False], repeat=len(vars)):
    env = dict(zip(vars, values))
    env["implies"] = implies
 
    row = list(values)

    for s in subs:
        try:
            result = eval(convert(s), {}, env)

        except:
            result = "Err"
        row.append(result)

    print(*row, sep="\t")