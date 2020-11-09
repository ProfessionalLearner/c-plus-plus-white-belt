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
		  throw invalid_argument("");
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


Rational operator * (const Rational& lhs, const Rational& rhs) {
	return {lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator()};
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
	if(rhs.Numerator() == 0) {
		throw domain_error("");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

