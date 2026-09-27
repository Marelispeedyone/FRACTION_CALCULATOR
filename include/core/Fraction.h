#ifndef FRACTION
#define FRACTION

#include<iostream>
#include<string>

// Greatest Common divisor, to simplify fraction.

int GCD (int a, int b);
class Fraction{

    public :

        Fraction(int numerator = 0, int denominator = 1);

        bool denominatorIsNull();
        void simplify();
        void normalize();
        
        double toDouble() const;
        std::string normalFormat() const;
        // Only if numerator > denominator
        std::string mixedFormat() const;

        Fraction& operator+=(Fraction fraction);
        Fraction& operator+=(int number);
        Fraction& operator-=(Fraction fraction);
        Fraction& operator-=(int number);
        Fraction& operator-=(double number);
        Fraction& operator*=(Fraction fraction);
        Fraction& operator*=(int number);
        Fraction& operator/=(Fraction fraction);
        Fraction& operator/=(int number);
        Fraction& operator=(Fraction fraction); // Copy operator
        Fraction& operator=(int number); 

    // getters & setters
        int getNumerator();
        int getDenominator();

    protected :
        void setFraction(int numerator);
        void setFraction(int numerator, int denominator);


    private :

        int m_numerator ;
        int m_denominator ;
};

// Arithmetics operators

Fraction operator+(Fraction const& fraction1, Fraction const& fraction2) ;
Fraction operator-(Fraction const& fraction1, Fraction const& fraction2) ;
Fraction operator*(Fraction const& fraction1, Fraction const& fraction2) ;
Fraction operator/(Fraction const& fraction1, Fraction const& fraction2) ;

// Comparison operators

bool operator==(Fraction const&  fraction1, Fraction const& fraction2);
bool operator!=(Fraction const& fraction1, Fraction const& fraction2);
bool operator<(Fraction const& fraction1, Fraction const&fraction2);
bool operator>(Fraction const& fraction1, Fraction const& fraction2);
bool operator>=(Fraction  const& fraction1, Fraction const& fraction2);
bool operator<=(Fraction const& fraction1, Fraction const& fraction2);




// Output operator

std::ostream& operator<<(std::ostream &flux, Fraction const& fraction);

#endif  // FRACTION
