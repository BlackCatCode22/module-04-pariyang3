#include <iostream>
#include <fstream>
#include <vector>
#include <map>

class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    Animal(const std::string& _name, int _age, const std::string& _species)
        : name(_name), age(_age), species(_species) {}


    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    const std::string& getSpecies() const { return species; }

    void setName(const std::string& _name) { name = _name; }
    void setAge(int _age) { age = _age; }
    void setSpecies(const std::string& _species) { species = _species; }


    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Species: " << species;
    }
};

class Hyena : public Animal {
public:
    Hyena(const std::string& _name, int _age)
        : Animal(_name, _age, "Bud") {}

    // Additional attributes specific to Hyena

};

class Lion : public Animal {
public:
    Lion(const std::string& _name, int _age)
        : Animal(_name, _age, "Simba") {}

    // Additional attributes specific to Lion
};

class Tiger : public Animal {
public:
    Tiger(const std::string& _name, int _age)
        : Animal(_name, _age, "Tigger") {}

    // Additional attributes specific to Tiger
};

class Bear : public Animal {
public:
    Bear(const std::string& _name, int _age)
        : Animal(_name, _age, "Smokey") {}

    // Additional attributes specific to Bear
};

int main() {
    std::vector<Animal*> animals;
    std::map<std::string, int> speciesCount;

    // Read animal details from the file
    std::ifstream inputFile("C:\Users\pariy\Downloads/arrivingAnimals.txt");
    std::string name;
    int age;
    std::string species;

    while (inputFile >> name >> age >> species) {
        // Create an animal based on species
        Animal* newAnimal;
        if (species == "Hyena") {
            newAnimal = new Hyena(name, age);
        } else if (species == "Lion") {
            newAnimal = new Lion(name, age);
        } else if (species == "Tiger") {
            newAnimal = new Tiger(name, age);
        } else if (species == "Bear") {
            newAnimal = new Bear(name, age);
        } else
            continue;


        animals.push_back(newAnimal);

        // Update species count
        speciesCount[species]++;
    }


    // Output the report to a new file
    std::ofstream outputFile("newAnimals.txt");

    for (const auto& animal : animals) {
        animal->display();
        outputFile << std::endl;
    }

    // Output species count
    outputFile << "\nSpecies Count:\n";
    for (const auto& entry : speciesCount) {
        outputFile << entry.first << ": " << entry.second << std::endl;
    }



    for (const auto& animal : animals) {
        delete animal;
    }

    return 0;
}
