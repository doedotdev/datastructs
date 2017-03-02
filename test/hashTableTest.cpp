//
// Created by Benjamin D. Horn on 2/24/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "hashTable.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

using testing::Eq;

namespace {
    class classTestHashTable : public testing::Test {
    public:

    };
}


const int SIZE = 2000;  // Size of Linked List to test speed.

unsigned int hash(const int& number){ // hash function
    return abs(number);
}


unsigned int hash(const string& word){ // hash function
    unsigned int ret = 0;
    for(unsigned int i = 0; i < word.length(); i++){
        ret += word[i] * i + i * 47;
    }
    return ret;
}

TEST_F(classTestHashTable, test1){
    HashTable<int> a(::hash, 5);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test2){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test3){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(1);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test4){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(15);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test5){
    HashTable<int> a(::hash, 1);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
    ASSERT_ANY_THROW(a.insert(2));
}

TEST_F(classTestHashTable, test6){
    HashTable<int> a(::hash, 5);
    a.insert(0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    ASSERT_EQ(a.size(), 5);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test7){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(classTestHashTable, test8){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(1);
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test9){
    HashTable<int> a(::hash, 5);
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test10){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 5);
}

TEST_F(classTestHashTable, test11){
    HashTable<int> a(::hash, 2);
    a.insert(2);
    a.insert(1);
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 2);
}

TEST_F(classTestHashTable, test12){
    HashTable<int> a(::hash, 1);
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(a.capacity(), 1);
}

TEST_F(classTestHashTable, test13){
    HashTable<int> a(::hash,5);
    a.insert(5);
    HashTable<int> b(a);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(b.size(), 1);
}

