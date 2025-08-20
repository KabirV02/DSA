class Solution {
public:
    int n;
    int m;
    int l;
   vector<vector<int>> drs = {{1,0},{0,-1},{0,1},{-1,0}};

    bool solve(vector<vector<char>>& board, string word,int i,int j,int k){
        
        if(k >= l){
            return true;
        }

        if( i < 0 || j < 0 || i>=n || j>=m || board[i][j] != word[k])return false;
            char temp = board[i][j]; 
            board[i][j] = '$';
        for(auto& dir:drs){
            int new_x = i+dir[0];
            int new_y = j+dir[1];
            if(solve(board,word,new_x,new_y,k+1))return true;     
            }
            board[i][j] = temp;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();
        l = word.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && solve(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};