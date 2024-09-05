//
//  Person.h
//  CS221_1st
//
//  Created by Berk Iskar on 04/11/2023.
//


#ifndef Person_h
#define Person_h
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Person{
private:
    string* name;
    int* age;
    string *place_of_birth;
    string *password;
    float *balance;
    string** transactions;
    
    
        
public:
    Person();
    ~Person();
    // getters
    string* getName() const;
    string* getPob() const;
    string* getPassw() const;
    int* getAge() const;
    float* getBalance() const;
    string* getTransaction(int idx) const;
    // setters
    void setBalance(float newBalance);
    void setName(string name);

    void create_data(ofstream& os,vector<string> *sender_updated_data);
    void maketransaction();
    bool check_if_exists(string* name);
    void login();
    void txt_to_person(string* logname);
    void registeration();
    void main_menu();

    friend ostream& operator<<(ostream &out, Person& person);
      
};
#endif /* Person_h */

