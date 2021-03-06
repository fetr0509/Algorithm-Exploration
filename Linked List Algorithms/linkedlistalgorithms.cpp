#include "linkedlistalgorithms.h"

void deleteDuplicates(Node* head)
{
    Node* previousNode = NULL;
    Node* tempHead = head;
    std::unordered_map<int,int> duplicateMap;

    while (tempHead != NULL)
    {
        if((++duplicateMap[tempHead->data]) > 1)
        {
            Node* nodeToDelete = tempHead;
            previousNode->next = tempHead->next;
            delete nodeToDelete;
        } else {
            previousNode = tempHead;
        }
        tempHead = previousNode->next;
    }
}

Node* returnLastKElement(Node* head, int k)
{
    Node* runner = head;
    Node* current = head;

    for(int count = 0; count < k; count++)
    {
        if(runner == NULL)
            return current;
        else
            runner = runner->next;
    }

    while (runner != NULL)
    {
        runner = runner->next;
        current = current->next;
    }
    return current;
}

void deleteMiddleNode(Node* middleNode)
{
    Node* tempNext = middleNode->next;
    middleNode->data = tempNext->data;
    middleNode->next = tempNext->next;
    delete tempNext;
}

void partitionAroundValue(Node* head, int value)
{
    Node* smaller = head;
    int smallerPosition = 0;
    Node* bigger = head;
    int biggerPosition = 0;

    while(bigger != NULL && smaller != NULL)
    {
        while (bigger->data < value)
        {
                bigger = bigger->next;
                biggerPosition++;
                if(bigger == NULL)
                    return;
        }

        while (smaller->data >= value)
        {
                smaller = smaller->next;
                smallerPosition++;
                if(smaller == NULL)
                    return;
        }
        if(smallerPosition > biggerPosition)
        {
            int temp = bigger->data;
            bigger->data = smaller->data;
            smaller->data = temp;
        } else {
            smaller = smaller->next;
            bigger = bigger->next;
        }
    }
}

Node* addLinkedLists(Node* listOne, Node* listTwo)
{
    Node* runnerOne = listOne;
    Node* runnerTwo = listTwo;
    Node* newList = NULL;
    Node* currentNode;
    int carry = 0;

    while(runnerOne != NULL && runnerTwo != NULL)
    {
        if(newList == NULL)
        {
            newList = new Node;
            currentNode = newList;
        }
        else
        {
            Node* newNode = new Node;
            currentNode->next = newNode;
            currentNode = currentNode->next;
        }

        int sum = runnerOne->data + runnerTwo->data + carry;
        if(sum > 9)
        {
            currentNode->data = sum - 10;
            carry = 1;
        }
        else
        {
            currentNode->data = sum;
            carry = 0;
        }
        runnerOne = runnerOne->next;
        runnerTwo = runnerTwo->next;

    }
    if(runnerOne != NULL)
    {
        currentNode->next = runnerOne;
    }
    if(runnerTwo != NULL)
    {
        currentNode->next = runnerTwo;
    }
    return newList;
}
