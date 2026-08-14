#include"../../include/core/Fraction.h"

#include<iostream>
#include<string>

using namespace std;

int GCD (int a, int b){

    if(b == 0 ) return a ;
    else return (b, a % b ) ;

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

    return (double)(m_numerator/m_denominator);

}

string Fraction::normalFormat() const{

    return to_string(m_numerator)+"/"+to_string(m_denominator);

}

string Fraction::mixedFormat() const{

    // a/b -> a div b + (a mod b)/b
    
    return to_string(m_numerator/m_denominator)+"+"+to_string(m_numerator%m_denominator)+"/"+to_string(m_denominator);

}

void Fraction::operator+=(Fraction fraction){

    // a/b + c/d = (a.d + bc)/bd
    m_numerator = m_numerator*fraction.getDenominator() + m_denominator*fraction.getNumerator() ;

    m_denominator *= fraction.getDenominator();

}

void Fraction::operator-=(Fraction fraction){

    // a/b - c/d = (a.d - bc)/bd
    m_numerator = m_numerator*fraction.getDenominator() - m_denominator*fraction.getNumerator() ;
    
    m_denominator *= fraction.getDenominator();

}

void Fraction::operator*=(Fraction fraction){

    m_numerator *= fraction.getNumerator();
    m_denominator *= fraction.getDenominator();

}

void Fraction::operator/=(Fraction fraction){

    // invert and multiply

    m_numerator *= fraction.getDenominator();
    m_denominator *= fraction.getNumerator();

}


void Fraction::operator/=(int number){



}

void Fraction::operator=(Fraction fraction){

    m_numerator = fraction.getNumerator();
    m_denominator = fraction.getDenominator();

}

int Fraction::getNumerator(){

    return m_numerator ;

}

int Fraction::getDenominator(){

    return m_denominator ;

}
void Fraction::setFraction(int numerator){

    m_numerator = numerator ;
}

void Fraction::setFraction(int numerator, int denominator){

    m_numerator = numerator ;
    m_denominator = denominator ;

}

