#include "testcasegenerator.h"
#include <random>

int* CreateRandomIntArray(int length)
{
    int* intArray = new int[length];
    int* tempPointer = intArray;

    for(int count = 0; count < length; count++)
    {
        *tempPointer = rand();
        tempPointer++;
    }
    return intArray;
}

char* CreateRandomAlphaCharArray(int length)
{
    char* charArray = new char[length+1];
    char* tempPointer = charArray;

    for(int count = 0; count < length; count++)
    {
        *tempPointer = (rand() % 26) + 'a';
        tempPointer++;
    }
    *tempPointer = '\0';
    return charArray;
}

std::string* CreateRandomStringArray(int stringArrayLength, int maxStringLength)
{
    std::string* stringArray = new std::string[stringArrayLength];
    std::string* tempStringPointer = stringArray;

    for(int stringArrayCount = 0; stringArrayCount < stringArrayLength; stringArrayCount++)
    {
        int stringLength = rand() % maxStringLength;
        char* charArray = new char[stringLength+1];
        char* tempCharPointer = charArray;

        for(int count = 0; count < stringLength; count++)
        {
            *tempCharPointer = (rand() % 26) + 'a';
            tempCharPointer++;
        }
        *tempCharPointer = '\0';
        *tempStringPointer = charArray;
        tempStringPointer++;
    }

    return stringArray;
}

TreeNode* CreateRandomBinaryTree(int nodeCount)
{
    TreeNode* newNode = new TreeNode;
    newNode->value = rand() % 1000;
    if(nodeCount != 0)
    {
        int letfNodeCount = rand() % (nodeCount-1);
        int rightNodeCount = nodeCount - letfNodeCount;
        newNode->leftLeaf = CreateRandomBinaryTree(letfNodeCount);
        newNode->rightLeaf = CreateRandomBinaryTree(rightNodeCount);
    }
    else
    {
        newNode->leftLeaf = NULL;
        newNode->rightLeaf = NULL;
    }
    return newNode;
}

TreeNode* CreateRandomBinarySearchTree(int nodeCount, int rootPivotValue)
{
    TreeNode* newNode = new TreeNode;
    newNode->value = rootPivotValue;
    if(nodeCount != 0)
    {
        int letfNodeCount = rand() % (nodeCount-1);
        int rightNodeCount = nodeCount - letfNodeCount;
        newNode->leftLeaf = CreateRandomBinarySearchTree(letfNodeCount,rand() % (rootPivotValue-1));
        newNode->rightLeaf = CreateRandomBinarySearchTree(rightNodeCount,(rand() % (rootPivotValue)) + (rootPivotValue+1));
    }
    else
    {
        newNode->leftLeaf = NULL;
        newNode->rightLeaf = NULL;
    }
    return newNode;
}

TreeNode* CreateRandomBalancedBinarySearchTree(int NodeCount)
{

}

Node* createRandomLinkedList(int length, int valueBound)
{
    if (length == 0)
        return NULL;

    Node* head = new Node;
    Node* CurrentNode = head;
    CurrentNode->data = rand() % valueBound;

    for(int count = 0; count < length-1; count++)
    {
        Node* nextNode = new Node;
        nextNode->data = rand() % valueBound;
        CurrentNode->next = nextNode;
        CurrentNode = CurrentNode->next;
    }
    CurrentNode->next = NULL;
    return head;
}































