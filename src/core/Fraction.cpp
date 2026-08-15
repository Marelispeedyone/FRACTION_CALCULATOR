#include"../../include/core/Fraction.h"

#include<iostream>
#include<string>

#include"../../include/core/Parsing.h"

using namespace std;

int GCD (int a, int b){

    if(b == 0 ) return a ;
    else return GCD(b, a % b ) ;

}

Fraction::Fraction(): m_numerator(1), m_denominator(1){

}

Fraction::Fraction(int numerator): m_numerator(numerator), m_denominator(1){


}

Fraction::Fraction(int numerator, int denominator): m_numerator(numerator), m_denominator(denominator){

    if ( numerator != 0){
    
    normalize();
    simplify();

    }

}

bool Fraction::denominatorIsNull(){

    return m_denominator == 0 ;

}

void Fraction::simplify(){
    
    int num = m_numerator ;
    if(m_numerator < 0 ) num *= -1 ;

    int gcd = GCD(m_numerator, m_denominator);

    num /= gcd ;
    m_numerator = num ;
    m_denominator /= gcd ;

}

void Fraction::normalize(){

    // Cas 1 : m_denominator < 0 and m_numerator < 0

    if( m_denominator < 0 && m_numerator < 0){
        m_numerator *= -1 ;
        m_denominator *= -1 ;
    }

    // Case 2 : m_denominator < 0

    if( m_denominator < 0 ){

        m_denominator *= -1 ;
        m_numerator *= -1 ;

    }

}



double Fraction::toDouble() const{

    return (double)(((double)m_numerator)/((double)m_denominator));

}



string Fraction::normalFormat() const{

    
    if (m_denominator != 1 ) return to_string(m_numerator)+"/"+to_string(m_denominator);
    else return to_string(m_numerator);

}

string Fraction::mixedFormat() const{

    // a/b -> a div b + (a mod b)/b
    
    if ( m_denominator == 1 ) return to_string(m_numerator);

    if(m_numerator/m_denominator == 0 ) return to_string(m_numerator)+"/"+to_string(m_denominator); 

    return to_string(m_numerator/m_denominator)+" + "+to_string(m_numerator%m_denominator)+"/"+to_string(m_denominator);

}

Fraction& Fraction::operator+=(Fraction fraction){

    // a/b + c/d = (a.d + bc)/bd
    m_numerator = m_numerator*fraction.getDenominator() + m_denominator*fraction.getNumerator() ;

    m_denominator *= fraction.getDenominator();

    simplify();

    return *this ;

}

Fraction& Fraction::operator-=(Fraction fraction){

    // a/b - c/d = (a.d - bc)/bd
    m_numerator = m_numerator*fraction.getDenominator() - m_denominator*fraction.getNumerator() ;
    
    m_denominator *= fraction.getDenominator();

    simplify();

    return *this ;

}


Fraction& Fraction::operator*=(Fraction fraction){

    m_numerator *= fraction.getNumerator();
    m_denominator *= fraction.getDenominator();
    simplify();

    return *this ;

}

Fraction& Fraction::operator*=(int number){

    m_numerator *= number ;
    simplify();

    return *this ;

}

Fraction& Fraction::operator/=(Fraction fraction){

    // invert and multiply

    m_numerator *= fraction.getDenominator();
    m_denominator *= fraction.getNumerator();

    simplify();

    return *this ;

}


Fraction& Fraction::operator/=(int number){

    return *this ;

}

Fraction& Fraction::operator=(Fraction fraction){

    m_numerator = fraction.getNumerator();
    m_denominator = fraction.getDenominator();

    return *this ;

}

Fraction& Fraction::operator=(int number){

    m_numerator = number;
    m_denominator = 1;

    return *this ;

}

Fraction operator+(Fraction const& fraction1, Fraction const& fraction2) {

    Fraction result = fraction1 ;

    result+= fraction2 ;

    result.simplify();

    return result ;

}

Fraction operator-(Fraction const& fraction1, Fraction const& fraction2) {

    Fraction result = fraction1 ;

    result-= fraction2 ;

    result.simplify();

    return result ;

}

Fraction operator*(Fraction  const& fraction1, Fraction const& fraction2) {

    Fraction result = fraction1 ;
    
    result*= fraction2 ;

    result.simplify();

    return result ;

}

Fraction operator/(Fraction fraction1, Fraction fraction2) {

    Fraction result = fraction1 ;
    
    result/= fraction2 ;

    result.simplify();

    return result ;

}

bool operator==(Fraction const& fraction1, Fraction const& fraction2){

    return fraction1.toDouble()== fraction2.toDouble();

}

bool operator!=(Fraction fraction1, Fraction fraction2){

    return fraction1.toDouble()!= fraction2.toDouble();
}

bool operator<(Fraction const& fraction1, Fraction const& fraction2){

    return fraction1.toDouble()< fraction2.toDouble();

}

bool operator>(Fraction const& fraction1, Fraction const& fraction2){

    return fraction1.toDouble()> fraction2.toDouble();

}

bool operator<=(Fraction const& fraction1, Fraction const& fraction2){

    return fraction1.toDouble()<= fraction2.toDouble();

}

bool operator>=(Fraction const&  fraction1, Fraction const& fraction2){

    return fraction1.toDouble()>= fraction2.toDouble();

}

int Fraction::getNumerator(){

    return m_numerator ;

}

int Fraction::getDenominator(){

    return m_denominator ;

}
void Fraction::setFraction(int numerator){

    m_numerator = numerator ;
    simplify();
}

void Fraction::setFraction(int numerator, int denominator){

    m_numerator = numerator ;
    m_denominator = denominator ;
    simplify();

}


ostream& operator<<(ostream &flux, Fraction const& fraction){

    if(fraction.normalFormat() == fraction.mixedFormat()) flux << fraction.normalFormat() << endl ;

    else flux << "Normal format :" <<fraction.normalFormat() << "\nMixed format :" <<fraction.mixedFormat() << endl ;

    return flux ;
}

