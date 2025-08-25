
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        map<int, vector<int>> mp;
        
        vector<int> result;
        
        //fill the map using [i+j]
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool flip = true;
        for(auto &it : mp) {
            if(flip) {
                //it.second ko reverse kardo
                reverse(it.second.begin(), it.second.end());
            }
            
            for(int &num : it.second) {
                result.push_back(num);
            }
            
            flip = !flip;
        }
        
        return result;
    }
};


// Little bit imporved T.C.
class Solution {
public:
    int n;
    int m;

    void solve(vector<vector<int>>& mat,vector<int>& result,vector<int> helper){

        bool up = true;
        int k;
        for(k=0;k<n;k++){
           int i = k;
           int j = 0;
            while(i>=0&&j<m){
                helper.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(up == false){
                reverse(begin(helper),end(helper));
            }
             for(int help:helper){
                    result.push_back(help);
                }
            helper.clear();
            up = !up;
        }

        // up = false;
        for(int l = 1;l<m;l++){
             int i = k-1;
             int j = l;
            while(i>=0&&j<m){
                helper.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(up == false){
                reverse(begin(helper),end(helper));
            }
             for(int help:helper){
                    result.push_back(help);
                }
            helper.clear();
            up = !up;
        }

    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();
        vector<int> result;
        vector<int> helper;
        solve(mat,result,helper);
        return result;
    }
};