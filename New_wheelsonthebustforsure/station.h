#pragma once
#ifndef STATION
#define STATION
#include"Structures.h"
#include"Passengers.h"
class Stations {
private:
	int  stationNumber;
	int  nextStation;
	Queue<passengers>* waiting_passengers;
	Queue<passengers>* WP_waitingPassengers;
	Queue<passengers>* we_waited_too_long_boi;


public:
	Stations()
	{
		stationNumber = 0;
		nextStation = NULL;
		waiting_passengers = new Queue<passengers>;
		WP_waitingPassengers = new Queue<passengers>;
		we_waited_too_long_boi = new Queue<passengers>;
	}
	// Constructor
	/*Stations(int stationNo, int nextSt)
	:stationNumber(stationNo), nextStation(nextSt){
		stationNumber = stationNo;
		nextStation = nextSt;
		waiting_passengers = new Queue<passengers>;
		WP_waitingPassengers = new Queue<passengers>;

	}*/

	// Getter methods
	int getStationNumber() {
		return stationNumber;
	}

	int getNextStation() {
		return nextStation;
	}

	Queue<passengers>* getWaitingPassengers() {
		return waiting_passengers;
	}
	Queue<passengers>* getWe_waited_too_long() {
		return we_waited_too_long_boi;
	}
	Queue<passengers>* get_WP_WaitingPassengers() {
		return WP_waitingPassengers;
	}


	// Setter methods
	void setStationNumber(int newStationNo) {
		stationNumber = newStationNo;
	}

	void setNextStation(int newNextStation) {
		nextStation = newNextStation;
	}

	/*void Add_to_waiting_passengers(passengers& new_passenger) {
		waiting_passengers->priority_enqueue(new_passenger,new_passenger.getPriorityNo());
	}*/
};

#endif // !STATION
