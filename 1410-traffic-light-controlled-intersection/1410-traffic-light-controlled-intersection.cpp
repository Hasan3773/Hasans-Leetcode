class TrafficLight {
public:
    mutex lock;
    int currentState; 
    TrafficLight() {
            currentState = 1; // road A starts green
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car (south-1, north-2, east-3, west-4)
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        lock_guard<mutex> lck (lock); // lock the mutex to prepare for the critical section, automatically releases
        if (roadId != currentState){
            currentState = roadId;
            turnGreen();
        }
        crossCar();
    }
};