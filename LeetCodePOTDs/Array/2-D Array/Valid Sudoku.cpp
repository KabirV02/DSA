
class Solution {
public:

    bool isValid(vector<vector<char>>& board,int startRow,int startCol,int endRow,int endCol){

        
        unordered_set<char> st;
        for(int row=startRow;row<=endRow;row++){
            for(int col=startCol;col<=endCol;col++){
                if(board[row][col] =='.')continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        
    return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for(int row=0;row<9;row++){
            unordered_set<char> st;
            for(int col=0;col<9;col++){
                if(board[row][col] == '.')continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        for(int col=0;col<9;col++){
            unordered_set<char> st;
            for(int row=0;row<9;row++){
                if(board[row][col] =='.')continue;
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }


        
      for(int startRow = 0;startRow < 9;startRow+=3){
        int endRow = startRow+2;
        for(int startCol = 0;startCol < 9;startCol+=3){
            int endCol = startCol+2;
            if(!isValid(board,startRow,startCol,endRow,endCol)){
                return false;
            }
        }
      }

        return true; 
        
    }
};

// Optimised Approach

class Solution {

public:

    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')continue;
                string row = string(1,board[i][j]) + "ROW" + to_string(i);
                string col = string(1,board[i][j]) + "COL" + to_string(j);
                string box = string(1,board[i][j]) + "BOX" + to_string(i/3) + '_' + to_string(j/3);

                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end())return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }


        return true; 
        
    }
};