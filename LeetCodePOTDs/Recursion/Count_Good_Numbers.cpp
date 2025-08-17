// https://leetcode.com/problems/count-good-numbers/

/*
 Approach:-

 Here we have to count numbers which are following the condition given in question

 Now we know to place digit at even place we have 5 choices
 and to place digit at odd place we have 4 choices
 
 acc. to given n we find the count of even and odd place using formula
 
 to find count of even indexs = (n + 1)/2
 to find count of odd indexs = (n)/2


*/

class Solution {
public:
    int MOD = 1e9+7;
    int myPow(long long a,long long b ){

        if(b == 0)return 1;
        if(b == 1)return a;

        long long result = myPow(a,b/2);

        if(b % 2 == 0){
            return ((result * result) % MOD);
        }else{
            return ((a*result * result) % MOD);
        }
    }

    int countGoodNumbers(long long n) {

        if(n == 0)return 0;
        int count = 0;
       
        return (long long)myPow(5,(n+1)/2) * myPow(4,(n/2)) % MOD ;
        
    }
};