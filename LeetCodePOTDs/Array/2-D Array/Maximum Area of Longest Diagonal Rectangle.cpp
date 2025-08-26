
// Using Priority Queue space used here no need to use sqrt acc. to question 

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int m = dimensions[0].size();
        priority_queue<pair<double,pair<double,double>>> pq;
        for(int i=0;i<n;i++){
        
            double num =  (dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]);
                pq.push({num,{dimensions[i][0],dimensions[i][1]}});

           

        }
        return (pq.top().second.first * pq.top().second.second );
    }
};


// Optimised Approach Using Variables

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int maxDiag = 0;
        int maxArea = 0;
        for(auto& dimension: dimensions){

            int length = dimension[0];
            int width = dimension[1];

            int diag = length * length + width * width;
            int area = length  * width;

            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }else if(diag == maxDiag){
                maxArea = max(maxArea,area);
            }

        }
        return maxArea;
    }
};
