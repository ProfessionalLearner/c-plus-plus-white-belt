#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsPalindrom(string word) {
	int midPoint =  word.length() / 2;
	for(int i = 0; i <= midPoint; i++) {
		if(word[i] != word[word.length() - i - 1]) {
			return false;
		}
	}

	return true;
}


int main() {
	string s;
	cin >> s;
	cout << IsPalindrom(s);
	return 0;
}
