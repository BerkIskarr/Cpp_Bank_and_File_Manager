//
//  main.cpp
//  ex2
//
//  Created by Berk Iskar on 24/11/2023.
//a
#include "ReadWords.h"
#include <iostream>



int main(int argc, const char * argv[]) {
    
    // gets file names from the user, such as 'testwords.txt'
    string* saved_file = new string;
    cout<<"Enter books's file name to be analysed"<<endl;
    cin>>*saved_file;
    const char* book_file = saved_file->c_str();
    string* testwords =  new string;
    cout<<"Enter file containing search words"<<endl;
    cin>>*testwords;
    string* output_file = new string;
    cout<<"Enter output file to store the results"<<endl;
    cin>>*output_file;
    
    
    // create object since functions inside are needed
    ReadWords* readwords = new  ReadWords(book_file);
    // create the map
    readwords->create_map(*testwords, book_file);
    // open file for writing and clear in advance
    ofstream output_data(*output_file,ios::trunc);
    if(!output_data.is_open()){
        cout<<"File couldn't be created!";
    }
    // overloaded insertion, writes the bar chart into the output file
    else{output_data<< *readwords;}
    output_data.close();
    
    // open for reading, just to print in terminal
    string temp;
    ifstream read_data(*output_file);
    if(!read_data){cout<<"Failed to open "<<endl;}
    while(!read_data.eof()){
        getline(read_data,temp);
        cout<<temp<<endl;}
    read_data.close();
    
    readwords->close();
    // free memory
    delete output_file;
    delete book_file;
    delete readwords;
    delete testwords;
    output_file= nullptr;
    book_file = nullptr;
    readwords = nullptr;
    testwords = nullptr;
    
    return 0;
}
