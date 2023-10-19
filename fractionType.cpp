//
// Created by Jacob Yeung on 10/18/23.
//

#include "fractionType.h"
#include "iostream"
#include <numeric>

bool fractionType::shouldTheLowestTerms = false;

fractionType::fractionType(int numerator, int denominator, bool simplification) {
    if (simplification) {
        fractionType ref = generateReducedFraction(numerator, denominator);
        this->numerator = ref.numerator;
        this->denominator = ref.denominator;
    }else{
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

std::ostream& operator<<(std::ostream& os, const fractionType& fraction){
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}

std::istream& operator>>(std::istream& is, fractionType& fraction) {
    is >> fraction.numerator;
    is.ignore(1,'/');
    is >> fraction.denominator;
    return is;
}

fractionType fractionType::generateReducedFraction() const{
    return generateReducedFraction(this->numerator, this->denominator);
}

fractionType fractionType::generateReducedFraction(int numerator, int denominator){
    int gcd = std::gcd(numerator, denominator);
    return {numerator/gcd, denominator/gcd, false};
}
fractionType fractionType::generateReducedFraction(const fractionType &fraction){
    return generateReducedFraction(fraction.getNumerator(), fraction.getDenominator());
}

void fractionType::setFraction(int numerator, int denominator, bool simplification){
    if (simplification) {
        fractionType ref = generateReducedFraction(numerator, denominator);
        this->numerator = ref.numerator;
        this->denominator = ref.denominator;
    }else{
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

int fractionType::getNumerator() const{
    return numerator;
}

int fractionType::getDenominator() const{
    return denominator;
}

double fractionType::getDouble() const{
    return (double)numerator/denominator;
}

bool operator == (const fractionType& fractionType1, const fractionType& fractionType2){
    fractionType reducaedFractionType1 = fractionType1.generateReducedFraction();
    fractionType reducaedFractionType2 = fractionType2.generateReducedFraction();
    return (reducaedFractionType1.numerator == reducaedFractionType2.numerator && reducaedFractionType1.denominator == reducaedFractionType2.denominator);
}

bool operator != (const fractionType& fractionType1, const fractionType& fractionType2){
    return !(fractionType1 == fractionType2);
}

bool operator < (const fractionType& fractionType1, const fractionType& fractionType2){
    return fractionType1.getDouble() < fractionType2.getDouble();
}
bool operator > (const fractionType& fractionType1, const fractionType& fractionType2){
    return fractionType1.getDouble() > fractionType2.getDouble();
}

bool operator <= (const fractionType& fractionType1, const fractionType& fractionType2){
    return (fractionType1 < fractionType2) || (fractionType1 == fractionType2);
}
bool operator >= (const fractionType& fractionType1, const fractionType& fractionType2){
    return (fractionType1 > fractionType2) || (fractionType1 == fractionType2);
}

fractionType operator+(const fractionType& fractionType1, const fractionType& fractionType2){
    int numerator = fractionType1.numerator * fractionType2.denominator + fractionType2.numerator * fractionType1.denominator;
    int denominator = fractionType1.denominator * fractionType2.denominator;
    return {numerator, denominator, fractionType::shouldTheLowestTerms};
}

fractionType operator-(const fractionType& fractionType1, const fractionType& fractionType2){
    int numerator = fractionType1.numerator * fractionType2.denominator - fractionType2.numerator * fractionType1.denominator;
    int denominator = fractionType1.denominator * fractionType2.denominator;
    return {numerator, denominator, fractionType::shouldTheLowestTerms};
}

fractionType operator*(const fractionType& fractionType1, const fractionType& fractionType2){
    int numerator = fractionType1.numerator * fractionType2.numerator;
    int denominator = fractionType1.denominator * fractionType2.denominator;
    return {numerator, denominator, fractionType::shouldTheLowestTerms};
}

fractionType operator/(const fractionType& fractionType1, const fractionType& fractionType2){
    int numerator = fractionType1.numerator * fractionType2.denominator;
    int denominator = fractionType1.denominator * fractionType2.numerator;
    return {numerator, denominator, fractionType::shouldTheLowestTerms};
}