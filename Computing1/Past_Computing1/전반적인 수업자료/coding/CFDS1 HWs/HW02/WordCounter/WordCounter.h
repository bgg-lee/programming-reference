#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
// Fill in here

/*
python      c++             characteristics
list        vector          a dynamic ordered list
set         unordered_set   a dynamic set of unordered unique values
dictionary  unordered_map   a dynamic set of (key_value) pairs
deque       list            a doubly linked list
*/
using namespace std;
class WordCounter{
    public:
    int wordCount;
    int CharacterCount;
    unordered_map<std::string, int> wordDict;
    unordered_set<char> notContainSet;
    std::string text;
        void InputText(std::string str);
        int GetWordCount();
        int GetCharacterCount();
        int GetUniqueWordCount();
        int GetWordCount_OneWord(const char *);
        WordCounter();
};