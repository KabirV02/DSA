#include<bits/stdc++.h>
using namespace std;

// Approach (Set for ordered storage, Unordered Map for quick lookup)
// T.C. : 
// MovieRentingSystem() -> O(n log n) for n entries (insert each entry into sets)
// search(movie)        -> O(5) i.e. constant. We access the movie set in O(1) from map and then return first 5 elements
// rent(shop, movie)    -> O(log m + log r) per operation
//                         (log m to erase from available[movie], log r to insert into rented, r = total rented movies)
// drop(shop, movie)    -> O(log m + log r) per operation
// report()             -> O(5) i.e. constant

// S.C. : 
// O(n + r) total
// available          -> O(n) (sum of all available movies)
// movieToShopPrice   -> O(n) (sum of all shop-price pairs)
// rented             -> O(r) (r = total rented movies)

class MovieRentingSystem {
public:
    typedef pair<int,int> P;
    unordered_map<int,set<P> > availableMovie;//{movie -> set<price,shop>}
    unordered_map<int,set<P> > movieToShop;//{movie -> set<shop,price>}
    set<tuple<int,int,int> > rented;//{price,shop,movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        for(auto& entry : entries){

            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            availableMovie[movie].insert({price,shop});
            movieToShop[movie].insert({shop,price});

        }

    }
    
    vector<int> search(int movie) {

        vector<int> result;
        int count = 0;

        if(availableMovie.count(movie)){
        
            for(auto& [price,shop] : availableMovie[movie]){

                result.push_back(shop);
                count++;
                if(count == 5)break;

            }

        }
        return result;
    }
    
    void rent(int shop, int movie) {

        auto it = movieToShop[movie].lower_bound({shop,INT_MIN});

        int price = it->second;

        availableMovie[movie].erase({price,shop});
        rented.insert({price,shop,movie});
        
    }
    
    void drop(int shop, int movie) {

        auto it = movieToShop[movie].lower_bound({shop,INT_MIN});

        int price = it->second;

        availableMovie[movie].insert({price,shop});
        rented.erase({price,shop,movie});
        
    }
    
    vector<vector<int>> report() {

        vector<vector<int>> result;
        int count = 0;
        for(auto& [price,shop,movie] : rented){
            result.push_back({shop,movie});
            count++;
            if(count == 5)break;
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