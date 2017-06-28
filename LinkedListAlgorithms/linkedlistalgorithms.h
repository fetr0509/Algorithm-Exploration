#ifndef LINKEDLISTALGORITHMS_H
#define LINKEDLISTALGORITHMS_H

#include <unordered_map>
#include "listnode.h"

void deleteDuplicates(Node* head);
Node* returnLastKElement(Node* head, int k);
void deleteMiddleNode(Node* middleNode);
void partitionAroundValue(Node* head, int value);
Node* addLinkedLists(Node* listOne, Node* listTwo);

#endif // LINKEDLISTALGORITHMS_H
