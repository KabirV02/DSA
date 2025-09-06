#include<vector>
using namespace std;
class Solution {
public:
    int n,m;
    
    bool isSafe(vector<vector<char>>& board,int row,int col,char dig){

        for(int i=0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i] == dig){
                return false;
            }
        }


        int startingRow = 3 * (row/3);
        int startingCol = 3 * (col/3);
        for(int i = startingRow;i<=startingRow+2;i++){
            for(int j = startingCol;j<=startingCol+2;j++){
               
                if(board[i][j] == dig)return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board,int i,int j){

        if(i == 9)return true;

        int nextRow = i;
        int nextCol = j+1;

        if(j == 9){
            nextRow++;
            nextCol=0;
        }

        if(board[i][j] != '.'){
            return solve(board,nextRow,nextCol);
        }

        for(char dig = '1';dig<='9';dig++){
            
            if(isSafe(board,i,j,dig)){
               board[i][j] = dig;
               if(solve(board,nextRow,nextCol))return true;
               
               board[i][j] = '.';
            }

        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();

        solve(board,0,0);

    }
};