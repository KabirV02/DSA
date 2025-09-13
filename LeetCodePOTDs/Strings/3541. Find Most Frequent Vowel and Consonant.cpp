#include<bits/stdc++.h>
using namespace std;

//  T.C:- O(n)
//  S.C:- O(1)

class Solution {
public:
    int maxFreqSum(string s) {
        
        int n = s.length();
        vector<int> aplahbets(26,0);
        int maxC = 0,maxV = 0;

        int sum1 ,sum2;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
             aplahbets[s[i] - 'a']++;
             if(aplahbets[s[i] - 'a'] > maxV){
                maxV = aplahbets[s[i] - 'a'];
             }
            }else{
              aplahbets[s[i] - 'a']++;
              if(aplahbets[s[i] - 'a'] > maxC){
                maxC = aplahbets[s[i] - 'a'];
              }
            }
        }
    return maxV + maxC;
    }
};