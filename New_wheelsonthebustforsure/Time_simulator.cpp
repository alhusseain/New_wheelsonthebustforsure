#include<iostream>
#include<string>
#include "time.cpp"
#include<windows.h>
using namespace std;
class simulator
{
private:
	time_def simulation_time;
public:
	simulator()
	{
		simulation_time.set_time("0:0");
	}
	void plus_one() {
		int minutes = simulation_time.convert_all_to_min() + 1;
		simulation_time.set_time(simulation_time.return_to_format_from_minutes(minutes));
	}
	time_def get_time_def()
	{
		return simulation_time;
	}
	string get_current_time()
	{
		return simulation_time.get_time();
	}

};

/*
int main()
{
	time_def last_time("1:24");
	simulator simulate;
	while (simulate.get_time_def() != last_time) {
		simulate.plus_one();
		cout<<simulate.get_current_time()<<endl;
		system("cls");
		Sleep(3600);

	};
}*/