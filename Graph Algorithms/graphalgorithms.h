#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

#include "treenode.h"
#include <queue>
#include <math.h>
#include "listnode.h"

bool findPathExists(TreeNode* root, int data);
TreeNode* sortedArraytoTree(int sorted[], int min, int max);
std::vector<Node*> createListsFromDepth(TreeNode* root);
bool isTreeBalanced(TreeNode* root);

#endif // GRAPHALGORITHMS_H
