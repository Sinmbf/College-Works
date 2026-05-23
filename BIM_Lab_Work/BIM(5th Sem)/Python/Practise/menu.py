import tkinter as tk

def show_menu(event):
    menu.post(event.x_root, event.y_root)

root = tk.Tk()

menu = tk.Menu(root, tearoff=0)
menu.add_command(label="Cut")
menu.add_command(label="Copy")
menu.add_command(label="Paste")

root.bind("<Button-3>", show_menu)

root.mainloop()