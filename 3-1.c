#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getY(const double x);
/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);
/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main()
{
    printf("Введите начальное значение : ");
    double start = getValue();
    printf("Введите конечное  значение : ");
    double end = getValue();
    printf("Введите шаг : ");
    double step = getValue();
    checkStep(step);
    for (double x = start; x < end + DBL_EPSILON; x = x + step)
    {
        if (defineOOF(x))
        {
            printf("x = %.2lf , y = %.4lf \n", x , getY(x));
        }
        else
        {
            printf("x = %.2lf , x не принедлежит ООФ \n",x);
        }
    }
    return 0;
}
double getY(double const x)
{
    return 3 * log(x) + 6 * log(x) - 5;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
        {
            printf("Ошибка ввода!");
            abort();
        }
        return value;
}
void checkStep(const double step)
{
    if (step <= DBL_EPSILON)
    {
        printf("Ошибка, шаг должен быть положительным\n");
                abort();
    }
}
bool defineOOF(const double x)
{
    return x>0;
}
