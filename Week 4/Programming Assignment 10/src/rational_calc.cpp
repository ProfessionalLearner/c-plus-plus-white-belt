#include <iostream>
#include <map>
#include <set>
#include <exception>
#include <vector>
#include <cmath>
using namespace std;

class Rational {
public:
  Rational() {
	  p = 0;
	  q = 1;
  }
  Rational(int numerator, int denominator) {
	  if(denominator == 0) {
		  throw invalid_argument("Invalid argument");
	  }
	  int a = numerator;
	  int b = denominator;
	  int c = 0;

	  while(b != 0) {
		  c = a % b;
		  a = b;
		  b = c;
	  }

	  int gcd = a;
	  if (denominator / a < 0) {
		  numerator = -numerator;
		  denominator = -denominator;
	  }
	  p = numerator / gcd;
	  q = denominator / gcd;
  }

  int Numerator() const {
	  return p;
  }
  int Denominator() const {
	  return q;
  }
private:
  int p;
  int q;
};

Rational operator + (const Rational& lhs, const Rational& rhs) {
	return {lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()};
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
	return {lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()};
}

bool operator == (const Rational& lhs, const Rational& rhs) {
	return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
	return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	if(rhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& stream, Rational& r) {
	int p, q;
	char c;
	stream >> p >> c >> q;
	if(stream && c == '/') {
		r = Rational(p, q);
	}

	return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
	return stream << r.Numerator() << '/' << r.Denominator();
}

bool operator < (const Rational& lhs, const Rational& rhs) {
	return (lhs - rhs).Numerator() < 0;
}

int main() {
	Rational r1, r2;
	char operation;

	try {
		cin >> r1 >> operation >> r2;
		if(operation == '+') {
			cout << r1 + r2 << endl;
		} else if(operation == '-') {
			cout << r1 - r2 << endl;
		} else if(operation == '*') {
			cout << r1 * r2 << endl;
		} else if(operation == '/') {
			try {
				cout << r1 / r2 << endl;
			} catch (domain_error& de) {
				cout << de.what();
			}
		}
	} catch(invalid_argument& ia) {
		cout << ia.what();
	}
	return 0;
}
