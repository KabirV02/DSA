/******************Fully Optimised Approach************************/
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n = num.length();
        string maxi  = "";
        int maxNumber = INT_MIN;
        for(int i=0;i<n-2;i++){
            int number = num[i] - '0';
            if(maxNumber < number && num[i] == num[i+1] && num[i+1] == num[i+2]){
                maxNumber = number;
                maxi =  num.substr(i,3);
            }
        }
        
        return maxi;
    }
};