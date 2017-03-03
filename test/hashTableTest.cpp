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