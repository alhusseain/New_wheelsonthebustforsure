#include "Time_simulator.cpp"
#include"Events.cpp"


using namespace std;
void begin_simulation()
{
	simulator simulate;
	time_def begin_work("4:00");
}

/*int main()
{
	time_def last_time("1:24");
	simulator simulate;
	while (simulate.get_time_def() != last_time) {
		simulate.plus_one();
		cout << simulate.get_current_time() << endl;
		Sleep(900);
		system("cls");
		
	};
}*/