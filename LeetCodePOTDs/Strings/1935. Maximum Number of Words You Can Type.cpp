#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n)
// S.C:- O(n)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

    unordered_set<char> st;
        int n = text.length();
        for (char ch : brokenLetters) {
            if(ch != ' '){
            st.insert(ch);
            }
        }

        int count = 0;
        bool safe = true;
        for(char ch : text){
            if(ch == ' '){
                if(safe){
                    count++;
                }
                safe = true;
            }else if(st.count(ch)){
                safe = false;
            }
        }

        if(safe)count++;
       
        return count;
    }
};