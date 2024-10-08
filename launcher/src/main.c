#include <solver.h>
#include <stdio.h>

int main() {
    qmath_value_t a = 0.0L, b = 0.0L, c = 0.0L;
    qmath_equation_t factors = {
        .a = a,
        .b = b,
        .c = c
    };
    qmath_roots_t roots = ile_qe_solve(factors);
    printf("%Lf %Lf", roots.x1, roots.x2);
    return 0;
}