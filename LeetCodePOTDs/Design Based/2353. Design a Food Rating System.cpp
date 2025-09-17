#include<bits/stdc++.h>
using namespace std;

// T.C :- O(n*logn+Q*logm)
// Q = queries
// S.C :- O(n)

class FoodRatings {
public:
    unordered_map<string, string> food_cuisines;
    unordered_map<string, set<pair<int, string>>> food_rating_cuisines;
    unordered_map<string, int> food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines,vector<int>& ratings) {
        int n = cuisines.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            food_rating_cuisines[cuisine].insert({-rating,food});
            food_cuisines[food] = cuisine;
            food_rating[food] = rating;
        }
    }

    void changeRating(string food, int newRating) {

        string cuisine = food_cuisines[food];
        int oldRating = food_rating[food];
        food_rating[food] = newRating;
        food_rating_cuisines[cuisine].erase({-oldRating,food});
        food_rating_cuisines[cuisine].insert({-newRating,food});
    }

    string highestRated(string cuisine) {
        
        return begin(food_rating_cuisines[cuisine])->second;

    }
};
