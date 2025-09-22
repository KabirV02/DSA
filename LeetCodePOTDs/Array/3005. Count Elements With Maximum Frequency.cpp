#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n)
// S.C :- O(n)

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        int count = 0;
        int maxFreq = 0;
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
            if(mp[num] > maxFreq){
                maxFreq = mp[num];
                count = mp[num];
            }else if(mp[num] == maxFreq){
                count += mp[num];
            }
        }
        return count;
    }
};