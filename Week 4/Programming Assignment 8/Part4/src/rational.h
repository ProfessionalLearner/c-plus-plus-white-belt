/*
 * rational.h
 *
 *  Created on: 25 θών. 2020 γ.
 *      Author: DELL
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_
#pragma once

class Rational {
public:
  Rational() {
	  p = 0;
	  q = 1;
  }
  Rational(int numerator, int denominator) {
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


#endif /* RATIONAL_H_ */
