/******************Using Unordered Set************************/
// Time: O(1) average (set lookup) + O(31) precomputation = O(1)
// Space: O(31) = O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_set<long long> st;
        for(int i=0;i<31;i++){
            st.insert(pow(3,i)); // Precompute all powers
        }
        return st.count(n); // O(1) average
    }
};


/******************Iterative Approach************************/
// Time: O(log₃ n) → keeps dividing by 3
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
       if(n <= 0)return false;
       if(n == 1)return true;
       while(n%3 == 0){
           n /= 3;
       } 
       return n==1;
    }
};


/******************Recursive Approach************************/
// Time: O(log₃ n) → one recursive call per division by 3
// Space: O(log₃ n) recursion stack
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        else if(n == 1) return true;
        return n%3 == 0 && isPowerOfThree(n/3);  
    }
};


/******************Logarithmic Approach************************/
// Time: O(1) → just a log10 and division
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double logValue = log10(n) / log10(3);
        return logValue == (int)logValue;
    }
};


/******************Most Optimised Approach************************/
// Time: O(1) → single modulo check
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
       return n > 0 && 1162261467 % n == 0;
    }
};
