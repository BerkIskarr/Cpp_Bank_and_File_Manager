//
//  main.cpp
//  CS221_1st
//
//  Created by Berk Iskar on 04/11/2023.
//
#include "Person.h"

int main(int argc, const char * argv[]) {
    // create person object
    Person* person = new Person;
    person->main_menu();
    delete person;
    person = nullptr;
    return 0;
}
