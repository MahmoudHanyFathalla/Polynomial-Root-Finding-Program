/*
  By : Mahmoud Hany Fathalla 20104375 CC01
  
  How to Use the Polynomial Root-Finding Program:

  1. When you run this program, it will repeatedly ask you for the degree of the
     polynomial and its coefficients, followed by the root-finding method of your choice.

  2. Enter the degree of the polynomial. For example:
     Enter the degree of the polynomial: 2

  3. Enter the coefficients of the polynomial, starting from the highest degree to the constant term.
     For example, for a quadratic polynomial (3x^2 - 2x + 1), you would enter:
     Enter the coefficients for the polynomial (from highest degree to constant term): 3 -2 1

  4. Choose a root-finding method by entering the corresponding number:
     1. False Position Method
     2. Secant Method
     3. Bisection Method
     Enter your choice: 1

  5. Depending on the method selected, you'll be asked to enter initial bounds or approximations.
     - For False Position Method or Bisection Method:
       Enter initial bounds (xl and xu) and maximum iterations. For example:
       Enter initial bounds (xl and xu) and maximum iterations: 1.0 2.0 10
     - For Secant Method:
       Enter initial approximations (x0 and x1) and maximum iterations. For example:
       Enter initial approximations (x0 and x1) and maximum iterations: 0.5 1.0 5

  6. The program will run the chosen method to find the root, displaying each iteration's progress and results.

  7. After the root is found or the maximum iterations are reached, you'll be asked if you want to continue or exit:
     if you want to continue enter 1, if you want to leave enter any int except 1

  8. You can repeat the process to find roots for different polynomials and methods as desired.
*/


#include <stdio.h>
#include <math.h>

// Define the custom function you want to find the root for.
float customFunction(float x, float* coefficients, int degree) {
    float result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}
// Function to display the polynomial equation.
void displayPolynomial(int degree, float* coefficients) {
    printf("Polynomial Equation: f(x) = ");
    for (int i = 0; i <= degree; i++) {
        if (coefficients[i] != 0) {
            if (i == degree) {
                printf("(%.2f)", coefficients[i]);
                
            } else {
                printf("(%.2fx^%d) ", coefficients[i], degree - i);
                
            }
        }
        printf("+ ");
    }
    printf("\n");
}



// Function to find the root using the False Position Method.
void falsePositionMethod(float* xl, float* xu, int itmax, float* coefficients, int degree) {
    float fxl, fxu, fxr, xr, err;

    for (int i = 1; i <= itmax; i++) {
        fxl = customFunction(*xl, coefficients, degree);
        fxu = customFunction(*xu, coefficients, degree);
        

        if (fxl * fxu > 0) {
            printf("The False Position Method may not converge for the given bounds.\n");
            return;
        }

        xr = *xu - (fxu * ((*xl - *xu) / (fxl - fxu)));
        fxr = customFunction(xr, coefficients, degree);

        if (fxl * fxr < 0) {
            *xu = xr;
        } else if (fxl * fxr > 0) {
            *xl = xr;
        } else {
            printf("The root is %f\n", xr);
            return;
        }

        err = (fabsf(*xl - *xu) / fabsf(*xl + *xu)) * 100;
        printf("False Position Method - Iteration %d: xl(next) = %f, xu(next) = %f, f(xl) = %f, f(xu) = %f, xr = %f, f(xr) = %f, Error = %f%%\n", i, *xl, *xu, fxl, fxu, xr, fxr, err);

        if (err < 0.001) {
            printf("Converged to an acceptable error.\n");
            break;
        }
    }
}

// Function to find the root using the Secant Method.
void secantMethod(float* x0, float* x1, int itmax, float* coefficients, int degree) {
    float f0, f1, x2, err;

    for (int i = 1; i <= itmax; i++) {
        f0 = customFunction(*x0, coefficients, degree);
        f1 = customFunction(*x1, coefficients, degree);

        if (f0 == f1) {
            printf("The Secant Method may not converge for the given initial approximations.\n");
            return;
        }

        x2 = *x1 - (f1 * ((*x1 - *x0) / (f1 - f0)));

        err = (fabsf(x2 - *x1) / fabsf(x2)) * 100;

        printf("Secant Method - Iteration %d: x0 = %f, x1 = %f, f(x0) = %f, f(x1) = %f, x2 = %f, f(x2) = %f, Error = %f%%\n", i, *x0, *x1, f0, f1, x2, customFunction(x2, coefficients, degree), err);

        if (err < 0.001) {
            printf("Converged to an acceptable error.\n");
            break;
        }

        *x0 = *x1;
        *x1 = x2;
    }
}

// Function to find the root using the Bisection Method.
void bisectionMethod(float* xl, float* xu, int itmax, float* coefficients, int degree) {
    float fxl, fxu, xr, fxr, err;

    for (int i = 1; i <= itmax; i++) {
        fxl = customFunction(*xl, coefficients, degree);
        fxu = customFunction(*xu, coefficients, degree);

        xr = (*xl + *xu) / 2.0; // Midpoint of the interval
        fxr = customFunction(xr, coefficients, degree);

        if (fxl * fxr < 0) {
            *xu = xr;
        } else {
            *xl = xr;
        }

        if (fxl * fxr == 0) {
            printf("The root is %f\n", xr);
            return;
        }

        err = (fabsf(*xu - *xl) / fabsf(*xu + *xl)) * 100;
        printf("Bisection Method - Iteration %d: xl(next) = %f, xu(next) = %f, f(xl) = %f, f(xu) = %f, xr = %f, f(xr) = %f, Error = %f%%\n", i, *xl, *xu, fxl, fxu, xr, fxr, err);

        if (err < 0.001) {
            printf("Converged to an acceptable error.\n");
            break;
        }
    }
}


int main() {
    int method;
    int degree;
    float xl, xu, x0, x1;
    int itmax;
    int flag = 1;
while (flag == 1)
{
    /* code */


    printf("Enter the degree of the polynomial function: ");
    scanf("%d", &degree);

    float coefficients[degree + 1];
    printf("Enter the coefficients for the polynomial (from highest degree to constant term): ");
    //if degree =5 then you should enter (5+1) numbers
    //if degree =8 then you should enter (8+1) numbers and so on
    // dont enter more or less than (degree+1) numbers
    for (int i = 0; i <= degree; i++) { 
        scanf("%f", &coefficients[i]);
    }
    displayPolynomial(degree, coefficients);
    

    printf("Choose a method to find the root:\n");
    printf("1. False Position Method\n");
    printf("2. Secant Method\n");
    printf("3. Bisection Method\n");
    scanf("%d", &method);

    if (method == 1 || method == 2 || method == 3) {
        if (method == 1 || method == 3) {
            printf("Enter initial bounds (xl and xu) and maximum iterations: ");
            scanf("%f %f %d", &xl, &xu, &itmax);
        } else if (method == 2) {
            printf("Enter initial approximations (x0 and x1) and maximum iterations: ");
            scanf("%f %f %d", &x0, &x1, &itmax);
        }

        // Now, we can call the function with the degree and coefficients.
        if (method == 1) {
            falsePositionMethod(&xl, &xu, itmax, coefficients, degree);
        } else if (method == 2) {
            secantMethod(&x0, &x1, itmax, coefficients, degree);
        } else if (method == 3) {
            bisectionMethod(&xl, &xu, itmax, coefficients, degree);
        }
    } else {
        printf("Invalid method choice.\n");
    }
    printf("if you want to continue enter 1 , if you want to leave enter any int exept 1 ");
    scanf("%d",&flag);
   

}
    return 0;
}

