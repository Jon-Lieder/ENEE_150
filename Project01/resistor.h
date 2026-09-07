#ifndef RESISTOR_H
#define RESISTOR_H

typedef struct {
    char identifier[5];
    double resistance;
    double tolerance;
} Resistor;

#endif
