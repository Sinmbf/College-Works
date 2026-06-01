import sqlite3
conn = sqlite3.connect("student.db")

cursor = conn.cursor()
cursor.execute('''
CREATE TABLE IF NOT EXISTS students (
    id INTEGER PRIMARY KEY,
    name TEXT,
    age INTEGER
)
''')

cursor.execute("DELETE FROM students")

students_data = [
    (1, "Ethan", 19),
    (2, "Maya", 23),
    (3, "Liam", 26),
    (4, "Zara", 23),
    (5, "Noah", 30),
    (6, "Isla", 24),
    (7, "Caleb", 28),
    (8, "Nora", 22),
    (9, "Felix", 23),
    (10, "Aria", 20)
]

cursor.executemany("INSERT INTO students VALUES (?, ?, ?)", students_data)
# Save changes
conn.commit()

# display data
cursor.execute("SELECT * FROM students")
# cursor.execute("DELETE FROM students")
rows = cursor.fetchall()

print("Student Records:")
for row in rows:
    print(row)

conn.close()