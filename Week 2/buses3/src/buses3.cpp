#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int q;
	cin >> q;

	map<set<string>, int> buses;

	for (int i = 0; i < q; i++) {
		int n;
		cin >> n;

		set<string> stops;

		for (int j = 0; j < n; j++) {
			string stop;
			cin >> stop;
			stops.insert(stop);
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
