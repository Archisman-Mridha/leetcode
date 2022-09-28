#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* children[26];

    bool isParentNodeMakingASubstring;

    Node( )
        : isParentNodeMakingASubstring(false)
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

        void insertUniqueSubstring(string substring, int& distinctSubstrings) {
            Node* currentNode= this->rootNode;

            for(int i= 0; i< substring.size( ); i++) {
                int index= substring[i] - 'a';

                if(currentNode->children[index] == nullptr)
                    currentNode->children[index]= new Node( );

                currentNode= currentNode->children[index];
            }

            if(! currentNode->isParentNodeMakingASubstring) {
                currentNode->isParentNodeMakingASubstring= true;

                ++distinctSubstrings;
            }
        }
};

int countDistinctSubstrings(string &s) {

    //* initalize a trie data structure
    Trie* trie= new Trie( );

    //* variable to keep track of number of unique substrings inserted into the trie
    int distinctSubstrings= 0;

    //* insert all unique substrings into the trie
    for(int i= 0; i< s.size( ); i++)
        for(int j= i; j< s.size( ); j++)
            trie->insertUniqueSubstring(s.substr(i, j - i + 1), distinctSubstrings);

    //* register "" as a substring
    distinctSubstrings= distinctSubstrings + 1;

    return distinctSubstrings;
}