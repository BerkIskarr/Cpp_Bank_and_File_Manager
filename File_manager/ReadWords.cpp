// replace my comments with your own
// except: you can use my comment about one-word lookahead

// you may modify the code that I have supplied if you wish




#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

string removePunct(string word)
{
    // delete punctuations from the beginning of the word
    for (int i = 0; i<word.size();i++){
        bool* ispun=new bool(ispunct(word[i]));
        if(*ispun==true) word.erase(i,1);
        else if(*ispun==false) break;
        delete ispun;
    }
    // delete punctuations from the end of the word (I thought size_t not allowed, so not used)
    for (int i = word.size() - 1; i >= 0; i--){
        bool* ispun=new bool(ispunct(word[i]));
        if(*ispun==true) word.erase(i,1);
        else if(*ispun==false) break;
        delete ispun;}
    
  return word;
}
// constructor
ReadWords::ReadWords(const char *fname)
{   wordfile.open(fname);//open file
    if (!wordfile)
    {   cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}
// returns the next simplified word
string ReadWords::getNextWord()
{
  string word = nextword;
  wordfile >> nextword;

    if (wordfile.eof())
       eoffound = true;
    // remove punctuations
    word = removePunct(word);
      // if number exists return empty(isalpha can be used instead as well)
      for(char& character: word){
          if(isdigit(character)) return "";}
    // convert word to lowercase
    for (char &character : word) {
            character = tolower(character);
        }
    // if cointains one digit return empty
    if (word.size() < 2)return "";
    
    return word;
}
// check if end is reached
bool ReadWords::isNextWord()
{return !eoffound;
}
// close the file
void ReadWords::close()
{wordfile.close();
}
// overload to insert bar chart
ostream& operator<<(ostream &out, ReadWords& readwords){
    string each_bar;
    // overall word count
    int countall = readwords.countAll(1);
    int highestsize = 0;
    // get the longest word- for better design and as size_t not allowed, loses precision
    for (const auto& p : readwords.getMap()) {
        if(highestsize < p.first.size()){
            highestsize = p.first.size();
        }
    }
    // create the bar of the bar chart for each word in search word file
    out<<"Word Occurrence:"<<endl;
    for( auto& pair: readwords.getMap()){
           each_bar = pair.first+string(highestsize - pair.first.size()+1, ' ')+string(pair.second,'=')+" "+to_string(pair.second)+" ("+to_string(100*(double(pair.second)/countall))+"%)";
           out <<each_bar<<endl;
       }
    return out;
}
// count only the specific word
int ReadWords::checkWord(string word,int initial){
    int count= initial;
    // check each proper word
    while (!wordfile.eof()){ string nextword = getNextWord();
        if (nextword==word) {
            count++;
        }}
        
    return count-1;
}
// getter map
map<string,int> ReadWords::getMap(){return word_with_count;}

// create map for storing search words and their quantities
void ReadWords::create_map(string testfilename,const char* bookfilename){
    // open for reading
    ifstream testfile(testfilename);
    string word;
    while (testfile >> word) {
        // create new object to restart the book
        ReadWords* readwords = new ReadWords(bookfilename);
        this->word_with_count[word] = readwords->checkWord(word, 1);
        readwords->close();
        delete readwords;
    }
    testfile.close();
}
// counts all words- doesn't count emails
double ReadWords::countAll(double initial){
    double count= initial;
    while (!wordfile.eof()){
        if (!getNextWord().empty()) {
        count++;
        }
    }
    return count-1;
}

