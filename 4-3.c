#include <stdio.h>
#include <stdlib.h>
/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int Value();
/**
 * @brief заполняет массив числами,введенными с клавиатуры
 * @param arr указатель на массив для заполнения
 * @param size размер массива
 */
size_t getSize(char* message);
/**
 * @brief заполняет массив с клавиатуры
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
void fillArray(int** arr, const size_t rows,const size_t columns);
/**
 * @brief выводит массив
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
void printArray(int** arr, const size_t rows,const size_t columns);
/**
 * @brief заполняет массив рандомными числами
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
void fillRandom(int** arr, const size_t rows,const size_t columns);
/**
 * @brief заполняет массив с клавиатуры
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
int** getArray(const size_t rows, const size_t columns);
/**
 * @brief проверяет расстояние между начальныым значением и конечным
 * @param start начальне значение
 * @param end конечное значение
 */
void checkRange(const int start, const int end);
/**
 * @brief освобождает массив
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 */
void freeArray(int** arr, const size_t rows);
/**
 * @brief заменяет элементы кратные трем на нули
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
void replaceElKRAtTREM(int** arr,const size_t rows, const size_t columns);
/**
 * @brief убирает строку,в которой второй элемент больше предпоследнего
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
void removeElementsFromString(int** arr, size_t rows, size_t columns);
/**
 * @brief делает копию массива
 * @param arr указатель на массив для заполнения
 * @param rows строки массива
 * @param columns  строки массива
 */
int** copyArray(int** arr,const size_t rows, const size_t columns);
/**
 * @brief освбождает память и выводит ошибку
 * @param arr массив для освобождения
 * @param message сообщение об ошибке
 */
void handleError(int* arr, char* message);
/**
@brief RANDOM -  заполняет массив случайными числами
@brief MANUAL - заполняет массив числами введенными с клавиатуры
*/
enum{RANDOM =1 , MANUAL = 2};
/**
@brief ex1  -  выполняет первую функцию
@brief ex2  -  выполняет вторую функцию
 */
enum{ ex1 = 1, ex2 = 2};
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    size_t rows = getSize("Введите количество строк массива:  ");
    size_t columns = getSize("Введите количество стобцов массива:  ");
    int** arr = getArray(rows,columns);
    printf("Выберите способ заполнения массива:\n"
                "%d случайными числами, %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch(choice)
        {
            case RANDOM:
                fillRandom(arr, rows, columns);
                break;
            case MANUAL:
                fillArray(arr, rows, columns);
                break;
            default:
                printf("error");
                freeArray(arr, rows);
                break;
        }
    int** copyArr = copyArray(arr,rows,columns);
    if (arr == NULL)
    {
        handleError(NULL, "Ошибка выделения памяти!");
    }
    printf("выберите задание - 1,2 : ");
    int choice2 = Value();
    switch(choice2)
    {
        case ex1:
            replaceElKRAtTREM(copyArr,rows,columns);
            break;
        case ex2:
            removeElementsFromString(copyArr,rows,columns);
            break;
    }
    printArray(copyArr, rows, columns);
    freeArray(copyArr, rows);
    freeArray(arr, rows);
    return 0;
}
int Value()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}
size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}
void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j<columns; j++)
        {
            printf("Введите a[%d,%d] = ",i,j);
            arr[i][j] = Value();
        }
    }
}
void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j=0; j<columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fillRandom(int** arr, const size_t rows,const size_t columns)
{
    printf("Введите начало диапазона случайных чисел : ");
    int start = Value();
    printf("Введите конец диапазона случайных чисел : ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}
int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    for (size_t i = 0; i<rows; i++ )
    {
        arr[i] = malloc(columns * sizeof(int));
    }
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    return arr;
}
void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i<rows; i++ )
    {
        free(arr[i]);
    }
    free(arr);
}
void checkRange(const int start, const int end)
{
    if(start > end)
    {
        printf("Error\n");
        exit(1);
    }
}
void replaceElKRAtTREM(int** arr,const size_t rows, const size_t columns)
{
    int found = 0;
    for ( size_t i =0; i<rows;i++)
    {
        for ( size_t j =0; j<columns;j++)
        {
            if (arr[i][j] %3 == 0)
            {
                arr[i][j] = 0;
                found = 1;
            }
        }
    }
    if (found)
    {
        printf("элементы кратные трем заменены на нули\n");
        printArray(arr,rows,columns);
    }
    else
    {
        printf("элементы кратные трем заменены не найдены\n");
    }
}
void removeElementsFromString(int** arr, size_t rows, size_t columns)
{
    if (columns < 4) {
        printf("Массив должен иметь минимум 4 столбца для сравнения\n");
        return;
    }
    int found = 0;
    
    for (size_t i = 0; i < rows; i++)
    {
        if (arr[i][1] > arr[i][columns - 2])
        {
            for (size_t j = 0; j < columns; j++)
            {
                arr[i][j] = 0;
            }
            found = 1;
        }
    }
    
    if (found)
    {
        printf("Строки, где второй элемент больше предпоследнего, обнулены\n");
        printArray(arr, rows, columns);
    }
    else
    {
        printf("Строки для обнуления не найдены\n");
    }
}
int** copyArray(int** arr,const size_t rows, const size_t columns)
{
    int** copyArr = malloc(rows * sizeof(int*));
    for (size_t i =0; i<rows; i++)
    {
        copyArr[i] = malloc(columns * sizeof(int));
        for (size_t j =0; j<columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}
void handleError(int* arr, char* message)
{
    if (arr != NULL)
    {
        free(arr);
    }
    fprintf(stderr, "%s\n", message);
    exit(1);
}
