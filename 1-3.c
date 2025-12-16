#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <float.h>
/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getValue();
/** 
* @brief расчитывает дистанцию между двум телами по определенной форумле
* @param m1_ton - масса первого тела в тоннах
* @param m2_ton - масса второго тела в тоннах
* @param F - коэффицен для получения силы притяжения
* @return возвращает расчитанное значение
*/
double findDistance(const double m1_ton, const double m2_ton, const double F);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    printf("Введите массу первого тела в тоннах: ");
    double m1 = getValue();
    printf("Масса первого тела в кг: %.2lf\n", m1 * 1000);
    
    printf("Введите массу второго тела в тоннах: ");
    double m2 = getValue();
    printf("Масса второго тела в кг: %.2lf\n", m2 * 1000);
    
    printf("Введите коэффициент F (сила = F * 10^-5 Н): ");
    double F = getValue();
    printf("Сила тяготения: %e Н\n", F * 1e-5);
    printf("Расстояние между телами в метрах: %.4lf\n", findDistance(m1,m2,F));
    
    return 0;
}
double  getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

double findDistance(double m1_ton, double m2_ton, double F)
{
    const double G = 6.67430e-11; // гравитационная постоянная
    double m1_kg = m1_ton * 1000;
    double m2_kg = m2_ton * 1000;
    double force = F * 1e-5;
    if (fabs(force) < DBL_EPSILON )
    {
        printf("Ошибка: сила не может быть нулевой!\n");
        abort();
    }
    
    return  sqrt((G * m1_kg * m2_kg) / force);
}
