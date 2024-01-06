#pragma once
#ifndef STATION
#define STATION
#include"Structures.h"
#include"Passengers.h"
#include"bus.cpp"
#include"Company.cpp"
class Stations {
private:
	int  stationNumber;
	int  nextStation;
	Queue<passengers>* waiting_passengers;
	Queue<passengers>* WP_waitingPassengers;
	Queue<bus*>* boarded_busses;
	Queue<bus*>* wp_boarded_busses;


public:
	Stations()
	{
		stationNumber = 0;
		nextStation = NULL;
		waiting_passengers = new Queue<passengers>;
		WP_waitingPassengers = new Queue<passengers>;
		boarded_busses = new Queue<bus*>;
		wp_boarded_busses = new Queue<bus*>;
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
	void board_bus(bus* to_board)
	{
		boarded_busses->enqueue(to_board);
	}
	void board_wp_bus(bus* to_board)
	{
		wp_boarded_busses->enqueue(to_board);
	}

	int get_boarded_count()
	{
		return boarded_busses->get_count();
	}

	int get_wp_boarded_count()
	{
		return wp_boarded_busses->get_count();
	}

	int getStationNumber() {
		return stationNumber;
	}

	/*int getNextStation() {
		return nextStation;
	}*/

	Queue<passengers>* getWaitingPassengers() {
		return waiting_passengers;
	}

	Queue<passengers>* get_WP_WaitingPassengers() {
		return WP_waitingPassengers;
	}
	//Release busses, sets the bus' pointer , board bus into next station
	bus* release_bus()
	{
		bus* released = wp_boarded_busses->dequeue();
		company manager;
		int st_size = manager.num_of_stations() - 1;
		released->set_current_station_num(released->get_current_station_num() + 1);
		int st_num = released->get_current_station_num();
		released->set_current_station_ptr(manager.get_station_ptr(st_size-(st_num%(st_size*2))));
		Stations* station=released->get_current_station_ptr();
		station->board_wp_bus(released);
	}
	
	bus* release_wp_bus()
	{
		bus* released = boarded_busses->dequeue();
		company manager;
		int st_size = manager.num_of_stations() - 1;
		released->set_current_station_num(released->get_current_station_num() + 1);
		int st_num = released->get_current_station_num();
		released->set_current_station_ptr(manager.get_station_ptr(st_size - (st_num % (st_size * 2))));
		Stations* station = released->get_current_station_ptr();
		station->board_bus(released);
	}

	// Setter methods
	void setStationNumber(int newStationNo) {
		stationNumber = newStationNo;
	}

	/*void setNextStation(int newNextStation) {
		nextStation = newNextStation;
	}*/

	/*void Add_to_waiting_passengers(passengers& new_passenger) {
		waiting_passengers->priority_enqueue(new_passenger,new_passenger.getPriorityNo());
	}*/
};

#endif // !STATION