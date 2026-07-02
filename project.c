

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#  define M_PI 3.14159265358979323846
#endif


#define VERSION     "1.0.0"
#define APP_NAME    "C Console Calculator"
#define DIVIDER     "========================================"


void        display_menu(void);
void        display_scientific_menu(void);
double      add(double a, double b);
double      subtract(double a, double b);
double      multiply(double a, double b);
double      divide(double a, double b);
double      modulus(double a, double b);
double      power_recursive(double base, int exp);
long long   factorial_recursive(int n);
double      get_number(const char *prompt);
int         get_menu_choice(int min, int max);
void        clear_input_buffer(void);
void        print_result(double result);
void        run_basic_calc(void);
void        run_scientific_calc(void);
void        print_header(void);


int main(void)
{
    int choice;
    int running = 1;

    print_header();

    while (running) {
        printf("\n%s\n", DIVIDER);
        printf("  MAIN MENU\n");
        printf("%s\n", DIVIDER);
        printf("  1. Basic Calculator  (+  -  *  /  %%)\n");
        printf("  2. Scientific Calculator\n");
        printf("  3. About\n");
        printf("  0. Exit\n");
        printf("%s\n", DIVIDER);

        choice = get_menu_choice(0, 3);

        switch (choice) {
            case 1:
                run_basic_calc();
                break;
            case 2:
                run_scientific_calc();
                break;
            case 3:
                printf("\n  %s  v%s\n", APP_NAME, VERSION);
                printf("  Built with pure C (C99) – no external deps.\n");
                printf("  Compile: gcc -o calculator calculator.c -lm\n");
                break;
            case 0:
                printf("\n  Goodbye! Thank you for using %s.\n\n", APP_NAME);
                running = 0;
                break;
        }
    }

    return EXIT_SUCCESS;
}


void print_header(void)
{
    printf("\n%s\n", DIVIDER);
    printf("   %s  v%s\n", APP_NAME, VERSION);
    printf("%s\n", DIVIDER);
}

