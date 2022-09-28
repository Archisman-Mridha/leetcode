#include <bits/stdc++.h>

class Node {

    public:
        Node* children[26];

        int startsWith, endsWith;

        Node( )
            : startsWith(0), endsWith(0)
        {
            for(int i= 0; i< 26; i++)
                children[i]= nullptr;
        }
};

class Trie {

    private:
        Node* rootNode;

    public:
        Trie( )
            : rootNode(new Node( ))
        { }

        void insert(string &word) {

            Node* currentNode= this->rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word.at(i) - 'a';

                if(currentNode->children[index] == nullptr)
                    currentNode->children[index]= new Node( );

                currentNode->startsWith++;

                currentNode= currentNode->children[index];
            }

            currentNode->endsWith++;
        }

        int countWordsEqualTo(string &word) {

            Node* currentNode= this->rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word.at(i) - 'a';

                if(currentNode->children[index] == nullptr)
                    return 0;

                currentNode= currentNode->children[index];
            }

            return currentNode->endsWith;
        }

        int countWordsStartingWith(string &word) {

            Node* currentNode= this->rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word.at(i) - 'a';

                if(currentNode->children[index] == nullptr)
                    return 0;

                currentNode= currentNode->children[index];
            }

            return currentNode->startsWith;
        }

        void erase(string &word) {

            Node *currentNode= this->rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word.at(i) - 'a';

                //* store the parent node of the current character
                Node* parentNode= currentNode;

                currentNode= currentNode->children[index];

                currentNode->startsWith--;

                if(currentNode->startsWith == 0)
                    parentNode->children[index]= nullptr;
            }

            currentNode->endsWith--;
        }
};
