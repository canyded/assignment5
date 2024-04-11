#include <iostream>
#include <string>

using namespace std;

class Weapon {
public:
    string Type;
    int Damage;
    int Speed;
    int Range;
};

class Character {
public:
    string Name;
    string Class;
    Weapon* WeaponPtr;
    int Health;
    int Mana;
};

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    virtual Weapon* createWeapon() = 0;
};

class WarriorSwordFactory : public CharacterFactory {
public:
    Character* createCharacter() override {
        Character* warrior = new Character();
        warrior->Name = "Warrior";
        warrior->Class = "Warrior";
        warrior->Health = 100;
        warrior->Mana = 50;
        warrior->WeaponPtr = createWeapon();
        return warrior;
    }

    Weapon* createWeapon() override {
        Weapon* sword = new Weapon();
        sword->Type = "Sword";
        sword->Damage = 20;
        sword->Speed = 10;
        sword->Range = 2;
        return sword;
    }
};

class CharacterCreator {
private:
    CharacterFactory* factory;
public:
    void setFactory(CharacterFactory* f) {
        factory = f;
    }

    Character* createCharacter() {
        return factory->createCharacter();
    }
};

int main() {
    CharacterCreator creator;
    WarriorSwordFactory warriorSwordFactory;
    creator.setFactory(&warriorSwordFactory);

    Character* warrior = creator.createCharacter();

    cout << "Character: " << warrior->Name << ", Class: " << warrior->Class << endl;
    cout << "Weapon: " << warrior->WeaponPtr->Type << ", Damage: " << warrior->WeaponPtr->Damage << endl;

    delete warrior->WeaponPtr;
    delete warrior;

    return 0;
}
