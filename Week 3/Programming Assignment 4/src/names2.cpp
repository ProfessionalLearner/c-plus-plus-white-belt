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

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	  last_names[year] = last_name;
  }
  string GetFullName(int year) {
	  string first_name = FindNameByYear(first_names, year);
	  string last_name = FindNameByYear(last_names, year);

	  return BuildFullName(first_name, last_name);

  }

  string BuildFullName(const string& first_name, const string& last_name) {
	  if (first_name.empty()  && last_name.empty()) {
		  return "Incognito";
	  } else if (first_name.empty()) {
		  return last_name + " with unknown first name";
	  } else if (last_name.empty()) {
		  return first_name + " with unknown last name";
	  } else {
		  return first_name + " " + last_name;
	  }
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


  string GetFullNameWithHistory(int year) {
	  vector<string> first_name_history = GetHistoryByYear(first_names, year);
	  vector<string> last_name_history = GetHistoryByYear(last_names, year);

	  string first_name = BuildName(first_name_history);
	  string last_name = BuildName(last_name_history);

	  return BuildFullName(first_name, last_name);
   }
private:
  	  map<int, string> first_names;
  	  map<int, string> last_names;
};
