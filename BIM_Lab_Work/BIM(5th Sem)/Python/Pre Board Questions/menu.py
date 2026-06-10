import tkinter as tk

# Create main window
root = tk.Tk()
root.title("Sid")
root.geometry("500x400") # (width, height)

# Create menu bar
menubar = tk.Menu(root)

# # # File menu
file_menu = tk.Menu(menubar,tearoff=1)
file_menu.add_command(label="New")
file_menu.add_command(label="Open...")
file_menu.add_separator()
file_menu.add_command(label="Exit", command=root.destroy)

# # # Add File menu to menu bar
menubar.add_cascade(label="File", menu=file_menu)

# # # Help menu
help_menu = tk.Menu(menubar, tearoff=0)
menubar.add_cascade(label="Help", menu=help_menu)

# # # Attach menu bar to window
root.config(menu=menubar)

root.mainloop()

