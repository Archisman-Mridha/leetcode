#include <bits/stdc++.h>

using namespace std;

class MyStack {

    private:
        queue<int> queue_1, queue_2;
        bool isUsingQueue1= true;

        int recentlyPushedElement= -1;

    public:
        MyStack( ) { }

        void push(int x) {

            if(this->isUsingQueue1)
                this->queue_1.push(x);

            else this->queue_2.push(x);

            this->recentlyPushedElement= x;
        }

        int pop( ) {
            int upcomingTopElement= -1, element= -1;

            if(this->isUsingQueue1) {
                while(! this->queue_1.empty( )) {

                    element= this->queue_1.front( );
                    this->queue_1.pop( );

                    if(! this->queue_1.empty( )) {
                        upcomingTopElement= element;

                        this->queue_2.push(element);
                    }
                }
            }

            else {
                while(! this->queue_2.empty( )) {

                    element= this->queue_2.front( );
                    this->queue_2.pop( );

                    if(! this->queue_2.empty( )) {
                        upcomingTopElement= element;

                        this->queue_1.push(element);
                    }
                }
            }

            this->isUsingQueue1= !this->isUsingQueue1;
            this->recentlyPushedElement= upcomingTopElement;

            return element;
        }

        int top( ) {
            return this->recentlyPushedElement;
        }

        bool empty( ) {

            if(this->isUsingQueue1)
                return this->queue_1.empty( );

            else return this->queue_2.empty( );
        }
};