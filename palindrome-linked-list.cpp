#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x= 0)
        : val(x), next(nullptr)
    { }
};

class Solution {

    private:
        bool isMiddleReached= false;
        ListNode *frontTracker;

        bool recursiveHelper(ListNode *head) {

            if(head == NULL)
                return true;

            bool recursionResult= recursiveHelper(head->next);

            if(!recursionResult)
                return false;

            else if(this->isMiddleReached)
                return true;

            else if(this->frontTracker->val == head->val) {

                if(this->frontTracker == head || this->frontTracker->next == head)
                    this->isMiddleReached= true;

                else this->frontTracker= this->frontTracker->next;

                return true;
            }

            else return false;
        }

    public:
        bool isPalindrome(ListNode *head) {

            if(head->next == NULL)
                return true;

            this->frontTracker= head;

            return recursiveHelper(head->next);
        }
};