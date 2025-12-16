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
void getStrypeUP(const double min_num, const double middle_num, const double max_num);
/**
 * @brief сортирует числа в порядке убывания
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @return возвращает сортировку в порядке убывания
 */
void getStrypeDOWN(const double min_num,const  double middle_num,const double max_num);
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
    printf("Введите переменную x : ");
    double x = getValue();
    double x1 = sin(x);
    printf("sin x = %.2lf\n",x1);
    double x2 = cos(x);
    printf("cos x = %.2lf\n",x2);
    double x3 = log(x);
    if (x>0)
    {
        printf("log x находится в пределах области значений");
        printf("ln(x) x = %.2lf\n",x3);
    }
    else
    {
        printf("ln(x) находится за пределами области значений");
        return 1
    }
    double max_num = fmax(fmax(x1, x2), x3);
    double min_num = fmin(fmin(x1, x2), x3);
    double middle_num = x1+ x2 + x3 - max_num - min_num;

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
            return 1
    }
return 0;
}

void getStrypeUP(const double min_num, const double middle_num,const  double max_num)
{
    printf("Сортировка по возрастанию: %.2lf, %.2lf, %.2lf\n", min_num, middle_num, max_num);
}

void getStrypeDOWN(const double min_num, const double middle_num, const double max_num)
{
    printf("Сортировка по убыванию: %.2lf, %.2lf, %.2lf\n", max_num, middle_num, min_num);
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
