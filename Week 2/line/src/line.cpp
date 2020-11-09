#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int q;
	cin >> q;

	vector<bool> is_nervous;

	for(int i = 0; i < q; i++) {
		string operation;
		cin >> operation;

		if(operation == "WORRY" || operation == "QUIET") {
			int person;
			cin >> person;

			is_nervous[person] = (operation == "WORRY");

		} else if (operation == "COME") {
			int people;
			cin >> people;

			is_nervous.resize(is_nervous.size() + people, false);
		} else if (operation == "WORRY_COUNT") {
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;
		}
	}
	return 0;
}
