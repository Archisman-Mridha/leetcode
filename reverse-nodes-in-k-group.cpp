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
        ListNode* nextKGroupNewHead= NULL;

        pair<ListNode*, bool> recursiveHelper(ListNode* previousNode, ListNode* currentNode, int nodeCount, int k) {

            if(currentNode == NULL) {

                if(nodeCount > k)
                    return {NULL, true};

                else return {NULL, false};
            }

            //* deal with the next group of k nodes
            else if(nodeCount > k) {
                this->nextKGroupNewHead= this->recursiveHelper(NULL, currentNode, 1, k).first;

                return {NULL, true};
            }

            pair<ListNode*, bool> result= recursiveHelper(currentNode, currentNode->next, nodeCount + 1, k);

            bool shouldReverse= result.second;

            if(shouldReverse) {
                ListNode* newHead= result.first;

                currentNode->next= previousNode;

                if(nodeCount == 1 && this->nextKGroupNewHead != NULL) {
                    currentNode->next= this->nextKGroupNewHead;

                    this->nextKGroupNewHead= NULL;
                }

                return newHead == NULL ? make_pair(currentNode, true): make_pair(newHead, true);
            }

            else return {currentNode, false};
        }

    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            return this->recursiveHelper(NULL, head, 1, k).first;
        }
};