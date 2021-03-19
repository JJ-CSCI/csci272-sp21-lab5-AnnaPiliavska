//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real {
private:
  double n;
public:
  Real() {};
  Real (double num) : n{num} {};
  double GetReal() {
    return n;
  }
  // An overwritten multiplication operation that adds a real value to the stored value in an object of Real class, and returns the results as an **object of Real class** (not double).
  Real operator*(double rhs) const {
    Real res {n * rhs};
    return res;
  }
};
class Complex : public Real {
private:
  using Real::Real;
  double c;
   // you defined 2 data members
   // You only need one, the other one
   // need to come from the base class
public:
  Complex(double num, double im) : Real{num}, c{im} {};  
  double GetImaginary() {
    return c;
  }
  Complex operator*(double rhs) const {
    Complex res;
    res.c = rhs * this -> c;
    Real::operator*(rhs);
    return res;
  }
};
class Surreal : public Complex {
private:
  using Complex::Complex;
  double sur;
public:
  Surreal (double num, double im, double s) : Complex{num,im}, sur{s} {}; 
  double GetSurreal() {
    return sur;
  }
  Surreal operator*(double rhs) const {
    Real::operator*(rhs);
     Surreal res {sur * rhs};
     return res;
  }
};




//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n * 2.0;
        REQUIRE( r.GetReal() == 20.0 );
        REQUIRE( r.GetImaginary() == 40.0 );
        REQUIRE( r.GetSurreal() == 60.0 );
    }
}
//------------------------------
