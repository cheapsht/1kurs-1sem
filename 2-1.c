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
 * @brief даёт выбрать пользователю тип сортировки
 * @param min_num минимальное значение из трех
 * @param middle_num среднее значение из трех
 * @param max_num максимальное значение из трех
 * @param choice значения ввода (1 или 2)
 * @return возвращает выбор пользователя и выбранную сортировку
 */
double getChoice(int choice, double min_num, double middle_num, double max_num);
/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    double a, b, c;
    int choice;
    
    printf("введите переменную a:");
    if (scanf("%lf", &a) != 1)/* если в программу ввести не число , она экстренно завершает работу*/
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    
    printf("введите переменную b:");
    if (scanf("%lf", &b) != 1)/* если в программу ввести не число , она экстренно завершает работу*/
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    
    printf("введите переменную c:");
    if (scanf("%lf", &c) != 1)/* если в программу ввести не число , она экстренно завершает работу*/
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    

    double max_num = fmax(fmax(a, b), c);
    double min_num = fmin(fmin(a, b), c);
    double middle_num = a + b + c - max_num - min_num;
    
    printf("выберите порядок чисел: 1(по возрастанию),2(по убыванию)\n");
    if (scanf("%d", &choice) != 1)/* если в программу ввести не число , она экстренно завершает работу*/
    {
        printf("Ошибка ввода!\n");
        abort();
    }
    
    return getChoice(choice, min_num, middle_num, max_num);
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

double getChoice(int choice, double min_num, double middle_num, double max_num)
{
    if (choice == 1)
    {
        getStrypeUP(min_num, middle_num, max_num);
    }
    else if (choice == 2)
    {
        getStrypeDOWN(min_num, middle_num, max_num);
    }
    else
    {
        printf("Неверный ввод, программа завершена");/* если ввести числа  не подходящие под программу */
        abort();
    }
    return 0;
}
