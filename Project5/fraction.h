#ifndef FRACTION_H
#define FRACTION_H

#include <stdio.h>

typedef struct{
    int numerator;
    int denominator;
} Fraction;

Fraction addFraction(Fraction a, Fraction b);
Fraction subFraction(Fraction a, Fraction b);
Fraction multiplyFraction(Fraction a, Fraction b);
Fraction divideFraction(Fraction a, Fraction b);
void simplifyFraction(Fraction *f);
void displayFraction(Fraction f, FILE *out);
int readInt(const char *prompt, int *value);

#endif
