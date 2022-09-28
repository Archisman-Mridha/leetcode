#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* children[26];

    bool doesParentNodeMarkACompleteWord;

    Node( )
        : doesParentNodeMarkACompleteWord(false)
    {

        for(int i= 0; i< 26; i++)
            children[i]= nullptr;
    }

    ~Node( ) {

        for(int i= 0; i< 26; i++)
            delete children[i];
    }
};

class Trie {

    private:
        Node* rootNode;

    public:
        Trie( )
            : rootNode(new Node( ))
        { }

        ~Trie( ) {
            delete this->rootNode;
        }

        void insertWord(string word) {
            Node* currentNode= rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word[i] - 'a';

                if(currentNode->children[index] == nullptr)
                    currentNode->children[index]= new Node( );

                currentNode= currentNode->children[index];
            }

            currentNode->doesParentNodeMarkACompleteWord= true;
        }

        bool isCompleteStringExisting(string word) {
            Node* currentNode= rootNode;

            for(int i= 0; i< word.size( ); i++) {
                int index= word[i] - 'a';

                if(! currentNode->children[index]->doesParentNodeMarkACompleteWord)
                    return false;

                currentNode= currentNode->children[index];
            }

            return true;
        }
};

//! time complexity= O(n) x O(average length of strings) + O(N x average length) and space complexity cannot be determined in case of a trie
string completeString(int n, vector<string> &a) {

    //* create a new Trie data structure
    Trie* trie= new Trie( );

    //* insert all the words in a trie
    for(int i= 0; i< n; i++)
        trie->insertWord(a[i]);

    //* evaluate the result

    string result;

    for(int i= 0; i< n; i++) {
        bool isCompleteString= trie->isCompleteStringExisting(a[i]);

        if(!isCompleteString)
            continue;

        else if(a[i].size( ) > result.size( ))
            result= a[i];

        else if(a[i].size( ) == result.size( )) {

            for(int j= 0; j< a[i].size( ); j++) {

                if(a[i][j] == result[j])
                    continue;

                else if(a[i][j] < result[j])
                    result= a[i];
            }
        }
    }

    return result.size( ) == 0 ? "None": result;
}