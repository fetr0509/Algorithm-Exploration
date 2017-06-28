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


