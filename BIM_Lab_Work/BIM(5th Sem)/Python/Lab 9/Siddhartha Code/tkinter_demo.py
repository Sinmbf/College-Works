import tkinter as tk

# Function to calculate sum
def calculate_sum():
    try:
        num1 = int(entry1.get())
        num2 = int(entry2.get())
        result = num1 + num2
        result_label.config(text="Sum: " + str(result))
    except ValueError:
        result_label.config(text="Enter valid integers")

# Create window
root = tk.Tk()
root.title("Sum Calculator")

# First Input
label1 = tk.Label(root, text="Enter first number:")
label1.pack()

entry1 = tk.Entry(root)
entry1.pack()

# Second Input
label2 = tk.Label(root, text="Enter second number:")
label2.pack()

entry2 = tk.Entry(root)
entry2.pack()

# Button
btn = tk.Button(root, text="Add", command=calculate_sum)
btn.pack(pady=10)

# Result label
result_label = tk.Label(root, text="Sum: ")
result_label.pack()

# Run the app
root.mainloop()