
// Here we are having only 2 choices 0 or 1 and also the condition 1 will not comes consecutively 

class Solution {
  public:
  
    void solve(int num,vector<string>& result,string& output){
        
        if(output.length() == num){
            result.push_back(output);
            return;
        }
        
        output+='0';
        solve(num,result,output);
        output.pop_back();
        if(output.back() != '1'){
             output+='1';
           solve(num,result,output);
           output.pop_back();
        }
    }
  
    vector<string> generateBinaryStrings(int num) {
        string output;
        vector<string> result;
        solve(num,result,output);
        return result;
    }
};