#include<vector>
#include<queue>
using namespace std;

//Approach-1 : (Chossing class with max delta/improvement everytime) - Will give TLE/MLE
//T.C : O(extraStudents * n)
//S.C : O(n)

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int n = classes.size();

        vector<double> PR(n);
        for(int i=0;i<n;i++){
            PR[i] = (double)classes[i][0]/classes[i][1];
        }

        while(extraStudents--){

            vector<double> updatePR(n);
            for(int i=0;i<n;i++){
                updatePR[i] = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
            }

            int bestClassIdx = 0;
            double bestClassPR = 0.0;

            for(int i=0;i<n;i++){
                double diff = updatePR[i] - PR[i];
                if(diff > bestClassPR){
                    bestClassIdx = i;
                    bestClassPR = diff;
                }
            }

            PR[bestClassIdx] = updatePR[bestClassIdx];
            classes[bestClassIdx][0]++;
            classes[bestClassIdx][1]++;

        }

        double result = 0.0;
        for(int i=0;i<n;i++){
            result += PR[i];
        }
        return result/n;
    }
};


//Approach-2 : (Chossing class with max delta/improvement everytime - Improving with max heap)
//T.C : O(extraStudents * log(n))
//S.C : O(n)


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int n = classes.size();

        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){

            double currPR = (double)classes[i][0]/classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = newPR - currPR;
            pq.push({diff,i});
        }

        while(extraStudents--){

            auto top = pq.top();
            pq.pop();

            double maxValue = top.first;
            int idx = top.second;
            classes[idx][0]++;
            classes[idx][1]++;
            
            double currPR = (double)classes[idx][0]/classes[idx][1];
            double newPR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double diff = newPR - currPR;
            pq.push({diff,idx});

        }
        double result = 0.0;
        for(int i=0;i<n;i++){
            result += (double)classes[i][0]/classes[i][1];
        }
        return result/n;
    }
};