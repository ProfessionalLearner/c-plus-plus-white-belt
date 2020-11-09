#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include <cmath>
using namespace std;


map<char, int> BuildCharCounters(const string& word) {
	map<char, int> result;
	for(char c : word) {
		++result[c];
	}
	return result;
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string word_one, word_two;
		cin >> word_one >> word_two;
		if(BuildCharCounters(word_one) == BuildCharCounters(word_two)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
