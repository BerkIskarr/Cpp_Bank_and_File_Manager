//
//  Implementation.cpp
//  CS221_1st
//
//  Created by Berk Iskar on 04/11/2023.
//

#include "Person.h"
#include <stdio.h>

// constructor
Person::Person(){
    name = new string;
    age = new int;
    place_of_birth = new string;
    password = new string;
    balance = new float;
    transactions = new string*[3];
    for (int i = 0; i < 3; ++i) {
            transactions[i] = new string;
        }
}
// destructor, free pointers
Person::~Person(){
    delete name;
    delete age;
    delete place_of_birth;
    delete password;
    delete balance;
    delete transactions[0];
    delete transactions[1];
    delete transactions[2];
    delete[] transactions;
    name = nullptr;
    age = nullptr;
    place_of_birth = nullptr;
    password = nullptr;
    balance = nullptr;
    transactions[0] = nullptr;
    transactions[1] = nullptr;
    transactions[2] = nullptr;
    transactions = nullptr;
    }
// returns name
string* Person::getName() const{ return this->name;}
// returns place of birth
string* Person::getPob() const{return this->place_of_birth;}
// returns password
string* Person::getPassw() const{return this->password;}
// returns age
int* Person::getAge() const{return this->age;}
// returns balance
float* Person::getBalance() const{return this->balance;}
// returns transactions for specific index
string* Person::getTransaction(int idx) const{return this->transactions[idx];}
// update balance
void Person::setBalance(float newBalance){ *this->balance=newBalance;}
// update name
void Person::setName(string name){*this->name = name;}

// login functionality, logs in if account with the entered credentials exist
void Person::login(){
    try{
        string* logname = new string;
        string* logpass = new string;
        cout<<"name:  ";
        cin>>*logname;
        cout<<"password:  ";
        cin>>*logpass;
        // checks if account exists using file name
        if(!check_if_exists(logname)){
            cout<<"Not registered"<<endl;
            cout<<"Go to registration page to register"<<endl;
            delete logname;
            delete logpass;
            logname = nullptr;
            logpass = nullptr;
            return;}
        // extracts information and populates the corresponding attributes of a Person object
        txt_to_person(logname);
        delete logname;
        delete logpass;
        logname = nullptr;
        logpass = nullptr;
    }
    // if error occurs go back
    catch(...){cout<<"Invalid!"<<endl;cout<<"Restarting..."<<endl;}
}

// extracts information and populates the corresponding attributes of a Person object
void Person::txt_to_person(string* logname){
    string* data = new string(*logname + ".txt");
    ifstream user_data(*data);
    // file name is the name of the person
    this->setName(*logname);
    // skip the line since I dont need name
    user_data.ignore(numeric_limits<streamsize>::max(),'\n');
    // extract the attributes from file and assign to person object
    while (user_data >> *this->password >> *this->age >> *this->place_of_birth >> *this->balance){
        user_data.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(user_data, *this->transactions[0]);
        if (!this->transactions[0]->empty()) {
            getline(user_data, *this->transactions[1]);
            if (!this->transactions[1]->empty()) {
                getline(user_data, *this->transactions[2]);
                if (!this->transactions[2]->empty()) {
                    // process the lines if they are not empty
                }}}}
    user_data.close();
    delete data;
    data = nullptr;
}

