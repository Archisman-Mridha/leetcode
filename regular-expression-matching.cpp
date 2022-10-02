#include <bits/stdc++.h>

using namespace std;

class Solution {

    private:
        bool recursiveHelper(string &s, string &p, int currentCharacterPositionInString, int currentCharacterPositionInPattern) {

            //* when both string and pattern ends are crossed
            if((currentCharacterPositionInString > s.size( ) - 1) && (currentCharacterPositionInPattern > p.size( ) - 1))
                return true;

            //* when end of string is crossed but still charaters are left in pattern
            if(currentCharacterPositionInString > s.size( ) - 1) {

                while(currentCharacterPositionInPattern <= p.size( ) - 1) {

                    if(p.at(currentCharacterPositionInPattern) == '*')
                        currentCharacterPositionInPattern++;

                    else return false;
                }

                return true;
            }

            //* when end of pattern is crossed but still characters are left in string
            if(currentCharacterPositionInPattern > p.size( ) - 1)
                return false;

            char currentCharacterFromPattern= p.at(currentCharacterPositionInPattern),
                currentCharacterFromString= s.at(currentCharacterPositionInString);

            //* in case of '*' explore all the possibilities
            if(currentCharacterFromPattern == '*') {

                for(int i= 0; i <= s.size( ) - currentCharacterPositionInString; i++) {
                    bool resultFromRecursion= recursiveHelper(s, p, currentCharacterPositionInString + i, currentCharacterPositionInPattern + 1);

                    if(! resultFromRecursion)
                        continue;

                    else return true;
                }

                return false;
            }

            //* for an alphabet characater or '.'

            if(currentCharacterFromPattern == currentCharacterFromString || currentCharacterFromPattern == '.')
                return recursiveHelper(s, p, currentCharacterPositionInString + 1, currentCharacterPositionInPattern + 1);

            else return false; 
        }

    public:
        bool isMatch(string s, string p) {
            return this->recursiveHelper(s, p, 0, 0);
        }
};

int main( ) {
    Solution* solution= new Solution( );

    cout<<solution->isMatch("a", "*")<<endl;

    return 0;
}