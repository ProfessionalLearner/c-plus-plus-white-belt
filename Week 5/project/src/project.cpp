#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <map>
#include <set>
using namespace std;


class Date {
public:
  Date(const int& new_year, const int& new_month, const int& new_day) {
	  year = new_year;
	  if(new_month > 12 || new_month < 1)  {
		  throw logic_error("Month value is invalid: " + to_string(new_month));
	  }

	  month = new_month;

	  if(new_day > 31 || new_day < 1) {
		  throw logic_error("Day value is invalid: " + to_string(new_day));
	  }

	  day = new_day;
  }
  int GetYear() const {
	  return year;
  }
  int GetMonth() const {
	  return month;
  }
  int GetDay() const {
	  return day;
  }

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector < rhs_vector;
}

ostream& operator << (ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear()
			<< "-" << setw(2) << setfill('0') << date.GetMonth()
			<< "-" << setw(2) << setfill('0') << date.GetDay();
	return stream;
}



class Database {
public:
  void AddEvent(const Date& date, const string& event) {
  	  storage[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
  	  if(storage.count(date) > 0 && storage[date].count(event) > 0) {
  		  storage[date].erase(event);
  		  return true;
  	  }

  	  return false;
  }

  int  DeleteDate(const Date& date) {
  	  if (storage.count(date) == 0) {
  		  return 0;
  	  } else {
  		  const int n = storage[date].size();
  		  storage.erase(date);
  		  return n;
  	  }
  }

  set<string> Find(const Date& date) const {
	  if(storage.count(date) > 0) {
		  return storage.at(date);
	  } else {
		  return {};
	  }
  }


  void Print() const {
	  for(const auto& item : storage) {
		  for(const string& event : item.second) {
			  cout << item.first << " " << event << endl;
		  }
	  }
  }
private:
  map<Date, set<string>> storage;
};


/** Date CreateDate(const string& s) {
	istringstream ss(s);
	int year;
	if(ss.eof()) {
		throw logic_error("Wrong date format: " + s);
	}
	ss >> year;
	if(ss.peek() != '-' || ss.peek() == EOF) {
		throw logic_error("Wrong date format: " + s);
	}
	ss.ignore(1);
	if(ss.eof()) {
		throw logic_error("Wrong date format: " + s);
	}
	int month;
	ss >> month;
	if(ss.peek() != '-' || ss.peek() == EOF) {
		throw logic_error("Wrong date format: " + s);
	}
	ss.ignore(1);
	if(ss.eof()) {
		throw logic_error("Wrong date format: " + s);
	}
	int day;
	ss >> day;
	if(!ss.eof()) {
		throw logic_error{"Wrong date format: " + s};
	}

	return Date(year, month, day);
}
*/

Date CreateDate(const string& s) {
	istringstream ss(s);
	bool correct = true;

	int year;
	correct = correct && (ss >> year);
	correct = correct && (ss.peek() == '-');
	ss.ignore(1);

	int month;
	correct = correct && (ss >> month);
	correct = correct && (ss.peek() == '-');
	ss.ignore(1);

	int day;
	correct = correct && (ss >> day);
	correct = correct && ss.eof();

	if (!correct) {
		throw logic_error("Wrong date format: " + s);
	}

	return Date(year, month, day);
}
int main() {
	try {
	  Database db;

	  string command;
	  while (getline(cin, command)) {
		  stringstream ss(command);

		  string operation;
		  ss >> operation;

		  if(operation == "Add") {

			  string date_str, event;
			  ss >> date_str >> event;
			  const Date date = CreateDate(date_str);
			  db.AddEvent(date, event);

		  } else if (operation == "Del") {

			  string date_str;
			  string event;
			  ss >> date_str;
			  if(!ss.eof()) {
				  ss >> event;
			  }

			  const Date date = CreateDate(date_str);
			  if(event.empty()) {
				  const int n = db.DeleteDate(date);
				  cout << "Deleted " << n << " events" << endl;
			  } else {
				  if(db.DeleteEvent(date, event)) {
					  cout << "Deleted successfully" << endl;
				  } else {
					  cout << "Event not found" << endl;
				  }
			  }
		  } else if (operation == "Find") {

			  string date_str;
			  ss >> date_str;
			  const Date date = CreateDate(date_str);
			  for(const string& event : db.Find(date)) {
				  cout << event << endl;
			  }

		  } else if (operation == "Print") {

			 db.Print();

		  } else if(!operation.empty()) {

			throw logic_error("Unknown command: " + operation);

		  }
	  }

	} catch (exception& e) {
		cout << e.what() << endl;
	  }

  return 0;
}
