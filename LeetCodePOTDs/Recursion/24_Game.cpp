
// https://leetcode.com/problems/24-game/?envType=daily-question&envId=2025-08-18

/*
Here we use Epsilon bcz of division operator it might be possible we get the value which is very near to our 
target 
For eg:- target = 8 and we get value = 7.9999
At base case 7.99999 != 8 acc. to system 
So here we calculate the difference and we get 0.11111 which is equal epsilon so epsilon help here 
*/

class Solution {
public:
    double epsilon = 0.1;
    bool solve(vector<double>& cards){

        if(cards.size() == 1){
           return abs(cards[0] - 24) <= epsilon;
        }

        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j)continue;

                vector<double>temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j){
                    temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];

                vector<double> operation = {a+b,a-b,b-a,a*b};
                if(abs(b) > 0.0){
                    operation.push_back(a/b);
                }
                if(abs(a) > 0.0){
                    operation.push_back(b/a);
                }


                for(double val:operation){
                    temp.push_back(val);
                    if(solve(temp)){
                        return true;
                    }
                    temp.pop_back();
                }
    
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(4);
        for(int i=0;i<4;i++){
            nums[i] = 1.0 * cards[i];
        }

        return solve(nums);
    }
};