TEST_F(classTestHashTable, test14){
    HashTable<int> a(::hash,5);
    HashTable<int> b(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(classTestHashTable, test15){
    HashTable<int> a(::hash,5);
    a.insert(5);
    a.insert(8);
    a.insert(7);
    HashTable<int> b(a);
    ASSERT_EQ(a.size(), 3);
    ASSERT_EQ(b.size(), 3);
}

TEST_F(classTestHashTable, test16){
    HashTable<int> a(::hash,5);
    a.insert(5);
    HashTable<int> b = a;
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(b.size(), 1);
}

TEST_F(classTestHashTable, test17){
    HashTable<int> a(::hash,5);
    HashTable<int> b = a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(classTestHashTable, test18){
    HashTable<int> a(::hash,5);
    a.insert(5);
    a.insert(2);
    HashTable<int> b = a;
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(b.size(), 2);
}

TEST_F(classTestHashTable, test19){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    ASSERT_TRUE(a.find(5));
}

TEST_F(classTestHashTable, test20){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    ASSERT_TRUE(!a.find(4));
}

TEST_F(classTestHashTable, test21){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    ASSERT_TRUE(!a.find(15));
}

TEST_F(classTestHashTable, test22){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(10);
    ASSERT_TRUE(a.find(10));
}

TEST_F(classTestHashTable, test23){
    HashTable<int> a(::hash, 5);
    a.insert(0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    ASSERT_TRUE(a.find(4));
}

TEST_F(classTestHashTable, test24){
    HashTable<int> a(::hash, 5);
    ASSERT_TRUE(!a.find(5));
}

TEST_F(classTestHashTable, test25){
    HashTable<int> a(::hash, 5);
    a.remove(5);
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestHashTable, test26){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.remove(5);
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestHashTable, test27){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.insert(10);
    a.remove(5);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(classTestHashTable, test28){
    HashTable<int> a(::hash, 5);
    a.insert(0);
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.remove(5);
    ASSERT_EQ(a.size(), 5);
}

TEST_F(classTestHashTable, test29){
    HashTable<int> a(::hash, 1);
    a.insert(5);
    a.remove(5);
    a.insert(4);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(classTestHashTable, test30){
    HashTable<int> a(::hash, 5);
    a.insert(5);
    a.remove(5);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
}

// Test Type T Exercises


TEST_F(classTestHashTable, test31){
    HashTable<string> a(::hash, 10);
    a.insert("bob");
    a.insert("bib");
    a.insert("bab");
    a.remove("bla");
    a.remove("bab");
    a.remove("bib");
    a.remove("bob");
    ASSERT_EQ(a.size(), 0);
    ASSERT_TRUE(! a.find("bob"));
}

TEST_F(classTestHashTable, testFuzz){
    HashTable<int> a(::hash, SIZE);
    for(unsigned int i = 0; i < SIZE; i++){
        a.insert(SIZE * i);
        ASSERT_EQ(a.size(), i+1);
    }
    ASSERT_EQ(a.size(), SIZE);
    for(unsigned int i = 0; i < SIZE; i++){
        a.remove(SIZE * i);
        ASSERT_EQ(a.size(), SIZE - i - 1);
    }
    ASSERT_EQ(a.size(), 0);
}

// dictionary tests

unsigned int strlen(string str){
    unsigned int sz = str.size();
    return sz/1;
}

// Deletion Check
int del(string word1, string word2){
    int count = 0;
    for(unsigned int i = 0; i < word1.length(); i++){
        if(word2[count] == word1[i]){
            count++;
        }
    }
    if(count == strlen(word2)){
        return 1;
    }
    else{
        return 0;
    }
}

// Good hash function for strings
unsigned int hash2(const string& thing){
    unsigned int ret = 7;
    for(unsigned int i = 0; i < thing.length(); i++){
        ret = ret * 31 * thing[i];
        // 31 is the next prime above 26
    }
    return ret;
}

// Substitution Check
int sub(string word1, string word2){
    int sims = 0;
    for(unsigned int i = 0; i < word1.length(); i++){
        if(word1[i] == word2[i]){
            sims++;
        }
    }
    if(sims == strlen(word1)-1){
        return 2;
    }
    else{
        return 0;
    }
}

// Addition Check
int added(string word1, string word2){
    int count = 0;
    for(unsigned int i = 0; i < word2.length(); i++){ // abc abdc
        if(word1[count] == word2[i]){
            count++;
        }
    }
    if(count == word1.length()){
        return 3;
    }
    else{
        return 0;
    }
}

// Determines if two words are similar
int findSim(string word1, string word2){
    if(strlen(word1) == strlen(word2)+1){ // Deletion: 1
        return del(word1, word2);
    }
    else if(strlen(word1) == strlen(word2)){ // Substitution: 2
        return sub(word1, word2);
    }
    else if(strlen(word1) == strlen(word2)-1){ // Addition: 3
        return added(word1, word2);
    }
    else{
        return 0; // Not Similar: 0
    }
}

void printWhile(string &word, vector<string> &all_words, HashTable<string> &dictionary){
    cout << "Enter word: ";
    cin >> word;
    if(word == "q"){
        return;
    }
    if(dictionary.find(word) == true){
        cout << "FOUND!" << endl;
    }
    else{
        cout << "Not Found." << endl;
    }
    cout << "Similar Words: \t";
    for(unsigned int i = 0; i < all_words.size(); i++){
        int res = findSim(word, all_words[i]);
        if(res == 0){

        }
        else{
            cout << all_words[i] << " ";
        }
    }
    cout << endl;
}

TEST_F(classTestHashTable, testDictionary){
    unsigned int capacity = 200000;
    HashTable<string> dictionary(::hash, capacity);
    vector<string> all_words;

    fstream file;
    file.open("speeches.txt", std::fstream::in);
    if(file.fail()) {
        cout << "Error in opening file " << endl;
        ASSERT_EQ(1,0); // file could not open
    }
    string line;
    getline(file,line);
    while(file) {
        string word = line;
        dictionary.insert(word);
        if(word[0] > 90 || word[0] < 65){
            all_words.push_back(word);
        }
        getline(file,line);
    }
    cout << "Words Loaded: " << dictionary.size() << endl;
    string word = "";
    while(word != "q"){
        printWhile(word, all_words, dictionary);
    }
    ASSERT_EQ(1,1);
}