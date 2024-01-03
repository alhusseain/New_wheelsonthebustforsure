#include<iostream>
#include<fstream>
#include<string>
#include"passengers.h"
#include"station.h"
#include"Events.cpp"
#include"Structures.h"
using namespace std;
class company
{
private:
	int S; 		// number of stations
	int ST; 	//time between each two successive stations
	int WBus_count;
	int MBus_count;
	int WBus_capacity;
	int MBus_capacity;
	int J; 			//number of trips the bus completes before performing a checkup
	int C_WBus;		// the check up duration in minutes for WBus
	int C_MBus;		//the checkup duration in minutes for MBus
	int maxW;		//maximum waiting time
	int on_off_time;//get on/off time in seconds
	int E; 			//number of events
	char event_type;
	string passenger_type;
	string string_time;
	time_def event_time;
	int id;
	int start_station;
	int end_station;
	char* event_types;
	string special_description;
	Queue<Arrival_event> A_events_list;
	Queue<Leave_event> L_events_list;
	Linked_List<Stations> stations_list;



public:
	company()
	{
		ifstream randomizer("random_file.txt");
		randomizer >> S >> ST;
		randomizer >> WBus_count >> MBus_count;
		randomizer >> WBus_capacity >> MBus_capacity;
		randomizer >> J >> C_WBus >> C_MBus;
		randomizer >> maxW >> on_off_time;
		randomizer >> E;
		event_types = new char[E];
		stations_list.create_array(S);


		//*****************************************************************************************************************************************************

		// FILLING EVENTS LIST --------------------------------------------------------------------------------------------------------------------------------
		for (int i = 0; i < E; i++)
		{
			randomizer >> event_type;
			event_types[i] = event_type;
			if (event_type == 'A') {
				randomizer >> passenger_type >> string_time >> id >> start_station >> end_station;
				if (passenger_type == "SP")
				{
					randomizer >> special_description;
				}
				Arrival_event new_event(start_station, end_station, passenger_type, special_description, string_time, id, event_type);
				A_events_list.enqueue(new_event);
			}
			else
			{
				randomizer >> string_time >> id >> end_station;
				Leave_event new_event(end_station, string_time, id, event_type);
				L_events_list.enqueue(new_event);
			}


		}

		//---------------------------------------------------------------------------------------------------------------------------------------------------------

		//*********************************************************************************************************************************************************

		//FILLING STATIONS LIST ------------------------------------------------------------------------------------------------------------------------------------

		for (int i = 0; i < S; i++)
		{
			Stations stn_ptr;
			stn_ptr.setStationNumber(i+1);
			stations_list.set_value(stn_ptr, i);


		}



		//----------------------------------------------------------------------------------------------------------------------------------------------------------

		for (int i = 0; i < E; i++)
		{



			if (event_types[i] == 'A')
			{
				Arrival_event to_execute = A_events_list.dequeue();
				//cout << to_execute.get_direction() << endl;
				int index = to_execute.get_start_station() - 1;
				//stations_list.get_value_pointer(index);
				to_execute.execute(stations_list.get_value_pointer(index));
			}
			/*else
			{
				Leave_event to_execute_leave = L_events_list.dequeue();
				int index = to_execute_leave.get_end_station() - 1;
				Stations*  current_station = stations_list.get_value(index);
				to_execute_leave.execute(current_station);
			}*/




		}


	}
	/*void display()
	{
		cout << S << " " << ST << endl;
		cout << WBus_count << " " << MBus_count << endl;
		cout << WBus_capacity << " " << MBus_capacity << endl;
		cout << J << " " << C_WBus << " " << C_MBus << endl;
		cout << maxW << " " << on_off_time << endl;
		cout << E << endl << endl;
		for (int i; i < E; i++)
		{
			if (event_types[i] == 'A')
			{
				Arrival_events_list.dequeue(new_event)
			}
		}
	}*/

	void display_events()
	{
		for (int i = 0; i < E; i++)
		{

			Arrival_event e = A_events_list.dequeue();
			if (e.get_event_type() == 'A')
			{
				cout << e.get_event_type() << " ";
				cout << e.get_passenger_type() << " ";
				cout << e.get_event_time_class().get_time() << " ";
				cout << e.get_ID() << " ";
				cout << e.get_start_station() << " ";
				cout << e.get_end_station() << " ";
				cout << e.get_direction() << " ";
				if (e.get_passenger_type() == "SP")
				{
					cout << " " << e.get_special_description();
				}
				cout << endl;
			}
			else
			{
				cout << e.get_event_type() << " ";
				cout << e.get_event_time_class().get_time() << " ";
				cout << e.get_ID() << " ";
				cout << e.get_end_station() << endl;
			}

		}
	}
	int num_of_stations() { return S; }
	int time_between_stations() { return ST; }
	int W_count() { return WBus_count; }
	int M_count() { return MBus_count; }
	int W_capacity() { return WBus_capacity; }
	int M_capacity() { return MBus_capacity; }
	int num_before_checkup() { return J; }
	int W_checkup_duration() { return C_WBus; }
	int M_checkup_duration() { return C_MBus; }
	int maximum_waiting_time() { return maxW; }
	int get_on_off_time() { return on_off_time; }

