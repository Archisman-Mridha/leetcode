#include <bits/stdc++.h>

using namespace std;

class MyQueue {

    private:
        stack<int> primaryStack, secondaryStack;

        int recentlyPushedElement= -1;

    public:
        MyQueue( ) { }

        void push(int x) {
            this->primaryStack.push(x);

            if(this->recentlyPushedElement == -1)
                this->recentlyPushedElement= x;
        }

        int pop( ) {
            int element= -1;

            while(! this->primaryStack.empty( )) {

                element= this->primaryStack.top( );
                this->primaryStack.pop( );

                if(! this->primaryStack.empty( )) {
                    this->recentlyPushedElement= element;

                    this->secondaryStack.push(element);
                }
            }

            while(! this->secondaryStack.empty( )) {
                this->primaryStack.push(this->secondaryStack.top( ));

                this->secondaryStack.pop( );
            }

            if(this->primaryStack.empty( ))
                this->recentlyPushedElement= -1;

            return element;
        }

        int peek( ) {
            return this->recentlyPushedElement;
        }

        bool empty( ) {
            return this->primaryStack.empty( );
        }
};