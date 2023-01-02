class ParkingSystem
{
    public:
        int bigspace = 0, mediumspace = 0, smallspace = 0, currbs = 0, currms = 0, currss = 0;
    ParkingSystem(int big, int medium, int small)
    {
        bigspace = big;
        mediumspace = medium;
        smallspace = small;
    }

    bool addCar(int t)
    {
        if (t == 1)
        {
            if (currbs < bigspace)
            {
                currbs++;
                return true;
            }
            return false;
        }
        if (t == 2)
        {
            if (currms < mediumspace)
            {
                currms++;
                return true;
            }
            return false;
        }
        if (t == 3)
        {
            if (currss < smallspace)
            {
                currss++;
                return true;
            }
            return false;
        }
        return 1;
    }
};

/**
 *Your ParkingSystem object will be instantiated and called as such:
 *ParkingSystem* obj = new ParkingSystem(big, medium, small);
 *bool param_1 = obj->addCar(carType);
 */