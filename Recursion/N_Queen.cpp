class Solution {
public:

    bool isvalid(int n,int row,int col,vector<string> result){

        for(int i=row-1;i>=0;i--){
                if(result[i][col] == 'Q')return false;
        }

        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(result[i][j] == 'Q')return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(result[i][j] == 'Q')return false;
        }
        return true;

    }

    void solve(int n,vector<vector<string>>& result,vector<string>& output,int row){

        if(row >= n){
            result.push_back(output);
            return;
        }

        for(int col = 0;col<n;col++){

                output[row][col] = 'Q';
            if(isvalid(n,row,col,output)){
                solve(n,result,output,row+1);
            }
                output[row][col] = '.';
        }

    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>result;
        vector<string> output(n,string(n,'.'));
        solve(n,result,output,0);
        return result;
        
    }
};