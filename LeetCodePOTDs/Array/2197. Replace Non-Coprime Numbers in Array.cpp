#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n * logx)
// S.C :- O(1) Because we have to retrun a vector in result so not taking it as a space

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {

        int n = nums.size();
        vector<int> result;

         for(int num : nums){
             
             while(!result.empty()){
                 
                int prev = result.back();
                int curr =  num;
                int GCD = gcd(prev,curr);
                if(GCD == 1)break;

                result.pop_back();
                int LCM = prev / GCD * curr;
                num = LCM;
             }
             result.push_back(num);

         }
        return result;
    }
};