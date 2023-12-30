
#ifndef TIME_D
#define TIME_D
#include <iostream>
#include <string>
#include<cstring>
using namespace std;

class time_def
{
private:
	string same_time;
	int hours, minutes;
	int count_to_delimiter;
	int total_minutes;
public:
	time_def()
	{
		hours = 0;
		minutes = 0;
		count_to_delimiter = 0;
		total_minutes = 0;
	};
	time_def(string time_string)
	{
		total_minutes = 0;
		same_time = time_string;
		count_to_delimiter = 0;
		while (1)
		{
			if (time_string[count_to_delimiter] == ':') break;
			else count_to_delimiter++;
		}
		if (count_to_delimiter == 1)
		{
			hours = stoi(time_string.substr(0, 1));
			minutes = stoi(time_string.substr(2, time_string.size() - 2));
		}
		else {
			hours = stoi(time_string.substr(0, 2));
			minutes = stoi(time_string.substr(3, time_string.size() - 3));
		}
	}

	void set_time(string time_string)
	{
		same_time = time_string;
		count_to_delimiter = 0;
		bool found = false;
		while (count_to_delimiter<time_string.size())
		{
			if (time_string[count_to_delimiter] == ':')
			{
				found = true;
				break;
			}
			else count_to_delimiter++;
		}
		if (found)
		{
			if (count_to_delimiter == 1)
			{
				hours = stol(time_string.substr(0, 1));
				minutes = stol(time_string.substr(2, time_string.size() - 2));
			}
			else {
				hours = stol(time_string.substr(0, 2));
				minutes = stol(time_string.substr(3, time_string.size() - 3));
			}
		}
	}
	string get_time()
	{
		return to_string(hours)+":"+to_string(minutes);
	}
	int convert_all_to_min()
	{
		total_minutes = hours * 60 + minutes;
		return total_minutes;
	}
	string return_to_format_from_minutes(int minutes)
	{
		string to_return_hours = to_string(minutes / 60);
		string to_return_minutes = to_string(minutes % 60);
		return to_return_hours + ":" + to_return_minutes;



	}

	void operator+(time_def& x)
	{
		int current_class_minutes = convert_all_to_min();
		int guest_class_minutes = x.convert_all_to_min();
		int sum_minutes = current_class_minutes + guest_class_minutes;
		same_time = return_to_format_from_minutes(sum_minutes);
	}


	void operator-(time_def& x)
	{
		int current_class_minutes = convert_all_to_min();
		int guest_class_minutes = x.convert_all_to_min();
		int diff_minutes = abs(current_class_minutes - guest_class_minutes);
		same_time = return_to_format_from_minutes(diff_minutes);
	}

	bool operator==(time_def& x)
	{
		if (this->convert_all_to_min() == x.convert_all_to_min())
		{
			return true;

		}
		else return false;
	}
	bool operator!=(time_def& x)
	{
		if (convert_all_to_min() != x.convert_all_to_min())
		{
			return true;

		}
		else return false;
	}

	bool operator<=(time_def& x)
	{
		if (convert_all_to_min() <= x.convert_all_to_min())
		{
			return true;

		}
		else return false;
	}
	/*
	void display()
	{
		cout << "hours: " << hours << endl;
		cout << "minutes: " << minutes;
	}*/
};
/*
int main()
{
	time_def inter("4:3"),inter2("5:57");
	cout << inter + inter2;
}*/

#endif TIME_D