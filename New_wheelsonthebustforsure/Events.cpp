#include"time.cpp"
#include"station.h"
#include"Passengers.h"

class Event
{
protected:
	char event_type;
	time_def event_time;
	int ID;
	int start_station, end_station;
	string direction;
	string passenger_type;
	string special_description;
	string time_string;

public:
	char get_event_type() { return event_type; }
	Event():event_type(NULL),ID(NULL),start_station(NULL),end_station(NULL), direction(""),passenger_type(""),special_description(""),time_string("0:0") {}
	
	Event(int end_station, string time_string, int identity, char type)
	{
		this->end_station = end_station;
		this->time_string = time_string;
		ID = identity;
		event_type = type;
		event_time.set_time(this->time_string);
		start_station = NULL;
		passenger_type = " ";
		special_description = " ";
		direction = "";
	}
	Event(int start_station, int end_station, string passenger_type, string special_description, string time_string, int identity, char type)
	{
		event_time.set_time(time_string);
		ID = identity;
		event_type = type;
		this->start_station = start_station;
		this->end_station = end_station;
		this->passenger_type = passenger_type;
		this->special_description = special_description;
		if ((this->end_station - this->start_station > 0)) direction = "FWD";
		else direction = "BCK";
	}
	time_def get_event_time_class()
	{
		return event_time;
	}

	int get_ID()
	{
		return ID;
	}
	int get_start_station() { return start_station; }
	int get_end_station() { return end_station; }
	string get_direction() { return  direction; }
	string get_passenger_type() { return passenger_type; }
	string get_special_description() { return special_description; }
	virtual void execute(Stations* stationlist)
	{ 
	}
};

class Arrival_event:public Event
{
private:
	
	/*int start_station, end_station;
	string direction;
	string passenger_type;
	string special_description;*/
public:
	Arrival_event(){}
	Arrival_event(int start_station, int end_station, string passenger_type, string special_description, string time_string, int identity,char type) :Event(start_station,end_station,passenger_type,special_description,time_string, identity,type)
	{
		/*this->start_station = start_station;
		this->end_station = end_station;
		this->passenger_type = passenger_type;
		this->special_description = special_description;
		if ((this->end_station - this->start_station > 0)) direction = "FWD";
		else direction = "BCK";*/

	}
	
	/*int get_start_station() override { return start_station; }
	int get_leave_station() override { return end_station; }
	string get_direction() override { return direction; }
	string get_passenger_type() override
	{
		return passenger_type;
	}

	string get_special_description() override
	{
		return special_description;
	}
	*/
	void execute(Stations* stationlist) override 
	{
		passengers NewPassenger(ID,passenger_type,special_description,direction,event_time);
		if (passenger_type == "SP") stationlist->getWaitingPassengers()->enqueue(NewPassenger);
		else if (passenger_type == "NP")
		{
			Queue<passengers>* current_station = stationlist->getWaitingPassengers();
			current_station->enqueue(NewPassenger);
		}
		else {
			Queue<passengers>* current_station = stationlist->get_WP_WaitingPassengers();
			current_station->enqueue(NewPassenger);
		}
	}
};

class Leave_event :public Event
{
private:
	//int leave_station;
public:
	Leave_event(int end_station, string time_string, int identity,char type) :Event( end_station,time_string, identity,type)
	{

	}
	//int get_leave_station() { return leave_station; }
	void execute(Stations* stationlist) override
	{
		Queue<passengers>* current_waiting = stationlist->getWaitingPassengers();
		current_waiting->dequeue();
	}

};







/*
int main()
{
	Leave_event first(1, "4:40",3);
	cout << "The event time: " << first.get_event_time_class().get_time() << endl;
	cout << "Passenger type: " << first.get_leave_station() << endl;
	cout << "ID: " << first.get_ID();
	
}*/
