#include"../../include/core/Fraction.h"
#include"../../include/core/Parsing.h"


#include<iostream>
#include<string>
#include<vector>
#include <sstream> // To use istringstream
#include <stdexcept>

using namespace std ;

Fraction const null(0,1);

Fraction parserExpression (string expression){

    vector<char> operators;
    vector<Fraction> fractions;

    istringstream flux(expression);
    string word;
    while(flux >> word){

        if(isNumber(word))
        {
            Fraction number = convertStringToFraction(word);

            fractions.push_back(number);
            operators.push_back('.') ;
        }

        else{
            // If this is an operator, we have only one character into this word : word[0].

            operators.push_back(word[0]) ;
            fractions.push_back(null);

        }

    }

    priorityCalculator(operators, fractions);
    size_t i = 0 ;
    while(fractions[i] == null && i < fractions.size()){
        i++;
    }

    return fractions[i] ;
}

bool isNumber(std::string word){

    if( word == "+" || word == "-" || word == "*" || word == "/") return 0 ;
    else return 1 ;

}

Fraction convertStringToFraction(std::string word){

    int numerator = 0, denominator = 1 ;
    int sign_up = 1, sign_down = 1; // Default : positive sign 

    for(size_t i=0 ; i < word.length(); i++){

        if(word[i] == '/'){
            
            if(word[i+1] == '-') {

                sign_down *=-1 ;
                denominator = word[i+2] -'0';
                for( size_t j = i+3 ; j < word.length() ; j++ ) denominator = denominator*10 +( word[j]-'0' );
                
            }
            
            else {

                denominator = word[i+1] -'0';
                for( size_t j = i+2 ; j < word.length() ; j++ ) denominator = denominator*10 +( word[j]-'0' );
            }
            break ;
            
        }

        else if(word[i] == '-') sign_up*= (-1) ;
        // ASCII offset method
        else{

            numerator = numerator*10 + (word[i]-'0') ;
        }
    }
    numerator *= sign_up ;
    denominator *= sign_down ;
    Fraction fraction(numerator, denominator) ;

    return fraction ;
}

void priorityCalculator(std::vector<char> &operators, std::vector<Fraction> &fractions){

    // first step
    for( size_t i = 1; i < operators.size(); i++){
    
        size_t left = 1 ;
        size_t right = 1 ;

        if(operators[i]=='*' || operators[i]=='/'){

            // always calculate with numbers > 0 into fractions vector

            while(fractions[i-left] == null){
                left++ ;
            }
            while(fractions[i+right] == null){
                right++ ;
            }


            switch(operators[i]){
                
                case '*':
                    fractions[i] = fractions[i-left] * fractions[i+right];
                    fractions[i].normalize();
                    fractions[i].simplify();
                    fractions[i-left]= fractions[i+right] = 0 ;
                    operators[i] ='.' ;
                    break ;
                
                case'/':
                    fractions[i] = fractions[i-left] / fractions[i+right];
                    fractions[i].normalize();
                    fractions[i].simplify();
                    fractions[i-left]= fractions[i+right] = 0 ;
                    operators[i] = '.' ;
                    break ;

                default:
                    break ;
            }

        }
        else continue ;
    }
    
    // second step
    for( size_t i = 1; i < operators.size(); i++){
    
        size_t left = 1 ;
        size_t right = 1 ;
    
        if(operators[i]=='+' || operators[i]=='-'){

            while(fractions[i-left] == null){
                left++ ;
            }
            while(fractions[i+right] == null){
                right++ ;
            }

            switch(operators[i]){
                
                case '+':
                    fractions[i] = fractions[i-left] + fractions[i+right];
                    fractions[i].normalize();
                    fractions[i].simplify();
                    fractions[i-left]= fractions[i+right] = 0 ;
                    operators[i] = '.' ;
                    break ;
                
                case'-':
                    fractions[i] = fractions[i-left] - fractions[i+right];
                    fractions[i].normalize();
                    fractions[i].simplify();
                    fractions[i-left]= fractions[i+right] = 0 ;
                    operators[i] = '.' ;
                    break ;

                default:
                    break ;
            }

        }
        else continue ;
    }

}