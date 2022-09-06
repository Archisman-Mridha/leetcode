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

        ListNode* recursiveHelper(ListNode* head, int nodeNumber, int targetNodeNumber) {

            if(head == NULL)
                return NULL;

            ++this->nodeCount;

            ListNode* next= recursiveHelper(head->next, nodeNumber + 1, targetNodeNumber);
            head->next= next;

            if(this->nodeCount - targetNodeNumber + 1 == nodeNumber)
                return head->next;

            else return head;
        }

    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            return recursiveHelper(head, 1, n);
        }
};