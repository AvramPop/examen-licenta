#include "iostream"
#include "string"
using namespace std;
class RailCar {
    string name;
    RailCar* next;
public:
    RailCar(string name) {
        if (name.size() >= 2) {
            this->name = name;
        }
    }
    virtual bool isProfitable() = 0;
    virtual string toString() = 0;
    virtual RailCar clone() = 0;
    virtual ~RailCar() {
        delete next;
    };
    RailCar* getNext();
    void setNext(RailCar* railCar);
    string getName();
};

class PassengerCar : public RailCar {
    int capacity;
public:
    PassengerCar(string name, int capacity) : RailCar(name) {
        if (capacity > 0) {
            this->capacity = capacity;
        }
    }
    bool isProfitable() override {
        return capacity > 40;
    }
    string toString() override {
        return name + capacity;
    }
    RailCar clone() override {
        RailCar* copy = new PassengerCar(name, capacity);
        return copy
    }
};

class RestaurantCar : public RailCar {
    int numberOfTables;
public:
    RestaurantCar(string name, int numberOfTables) : RailCar(name) {
        if (numberOfTables > 0) {
            this->numberOfTables = numberOfTables;
        }
    }
    bool isProfitable() override {
        return numberOfTables >= 20;
    }
    string toString() override {
        return name + numberOfTables;
    }
    RailCar clone() override {
        RailCar* copy = new RestaurantCar(name, numberOfTables);
        return copy
    }
};

class Locomotive {
    RailCar* first;
private:
    void attachRailCar(RailCar* railCar) {
        RailCar* next = first;
        while (next->getNext() != NULL && railCar->toString().compare(next->toString() > 0)) {
            next = next->getNext();
        }
        if (next->getNext() != NULL) {
            RailCar* temp = next->getNext();
            next->setNext(railCar);
            railCar->setNext(temp);
        } else {
            next->setNext(railCar);
        }
    }
    RailCar* getFirstRailCar();
    RailCar* setFirstRailCar();
    virtual ~Locomotive() {
        delete first;
    };
};

int main() {
    RailCar* railCar = new PassengerCar("p1", 50);
    cout << railCar->toString();
    return 0;
}