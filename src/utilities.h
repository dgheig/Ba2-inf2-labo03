/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : utilities.h
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Define utilities functions
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef UTILITIES_H
#define UTILITIES_H


/*!
* @param index index of a char in the alphabete
* @return char corresponding to index
*/
char indexToChar(int index);

/*!
* @param a left operand
* @param b right operand
* @brief since operator% is not mathematical modulo but reminder operator, this version ensure a positive result
* @return return the modulo of a and b
*/
unsigned mod(int a, int b);

/*!
* @param a index that may be invalid
* @return return the valid index corresponding to a
*/
unsigned alphaIndex(int index);

/*!
* @param c char of which we want to have the corresponding index
* @return return the valid index corresponding to c
*/
int alphaIndex(char c);


#endif