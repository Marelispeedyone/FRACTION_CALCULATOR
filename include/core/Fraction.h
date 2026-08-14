#ifndef FRACTION
#define FRACTION

#include<iostream>
#include<string>

class Fraction{

    public :

        Fraction(); // default constructor
        Fraction(int numerator);
        Fraction(int numerator, int denominator);

        void simplify();
        
        double toDouble() const;
        std::string normalFormat() const;
        std::string mixedFormat() const;

        Fraction parser(std::string expression);

        Fraction operator+=(Fraction fraction);
        Fraction operator-=(Fraction fraction);
        Fraction operator*=(Fraction fraction);
        Fraction operator/=(Fraction fraction);

    private :

        int m_numerator ;
        int m_denominator ;
};

std::ostream& operator<<(std::ostream &flux, Fraction fraction);

#endif  // FRACTION
