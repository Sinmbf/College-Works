import tkinter as tk

root = tk.Tk()
root.title("Sum calculator")
root.geometry("400x200")

def calculate_sum():
    try:
        num1 = float(entry1.get())
        num2 = float(entry2.get())
        result = num1 + num2
        label_result.config(text=f"Result: {result}")
    except Exception:
        label_result.config(text="Please enter valid numbers.", fg="red")


num1_label = tk.Label(root, text="Enter first number:")
num1_label.pack()

entry1 = tk.Entry(root, width=20)
entry1.pack()

num2_label = tk.Label(root, text="Enter second number:")
num2_label.pack()

entry2 = tk.Entry(root, width=20)
entry2.pack()

button = tk.Button(root, text='Calculate sum', command=calculate_sum)
button.pack()

label_result = tk.Label(root, text="Result:")
label_result.pack()

root.mainloop()