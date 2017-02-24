//
// Created by Benjamin D. Horn on 2/24/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "bst.h"

using testing::Eq;

namespace {
    class classTestBinarySearchTree : public testing::Test {
    public:

    };
}

TEST_F(classTestBinarySearchTree, test1){
    ASSERT_EQ(1,1);
}



int compare(const int& left, const int& right){
    return left - right;
}

int compare(const string& left, const string& right){
    // The string class has a built-in compare function!
    return left.compare(right);
}


TEST_F(classTestBinarySearchTree, test2){
    bst<int> a(compare);
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestBinarySearchTree, test3){
    bst<int> a(compare);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
}

TEST_F(classTestBinarySearchTree, test4){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(4);
    ASSERT_EQ(a.size(), 3);
}
TEST_F(classTestBinarySearchTree, test5){
    bst<int> a(compare);
    a.insert(1);
    a.insert(1);
    a.insert(1);
    ASSERT_EQ(a.size(), 3);
}

TEST_F(classTestBinarySearchTree, test6){
    bst<int> a(compare);
    a.insert(5);
    a.insert(5);
    a.insert(6);
    ASSERT_EQ(a.size(), 3);
    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestBinarySearchTree, test7){
    bst<int> a(compare);
    a.insert(5);
    ASSERT_EQ(a.size(), 1);
    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestBinarySearchTree, test8){
    bst<int> a(compare);
    ASSERT_EQ(a.size(), 0);
    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST_F(classTestBinarySearchTree, test9){
    bst<int> a(compare);
    ASSERT_ANY_THROW(a.getSmallest());
}

TEST_F(classTestBinarySearchTree, test10){
    bst<int> a(compare);
    a.insert(5);
    ASSERT_EQ(a.getSmallest(), 5);
}

TEST_F(classTestBinarySearchTree, test11){
    bst<int> a(compare);
    a.insert(5);
    a.insert(23);
    a.insert(3);
    a.insert(1);
    ASSERT_EQ(a.getSmallest(), 1);
}

TEST_F(classTestBinarySearchTree, test12){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(1);
    a.insert(3);
    ASSERT_EQ(a.getSmallest(), 1);
}

TEST_F(classTestBinarySearchTree, test121){
    bst<int> a(compare);
    a.insert(5);
    bst<int> b(a);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(b.size(), 1);
}

TEST_F(classTestBinarySearchTree, test13){
    bst<int> a(compare);
    a.insert(5);
    bst<int> b(a);
    ASSERT_EQ(a.size(), 1);
    ASSERT_EQ(b.size(), 1);
    a.insert(6);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(b.size(), 1);
}

TEST_F(classTestBinarySearchTree, test14){
    bst<int> a(compare);
    bst<int> b(a);
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 0);
}

TEST_F(classTestBinarySearchTree, test15){
    bst<int> a(compare);
    a.insert(5);
    a.insert(5);
    bst<int> b(a);
    ASSERT_EQ(a.size(), 2);
    ASSERT_EQ(b.size(), 2);
}

TEST_F(classTestBinarySearchTree, test16){
    bst<int> a(compare);
    bst<int> b(compare);
    a.insert(1);
    a = a;
    b = a;
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 1);
}

TEST_F(classTestBinarySearchTree, test17){
    bst<int> a(compare);
    bst<int> b(compare);
    a.insert(1);
    a.insert(2);
    b.insert(3);
    b = a;
    a.clear();
    ASSERT_EQ(a.size(), 0);
    ASSERT_EQ(b.size(), 2);
}

TEST_F(classTestBinarySearchTree, test18){
    bst<int> a(compare);
    ASSERT_TRUE(!a.find(5));
}

TEST_F(classTestBinarySearchTree, test19){
    bst<int> a(compare);
    a.insert(5);
    ASSERT_TRUE(a.find(5));
}

