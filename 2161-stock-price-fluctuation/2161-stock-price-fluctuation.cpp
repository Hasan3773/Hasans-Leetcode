#include <map>
class StockPrice {
private:
    unordered_map<int, int> stock; // timestamp, price 
    multiset<int> prices;
    int max_time = 0;
public:
    StockPrice() {
    }
    
    void update(int timestamp, int price) { 
        if (stock.count(timestamp)){
            auto it = prices.find(stock[timestamp]);
            prices.erase(it);
        }
        stock[timestamp] = price;
        prices.insert(price);
        max_time = max(max_time, timestamp);

    }
    
    int current() { 
        return stock[max_time];
    }
    
    int maximum() {
        if (stock.empty()) 
            return 0;
        return *prices.rbegin(); 
    }
    
    int minimum() {
        if (stock.empty()) 
            return 0;
        return *prices.begin(); 

    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */