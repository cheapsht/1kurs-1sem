#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * @brief сортирует числа в порядке возрастания
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @return возвращает сортировку в порядке возрастания
 */
double getStrypeUP(double min_num, double middle_num, double max_num);
/**
 * @brief сортирует числа в порядке убывания
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @return возвращает сортировку в порядке убывания
 */
double getStrypeDOWN(double min_num, double middle_num, double max_num);
/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();
/**
@brief StrypeUP - сортировка по возрастанию
@brief StrypeDOWN - сортировка по убыванию
*/
enum {StrypeUP, StrypeDOWN};
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    printf("Введите переменную а : ");
    double a = getValue();
    printf("Введите переменную b : ");
    double b = getValue();
    printf("Введите переменную c : ");
    double c = getValue();
    double max_num = fmax(fmax(a, b), c);
    double min_num = fmin(fmin(a, b), c);
    double middle_num = a + b + c - max_num - min_num;
    
    printf("выберите порядок чисел: 0(по возрастанию),1(по убыванию) : ");
    int choice = (int) getValue();
    switch(choice)
    {
        case StrypeUP:
           return getStrypeUP(min_num,  middle_num, max_num);
            break;
        case StrypeDOWN:
            return getStrypeDOWN(min_num,  middle_num, max_num);
            break;
        default:
            printf("Неправильный выбор");
            abort();
    }
}

double getStrypeUP(double min_num, double middle_num, double max_num)
{
    printf("Сортировка по возрастанию: %.2lf, %.2lf, %.2lf\n", min_num, middle_num, max_num);
    return 0;
}

double getStrypeDOWN(double min_num, double middle_num, double max_num)
{
    printf("Сортировка по убыванию: %.2lf, %.2lf, %.2lf\n", max_num, middle_num, min_num);
    return 0;
}
double getValue()
{
    double value = 0;
    if (!scanf("%lf",&value))
    {
        printf("Неверный ввод!");
        abort();
    }
    return value;
}


