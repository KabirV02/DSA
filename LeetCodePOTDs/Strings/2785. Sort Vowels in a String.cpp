#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n log n)
// S.C :- O(n)

class Solution {
public:
    string sortVowels(string s) {

        int n = s.length();

        vector<char> vowels;
        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels.push_back(ch);
            }
        }
        sort(begin(vowels), end(vowels));

        int vowelIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U') {
                s[i] = vowels[vowelIdx];
                vowelIdx++;
            }

        }

        return s;
    }
};