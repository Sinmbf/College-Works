# Backward Chaining - Medical Diagnosis Example

# Known facts
facts = {"Fever", "Cough"}

# Rules: Conclusion -> Conditions
rules = {
    "Flu": {"Fever", "Cough"},
    "Visit Doctor": {"Flu"},
    "Take Medicine": {"Visit Doctor"},
    "Recover Soon": {"Take Medicine"}
}

# Backward Chaining Function
def backward_chain(goal):
    # If the goal is already a known fact
    if goal in facts:
        print(f"{goal} is a known fact.")
        return True

    # If there is no rule to prove the goal
    if goal not in rules:
        print(f"No rule to prove {goal}.")
        return False

    print(f"Trying to prove: {goal}")

    # Check if all conditions can be proved
    for condition in rules[goal]:
        if not backward_chain(condition):
            return False

    print(f"{goal} is proved.")
    return True

# Goal to prove
goal = "Recover Soon"

print("Known Facts:", facts)
print("Goal:", goal)
print()

if backward_chain(goal):
    print("\nGoal Achieved:", goal)
else:
    print("\nGoal Cannot Be Achieved.")
    