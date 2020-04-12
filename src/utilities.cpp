/*
-----------------------------------------------------------------------------------
Laboratory  : labo_03
File        : utilities.cpp
Author(s)   : Basset Nils, Lange Yannik et Gallay David
Date        : 26.03.2020

Purpose     : Function definition for header utilities.h
Remark(s)   :

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include "utilities.h"

unsigned mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

unsigned alphaIndex(int index) {
    return mod(index, 26);
}

int alphaIndex(char c) {
    return alphaIndex(c - 'A');
}

char indexToChar(int index) { // 0 <= index < 26
    return char(alphaIndex(index) + 'A');
}