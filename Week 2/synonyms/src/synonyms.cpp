#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int q;
	cin >> q;

	map<string, set<string>> synonyms;

	for(int i = 0; i < q; i++) {
		string operation;
		cin >> operation;

		if (operation == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;

			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		} else if (operation == "COUNT") {
			string word;
			cin >> word;
			cout << synonyms[word].size() << endl;
		} else if (operation == "CHECK") {
			string word1, word2;

			cin >> word1 >> word2;
			if (synonyms[word1].count(word2) == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
