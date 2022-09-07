#include <bits/stdc++.h>

using namespace std;

struct ListNode {

    int val;
    ListNode *next;

    ListNode(int x)
        : val(x), next(nullptr)
    { }
};


//* approach 1 - time complexity= O(m*n) and space complexity= O(1)
class SolutionA {

    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

            while(headA != NULL) {
                ListNode* currentPointer= headB;

                while(currentPointer != NULL) {

                    if(headA == currentPointer)
                        return headA;

                    currentPointer= currentPointer->next;
                }

                headA= headA->next;
            }

            return NULL;
        }
};

//* approach 2 - time complexity= O(m + n) and space complexity= O(n)
class SolutionB {

    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

            unordered_set<ListNode*> set= { };

            while(headA != NULL) {
                set.insert(headA);

                headA= headA->next;
            }

            while(headB != NULL) {
                if(set.find(headB) != set.end( ))
                    return headB;

                else headB= headB->next;
            }

            return NULL;
        }
};

//* approach 3 - time complexity= O(m + n) and space complexity= O(1)
class SolutionC {

    private:
        int getListLength(ListNode* head) {
            int length= 0;

            ListNode* currentNode= head;

            while(currentNode != NULL) {
                length++;

                currentNode= currentNode->next;
            }

            return length;
        }

    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            int listALength= getListLength(headA), listBLength= getListLength(headB);

            int lengthDifference= abs(listALength - listBLength);

            ListNode* largerList= listALength > listBLength ? headA: headB,
                *smallerList= largerList == headA ? headB: headA;

            for(int i= 0; i < lengthDifference; i++)
                largerList= largerList->next;

            while(smallerList != NULL) {

                if(largerList == smallerList)
                    return smallerList;

                else {
                    largerList= largerList->next;
                    smallerList= smallerList->next;
                }
            }

            return NULL;
        }
};