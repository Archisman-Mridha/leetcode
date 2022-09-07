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
        ListNode* startPointer= NULL;
        bool startPointerReachedListMiddle= false;

        bool recursiveHelper(ListNode* endPointer) {

            if(endPointer == NULL)
                return true;

            bool result= recursiveHelper(endPointer->next);

            if(!result || this->startPointerReachedListMiddle)
                return result;

            else {
                bool result= this->startPointer->val == endPointer->val;

                if(this->startPointer == endPointer || this->startPointer->next == endPointer)
                    this->startPointerReachedListMiddle= true;

                else this->startPointer= this->startPointer->next;

                return result;
            }
        }

    public:
        bool isPalindrome(ListNode* head) {
            this->startPointer= head;

            return recursiveHelper(head);
        }
};