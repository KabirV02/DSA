class Solution {
public:
 int n;

    bool isPalindrom(string s){

        int m = s.length();

        int low = 0;
        int high = m-1;

        while(low <= high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    void solve(string s,vector<vector<string>>& result,vector<string> output,int i){

        if( i >= n){
            result.push_back(output);
            return;
        }

        for(int idx = i;idx<n;idx++){

            if(isPalindrom(s.substr(i,idx-i+1))){
                output.push_back(s.substr(i,idx-i+1));
                solve(s,result,output,idx+1);
                output.pop_back();
            }

        }

    }

    vector<vector<string>> partition(string s) {

       n = s.length();
       vector<string> output;
       vector<vector<string>> result;
       int i=0;
       solve(s,result,output,i);
       return result; 
        
    }
};