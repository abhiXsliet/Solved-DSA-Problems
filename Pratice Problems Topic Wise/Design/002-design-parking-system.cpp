// https://leetcode.com/problems/design-parking-system/



// ---------------------------------------------------- SOLUTION - 1 ----------------------------------------------------------------

class ParkingSystem {
public:
    vector<int> store;
    ParkingSystem(int big, int medium, int small) {
        store = vector<int>(3, 0);
        store[0] = big;
        store[1] = medium;
        store[2] = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (store[0] > 0) {
                store[0] -= 1;
                return true;
            }
        }
        else if (carType == 2) {
            if (store[1] > 0) {
                store[1] -= 1;
                return true;
            }
        }
        else {
            if (store[2] > 0) {
                store[2] -= 1;
                return true;
            }
        }
        return false;
    }
};

// -------------------------------------------------------- SOLUTION - 2 ------------------------------------------------------------------

class ParkingSystem {
public:
    int bigC;
    int medC;
    int smaC;
    ParkingSystem(int big, int medium, int small) {
        this -> bigC = big;
        this -> medC = medium;
        this -> smaC = small;
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1 : 
                    {
                        if (bigC == 0)
                            return false;
                        else bigC --;
                    }
                    break;
            case 2 : 
                    {
                        if (medC == 0)
                            return false;
                        else medC --;
                    }
                    break;
            case 3 :
                    {
                        if (smaC == 0)
                            return false;
                        else smaC --;
                    }
                    break;
        }
        return true;
    }
};

// -------------------------------------------------------- SOLUTION - 3 ------------------------------------------------------------------

class ParkingSystem {
public:
    unordered_map<int, int> mpp;
    ParkingSystem(int big, int medium, int small) {
        mpp[1] = big;
        mpp[2] = medium;
        mpp[3] = small;
    }
    
    bool addCar(int carType) {
        if (mpp[carType] > 0) {
            mpp[carType] -= 1;
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