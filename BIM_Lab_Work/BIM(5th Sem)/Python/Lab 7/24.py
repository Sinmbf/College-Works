with open("poem.txt", "r") as file:
    # Step 1: Read entire file
    content = file.read()
    
    # Step 2: Move pointer back to beginning
    file.seek(0)
    
    # Step 3: Read lines again
    lines = file.readlines()

# Step 4: Print in reverse order
print("Poem in reverse order:")
for line in reversed(lines):
    print(line.strip())

