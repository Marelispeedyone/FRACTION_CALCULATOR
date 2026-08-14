#ifndef FRACTION
#define FRACTION

#include<iostream>
#include<string>

// Greatest Common divisor, to simplify fraction.

int GCD (int a, int b);
class Fraction{

    public :

        Fraction(); // default constructor
        Fraction(int numerator);
        Fraction(int numerator, int denominator);

        bool denominatorIsNull();
        void simplify();
        void normalize();
        
        double toDouble() const;
        std::string normalFormat() const;
        // Only if numerator > denominator
        std::string mixedFormat() const;

        Fraction parser(std::string expression);

        void display(std::ostream &flux) const;

        Fraction& operator+=(Fraction fraction);
        Fraction& operator+=(int number);
        Fraction& operator-=(Fraction fraction);
        Fraction& operator-=(int number);
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

inline Fraction operator+(Fraction fraction1, Fraction fraction2) ;
inline Fraction operator-(Fraction fraction1, Fraction fraction2) ;
inline Fraction operator*(Fraction fraction1, Fraction fraction2) ;
inline Fraction operator/(Fraction fraction1, Fraction fraction2) ;

// Comparison operators

inline bool operator==(Fraction fraction1, Fraction fraction2);
inline bool operator<(Fraction fraction1, Fraction fraction2);
inline bool operator>(Fraction fraction1, Fraction fraction2);
inline bool operator>=(Fraction fraction1, Fraction fraction2);
inline bool operator<=(Fraction fraction1, Fraction fraction2);




// Output operator

std::ostream& operator<<(std::ostream &flux, Fraction fraction);

#endif  // FRACTION
