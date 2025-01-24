#include <iostream>
#include <string>

// Citizen class
class Citizen {
public:
    std::string name;
    int age;

    Citizen(std::string n, int a) : name(n), age(a) {}

    // Method to display citizen's information
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Method to change citizen's information
    void changeInfo(std::string newName, int newAge) {
        name = newName;
        age = newAge;
    }
};

// LawEnforcement class
class LawEnforcement {
public:
    void viewCitizenInfo(const Citizen& citizen) {
        // Law enforcement can view but not change citizen's information
        citizen.displayInfo();
        // citizen.name = "New Name"; // This would cause a compilation error
    }
};

int main() {
    Citizen john("John Doe", 30);
    LawEnforcement officer;

    // Officer views John's information
    officer.viewCitizenInfo(john);

    // John changes his own information
    john.changeInfo("John Smith", 31);
    
    // Officer views the updated information
    officer.viewCitizenInfo(john);

    return 0;
}
