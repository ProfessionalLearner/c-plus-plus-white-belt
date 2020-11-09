#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include <cmath>
using namespace std;




int main() {
	int q;
	cin >> q;

	map<string, string> country_to_capital;

	for(int i = 0; i < q; i++) {
		string operation;
		cin >> operation;

		if(operation == "CHANGE_CAPITAL") {
			string country, capital;
			cin >> country >> capital;

			if(country_to_capital.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			} else {
				const string& old_capital = country_to_capital[country];
				if(old_capital == capital) {
					cout << "Country " << country << " hasn't changed its capital" << endl;
				} else {
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << capital << endl;
				}
			}

			country_to_capital[country] = capital;
		} else if(operation == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			if(old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] << " has been renamed to " << new_country_name << endl;
				country_to_capital[new_country_name] = country_to_capital[old_country_name];
				country_to_capital.erase(old_country_name);
			}
		} else if(operation == "ABOUT") {
			string country;
			cin >> country;

			if(country_to_capital.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
			}
		} else if(operation == "DUMP") {

			if(country_to_capital.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for(const auto& item : country_to_capital) {
					cout << item.first << "/" << item.second << endl;
				}
			}
		}
	}
	return 0;
}
