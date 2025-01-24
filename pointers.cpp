#include <iostream>
#include <string>

// Base class Animal
class Animal {
public:
    Animal(const std::string& name) : name(name) {}
    virtual void speak() const {
        std::cout << "Animal sound" << std::endl;
    }
protected:
    std::string name;
};

// Derived class Cat
class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    void speak() const override {
        std::cout << name << " says: Meow!" << std::endl;
    }
};

// Function to demonstrate pointer initialization and dereferencing
void demonstratePointerSyntax() {
    // 1. Pointer declaration
    Cat* catPtr;

    // 2. Pointer initialization
    Cat kitty("Whiskers");
    catPtr = &kitty;

    // 3. Pointer dereferencing
    catPtr->speak(); // Using -> to call member function
    (*catPtr).speak(); // Using * and . to call member function
}

// Function taking a pointer as an argument
void speakWithPointer(Animal* animalPtr) {
    animalPtr->speak();
}

// Function returning a pointer
Animal* createCat(const std::string& name) {
    return new Cat(name);
}

int main() {
    // 4. Pointers to objects
    Cat* cat = new Cat("Fluffy");
    cat->speak();

    // 5. Function pointers
    void (Animal::*speakFn)() const = &Animal::speak;
    (cat->*speakFn)();

    // 6. Pointers to pointers
    Cat** catPtrPtr = &cat;
    (*catPtrPtr)->speak();

    // 7. Dynamic memory allocation
    Animal* dynamicCat = new Cat("Dynamite");
    dynamicCat->speak();

    // 8. Passing pointers to functions
    speakWithPointer(cat);

    // 9. Returning pointers from functions
    Animal* newCat = createCat("Shadow");
    newCat->speak();

    // Free dynamically allocated memory
    delete cat;
    delete dynamicCat;
    delete newCat;

    return 0;
}
