#include "iostream"
#include "string"
using namespace std;
class RailCar {
protected:
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
    virtual RailCar* clone() = 0;
    virtual ~RailCar() {
        delete next;
    };
    RailCar* getNext() {
        return next;
    }
    void setNext(RailCar* railCar) {
        this->next = railCar;
    }
    string getName() {
        return name;
    }
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
        return capacity >= 40;
    }
    string toString() override {
        return name + to_string(capacity);
    }
    RailCar* clone() override {
        RailCar* copy = new PassengerCar(name, capacity);
        return copy;
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
        return name + to_string(numberOfTables);
    }
    RailCar* clone() override {
        RailCar* copy = new RestaurantCar(name, numberOfTables);
        return copy;
    }
};

class Locomotive {
    RailCar* first;
public:
    void attachRailCar(RailCar* railCar) {
        if (first == NULL) {
            first = railCar;
            return;
        }
        RailCar* next = first;
        while (next->getNext() != NULL && railCar->toString().compare(next->toString()) > 0) {
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
    RailCar* getFirstRailCar() {
        return first;
    }
    void setFirstRailCar(RailCar* first) {
        this->first = first;
    }
    virtual ~Locomotive() {
        delete first;
    };
    void toString() {
        RailCar* railCar = first;
        while(railCar->getNext() != NULL) {
            cout << railCar->toString() << endl;
            railCar = railCar->getNext();
        }
        cout << railCar->toString();
        cout << endl;
    }
};

void removeUnprofitableCars(Locomotive* locomotive) {
    while (locomotive->getFirstRailCar() != NULL && !locomotive->getFirstRailCar()->isProfitable()) {
        locomotive->setFirstRailCar(locomotive->getFirstRailCar()->getNext());
    }
    RailCar* current = locomotive->getFirstRailCar();
    RailCar* next = current->getNext();
    if (next == NULL) {
        return;
    }
    while (next->getNext() != NULL) {
        if (!next->isProfitable()) {
            current->setNext(next->getNext());
            next = next->getNext();
        } else {
            current = next;
            next = next->getNext();
        }
    }
    if (!next->isProfitable()) {
        current->setNext(NULL);
    }
}

Locomotive* reverseLocomotive(Locomotive* locomotive) {
    Locomotive* newLocomotive = new Locomotive();
    RailCar* current = locomotive->getFirstRailCar();
    RailCar* next = current->getNext();
    if (next == NULL) {
        newLocomotive->setFirstRailCar(current->clone());
        return newLocomotive;
    }
    RailCar* end = current->clone();
    RailCar* before = next->clone();
    while (next->getNext() != NULL) {
        before->setNext(end);
        current = next;
        next = next->getNext();
        end = before;
        before = next->clone();
    }
    before->setNext(end);
    newLocomotive->setFirstRailCar(before);
    return newLocomotive;
}

int main() {
    RailCar* passengerCar1 = new PassengerCar("p1", 20);
    RailCar* passengerCar2 = new PassengerCar("p2", 20);
    RailCar* passengerCar3 = new PassengerCar("p3", 20);
    RailCar* restaurantCar1 = new RestaurantCar("r1", 19);
    RailCar* restaurantCar2 = new RestaurantCar("r2", 20);
    Locomotive* locomotive = new Locomotive();
    locomotive->attachRailCar(passengerCar1);
    locomotive->attachRailCar(passengerCar2);
    locomotive->attachRailCar(passengerCar3);
    locomotive->attachRailCar(restaurantCar1);
    locomotive->attachRailCar(restaurantCar2);
    locomotive->toString();
    cout << "--------\n";
    removeUnprofitableCars(locomotive);
    locomotive->toString();
    cout << endl;
    cout << "------------\n";
    Locomotive* reversed = reverseLocomotive(locomotive);
    reversed->toString();
    return 0;
}