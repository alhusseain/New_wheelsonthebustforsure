#include <iostream>
#include "station.h"

using namespace std;


class bus {
private:
    int capacity;
    int numberOfJourneysDoneBeforeCheckUp;
    //int checkUpDuration;
    Stations* curr;
    int curr_station_num;
    int NumberOfPassengers;
    Queue<passengers>* currentPassengers;
public:
    bus(int capacity) {
        this->capacity = capacity;
        numberOfJourneysDoneBeforeCheckUp = 0;
        curr_station_num = -1;
    }

    int getCapacity() {
        return capacity;
    }
    int getNumberOfJourneys() {
        return numberOfJourneysDoneBeforeCheckUp;
    }
    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }
    int get_current_station_num()
    {
        return curr_station_num;
    }
    void set_current_station_num(int x)
    {
        curr_station_num = x;
    }

    void set_current_station_ptr(Stations* x)
    {
        curr= x;
    }

    Stations* get_current_station_ptr()
    {
        return curr;
    }
};