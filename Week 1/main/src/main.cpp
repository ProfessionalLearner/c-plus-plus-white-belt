#include <iostream>
#include <vector>
using namespace std;

int Factorial(int x) {
	if (x <= 1) {
		return 1;
	} else {
		x = x * (Factorial((x-1)));
		return x;
	}
}

int main() {
	int a;
	cin >> a;

	cout << Factorial(a);
	return 0;
}
