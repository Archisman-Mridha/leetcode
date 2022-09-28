#include <bits/stdc++.h>

using namespace std;

//! currently this algorithm is not correct

struct Node {
    Node* children[26];
    bool isParentNodeMarkingACompleteWord;

    Node( )
        : isParentNodeMarkingACompleteWord(false)
    {

        for(int i= 0; i< 26; i++)
            this->children[i]= nullptr;
    }

    ~Node( ) {

        for(int i= 0; i< 26; i++)
            delete this->children[i];
    }
};

class WordDictionary {

    private:
        Node* rootNode;

    public:
        WordDictionary( )
            : rootNode(new Node( ))
        { }

        ~WordDictionary( ) {
            delete this->rootNode;
        }

        void addWord(string word) {
            Node* currentNode= this->rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word[i] - 'a';

                if(currentNode->children[index] == nullptr)
                    currentNode->children[index]= new Node( );

                currentNode= currentNode->children[index];
            }

            currentNode->isParentNodeMarkingACompleteWord= true;
        }

        bool searchFromStartingNode(string word, int currentCharacterPosition, Node* startingNode) {

            //* base case
            if(word.size( ) == 0)
                return startingNode->isParentNodeMarkingACompleteWord;

            Node* currentNode= startingNode;

            if(word[currentCharacterPosition] == '.') {

                //* look over all the children of the currentNode until a match is found
                for(int i= 0; i< 26; i++) {

                    if(currentNode->children[i] == nullptr)
                        continue;

                    else if(this->searchFromStartingNode(word, currentCharacterPosition + 1, currentNode->children[i]))
                        return true;
                }

                return false;
            }

            else {
                int index= word[currentCharacterPosition] - 'a';

                if(currentNode->children[index] == nullptr)
                    return false;

                else return this->searchFromStartingNode(word, currentCharacterPosition + 1, currentNode->children[index]);
            }
        }

        bool search(string word) {
            return this->searchFromStartingNode(word, 0, rootNode);
        }
};