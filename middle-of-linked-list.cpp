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
        int nodeCount= 0;

        ListNode* recursiveHelper(ListNode* head, int nodeNumber) {

            if(head == NULL)
                return NULL;

            ++this->nodeCount;

            ListNode* middleNode= recursiveHelper(head->next, nodeNumber + 1);

            if(nodeNumber == ((nodeCount / 2) + 1))
                middleNode= head;
            
            return middleNode;
        }

    public:
        ListNode* middleNode(ListNode* head) {
            return recursiveHelper(head, 1);
        }
};