// every functionality of making transactions
void Person::maketransaction(){
        
    int* number = new int;
    string* person = new string;
    float* amount = new float;
    string* transact_send = new string;
    string* transact_receive = new string;
    
    try{
        cout<<"1- Send Money\n2- Deposit Money"<<endl;
        cin>>*number;
        // in case non int entered free memory and restart
        if (cin.fail()) {
            cerr << "Invalid input! Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            delete transact_send;
            delete transact_receive;
            delete number;
            delete person;
            delete amount;
            transact_send = nullptr;
            transact_receive =nullptr;
            number = nullptr;
            person = nullptr;
            amount = nullptr;
            return;}
        else
            // send money
            if(*number==1){
                cout<<"Who do you want to sent to?"<<endl;
                cin>>*person;
                // to check if person is registered
                bool *exists = new bool(check_if_exists(person));
                if(*exists==true){
                    cout<<"Enter amount"<<endl;
                    cin>>*amount;
                    // in case non float entered free memory and restart
                    if (cin.fail()) {
                        cerr << "Invalid input! amount cannot be string." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        delete transact_send;
                        delete transact_receive;
                        delete number;
                        delete person;
                        delete amount;
                        delete exists;
                        transact_send = nullptr;
                        transact_receive =nullptr;
                        number = nullptr;
                        person = nullptr;
                        amount = nullptr;
                        exists = nullptr;
                        return;}
                    // if amount more than 0 proceed and and create transaction
                    if(*amount>0){
                        if(*amount<=*this->getBalance()){
                            this->setBalance(*this->getBalance()-*amount);
                            *transact_send = "To "+*person+" you paid £"+to_string(*amount);
                            *transact_receive = "From "+*this->getName()+" you receieved £"+to_string(*amount);
                            cout<<"Your money is sent"<<endl;
                        }
                        // if money is not enough
                        else if(*amount>*this->getBalance()){
                            cout<<"Sorry, not enough money"<<endl;
                            delete transact_send;
                            delete transact_receive;
                            delete number;
                            delete person;
                            delete amount;
                            delete exists;
                            transact_send = nullptr;
                            transact_receive =nullptr;
                            number = nullptr;
                            person = nullptr;
                            amount = nullptr;
                            exists = nullptr;
                            return;
                        }
                        // Invalid input
                        else{cout<<"Invalid Input\nResetting..."<<endl;
                            delete transact_send;
                            delete transact_receive;
                            delete number;
                            delete person;
                            delete amount;
                            delete exists;
                            transact_send = nullptr;
                            transact_receive =nullptr;
                            number = nullptr;
                            person = nullptr;
                            amount = nullptr;
                            exists = nullptr;
                            return;}
                        
                    }else{cout<<"Invalid Input\nResetting..."<<endl;
                        delete transact_send;
                        delete transact_receive;
                        delete number;
                        delete person;
                        delete amount;
                        delete exists;
                        transact_send = nullptr;
                        transact_receive =nullptr;
                        number = nullptr;
                        person = nullptr;
                        amount = nullptr;
                        exists = nullptr;
                        return;}}
                // if receiver not registered
                else if(*exists==false){
                    cout<<"This person does not exist"<<endl;
                    delete transact_send;
                    delete transact_receive;
                    delete number;
                    delete person;
                    delete amount;
                    delete exists;
                    transact_send = nullptr;
                    transact_receive =nullptr;
                    number = nullptr;
                    person = nullptr;
                    amount = nullptr;
                    exists = nullptr;
                    return;
                }
            }
            // deposit money to account
            else if(*number==2){
                cout<<"How much do you want to deposit?"<<endl;
                cin>>*amount;
                if (cin.fail()) {
                    cerr << "Invalid input! Please enter an integer." << endl;
                    // recover from failed input
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    delete transact_send;
                    delete transact_receive;
                    delete number;
                    delete person;
                    delete amount;
                    transact_send = nullptr;
                    transact_receive =nullptr;
                    number = nullptr;
                    person = nullptr;
                    amount = nullptr;
                    return;}
                // amount must be more than 0
                if(*amount<=0){
                    cout<<"Invalid amount\nResetting..."<<endl;
                    delete transact_send;
                    delete transact_receive;
                    delete number;
                    delete person;
                    delete amount;
                    transact_send = nullptr;
                    transact_receive =nullptr;
                    number = nullptr;
                    person = nullptr;
                    amount = nullptr;
                    return;}
                // update balance and create transaction
                else if(*amount>0){
                    *transact_send="You deposited "+to_string(*amount);
                    setBalance(*amount+*this->getBalance());
                    cout<<"Deposit successful"<<endl;}
                else{cout<<"Invalid option\nResetting"<<endl;
                    delete transact_send;
                    delete transact_receive;
                    delete number;
                    delete person;
                    delete amount;
                    transact_send = nullptr;
                    transact_receive =nullptr;
                    number = nullptr;
                    person = nullptr;
                    amount = nullptr;
                    return;}}
            else{cout<<"Invalid option\nRestarting..."<<endl;
                delete transact_send;
                delete transact_receive;
                delete number;
                delete person;
                delete amount;
                transact_send = nullptr;
                transact_receive =nullptr;
                number = nullptr;
                person = nullptr;
                amount = nullptr;
                return;}
        // swap values to open space for the recent transaction
        for (int i = 2; i > 0; --i) {
            *this->transactions[i] = *this->transactions[i - 1];
        }
        // save the most recent transaction
        this->transactions[0] = new string(*transact_send);
        }catch(...){cout<<"Invalid!"<<endl;cout<<"Restarting..."<<endl;}
    
        string* data = new string(*this->getName() + ".txt");
        // open file for reading
        ifstream fname_data(*data);
        // if couldn't be opened
        if (!fname_data.is_open()) {
            cerr << "Error opening file: " << data << endl;
            delete transact_send;
            delete transact_receive;
            delete number;
            delete person;
            delete amount;
            delete data;
            transact_send = nullptr;
            transact_receive =nullptr;
            number = nullptr;
            person = nullptr;
            amount = nullptr;
            data = nullptr;
            return;
        }
        // to store each line
        vector<string>* sender_updated_data = new vector<string>;

        // read all lines into the vector
        string* line = new string;
        while (getline(fname_data, *line)) {
            sender_updated_data->push_back(*line);
        }
        fname_data.close();
        // insert the most recent transaction on top of the transactions
        sender_updated_data->insert(sender_updated_data->begin() + 5,*transact_send);
        // update balance
        sender_updated_data->at(4) = to_string(*this->getBalance());
    
        // open file for writing, clearing the file
        ofstream user_data(*data,ios::trunc);
        if(!user_data.is_open()){
            cout<<"File couln't be created!";
            sender_updated_data->clear();
            delete sender_updated_data;
            delete line;
            delete data;
            delete person;
            delete transact_send;
            delete transact_receive;
            delete number;
            delete amount;
            sender_updated_data = nullptr;
            transact_send = nullptr;
            transact_receive =nullptr;
            number = nullptr;
            person = nullptr;
            amount = nullptr;
            data = nullptr;
            line = nullptr;
            return;
        }
        // saves updated user infos into the file
        else{create_data(user_data,sender_updated_data);}
        user_data.close();
        delete data;
        // free memory
        sender_updated_data->clear();
        delete sender_updated_data;
        sender_updated_data = nullptr;
    
    

        
        data = new string(*person + ".txt");
        // open to read receiver file
        ifstream rname_data(*data);

        if (!rname_data.is_open()) {
        cerr << "Error opening file: " << data << endl;
            delete line;
            delete person;
            delete transact_send;
            delete transact_receive;
            delete number;
            delete amount;
            transact_send = nullptr;
            transact_receive =nullptr;
            number = nullptr;
            person = nullptr;
            amount = nullptr;
            line = nullptr;
            return;
        }
        // to store each line for receiver
        vector<string>* receiver_updated_data = new vector<string>;

        // read all lines into the vector
        while (getline(rname_data, *line)) {
            receiver_updated_data->push_back(*line);
        }
        fname_data.close();
        receiver_updated_data->insert(receiver_updated_data->begin() + 5,*transact_receive);
        receiver_updated_data->at(4) = to_string(stof(receiver_updated_data->at(4))+*amount);
        // clear the file and get it ready for writing
        ofstream receiver_data(*data,ios::trunc);
        if(!receiver_data.is_open()){
            cout<<"File couln't be created!";
            receiver_updated_data->clear();
            delete receiver_updated_data;
            delete data;
            delete person;
            delete transact_send;
            delete transact_receive;
            delete number;
            delete amount;
            delete line;
            receiver_updated_data=nullptr;
            data=nullptr;
            person=nullptr;
            transact_send = nullptr;
            transact_receive=nullptr;
            number=nullptr;
            amount=nullptr;
            line=nullptr;
            return;
        }
        // update receiver file
        else{create_data(receiver_data,receiver_updated_data);}
        receiver_data.close();
    
    // memory allocation
    receiver_updated_data->clear();
    delete receiver_updated_data;
    delete data;
    delete person;
    delete transact_send;
    delete transact_receive;
    delete number;
    delete amount;
    delete line;
    receiver_updated_data=nullptr;
    data=nullptr;
    person=nullptr;
    transact_send = nullptr;
    transact_receive=nullptr;
    number=nullptr;
    amount=nullptr;
    line=nullptr;
    }
