class Solution {
public:

    void solve(int n,vector<string>& result,string& output,int open,int close){

        if(output.length() == 2*n){
            result.push_back(output);
            return;
        }

        if(open < n){
            output.push_back('(');
            solve(n,result,output,open+1,close);
             output.pop_back();
        }

        if(close < open){
            output.push_back(')');
            solve(n,result,output,open,close+1);
            output.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {

        int open = 0;
        int close = 0;
        vector<string> result;
        string output;
        solve(n,result,output,open,close);
        return result;
        
    }
};