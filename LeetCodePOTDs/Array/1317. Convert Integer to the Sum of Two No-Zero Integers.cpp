
#include<iostream>
#include<vector>
using namespace std;

// T.C :- O(n log n)
// S.C :- O(1)

class Solution {
public:

    bool isValid(int a , int b){

        int rem = 1;
        while(a && b){
            rem = b % 10;
            if(rem  == 0)return false;
            b = b / 10;
            rem = a % 10;
            if(rem  == 0)return false;
            a = a / 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        
        int a = n/2, b = n - a;
      while(1){
         if(isValid(a,b)){
            return {a,b};
         }
          a++;
          b = n - a;
      }
      return {};

    }
};