// to check if the person already registered, true if registered
bool Person::check_if_exists(string* name){
    string* data = new string(*name + ".txt");
    ifstream receiver_data(*data);
    delete data;
    data = nullptr;
    return receiver_data.good();
}
// to save person object informations in a file
void Person::create_data(ofstream& os,vector<string> *sender_updated_data){
    for (string attribute : *sender_updated_data) {
            os << attribute << "\n";
        }
}
// registration functionality
void Person::registeration(){
    try{
        int *length = new int;
        string* initial_deposit = new string;
        cout << "Please enter your NAME, AGE(int), PLACE OF BIRTH - respectively: " << endl;
        cin >> *name >> *age >> *place_of_birth;
        if (cin.fail()) {
            cerr << "Invalid input! Age should be integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            delete length;
            delete initial_deposit;
            length = nullptr;
            initial_deposit = nullptr;
            return;}
            // to check if already registered
            if(this->check_if_exists(name)){cout<<"This account already exists"<<endl;return;}
            cout << "Now set your password: " << endl;
            cin >> *password;
            
        while(true){float *amount = new float;
            cout << "How much do you want to deposit: " << endl;
            cin >> *amount;
            if (cin.fail()) {
                cerr << "Invalid input! amount cannot be string." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                delete amount;
                amount = nullptr;}
            // update balance and create transaction
            if(*amount>0){
                this->setBalance(*amount);
                cout<<"Deposit successful"<<endl;
                *initial_deposit = "You deposited "+to_string(*amount);
                delete amount;
                amount = nullptr;
                break;
                
            }
            else{cout<<"Invalid amount"<<endl;
                delete amount;
                amount = nullptr;}
        }
        // Vector to store each line
        vector<string>* sender_updated_data = new vector<string>;
        // store every attribute of the person object
        sender_updated_data->push_back(*this->getName());
        sender_updated_data->push_back(*this->getPassw());
        sender_updated_data->push_back(to_string(*this->getAge()));
        sender_updated_data->push_back(*this->getPob());
        sender_updated_data->push_back(to_string(*this->getBalance()));
        sender_updated_data->push_back(*initial_deposit);
        
        delete initial_deposit;
        initial_deposit = nullptr;
        
        string* data = new string(*this->getName() + ".txt");
        // open file for storing info
        ofstream user_data(*data);
        if(!user_data.is_open()){
        cout<<"File couln't be created!";
            sender_updated_data->clear();
            delete sender_updated_data;
            delete data;
            delete length;
            sender_updated_data = nullptr;
            data = nullptr;
            length = nullptr;
            return;
        }
        // save stored infos in vector to file
        else{create_data(user_data,sender_updated_data);}
        user_data.close();
        
        
        cout << "How many transactions? " << endl;
        cin >> *length;
        // if invalid input
        if (cin.fail()) {
            cerr << "Invalid input! Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sender_updated_data->clear();
            delete sender_updated_data;
            delete length;
            delete data;
            sender_updated_data = nullptr;
            data = nullptr;
            length = nullptr;
            return;}
        // make transaction for the amount of length, if any mistake is made breaks and saves directly
        for(int i =0;i<*length;i++)
            this->maketransaction();
        // memory freeing
        sender_updated_data->clear();
        delete sender_updated_data;
        delete data;
        delete length;
        sender_updated_data = nullptr;
        data = nullptr;
        length = nullptr;
    }catch(...){cerr<<"Invalid!"<<endl;cerr<<"Restarting..."<<endl;}
}
// main menu of the system
void Person::main_menu(){
    int* choice = new int(0);
    bool* alreadyloggedin = new bool(false);
    
    while (*choice != 4) {
        try{
            
            if(*alreadyloggedin==true){cout<<string(30,'-')<<"\n"<<endl;
                cout<<*this<<endl;
                cout<<string(30,'-')<<endl;}
            cout << "Please select a number for the option of:"<<endl;
            cout<<"1- Login"<<endl;
            cout<<"2- Register"<<endl;
            cout<<"3- Make a transaction"<<endl;
            cout<<"4- Exit"<<endl;
            cin >> *choice;
            if (cin.fail()) {
                cerr << "Invalid input! Please enter an integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            else{
                // log in if not already
                if (*choice == 1) {
                    if(*alreadyloggedin==true) cout<<"already logged in"<<endl;
                    else{this->login(); if(*this->getName()!=""){*alreadyloggedin=true;}}}
                // registration if not logged in
                else if (*choice == 2) {
                    if(*alreadyloggedin==true) cout<<"already registered"<<endl;
                    else {Person* newperson = new Person; newperson->registeration(); delete newperson;newperson = nullptr;}}
                // make transaction if logged in
                else if (*choice == 3) {
                    if(*alreadyloggedin==true) this->maketransaction();
                    else cout<<"Haven't logged in yet!"<<endl;}
                else if (*choice == 4) {
                    break;}
                else {
                    cout << "Invalid input! Please enter try again" << endl;}
            }
        // if error occurs restart
        }catch(...){cerr<<"Invalid!"<<endl;cerr<<"Restarting..."<<endl;
            delete alreadyloggedin;
            delete choice;
            alreadyloggedin = nullptr;
            choice = nullptr;}
    }
    
    delete alreadyloggedin;
    delete choice;
    alreadyloggedin = nullptr;
    choice = nullptr;
}
// operator overload to show account info while logged in
ostream& operator<<(ostream &out, Person& person){
    return out << "Welcome " << *person.getName() << "!\n\nYour age is " << *person.getAge()
                   << "\n\nYou were born in " << *person.getPob() << "\n\nYour balance is £" << *person.getBalance()
                   << "\n\nYour recent transactions are\n\n- " << *person.getTransaction(0)
                   << "\n- " << *person.getTransaction(1) << "\n- " << *person.getTransaction(2) <<"\n"<< endl;
}


