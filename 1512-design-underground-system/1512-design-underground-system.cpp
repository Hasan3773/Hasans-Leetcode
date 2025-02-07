// What data type bruh
// graphs? where each node is a station and the edge is the avg time to get there?
// also a hashmap that has the customer id and which station they started from, once they get off you remove the entry
// need to connect the hashmap and graph in order to get the time diff between stations
// gonna use a map to store everything and then a travel times map as well, will try to implement with a graph instead later
#include <map>

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
      // make sure the id is not checked in at any other stations
      // store the station name and time and id?
        if (infomap.count(id) > 0) { 

        }
        else {
            infomap[id] = make_pair(stationName, t);
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        // remove id from the station and store these values
        // this is prob where i want to calculate how long it took this customer to travel
        auto info = infomap[id];
        infomap.erase(id);
        string path = info.first + ',' + stationName;
        int time = t - info.second;
        if (timemap.count(path) > 0){
            timemap[path].first += time;
            timemap[path].second++; 
        }
        else{
            timemap[path] = make_pair(time, 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        // use each customer travel time from the specific stations to get the average time
        // has to be unique per direction, cant flip directions and have the same time
        string path = startStation + ',' + endStation;
        auto timeinfo = timemap[path];
        return (double) timeinfo.first / timeinfo.second;
    }
private:
    map<int, pair<string, int>> infomap; //id, station, time
    map<string, pair<int, int>> timemap; // (station1,station2), time taken, trip #
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */