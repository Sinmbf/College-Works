class Student:
    def __init__(self, name, marks):
        self.name = name  # public attribute
        self.__marks = marks    # Private attribute

    def get_marks(self):
        return self.__marks

    def set_marks(self, marks):
        if 0 <= marks <= 100:
            self.__marks = marks
        else:
            print("Marks must be between 0 and 100.")

# Example usage
s1 = Student("Alice", 85)
print(s1.get_marks())  # Output: 85
s1.set_marks(90)
print(s1.get_marks())  # Output: 90
s1.set_marks(110)  # Output: Marks must be between 0 and 100.  
print(s1.__marks)  # This will raise an AttributeError since __marks is private