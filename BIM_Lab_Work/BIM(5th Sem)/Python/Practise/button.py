import tkinter as tk
import random

messages = ["Hello!", "Welcome!", "Good Day!", "Keep Learning!", "Python is fun!"]

def change_text():
    label.config(text=random.choice(messages))

root = tk.Tk()
root.title("Random Message")

label = tk.Label(root, text="Click the button", font=("Arial", 14))
label.pack(pady=20)

button = tk.Button(root, text="Change Message", command=change_text)
button.pack()

root.mainloop()