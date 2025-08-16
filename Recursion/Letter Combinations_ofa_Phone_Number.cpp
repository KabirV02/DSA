//https://leetcode.com/problems/letter-combinations-of-a-phone-number/ 

class Solution {
public:
    int n;
    vector<string> numbers = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(string digits,vector<string>& result,string& output,int i){
        if( i >= n){
            result.push_back(output);
            return;
        }

        int digit = digits[i] - '0';
        string number = numbers[digit]; 
       for(int j=0;j<number.length();j++){
            output.push_back(number[j]);
            solve(digits,result,output,i+1);
            output.pop_back();
       }
    }

    vector<string> letterCombinations(string digits) {
        
        n = digits.length();
        vector<string> result;
        if(n == 0)return result;
        string output = "";
        int i=0;
        solve(digits,result,output,i);
        return result;
    }
};