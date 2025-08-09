
// First Approach Using AND(&) operator
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)return false;

        return (n & (n-1)) == 0;

    }
};

// Second operator is due to we are having constraints b/w -2^31 to 2^31
/*
 So here we are get the value of 2^30=1073741824 now if n is giving the remainder by doing modulus if we get 0 so its true 
 else false
*/ 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0)return false;

        return 1073741824 % n == 0;

    }
};