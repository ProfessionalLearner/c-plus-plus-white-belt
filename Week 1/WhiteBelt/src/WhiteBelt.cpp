#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include <cmath>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector<string> v(n);

	for(string& s : v) {
		cin >> s;
	}

	sort(begin(v), end(v), [](const string& a, const string& b) {
		return lexicographical_compare(begin(a), end(a), begin(b), end(b),
				[](char ca, char cb) {
			return tolower(ca) < tolower(cb);
		});
	});

	for(const string& s : v) {
		cout << s << " ";
	}
	return 0;
}
