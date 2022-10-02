#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:
        string intToRoman(int num) {
            string romanNumber;

            while(num > 0) {
                if(num >= 1000) {
                    romanNumber += "M";

                    num -= 1000;
                }

                else if(num >= 900) {
                    romanNumber += "CM";

                    num -= 900;
                }

                else if(num >= 500) {
                    romanNumber += "D";

                    num -= 500;
                }

                else if(num >= 400) {
                    romanNumber += "CD";

                    num -= 400;
                }

                else if(num >= 100) {
                    romanNumber += "C";

                    num -= 100;
                }

                else if(num >= 90) {
                    romanNumber += "XC";

                    num -= 90;
                }

                else if(num >= 50) {
                    romanNumber += "L";

                    num -= 50;
                }

                else if(num >= 40) {
                    romanNumber += "XL";

                    num -= 40;
                }

                else if(num >= 10) {
                    romanNumber += "X";

                    num -= 10;
                }

                else if(num >= 9) {
                    romanNumber += "IX";

                    num -= 9;
                }

                else if(num >= 5) {
                    romanNumber += "V";

                    num -= 5;
                }

                else if(num >= 4) {
                    romanNumber += "IV";

                    num -= 4;
                }

                else {
                    romanNumber += "I";

                    num -= 1;
                }
            }

            return romanNumber;
        }
};