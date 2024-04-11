#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Furniture {
public:
    string Name;
    string Style;
    string Material;
    float Price;
};

class FurnitureFactory {
public:
    virtual Furniture* createChair() = 0;
    virtual Furniture* createTable() = 0;
    virtual Furniture* createSofa() = 0;
};

class ModernWoodFactory : public FurnitureFactory {
public:
    Furniture* createChair() override {
        Furniture* chair = new Furniture();
        chair->Name = "Modern Wood Chair";
        chair->Style = "Modern";
        chair->Material = "Wood";
        chair->Price = 150.0f;
        return chair;
    }

    Furniture* createTable() override {
        Furniture* table = new Furniture();
        table->Name = "Modern Wood Table";
        table->Style = "Modern";
        table->Material = "Wood";
        table->Price = 300.0f;
        return table;
    }

    Furniture* createSofa() override {
        Furniture* sofa = new Furniture();
        sofa->Name = "Modern Wood Sofa";
        sofa->Style = "Modern";
        sofa->Material = "Wood";
        sofa->Price = 500.0f;
        return sofa;
    }
};


class FurnitureCreator {
private:
    FurnitureFactory* factory;
public:
    void setFactory(FurnitureFactory* f) {
        factory = f;
    }

    Furniture* createChair() {
        return factory->createChair();
    }

    Furniture* createTable() {
        return factory->createTable();
    }

    Furniture* createSofa() {
        return factory->createSofa();
    }
};

int main() {
    FurnitureCreator creator;
    ModernWoodFactory modernWoodFactory;
    creator.setFactory(&modernWoodFactory);

    Furniture* chair = creator.createChair();
    Furniture* table = creator.createTable();
    Furniture* sofa = creator.createSofa();

    cout << "Chair: " << chair->Name << ", Price: $" << chair->Price << endl;
    cout << "Table: " << table->Name << ", Price: $" << table->Price << endl;
    cout << "Sofa: " << sofa->Name << ", Price: $" << sofa->Price << endl;

    delete chair;
    delete table;
    delete sofa;

    return 0;
}
