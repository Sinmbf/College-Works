import sqlite3

# i. Create database
conn = sqlite3.connect("company.db")
cursor = conn.cursor()

# ii. Create table
cursor.execute("""
CREATE TABLE IF NOT EXISTS Employees (
    EmployeeID INTEGER PRIMARY KEY,
    FirstName TEXT,
    LastName TEXT,
    HireDate TEXT,
    Salary REAL
)
""")

# iii. Insert record
cursor.execute("""
INSERT INTO Employees (EmployeeID, FirstName, LastName, HireDate, Salary)
VALUES (1, 'John', 'Doe', '2024-01-01', 50000)
""")

conn.commit()

# iv. Retrieve records
cursor.execute("SELECT * FROM Employees")
rows = cursor.fetchall()

for row in rows:
    print(row)

conn.close()