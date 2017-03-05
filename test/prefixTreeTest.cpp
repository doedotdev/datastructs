//
// Created by Benjamin D. Horn on 3/2/17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "prefixTree.h"

using namespace std;


using testing::Eq;

namespace {
    class classTestPrefixTree : public testing::Test {
    public:

    };
}

TEST_F(classTestPrefixTree, test1){
    prefixTree a;
    ASSERT_EQ(a.sizeN(), 1);
    ASSERT_EQ(a.sizeS(), 0);
}

TEST_F(classTestPrefixTree, test2){
    prefixTree a;
    a.insert("one");
    a.insert("two");
    prefixTree b(a);
    ASSERT_EQ(a.getNumNodes(), b.getNumNodes());
    ASSERT_EQ(b.isStored("two"), true);
    ASSERT_EQ(a.isStored("two"), true);
}

TEST_F(classTestPrefixTree, test3){
    prefixTree a;
    a.insert("red");
    a.insert("blue");
    prefixTree b;
    b = a;
    ASSERT_EQ(a.getNumNodes(), b.getNumNodes());
    ASSERT_EQ(b.isStored("red"), true);
    ASSERT_EQ(a.isStored("red"), true);
}

TEST_F(classTestPrefixTree, test4){
    prefixTree a;
    a.insert("copy");
    a = a;
    ASSERT_EQ(a.isStored("copy"), true);
}

TEST_F(classTestPrefixTree, test5){
    prefixTree a;
    a.insert("a");
    prefixTree b;
    b.insert("b");
    b = a;
    ASSERT_EQ(a.getNumNodes(), 2);
    ASSERT_EQ(b.getNumNodes(), 2);
}

TEST_F(classTestPrefixTree, test6){
    prefixTree a;
    a.insert("a");
    ASSERT_EQ(a.sizeN(), 2);
    ASSERT_EQ(a.sizeS(), 1);
}

TEST_F(classTestPrefixTree, test7){
    prefixTree a;
    a.insert("cat");
    ASSERT_EQ(a.sizeN(), 4);
    ASSERT_EQ(a.sizeS(), 1);
}

TEST_F(classTestPrefixTree, test8){
    prefixTree a;
    a.insert("dog");
    a.insert("do");
    ASSERT_EQ(a.sizeN(), 4);
    ASSERT_EQ(a.sizeS(), 2);
}

TEST_F(classTestPrefixTree, test9){
    prefixTree a;
    a.insert(",");
    a.insert(" ");
    ASSERT_EQ(a.sizeN(), 2);
    ASSERT_EQ(a.sizeS(), 1);
}

TEST_F(classTestPrefixTree, test10){
    prefixTree a;
    a.insert("12");
    a.insert("Ab");
    ASSERT_EQ(a.sizeN(), 5);
    ASSERT_EQ(a.sizeS(), 2);
}

TEST_F(classTestPrefixTree, test11){
    prefixTree a;
    a.insert("a");
    a.insert("aa");
    a.insert("aaa");
    ASSERT_EQ(a.sizeN(), 4);
    ASSERT_EQ(a.sizeS(), 3);
}

TEST_F(classTestPrefixTree, test12){
    prefixTree a;
    ASSERT_EQ(a.getHeight(), 0);
}

TEST_F(classTestPrefixTree, test13){
    prefixTree a;
    a.insert("a");
    ASSERT_EQ(a.getHeight(), 1);
}

TEST_F(classTestPrefixTree, test14){
    prefixTree a;
    a.insert("a");
    a.insert("aa");
    ASSERT_EQ(a.getHeight(), 2);
}

TEST_F(classTestPrefixTree, test15){
    prefixTree a;
    a.insert("a");
    a.insert("b");
    a.insert("c");
    ASSERT_EQ(a.getHeight(), 1);
}

TEST_F(classTestPrefixTree, test16){
    prefixTree a;
    a.insert("123456789");
    ASSERT_EQ(a.getHeight(), 9);
}

TEST_F(classTestPrefixTree, test17){
    prefixTree a;
    a.insert("a");
    a.insert("ab");
    a.insert("bc");
    ASSERT_EQ(a.getHeight(), 2);
}

TEST_F(classTestPrefixTree, test18){
    prefixTree a;
    ASSERT_EQ(a.getNumNodes(), 1);
}

