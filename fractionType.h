//
// Created by Jacob Yeung on 10/18/23.
//

#ifndef CS216PROGRAMMINGEXERCISE1310_FRACTIONTYPE_H
#define CS216PROGRAMMINGEXERCISE1310_FRACTIONTYPE_H

#include <iostream>
#include <cmath>

using namespace std;

class fractionType {
private:
    static bool shouldTheLowestTerms;
protected:
    int numerator;
    int denominator;
    static fractionType generateReducedFraction(int numerator, int denominator);
    static fractionType generateReducedFraction(const fractionType &fraction);
public:
    fractionType generateReducedFraction() const;

    fractionType(int numerator = 0, int denominator = 1, bool simplification = shouldTheLowestTerms);
    void setFraction(int numerator, int denominator, bool simplification = shouldTheLowestTerms);
    int getNumerator() const;
    int getDenominator() const;
    fractionType operator+(const fractionType& otherFraction) const;
    fractionType operator-(const fractionType& otherFraction) const;
    fractionType operator*(const fractionType& otherFraction) const;
    fractionType operator/(const fractionType& otherFraction) const;
    //Overload the relational operators
    friend bool operator == (const fractionType&, const fractionType&) ;
    friend bool operator != (const fractionType&, const fractionType&) ;
    friend bool operator <= (const fractionType&, const fractionType&) ;
    friend bool operator < (const fractionType&, const fractionType&) ;
    friend bool operator >= (const fractionType&, const fractionType&) ;
    friend bool operator > (const fractionType&, const fractionType&) ;
//    fractionType operator++();
//    fractionType operator++(int);
//    fractionType operator--();
//    fractionType operator--(int);
    friend std::ostream& operator<<(std::ostream& os, const fractionType& fraction);
    friend std::istream& operator>>(std::istream& is, fractionType& fraction);
};

#endif //CS216PROGRAMMINGEXERCISE1310_FRACTIONTYPE_H
