#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n)
// S.C :- O(1)

class Solution {
public:
    bool doesAliceWin(string s) {

        int n = s.length();
        int vowelCount = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                vowelCount++;
            }
        }

            return vowelCount == 0 ? 0 : 1;
    }
};