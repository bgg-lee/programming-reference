#include "WordCounter.h"
#include <iostream>
#include <string>
// Fill in here

/*
---------------------------------------------------------------------
python      c++             characteristics
---------------------------------------------------------------------
list        vector          a dynamic ordered list
set         unordered_set   a dynamic set of unordered unique values
dictionary  unordered_map   a dynamic set of (key_value) pairs
deque       list            a doubly linked list
---------------------------------------------------------------------

How to compile:
g++ -std=c+11 -o wordcounter main.cpp WordCounter.cpp

How to execute:
./ wordcounter

*/

using namespace std;

WordCounter::WordCounter(){
    wordCount = 0;
    CharacterCount = 0;
    notContainSet.insert(' ');
    notContainSet.insert('.');
    notContainSet.insert(',');
}

void WordCounter::InputText(string str){
    wordCount = 0;
    CharacterCount = 0;
    // 1. store the argument string to 'text'.
    text = str; // in fact this is useless...
    
    // 2. fill in the variable 'CharacterCount'.
    for (auto c:str){
        if (notContainSet.find(c)==notContainSet.end()){ // check if the characther 'c' is in the {' ', ',', '.'}, i.e., the characters we should not contain.
            CharacterCount +=1;}
        }

    // 3. calculate each count of word with filling the unique word dictionary   
    int count = 0;
    int strSize = str.size();
    int start=0, end=0; 
    char prev='a';
    string substring;

    for (auto c:str){
        if (notContainSet.find(prev)==notContainSet.end() && notContainSet.find(c)!=notContainSet.end()){            
            end = count;
            substring = str.substr(start, end-start);
            // if (wordDict.find(substring)==wordDict.end()){wordDict.insert({substring, 0});}
            wordDict[str.substr(start, end-start)] = wordDict[str.substr(start, end-start)] + 1;
        }

        if (notContainSet.find(c)==notContainSet.end() && notContainSet.find(prev)!=notContainSet.end()){
            start = count;}

        count +=1;
        prev = c;
        }

    // 4. fill the variable 'wordCount'. Iterate the dictionary(unordered_map)
    for (auto elem:wordDict){
        wordCount += elem.second;
    }

    }
int WordCounter::GetWordCount(){return wordCount;}
int WordCounter::GetCharacterCount(){return CharacterCount;}
int WordCounter::GetUniqueWordCount(){return wordDict.size();}
int WordCounter::GetWordCount_OneWord(const char * s){
    if (wordDict.find(s)!=wordDict.end()){
        return wordDict[s];
    }
    else return 0;
}