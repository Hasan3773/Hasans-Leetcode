class ParkingSystem {
private:
    int num_big = 0;
    int num_med = 0;
    int num_small = 0;
public:
    ParkingSystem(int big, int medium, int small) {
        // there are 3 types of parking spaces, passed number of each
        // init object of the parking class 
        num_big = big;
        num_med = medium;
        num_small = small;
    }
    
    bool addCar(int carType) {
        // checks if there a space of cartype (1 big, 2 medium, 3 small)
        if (carType == 1 && num_big != 0){
            num_big--;
            return true;
        } else if (carType == 2 && num_med != 0) {
            num_med--;
            return true;
        } else if (carType == 3 && num_small != 0) {
            num_small--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */