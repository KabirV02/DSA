#include<bits/stdc++.h>
using namespace std;

//T.C : O(denominator) approximately
//S.C : O(1)

class Solution {
public:
    typedef long long L;
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";
        string result;
        if (((L)numerator * (L)denominator) < 0) {

            result += "-";
        }

        L absNum = labs(numerator);
        L absDeno = labs(denominator);
        L Div = absNum / absDeno;

        result += to_string(Div);

        L rem = absNum % absDeno;
        if (rem == 0) {
            return result;
        }

        result += ".";

        unordered_map<int, int> mp;

            while (rem != 0) {

            if (mp.count(rem)) {
                result.insert(mp[rem], "(");
                result += ")";
                break;
            }

            mp[rem] = result.length();
            rem *= 10; 
            int digit = rem / absDeno;
            result += to_string(digit);
            rem = rem % absDeno;

        }

        return result;
    }
};