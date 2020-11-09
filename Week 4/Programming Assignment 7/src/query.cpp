#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
	Student(const string& new_first, const string& new_last, const int& new_day, const int& new_month, const int& new_year) {
		first_name = new_first;
		last_name = new_last;
		day = new_day;
		month = new_month;
		year = new_year;
	}
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

int main() {

	int n;
	string first_name;
	string last_name;
	int day;
	int month;
	int year;

	vector<Student> v;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> first_name >> last_name >> day >> month >> year;
		Student student{first_name, last_name, day, month, year};
		v.push_back(student);
	}

	int m;
	cin >> m;

	for(int j = 0; j < m; j++) {
		string operation;
		int k;

		cin >> operation >> k;
		if(operation == "name" && k > 0 && k <= n) {
			cout << v[k-1].first_name << " " << v[k-1].last_name << endl;
		} else if(operation == "date" && k > 0 && k <= n) {
			cout << v[k-1].day << "." << v[k-1].month << "." << v[k-1].year << endl;
		} else {
			cout << "bad request" << endl;
		}
	}
	return 0;
}
