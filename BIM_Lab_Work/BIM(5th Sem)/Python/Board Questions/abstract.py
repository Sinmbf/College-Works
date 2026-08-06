from abc import ABC, abstractmethod

class Abstract_Demo(ABC):

    @abstractmethod
    def display(self):
        pass

class Abstract_Child(Abstract_Demo):

    def display(self):
        print("Abstract display")
        
    def child(self):
        print("Abstract child")

abs_child= Abstract_Child()
abs_child.child()
