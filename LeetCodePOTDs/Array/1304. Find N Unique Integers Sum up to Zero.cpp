
// T.C:- O(n)
// S.C:- O(n)
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n,0);

        int start = 1;
        int i =0;
        int j = n - 1;
        while(i < j){
            result[i] = start;
            result[j] = -start;
            start++;
            i++;j--;
        }

        return result;
    }
};