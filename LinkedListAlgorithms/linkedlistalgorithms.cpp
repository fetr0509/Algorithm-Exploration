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