TEST_F(classTestBinarySearchTree, test20){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    ASSERT_TRUE(a.find(6));
}

TEST_F(classTestBinarySearchTree, test21){
    bst<int> a(compare);
    a.insert(5);
    a.insert(8);
    a.insert(7);
    ASSERT_TRUE(a.find(7));
}

TEST_F(classTestBinarySearchTree, test22){
    bst<int> a(compare);
    a.insert(5);
    a.insert(2);
    a.insert(4);
    a.clear();
    ASSERT_TRUE(!a.find(5));
}

TEST_F(classTestBinarySearchTree, test23){
    bst<string> a(compare);
    a.insert("bob");
    a.insert("apple");
    a.insert("binge");
    ASSERT_TRUE(a.find("bob"));
    ASSERT_TRUE(a.find("apple"));
    ASSERT_TRUE(a.find("binge"));
    ASSERT_TRUE(!a.find("broad"));
}
/******
/*
void testInorder1(){
    bst<int> a(compare);
    a.insert(5);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[5]");
}

void testInorder2(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getInOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[5,6,7,8]");
}

void testPreOrder1(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(7);
    a.insert(6);
    a.insert(8);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[5,7,6,8]");
}

void testPreOrder2(){
    bst<int> a(compare);
    a.insert(6);
    string out = a.getPreOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[6]");
}

void testPostorder1(){
    bst<int> a(compare);
    a.insert(5);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[5]");
}

void testPostorder2(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    string out = a.getPostOrder();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    ASSERT_EQ(out, "[8,7,6,5]");
}

void testHeight0() {
    bst<int> a(compare);
    ASSERT_EQ(a.getHeight(), 0);
}

void testHeight1() {
    bst<int> a(compare);
    a.insert(5);
    ASSERT_EQ(a.getHeight(), 0);
}

void testHeight2() {
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    ASSERT_EQ(a.getHeight(), 1);
}
// TODO
void testHeight3(){
    bst<int> a(compare);
    a.insert(20);
    a.insert(2);
    a.insert(7);
    a.insert(5);
    a.insert(8);
    a.insert(21);
    a.insert(22);
    a.insert(24);
    a.insert(23);
    ASSERT_EQ(a.getHeight(), 4);
}

void testFull0() {
    bst<int> a(compare);
    ASSERT_TRUE(a.isFull());
}

void testFull1() {
    bst<int> a(compare);
    a.insert(10);
    ASSERT_TRUE(a.isFull());
}

void testFull2() {
    bst<int> a(compare);
    a.insert(10);
    a.insert(12);
    ASSERT_TRUE(!a.isFull());
}

void testFull3() {
    bst<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    ASSERT_TRUE(a.isFull());
}
// TODO
void testFull4(){
    bst<int> a(compare);
    a.insert(10);
    a.insert(12);
    a.insert(8);
    a.insert(6);
    a.insert(9);
    a.insert(11);
    a.insert(13);
    ASSERT_TRUE(a.isFull());
}

void testBalanced0(){
    bst<int> a(compare);
    ASSERT_TRUE(a.isBalanced());
}

void testBalanced1(){
    bst<int> a(compare);
    a.insert(5);
    ASSERT_TRUE(a.isBalanced());
}

void testBalanced2(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(3);
    ASSERT_TRUE(a.isBalanced());
}

void testBalanced3(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    ASSERT_TRUE(a.isBalanced());
}

void testBalanced4(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(3);
    a.insert(8);
    a.insert(4);
    ASSERT_TRUE(a.isBalanced());
}

void testBalanced5(){
    bst<int> a(compare);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    ASSERT_TRUE(!a.isBalanced());
}
// TODO
void testBalanced6(){
    bst<int> a(compare);
    a.insert(20);
    a.insert(15);
    a.insert(25);
    a.insert(12);
    a.insert(17);
    a.insert(27);
    a.insert(23);
    ASSERT_TRUE(a.isBalanced());
}
*/