void run_basic_calc(void)
{
    double num1, num2, result;
    int    op;
    int    running = 1;

    while (running) {
        printf("\n%s\n", DIVIDER);
        printf("  BASIC CALCULATOR\n");
        printf("%s\n", DIVIDER);
        printf("  1. Addition       ( + )\n");
        printf("  2. Subtraction    ( - )\n");
        printf("  3. Multiplication ( * )\n");
        printf("  4. Division       ( / )\n");
        printf("  5. Modulus        ( %% )\n");
        printf("  0. Back to Main Menu\n");
        printf("%s\n", DIVIDER);

        op = get_menu_choice(0, 5);
        if (op == 0) break;

        num1 = get_number("  Enter first  number : ");
        num2 = get_number("  Enter second number : ");

        switch (op) {
            case 1:
                result = add(num1, num2);
                printf("\n  %.4g + %.4g = ", num1, num2);
                print_result(result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("\n  %.4g - %.4g = ", num1, num2);
                print_result(result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("\n  %.4g × %.4g = ", num1, num2);
                print_result(result);
                break;
            case 4:
                if (num2 == 0.0) {
                    printf("\n  [ERROR] Division by zero is undefined.\n");
                } else {
                    result = divide(num1, num2);
                    printf("\n  %.4g ÷ %.4g = ", num1, num2);
                    print_result(result);
                }
                break;
            case 5:
                if (num2 == 0.0) {
                    printf("\n  [ERROR] Modulus by zero is undefined.\n");
                } else {
                    result = modulus(num1, num2);
                    printf("\n  %.4g %% %.4g = ", num1, num2);
                    print_result(result);
                }
                break;
        }

        printf("\n  Continue in Basic Calculator? (1=Yes / 0=No): ");
        int cont = get_menu_choice(0, 1);
        if (cont == 0) running = 0;
    }
}


void run_scientific_calc(void)
{
    double num, result;
    int    op;
    int    running = 1;

    while (running) {
        printf("\n%s\n", DIVIDER);
        printf("  SCIENTIFIC CALCULATOR\n");
        printf("%s\n", DIVIDER);
        printf("  1.  Square Root   ( √x  )\n");
        printf("  2.  Power         ( x^n )\n");
        printf("  3.  Factorial     ( n!  )\n");
        printf("  4.  Logarithm     ( log10 )\n");
        printf("  5.  Natural Log   ( ln  )\n");
        printf("  6.  Sine          ( sin )\n");
        printf("  7.  Cosine        ( cos )\n");
        printf("  8.  Tangent       ( tan )\n");
        printf("  9.  Absolute Val  ( |x| )\n");
        printf("  0.  Back to Main Menu\n");
        printf("%s\n", DIVIDER);

        op = get_menu_choice(0, 9);
        if (op == 0) break;

        switch (op) {
         
            case 1:
                num = get_number("  Enter number : ");
                if (num < 0) {
                    printf("\n  [ERROR] Cannot take square root of a negative number.\n");
                } else {
                    result = sqrt(num);
                    printf("\n  √(%.4g) = ", num);
                    print_result(result);
                }
                break;

            case 2: {
                int exp;
                num = get_number("  Enter base    : ");
                printf("  Enter exponent (integer): ");
                while (scanf("%d", &exp) != 1) {
                    clear_input_buffer();
                    printf("  [Invalid] Re-enter exponent: ");
                }
                clear_input_buffer();
                result = power_recursive(num, exp);
                printf("\n  %.4g ^ %d = ", num, exp);
                print_result(result);
                break;
            }

            case 3: {
                int n;
                printf("  Enter a non-negative integer: ");
                while (scanf("%d", &n) != 1 || n < 0) {
                    clear_input_buffer();
                    printf("  [Invalid] Re-enter a non-negative integer: ");
                }
                clear_input_buffer();
                if (n > 20) {
                    printf("\n  [WARNING] Result exceeds 64-bit integer range for n > 20.\n");
                } else {
                    long long fact = factorial_recursive(n);
                    printf("\n  %d! = %lld\n", n, fact);
                }
                break;
            }

            /* ── log10 ── */
            case 4:
                num = get_number("  Enter number (> 0): ");
                if (num <= 0) {
                    printf("\n  [ERROR] Logarithm undefined for non-positive numbers.\n");
                } else {
                    result = log10(num);
                    printf("\n  log10(%.4g) = ", num);
                    print_result(result);
                }
                break;

           
            case 5:
                num = get_number("  Enter number (> 0): ");
                if (num <= 0) {
                    printf("\n  [ERROR] Natural log undefined for non-positive numbers.\n");
                } else {
                    result = log(num);
                    printf("\n  ln(%.4g) = ", num);
                    print_result(result);
                }
                break;

            case 6:
                num = get_number("  Enter angle in degrees: ");
                result = sin(num * M_PI / 180.0);
                printf("\n  sin(%.4g°) = ", num);
                print_result(result);
                break;

    
            case 7:
                num = get_number("  Enter angle in degrees: ");
                result = cos(num * M_PI / 180.0);
                printf("\n  cos(%.4g°) = ", num);
                print_result(result);
                break;

          
            case 8:
                num = get_number("  Enter angle in degrees: ");
             
                double deg_mod = fmod(fabs(num), 180.0);
                if (fabs(deg_mod - 90.0) < 1e-9) {
                    printf("\n  [ERROR] tan(%.4g°) is undefined.\n", num);
                } else {
                    result = tan(num * M_PI / 180.0);
                    printf("\n  tan(%.4g°) = ", num);
                    print_result(result);
                }
                break;

            case 9:
                num = get_number("  Enter number : ");
                result = fabs(num);
                printf("\n  |%.4g| = ", num);
                print_result(result);
                break;
        }

        printf("\n  Continue in Scientific Calculator? (1=Yes / 0=No): ");
        int cont = get_menu_choice(0, 1);
        if (cont == 0) running = 0;
    }
}


double add(double a, double b)      { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b)   { return a / b; }
double modulus(double a, double b)  { return fmod(a, b); }

double power_recursive(double base, int exp)
{
    if (exp == 0)  return 1.0;
    if (exp < 0)   return 1.0 / power_recursive(base, -exp);
    return base * power_recursive(base, exp - 1);
}

long long factorial_recursive(int n)
{
    if (n == 0 || n == 1) return 1;
    return (long long)n * factorial_recursive(n - 1);
}



/* Clear leftover characters in stdin */
void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Prompt user and read a validated double */
double get_number(const char *prompt)
{
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        clear_input_buffer();
        printf("  [Invalid input] Please enter a number: ");
    }
    clear_input_buffer();
    return value;
}
 */
int get_menu_choice(int min, int max)
{
    int choice;
    printf("  Your choice [%d-%d]: ", min, max);
    while (scanf("%d", &choice) != 1 || choice < min || choice > max) {
        clear_input_buffer();
        printf("  [Invalid] Enter a number between %d and %d: ", min, max);
    }
    clear_input_buffer();
    return choice;
}


void print_result(double result)
{
 
    if (result == (long long)result && result < 1e15 && result > -1e15)
        printf("%.0f\n", result);
    else
        printf("%.6g\n", result);
}
