class Book:
    def __init__(self, *args):
        if len(args) == 1:
            self.title = args
        elif len(args) == 2:
            # self.title = args[0]
            # self.author = args[1]
            self.title,self.author=args

    def display(self):
        print(self.__dict__)

b1 = Book("Python")
b2 = Book("Python", "Guido")

b1.display()
b2.display()