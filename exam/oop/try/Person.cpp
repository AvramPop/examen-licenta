//
// Created by dani on 6/23/21.
//

#include "Person.h"
#include "iostream"
#include "cstring"
using namespace std;
Person::Person() {
    lastName = new char[1];
    *lastName = 0;
    firstName = new char[1];
    *firstName = 0;
    cout << "Calling default constructor" << endl;
}
Person::Person(char *lastName, char *firstName) {
    this->lastName = new char[strlen(lastName) + 1];
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->lastName, lastName);
    strcpy(this->firstName, firstName);
    cout << "custom constructor";
}
Person::Person(const Person &person) {
    lastName = new char[strlen(person.lastName) + 1];
    strcpy(lastName, person.lastName);
    firstName = new char[strlen(person.firstName) + 1];
    strcpy(firstName, person.firstName);
    cout << "copy constructor";
}
Person::~Person() {
    delete[] lastName;
    delete[] firstName;
}
void Person::print() {
    cout << firstName << " " << lastName << endl;
}
