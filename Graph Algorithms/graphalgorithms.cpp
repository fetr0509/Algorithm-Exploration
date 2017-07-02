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