	/*void events_set_up()
	{

	}*/
	void prioritizesp(Queue<passengers>* sp) {
		Queue<passengers>* aged = new Queue<passengers>;
		Queue<passengers>* POD = new Queue<passengers>;
		Queue<passengers>* Pregnant = new Queue<passengers>;

		int size = sp->get_count();

		for (int i = 0; i < size; i++) {
			passengers temp = sp->dequeue();
			if (temp.get_description() == "aged")
				aged->enqueue(temp);
			else if (temp.get_description() == "POD")
				POD->enqueue(temp);
			else if (temp.get_description() == "Pregnant")
				Pregnant->enqueue(temp);
		}

		// Prioritize by enqueuing back to sp in the desired order
		int agedCount = aged->get_count();
		for (int i = 0; i < agedCount; i++) {
			passengers temppass = aged->dequeue();
			sp->enqueue(temppass);
		}

		int podCount = POD->get_count();
		for (int i = 0; i < podCount; i++) {
			passengers tempn2 = POD->dequeue();
			sp->enqueue(tempn2);
		}

		int pregCount = Pregnant->get_count();
		for (int i = 0; i < pregCount; i++) {
			passengers tempn2 = Pregnant->dequeue();
			sp->enqueue(tempn2);
		}

		// Don't forget to delete the temporary queues to avoid memory leaks
		delete aged;
		delete POD;
		delete Pregnant;
	}
 


	
	void prioritizequeue(Queue<passengers>* rateb){
		Queue<passengers>* zeros=new Queue<passengers>; Queue<passengers>* ones = new Queue < passengers>;
		int size = rateb->get_count();
		
		
		for (int i=0; i < size; i++) {
			passengers temp = rateb->dequeue();
			if (temp.getPriorityNo() == 0) zeros->enqueue(temp);
			else if (temp.getPriorityNo() == 1) {
				ones->enqueue(temp);
				
			}
		}
		prioritizesp(zeros);
		
		int onescount = ones->get_count();
		for (int i = 0; i < onescount; i++) {
			passengers temppass = ones->dequeue();
			rateb->enqueue(temppass);
			
			}
		
		int zeroscount = zeros->get_count();
		for (int i=0; i < zeroscount; i++) {
			passengers tempn2 = zeros->dequeue();
			 
			rateb->enqueue(tempn2);
		
			
	   }
		
	}


	void display_waiting_passengers()
	{
		int choice;
		time_def compared_time;
		string compared_time_string;
		int Station_NO;
		cout << "Input Time of your choice: ";
		cin >> compared_time_string;
		compared_time.set_time(compared_time_string);
		cout << "Input Station number: ";
		cin >> Station_NO;
		for (int j = 0; j < stations_list.get_count(); j++)
		{

			if (Station_NO == j + 1)
			{
				cout << "##################################### STATION " << j + 1 << " ####################################################" << endl << endl;
				Stations test_station = stations_list.get_value(j);

				Queue<passengers>* current_waiting_passengers = test_station.getWaitingPassengers();
				prioritizequeue(current_waiting_passengers);
				Queue<passengers>* current_WP_waiting_passengers = test_station.get_WP_WaitingPassengers();
				int counter = current_waiting_passengers->get_count();
				int WP_counter = current_WP_waiting_passengers->get_count();
				
				for (int i = 0; i < counter; i++)
				{
					passengers person = current_waiting_passengers->dequeue();
					time_def test_time = person.get_arrival_time();
					if (test_time<=compared_time)
					{
						cout << "----------------------------- Person " << i + 1 << "------------------------" << endl;
						cout << " ID : " << person.getPassengerId() << endl;
						cout << " Arrival Time : " << person.get_arrival_time() << endl;
						cout << " Direction : " << person.get_direction() << endl;
						cout << " Passenger Type:" << person.getPassengerType() << endl;
						cout << " Priority Num: " << person.getPriorityNo() << endl;
						cout << person.get_description();
						
					}
				}
				
				for (int i = 0; i < WP_counter; i++)
				{
					passengers wp_person = current_WP_waiting_passengers->dequeue();
					time_def test_time = wp_person.get_arrival_time();
					if (test_time<=compared_time)
					{
						cout << "----------------------------- WP Person " << i + 1 << "------------------------" << endl;
						cout << " ID : " << wp_person.getPassengerId() << endl;
						cout << " Arrival Time : " << wp_person.get_arrival_time() << endl;
						cout << " Direction : " << wp_person.get_direction() << endl;
						cout << " Passenger Type:" << wp_person.getPassengerType() << endl;
					}
				}
				cout << endl;
			}
		}
		
	}
	
	Queue<Arrival_event> get_arrival_event_list()
	{
		return A_events_list;
	}



};

int main()
{
	company test;
	test.display_waiting_passengers();

}
