import tkinter as tk

# Create window
root = tk.Tk()
root.title("Placing widgets")
root.geometry("300x200")

# Entry widget
entry = tk.Entry(root, width=25)
entry.pack(pady=10)

# First label
button = tk.Button(root, text="Hello, world!")
button.pack()

# # Second label
label2 = tk.Label(root, text="...from tkinter!")
label2.pack()

# Run application
root.mainloop()