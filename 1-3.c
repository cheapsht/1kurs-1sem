#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
double getValue();
double findDistance(double m1_ton, double m2_ton, double F);

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
    if (force == 0)
    {
        printf("Ошибка: сила не может быть нулевой!\n");
        abort();
    }
    
    return  sqrt((G * m1_kg * m2_kg) / force);
}
