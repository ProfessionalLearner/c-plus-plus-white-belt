#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

string FindNameByYear(const map<int, string>& names, const int& year) {
	string name;

	for (const auto& item : names) {
		if(item.first <= year) {
			name = item.second;
		} else {
			break;
		}
	}

	return name;
}

vector<string> GetHistoryByYear(const map<int, string>& names, const int& year) {
	vector<string> names_history;

	for (const auto& item : names) {
		if (item.first <= year && (names_history.empty() || names_history.back() != item.second)) {
				names_history.push_back(item.second);
		}
	}

	reverse(begin(names_history), end(names_history));
	return names_history;
}

string BuildName(vector<string> names) {
	  if(names.empty()) {
		  return "";
	  }

	  string name = names[0];

	  for(int i = 1; i < (int) names.size(); i++) {
		  if(i == 1) {
			  name += " (";
		  } else {
			  name += ", ";
		  }

		  name += names[i];
	  }

	  if(names.size() > 1) {
		  name += ")";
	  }

	  return name;
}

class Person {
public:
	Person(const string& first_name, const string& last_name, int new_birth_year) {
		birth_year = new_birth_year;
		first_names[birth_year] = first_name;
		last_names[birth_year] = last_name;
	}
  void ChangeFirstName(int year, const string& first_name) {
	  if(year >= birth_year) {
		  first_names[year] = first_name;
	  }
  }
  void ChangeLastName(int year, const string& last_name) {
	  if(year >= birth_year) {
		  last_names[year] = last_name;
	  }
  }
  string GetFullName(int year) const {
	  if(year < birth_year) {
		  return "No person";
	  }
	  string first_name = FindNameByYear(first_names, year);
	  string last_name = FindNameByYear(last_names, year);

	  return first_name + " " + last_name;

  }

  string GetFullNameWithHistory(int year) const {
	  if(year < birth_year) {
		  return "No person";
	  }

	  vector<string> first_name_history = GetHistoryByYear(first_names, year);
	  vector<string> last_name_history = GetHistoryByYear(last_names, year);

	  string first_name = BuildName(first_name_history);
	  string last_name = BuildName(last_name_history);

	  return first_name + " " + last_name;
   }
private:
  	  int birth_year;
  	  map<int, string> first_names;
  	  map<int, string> last_names;
};
