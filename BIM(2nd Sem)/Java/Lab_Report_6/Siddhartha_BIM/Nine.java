// 9.	Provide an example on method overriding condition (dynamic or run time polymorphism)

// Parent class
class Animal {
    // Method
    public void sound() {
        System.out.println("Animal sound");
    }
}

// Child class
class Dog extends Animal {
    // Method
    @Override
    public void sound() {
        System.out.println("Refer to child method:\nDog is barking");
    }
}

// Main class
public class Nine {
    public static void main(String[] args) {
        // Dynamic polymorphism => assign object of child to reference of parent
        Animal a = new Dog();
        a.sound(); // Refers to the method of child
    }
}
