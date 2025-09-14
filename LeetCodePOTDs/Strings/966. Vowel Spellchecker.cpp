#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n + m) * L
// S.C :- O(n)
class Solution {
public:
    unordered_map<string, string> mp;
    unordered_map<string, string> vowels;
    string convertToLower(string word) {
        string str = "";
        for (char& ch : word) {
            str += tolower(ch);
        }
      
        return str;
    }

    string vowelCorrection(string str){
        for (char& ch : str) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u') {
                    ch = '*';
                }
            } 
            return str;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {

        int n = wordlist.size();
        vector<string> result;
        unordered_set<string> st(wordlist.begin(), wordlist.end());

        for (int i = 0; i < n; i++) {
            string str = "";
            str = convertToLower(wordlist[i]);
        if (mp.find(str) == mp.end()) {
            mp[str] = wordlist[i];
        }
            string vowled = vowelCorrection(str);
         if (vowels.find(vowled) == vowels.end()) {
                vowels[vowled] = wordlist[i];
            }
        }
        for (auto& query : queries) {
        string lowercases = convertToLower(query);
        string vowelcases = vowelCorrection(lowercases);
            if(st.count(query)) {
                result.push_back(query);
            }else if(mp.find(lowercases) != mp.end()){
                result.push_back(mp[lowercases]);
            }else if(vowels.find(vowelcases) != vowels.end()){
                result.push_back(vowels[vowelcases]);
            }else{
                result.push_back("");
            }
        }

        return result;
    }
};