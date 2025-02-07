# Polynomial Root-Finding Program

## Overview

The Polynomial Root-Finding Program is a C-based application that allows users to determine the roots of a polynomial equation using numerical methods. The program supports three root-finding techniques:

1. **False Position Method**
2. **Secant Method**
3. **Bisection Method**

This tool is particularly useful for numerical computing, engineering, and scientific research where polynomial equations need to be solved iteratively.

## Features

- Supports polynomial equations of any degree.
- Provides step-by-step iteration results for better understanding.
- Allows users to select different numerical methods.
- Includes an error convergence check to ensure result accuracy.
- User-friendly input and output display.

## How to Use the Program

### 1. Run the Program

When you execute the program, it will repeatedly prompt you to enter a polynomial equation and select a method for root finding.

### 2. Enter the Degree of the Polynomial

The program will ask for the degree of the polynomial. For example:

```
Enter the degree of the polynomial: 2
```

### 3. Enter the Coefficients

You must enter the coefficients starting from the highest degree down to the constant term. For instance, for the quadratic equation:
**3x^2 - 2x + 1**, enter:

```
Enter the coefficients for the polynomial (from highest degree to constant term): 3 -2 1
```

### 4. Choose a Root-Finding Method

You can choose one of the three numerical methods by entering the corresponding number:

```
1. False Position Method
2. Secant Method
3. Bisection Method
Enter your choice: 1
```

### 5. Provide Initial Bounds or Approximations

Depending on the selected method, the program will prompt you for the necessary initial values:

- **False Position and Bisection Methods** require lower (`xl`) and upper (`xu`) bounds:

```
Enter initial bounds (xl and xu) and maximum iterations: 1.0 2.0 10
```

- **Secant Method** requires two initial approximations (`x0` and `x1`):

```
Enter initial approximations (x0 and x1) and maximum iterations: 0.5 1.0 5
```

### 6. Observe Iteration Results

The program will display each iteration's progress, including function values, current estimates, and error values. Example output:

```
False Position Method - Iteration 1: xl = 1.000000, xu = 2.000000, xr = 1.500000, f(xr) = -0.125000, Error = 3.2%
```

### 7. Continue or Exit

After completing the process, the program will ask if you want to continue solving another polynomial:

```
If you want to continue, enter 1. To exit, enter any other integer: 1
```

## Compilation and Execution

### 1. Compile the Program

Use the GCC compiler to compile the C file:

```
gcc -o root_finder main.c -lm
```

### 2. Run the Executable

```
./root_finder
```

## Implementation Details

### **Custom Function Evaluation**

The program uses the `customFunction` function to evaluate the polynomial at a given `x` value:

```c
float customFunction(float x, float* coefficients, int degree) {
    float result = 0.0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}
```

### **Root-Finding Methods**

The program implements three numerical methods:

1. **False Position Method:** Uses linear interpolation between two points to estimate the root.
2. **Secant Method:** Uses two recent approximations to estimate the next root.
3. **Bisection Method:** Repeatedly bisects the interval to converge to a root.

Each method iterates until an acceptable error threshold (0.001%) is met or the maximum iteration count is reached.

## Example Run

```
Enter the degree of the polynomial: 2
Enter the coefficients for the polynomial (from highest degree to constant term): 1 -3 2
Choose a method to find the root:
1. False Position Method
2. Secant Method
3. Bisection Method
Enter your choice: 3
Enter initial bounds (xl and xu) and maximum iterations: 0 3 10
Bisection Method - Iteration 1: xl = 0.000000, xu = 3.000000, xr = 1.500000, f(xr) = 0.250000, Error = 5.3%
...
Converged to an acceptable error.
```

## License

This project is open-source and available for educational purposes.

## Author

**Mahmoud Hany Fathalla**

## Contributions

Contributions are welcome! If you'd like to enhance the program, feel free to submit a pull request or report issues.

