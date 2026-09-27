#include <stdio.h>
#include "config.h"

double cramerSolver(double det_ab, double det_a){
    printf("cramerSolver.c line 5: x = %.2lf\n", det_ab / det_a);
    return det_ab / det_a;
}
