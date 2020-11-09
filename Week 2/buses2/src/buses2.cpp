#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;

	map<vector<string>, int> buses;

	for (int i = 0; i < q; i++) {
		int stops_count;
		cin >> stops_count;

		vector<string> stops(stops_count);
		for(string& stop : stops) {
			cin >> stop;
		}

		if (buses.count(stops) == 0) {
			int number = buses.size() + 1;
			buses[stops] = number;
			cout << "New bus " << number << endl;
		} else {
			cout << "Already exists for " << buses[stops] << endl;
		}
	}
	return 0;
}
