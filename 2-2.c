#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
/**
 @brief расчитывает значение функции Y
 @param a значение переменной a
 @param x знаяение переменной x
 @return расчитывает значение
double getY(double const a, double const x);
 */
double getY(double const a,double const x);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main()
{
    double a = 2.5;
    printf("Введите перменную x : ");
    double x = getValue();
    printf("Результат : %.4lf\n",getY(a,x));
    return 0;
}
double getY(double const a,double const x)
{
    if (x<0.5)
    {
        return cbrt(a * x + 1);
    }
    else if  (fabs(x - 0.5) < DBL_EPSILON)
    {
        return a*x + 3;
    }
    else
    {
        return pow((pow(a,2)*x - 1),0.5);
    }
}
double getValue()
{
    double value = 0;
    if (!scanf("%4lf",&value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}
