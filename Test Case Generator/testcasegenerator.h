#ifndef TESTCASEGENERATOR_H
#define TESTCASEGENERATOR_H

#include <string>
#include "treenode.h"
#include "listnode.h"

int* CreateRandomIntArray(int length);
char* CreateRandomAlphaCharArray(int length);
std::string* CreateRandomStringArray(int stringArrayLength, int maxStringLength);

TreeNode* CreateRandomBinaryTree(int nodeCount);
TreeNode* CreateRandomBinarySearchTree(int nodeCount, int rootPivotValue);
TreeNode* CreateRandomBalancedBinarySearchTree(int nodeCount);

Node* createRandomLinkedList(int length, int valueBound = INT_MAX);

#endif // TESTCASEGENERATOR_H
