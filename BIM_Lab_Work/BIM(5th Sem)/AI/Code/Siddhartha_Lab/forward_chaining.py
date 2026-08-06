# Forward Chaining - Medical Diagnosis Example

# Initial known facts
facts = {"Fever", "Cough"}

# Rules: (Conditions, Conclusion)
rules = [
    ({"Fever", "Cough"}, "Flu"),
    ({"Flu"}, "Visit Doctor"),
    ({"Visit Doctor"}, "Take Medicine"),
    ({"Take Medicine"}, "Recover Soon")
]

print("Initial Facts:", facts)
print()

changed = True

while changed:
    changed = False

    for conditions, conclusion in rules:
        if conditions.issubset(facts) and conclusion not in facts:
            facts.add(conclusion)
            print(f"Rule Applied: {conditions} -> {conclusion}")
            print("Current Facts:", facts)
            print()

            changed = True

print("Final Facts:", facts)