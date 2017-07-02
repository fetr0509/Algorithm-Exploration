#include "graphalgorithms.h"

bool findPathExists(TreeNode* root, int data)
{
    if(!root)
        return false;

    std::queue<TreeNode*> BFSQueue;
    BFSQueue.push(root);

    while(!BFSQueue.empty())
    {
        TreeNode* nextNode = BFSQueue.front();
        BFSQueue.pop();

        if(nextNode->value == data)
            return true;

        if(nextNode->leftLeaf)
            BFSQueue.push(nextNode->leftLeaf);
        if(nextNode->rightLeaf)
            BFSQueue.push(nextNode->rightLeaf);
    }
    return false;
}

TreeNode* sortedArraytoTree(int sorted[], int min, int max)
{
    if(max < min)
        return nullptr;

    TreeNode* newNode = new TreeNode;
    int pivot = (min+max)/2;
    newNode->value = sorted[pivot];

    newNode->leftLeaf = sortedArraytoTree(sorted, min, pivot-1);
    newNode->rightLeaf = sortedArraytoTree(sorted, pivot+1, max);

    return newNode;
}

std::vector<Node*> createListsFromDepth(TreeNode* root)
{
    std::vector<Node*> depthVector;

    if(root == nullptr)
        return depthVector;

    std::queue<TreeNode*> currentQ;
    currentQ.push(root);

    while (!currentQ.empty())
    {
        std::queue<TreeNode*> nextQ;
        Node* startNode = new Node;
        Node* tempNode = startNode;

        while (!currentQ.empty())
        {
            TreeNode* currentNode = currentQ.front();
            currentQ.pop();
            tempNode->data = currentNode->value;
            Node* nextNode = new Node;
            tempNode->next = nextNode;
            tempNode = tempNode->next;

            if(currentNode->leftLeaf)
                nextQ.push(currentNode->leftLeaf);
            if(currentNode->rightLeaf)
                nextQ.push(currentNode->rightLeaf);
        }
        tempNode = nullptr;
        currentQ = nextQ;
        depthVector.push_back(startNode);
    }

    return depthVector;
}


