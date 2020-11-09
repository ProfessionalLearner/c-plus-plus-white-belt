#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;

	map<string, vector<string>> stops_to_buses, buses_to_stops;

	for(int i = 0; i < q; i++) {
		string operation;
		cin >> operation;

		if(operation == "NEW_BUS") {
			string bus;
			cin >> bus;
			int stops_count;
			cin >> stops_count;

			vector<string>& stops = buses_to_stops[bus];
			stops.resize(stops_count);

			for (string& stop : stops) {
				cin >> stop;
				stops_to_buses[stop].push_back(bus);
			}
		} else if(operation == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;

			if(stops_to_buses.count(stop) == 0) {
				cout << "No stop" << endl;
			} else {
				for(const string& bus : stops_to_buses[stop]) {
					cout << bus << " ";
				}

				cout << endl;
			}
		} else if(operation == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if(buses_to_stops.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				for (const string& stop : buses_to_stops[bus]) {
					cout << "Stop " << stop << ": ";

					if (stops_to_buses[stop].size() == 1) {
						cout << "no interchange";
					} else {
						for (const string& other_bus : stops_to_buses[stop]) {
							if (bus != other_bus) {
								cout << other_bus << " ";
							}
						}
					}

					cout << endl;
				}

			}
		} else if (operation == "ALL_BUSES") {
			if(buses_to_stops.empty()) {
				cout << "No buses" << endl;
			} else {
				for (const auto& item : buses_to_stops) {
					cout << "Bus " << item.first << ": ";
					for (const auto& stop : item.second) {
						cout << stop << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}
