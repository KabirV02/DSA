// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
  int n,m;
  
     bool isValid(vector<vector<int>>& maze,int i,int j,vector<vector<bool>>& visited){
         
         if(i<0||j<0||i>=n||j>=m||visited[i][j]||maze[i][j] == 0){
             return false;
         }
         return true;
         
     }
  
    void solve(vector<vector<int>>& maze,vector<string>& result,string directions,
    vector<vector<bool>>& visited,int i,int j){
        
        if(i == n-1 && j==n-1){
             result.push_back(directions);
             return;
        }
        
       
        int new_x = i+1;
        int new_y = j;
        if(isValid(maze,new_x,new_y,visited)){
            visited[new_x][new_y] = true;
            directions.push_back('D');
             solve(maze,result,directions,visited,new_x,new_y);
            directions.pop_back();
            visited[new_x][new_y] = false;
        }
        // Left
         new_x = i;
         new_y = j-1;
        if(isValid(maze,new_x,new_y,visited)){
            visited[new_x][new_y] = true;
            directions.push_back('L');
             solve(maze,result,directions,visited,new_x,new_y);
                directions.pop_back();
            visited[new_x][new_y] = false;
        }
        // Right
         new_x = i;
         new_y = j+1;
        if( isValid(maze,new_x,new_y,visited)){
            visited[new_x][new_y] = true;
            directions.push_back('R');
             solve(maze,result,directions,visited,new_x,new_y);
                directions.pop_back();
            visited[new_x][new_y] = false;
        }
        // UP
         new_x = i-1;
         new_y = j;
        if( isValid(maze,new_x,new_y,visited)){
            visited[new_x][new_y] = true;
            directions.push_back('U');
             solve(maze,result,directions,visited,new_x,new_y);
                directions.pop_back();
            visited[new_x][new_y] = false;
        }
        
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        n = maze.size();
        m = maze[0].size();
        vector<string> result;
        if(maze[0][0] == 0)return result;
        string directions;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[0][0] = true;
        int i=0,j=0;
        solve(maze,result,directions,visited,i,j);
        return result;
    }
};