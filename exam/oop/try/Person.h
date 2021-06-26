//
// Created by dani on 6/23/21.
//

#ifndef TRY_PERSON_H
#define TRY_PERSON_H


class Person {
private:
    char* lastName;
    char* firstName;
public:
    Person();
    Person(char* lastName, char* firstName);
    Person(const Person& person);
    ~Person();
    void print();
};

#endif //TRY_PERSON_H
