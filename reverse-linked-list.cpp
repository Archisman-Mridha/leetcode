#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr)
    { }
};

class Solution {

    private:
        ListNode* recursiveHelper(ListNode *previousNode, ListNode *currentNode) {

            if(currentNode == NULL)
                return previousNode;

            ListNode* newHead= recursiveHelper(currentNode, currentNode->next);

            currentNode->next= previousNode;

            if(previousNode != NULL)
                previousNode->next= NULL;

            return newHead;
        }

    public:
        ListNode* reverseList(ListNode *head) {
            return recursiveHelper(NULL, head);
        }
};

int main( ) {

    exit(0);
}