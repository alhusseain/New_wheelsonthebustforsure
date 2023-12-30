#pragma once
#ifndef PASSENGER
#define PASSENGER
#include"time.cpp"
#include <string>
#include <iostream>
using namespace std;


class passengers {
private:
    int priority_no;
    int passenger_id;
    string passenger_type;
    time_def arrival_time;
    time_def finish_time;
    string passenger_description;
    string passenger_direction;
    string string_time;

public:
    passengers()
    {
        passenger_id = NULL;
        passenger_type =" ";
        passenger_description = " ";
        passenger_description = " ";
        passenger_direction = " ";
        priority_no = NULL;

    }
    passengers(int passenger_id1, string passenger_type1, string description, string direction, time_def time){
        passenger_type = passenger_type1;
        passenger_description = description;
        passenger_direction = direction;
        arrival_time=time;
        passenger_id = passenger_id1;
        if (passenger_type == "SP") priority_no = 0;
        else priority_no = 1;
    }


    int getPriorityNo() const {
        return priority_no;
    }
    int getPassengerId() const {
        return passenger_id;
    }

    std::string getPassengerType() const {
        return passenger_type;
    }

    string get_arrival_time() { return arrival_time.get_time(); }

    string get_finish_time() { return finish_time.get_time(); }

    string get_direction() { return passenger_direction; }

    /*int getTripHours() const {
        return trip_hours;
    }*/

    /*int getTripMinutes() const {
        return trip_minutes;
    }*/

    /* void setPriorityNo()
    {

    }
    */
    /*void setArrivalTime(int minutes) {

        arrival_minutes = minutes;
    }*/

    /*void setFinishTime(int minutes) {
        finish_minutes = minutes;
    }*/

    /*  // Start the trip
      void start_trip() {
          waiting_hours = 0;
          waiting_minutes = 0;
      }
      */

      /*void finish_trip() {
          trip_hours = finish_hours - (arrival_hours + waiting_hours);
          trip_minutes = finish_minutes - (arrival_minutes + waiting_minutes);
      }*/


      /*void display() const {
          cout << "Passenger " << passenger_id << " - Type: " << passenger_type
              << ", Priority: " << priority_no << ", Arrival Time: " << arrival_hours << ":" << arrival_minutes
              << ", Finish Time: " << finish_hours << ":" << finish_minutes
              << ", Waiting Time: " << waiting_hours << ":" << waiting_minutes
              << ", Trip Time: " << trip_hours << ":" << trip_minutes << endl;
      }*/
};
#endif PASSENGER