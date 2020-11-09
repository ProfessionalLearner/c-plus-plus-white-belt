#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const vector<int> MONTHS = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main() {
	int q;
	cin >> q;
	int month = 0;
	vector<vector<string>> days_events(MONTHS[month]);
	//vector<string> operations = {"ADD", "ADD", "ADD", "ADD"};

	for(int i = 0; i < q; i++)
	//for (auto operation : operations)
		{
		string operation;
		cin >> operation;

		if (operation == "ADD") {
			int day;
			string event;
			cin >> day >> event;
			--day;
			days_events[day].push_back(event);
		} else if (operation == "DUMP") {
			int day;
			cin >> day;
			--day;

			cout << days_events[day].size() << " ";

			for(const string& event : days_events[day]) {
				cout << event << " ";
			}

			cout << endl;
		} else if (operation == "NEXT") {
			const int old_month_length = MONTHS[month];

			month = (month + 1) % MONTHS.size();

			const int new_month_length = MONTHS[month];

			if(old_month_length > new_month_length) {
				vector<string>& last_day = days_events[new_month_length - 1];

				for(int j = new_month_length; j < old_month_length; j++) {
					last_day.insert(end(last_day), begin(days_events[j]), end(days_events[j]));
				}
			}

			days_events.resize(new_month_length);
		}
	}

	return 0;
}
