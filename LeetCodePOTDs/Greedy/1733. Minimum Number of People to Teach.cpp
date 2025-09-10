#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        unordered_set<int> sadUsers;

        for(auto friends:friendships){
            int u = friends[0]-1;
            int v = friends[1]-1;

            unordered_set<int> langSet(begin(languages[u]),end(languages[u]));
            bool canTalk = false;
            for(int lang : languages[v]){
                if(langSet.count(lang)){
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }

        unordered_map<int,int> mp;
        int maxLangKnown = 0;
        for(int sadUser:sadUsers){
            for(int langKnow : languages[sadUser]){
                mp[langKnow]++;
                maxLangKnown = max(maxLangKnown,mp[langKnow]);
            }
        }
            return  sadUsers.size() - maxLangKnown;
    }
};