TEST_F(classTestPrefixTree, test19){
    prefixTree a;
    a.insert("b");
    ASSERT_EQ(a.getNumNodes(), 2);
}

TEST_F(classTestPrefixTree, test20){
    prefixTree a;
    a.insert("a");
    a.insert("b");
    a.insert("ab");
    ASSERT_EQ(a.getNumNodes(), 4);
}

TEST_F(classTestPrefixTree, test21){
    prefixTree a;
    ASSERT_EQ(a.getNumStored(), 0);
}

TEST_F(classTestPrefixTree, test22){
    prefixTree a;
    a.insert("charizard");
    ASSERT_EQ(a.getNumStored(), 1);
}

TEST_F(classTestPrefixTree, test23){
    prefixTree a;
    a.insert("abra");
    a.insert("ab");
    ASSERT_EQ(a.getNumStored(), 2);
}

TEST_F(classTestPrefixTree, test24){
    prefixTree a;
    a.insert("cat");
    vector<string> store = a.getAllStored();
    ASSERT_EQ(store[0], "cat");
}

TEST_F(classTestPrefixTree, test25){
    prefixTree a;
    a.insert("dog");
    a.insert("rabbit");
    a.insert("demon");
    vector<string> store = a.getAllStored();
    ASSERT_EQ(store[0], "demon");
    ASSERT_EQ(store[1], "dog");
    ASSERT_EQ(store[2], "rabbit");
}

TEST_F(classTestPrefixTree, test26){
    prefixTree a;
    a.insert("a");
    a.insert("aa");
    a.insert("aaa");
    vector<string> store = a.getAllStored();
    ASSERT_EQ(store[0], "a");
    ASSERT_EQ(store[1], "aa");
    ASSERT_EQ(store[2], "aaa");
}

TEST_F(classTestPrefixTree, test27){
    prefixTree a;
    a.insert("cat");
    vector<string> store = a.getWPrefix("c");
    ASSERT_EQ(store[0], "cat");
}

TEST_F(classTestPrefixTree, test28){
    prefixTree a;
    a.insert("this");
    a.insert("that");
    a.insert("these");
    a.insert("those");
    vector<string> store = a.getWPrefix("th");
    ASSERT_EQ(store[0], "that");
    ASSERT_EQ(store[1], "these");
    ASSERT_EQ(store[2], "this");
    ASSERT_EQ(store[3], "those");
}

TEST_F(classTestPrefixTree, test29){
    prefixTree a;
    a.insert("dog");
    a.insert("cat");
    vector<string> store = a.getWPrefix("d");
    ASSERT_EQ(store[0], "dog");
    ASSERT_EQ(store.size(), 1);
}

TEST_F(classTestPrefixTree, test30){
    prefixTree a;
    int num = a.getNumWPrefix("python");
    ASSERT_EQ(num, 0);
}

TEST_F(classTestPrefixTree, test31){
    prefixTree a;
    a.insert("holy hand grenade");
    int num = a.getNumWPrefix("holy");
    ASSERT_EQ(num, 1);
}

TEST_F(classTestPrefixTree, test32){
    prefixTree a;
    a.insert("Queen");
    a.insert("query");
    a.insert("kiwi");
    int num = a.getNumWPrefix("q");
    ASSERT_EQ(num, 2);
}


TEST_F(classTestPrefixTree, test33){
    prefixTree a;
    ASSERT_EQ(a.isStored("a"), false);
}


TEST_F(classTestPrefixTree, test34){
    prefixTree a;
    a.insert("stock");
    ASSERT_EQ(a.isStored("stock"), true);
}

TEST_F(classTestPrefixTree, test35){
    prefixTree a;
    a.insert("thats");
    a.insert("no");
    a.insert("ordinary");
    a.insert("rabbit");
    ASSERT_EQ(a.isStored("thats"), true);
    ASSERT_EQ(a.isStored("no"), true);
    ASSERT_EQ(a.isStored("ordinary"), true);
    ASSERT_EQ(a.isStored("rabbit"), true);
    ASSERT_EQ(a.isStored("run away"), false);
}

TEST_F(classTestPrefixTree, test36){
    prefixTree a;
    a.insert("word");
    ASSERT_EQ(a.isStored("wor"), false);
}

TEST_F(classTestPrefixTree, test37){
    //prefixTreeSuggestInterface a;
    ASSERT_TRUE(true);
}