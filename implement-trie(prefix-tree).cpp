#include <bits/stdc++.h>

using namespace std;

class Trie {

    private:
        Trie* children[26];
        bool isPreiousNodeMarkingACompleteWord;

    public:
        Trie( )
            : isPreiousNodeMarkingACompleteWord(false)
        {

            for(int i=0; i< 26; i++)
                children[i]= nullptr;
        }

        void insert(string word) {
            
            Trie* currentNode= this;
            int currentCharacterPosition= 0;

            do {
                int index= word[currentCharacterPosition] - 'a';

                if(currentNode->children[index] == nullptr)
                    currentNode->children[index]= new Trie( );

                currentNode= currentNode->children[index];
                currentCharacterPosition++;
            } while(currentCharacterPosition < word.size( ));

            currentNode->isPreiousNodeMarkingACompleteWord= true;
        }

        bool search(string word) {

            Trie* currentNode= this;
            int currentCharacterPosition= 0;

            do {
                int index= word[currentCharacterPosition] - 'a';

                if(currentNode->children[index] == nullptr)
                    return false;

                currentNode= currentNode->children[index];
                currentCharacterPosition++;
            } while(currentCharacterPosition < word.size( ));

            return currentNode->isPreiousNodeMarkingACompleteWord;
        }

        bool startsWith(string prefix) {

            Trie* currentNode= this;
            int currentCharacterPosition= 0;

            do {
                int index= prefix[currentCharacterPosition] - 'a';

                if(currentNode->children[index] == nullptr)
                    return false;

                currentNode= currentNode->children[index];
                currentCharacterPosition++;
            } while(currentCharacterPosition < prefix.size( ));

            return true;
        }
};