// https://leetcode.com/problems/design-movie-rental-system/




#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
public:
    using P = pair<int, int>;
    unordered_map<int, set<P>> movie_price_shop;  // {movie, {price, shop}}
    unordered_map<int, set<P>> movie_shop_price;  // {movie, {shop, price}}
    set<tuple<int, int, int>> rented;             // {price, shop, movie}

    // TC : O(N*log(N))
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entry : entries) {
            int shop  = entry[0];
            int movie = entry[1];
            int price = entry[2];
            movie_price_shop[movie].insert({price, shop});
            movie_shop_price[movie].insert({shop, price});
        }    
    }
    
    // TC : O(1)
    vector<int> search(int movie) {
        vector<int> result; // return top-5 shops
        int count = 0;
        if (movie_price_shop.count(movie)) {
            for (auto &it : movie_price_shop[movie]) {
                result.push_back(it.second);
                count ++;
                if (count >= 5) break;
            }
        }
        return result;
    }
    
    // TC : O(log(N))
    void rent(int shop, int movie) {
        auto it = movie_shop_price[movie].lower_bound({shop, INT_MIN});
        int price = it -> second;
        
        movie_price_shop[movie].erase({price, shop});   // erase from available
        rented.insert({price, shop, movie});            // add to rented
    }
    
    // TC : O(log(N))
    void drop(int shop, int movie) {
        auto it = movie_shop_price[movie].lower_bound({shop, INT_MIN});
        int price = it -> second;

        movie_price_shop[movie].insert({price, shop});  // make available
        rented.erase({price, shop, movie});             // erase from rented
    }
    
    // TC : O(1)
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;

        for (auto &[price, shop, movie] : rented) {
            result.push_back({shop, movie});
            count += 1;
            if (count >= 5) break;
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */