// https://leetcode.com/problems/design-a-food-rating-system/




#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, string> food_cuisine;
    unordered_map<string, int> food_rating;
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;
public:
    // TC : O(N)
    // SC : O(N)
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i ++) {
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
            cuisine_rating_food[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    // TC : O(1)
    void changeRating(string food, int newRating) {
        int oldRating = food_rating[food];
        food_rating[food] = newRating;

        string cuisine = food_cuisine[food];
        cuisine_rating_food[cuisine].erase({-oldRating, food});
        cuisine_rating_food[cuisine].insert({-newRating, food});
    }
    
    // TC : O(1)
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine]) -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */