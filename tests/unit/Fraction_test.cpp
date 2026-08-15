#include"../../include/core/Fraction.h"
#include"../../include/core/Parsing.h"


#include<iostream>
#include<string>
#include<vector>
#include <sstream> // To use istringstream
#include <stdexcept>
#include<cassert>
#include<fstream>

using namespace std ;

void fraction_construction_test (Fraction const& frac_1, Fraction const& frac_2, Fraction const& frac_3){

    cout << frac_1 << endl ;
    cout << frac_2 << endl ;
    cout << frac_3 << endl ;

}


int main(){

    // Fraction Test
    /*Fraction frac_1(200,96), frac_2(7,9), frac_3(8, 32) ;
    fraction_construction_test(frac_1,frac_2, frac_3);

    cout <<" conversion into double " ;
    cout << frac_1.toDouble() << " " << frac_2.toDouble() << " " << frac_3.toDouble() << endl ;*/

    string expression ;
    cout <<"Enter an expression ( WARNING :  )" ;
    getline(cin, expression) ;
    parserExpression(expression) ;
    cout <<"The result is : \n" << parserExpression(expression) << endl ;
    cin.ignore();

    return 0 ;
}