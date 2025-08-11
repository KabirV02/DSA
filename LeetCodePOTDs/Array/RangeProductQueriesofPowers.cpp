class Solution {
public:
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
    int  mod = 1e9+7;
        
        vector<int> powers;
        vector<int> result;
        int i=1;
        for (int bit = 0; bit < 31; bit++) {
            if (n & (1 << bit)) {
                powers.push_back(1 << bit);
            }
        }

        for(int i=0;i<queries.size();i++){
            
                        int multi = 1;
            for(int k = queries[i][0];k<=queries[i][1];k++){
                    multi = (1LL * multi * powers[k]) % mod;
       
            }
                       result.push_back(multi);    
            
        }

        return result;

    }
};