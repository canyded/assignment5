#include <iostream>
#include <string>
#include <vector>


class Appearance {
public:
    virtual std::string getDescription() const = 0;
};

class Ability {
public:
    virtual std::string getDescription() const = 0;
};

class Equipment {
public:
    virtual std::string getDescription() const = 0;
};

class Attribute {
public:
    virtual std::string getDescription() const = 0;
};

class Character {
public:
    std::string name;
    Appearance* appearance;
    std::vector<Ability*> abilities;
    std::vector<Equipment*> equipment;
    Attribute* attributes;

    virtual ~Character() {
        delete appearance;
        for (auto ability : abilities) {
            delete ability;
        }
        for (auto equip : equipment) {
            delete equip;
        }
        delete attributes;
    }

    virtual void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Appearance: " << appearance->getDescription() << std::endl;
        std::cout << "Abilities: ";
        for (auto ability : abilities) {
            std::cout << ability->getDescription() << ", ";
        }
        std::cout << std::endl;
        std::cout << "Equipment: ";
        for (auto equip : equipment) {
            std::cout << equip->getDescription() << ", ";
        }
        std::cout << std::endl;
        std::cout << "Attributes: " << attributes->getDescription() << std::endl;
    }
};

class CharacterFactory {
public:
    virtual Character* createCharacter(const std::string& name) = 0;
};


class WarriorAppearance : public Appearance {
public:
    std::string getDescription() const override {
        return "Warrior Appearance";
    }
};

class WarriorAbility : public Ability {
public:
    std::string getDescription() const override {
        return "Warrior Ability";
    }
};

class WarriorEquipment : public Equipment {
public:
    std::string getDescription() const override {
        return "Warrior Equipment";
    }
};

class WarriorAttribute : public Attribute {
public:
    std::string getDescription() const override {
        return "Warrior Attribute";
    }
};

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter(const std::string& name) override {
        Character* character = new Character();
        character->name = name;
        character->appearance = new WarriorAppearance();
        character->abilities.push_back(new WarriorAbility());
        character->equipment.push_back(new WarriorEquipment());
        character->attributes = new WarriorAttribute();
        return character;
    }
};


int main() {
    CharacterFactory* factory = new WarriorFactory();

    Character* character = factory->createCharacter("Warrior1");
    character->display();

    delete character;
    delete factory;

    return 0;
}
