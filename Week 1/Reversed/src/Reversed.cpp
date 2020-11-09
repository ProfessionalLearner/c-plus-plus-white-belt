#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int>& v) {
	vector<int> tmp;
	for(int i = v.size() - 1; i >= 0; i--) {
		tmp.push_back(v[i]);
	}
	v = tmp;
}
