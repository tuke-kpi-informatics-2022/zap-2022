#include <math.h>
#include <stdio.h>

//=Task1===========================================================================
float lift_a_car(const int stick_length, const int human_weight, const int car_weight)
{
    return (float)roundf(((float)((float)stick_length * (float)human_weight) / (float)((float)human_weight + (float)car_weight)) * 100.0) / 100.0;
}
//=================================================================================

//=Task2===========================================================================
float unit_price(const float pack_price, const int rolls_count, const int pieces_count)
{
    return (float)roundf(((float)((float)((float)pack_price / (float)rolls_count) / (float)pieces_count) * 100.0) * 100.0) / 100.0;
}
//=================================================================================

//=Task3===========================================================================
int collatz(const int number)
{
    int num = number, count = 0;

    for (; num != 1; count++)
    {
        num = (num % 2 == 0) ? num / 2 : num * 3 + 1;
    }

    return (int)count + 1;
}
//=================================================================================

//=Task4===========================================================================
int opposite_number(const int n, const int number)
{
    return (int)(number >= n / 2) ? number - n / 2 : number + n / 2;
}
//=================================================================================

//=Task5===========================================================================
void counter(const int input_array[], const int array_size, int result_array[2])
{
    if (input_array == NULL || array_size <= 0 || result_array == NULL)
    {
        return;
    }

    result_array[0] = result_array[1] = 0;

    for (int i = 0; i < array_size; i++)
    {
        result_array[(i % 2 == 0) ? 0 : 1] += (i % 2 == 0) ? (int)input_array[i] : (int)input_array[i];
    }
}
//=================================================================================

//=Task6===========================================================================
unsigned long sum_squared(const int line)
{
    unsigned long long pascalSum = 1;

    for (unsigned long long int i = 1, current = 0, previous = 1; i <= line; i++, previous = current)
    {
        current = (previous * (line - i + 1)) / i;
        pascalSum += (current * current);
    }

    return (unsigned long)pascalSum;
}
//=================================================================================

//=Task7===========================================================================
int array_min(const int input_array[], const int array_size)
{
    if (input_array == NULL || array_size <= 0)
    {
        return -1;
    }

    int min = (int)input_array[0];

    for (int i = 1; i < array_size; i++)
    {
        min = (min > input_array[i]) ? input_array[i] : min;
    }

    return (int)min;
}
int array_max(const int input_array[], const int array_size)
{
    if (input_array == NULL || array_size <= 0)
    {
        return -1;
    }

    int max = (int)input_array[0];

    for (int i = 1; i < array_size; i++)
    {
        max = (max < input_array[i]) ? input_array[i] : max;
    }

    return (int)max;
}
//=================================================================================

//=Task8===========================================================================
unsigned long special_counter(const int input_array[], const int array_size)
{
    int arr_sum = 0;

    for (int i = 0; i < array_size; i++)
    {
        arr_sum += (i % 2 == 0) ? input_array[i] : (input_array[i] * input_array[i]);
    }

    return (unsigned long)arr_sum;
}
//=================================================================================

//=Task9===========================================================================
int special_numbers(const int input_array[], const int array_size, int result_array[])
{
    if (input_array == NULL || array_size <= 0)
    {
        return -1;
    }

    int res_i = 0, sum = 0;

    for (int i = 0; i < array_size; i++)
    {
        sum += input_array[i];
    }

    for (int i = 0; i < array_size; i++)
    {
        sum -= input_array[i];

        if (input_array[i] > sum)
        {
            result_array[res_i++] = input_array[i];
        }
    }

    return (int)res_i;
}
//=================================================================================

int main()
{

    //=Task1===========================================================================
    printf("\nTest Task1 -------------------------\n");
    printf("%.4f == 0.1100\n", lift_a_car(2, 80, 1400)); // prints: 0.1100
    printf("%.4f == 0.2100\n", lift_a_car(4, 90, 1650)); // prints: 0.2100
    //=================================================================================

    //=Task2===========================================================================
    printf("\nTest Task2 -------------------------\n");
    printf("%.4f == 0.2000\n", unit_price(4.79, 16, 150)); // prints: 0.2000
    printf("%.4f == 0.1400\n", unit_price(5.63, 20, 200)); // prints: 0.1400
    //=================================================================================

    //=Task3===========================================================================
    printf("\nTest Task3 -------------------------\n");
    printf("%d == 8\n", collatz(20));  // prints: 8
    printf("%d == 14\n", collatz(35)); // prints: 14
    //=================================================================================

    //=Task4===========================================================================
    printf("\nTest Task4 -------------------------\n");
    printf("%d == 7\n", opposite_number(10, 2)); // prints: 7
    printf("%d == 3\n", opposite_number(12, 9)); // prints: 3
    //=================================================================================

    //=Task5===========================================================================
    printf("\nTest Task5 -------------------------\n");
    int input_array[] = {1, 2, 3, 4, 5};
    int result_array[2];
    counter(input_array, 5, result_array);
    printf("%d %d == 9 6\n", result_array[0], result_array[1]); // prints: 9 6
    //=================================================================================

    //=Task6===========================================================================
    printf("\nTest Task6 -------------------------\n");
    printf("%lu == 2\n", sum_squared(1));                    // prints: 2
    printf("%lu == 70\n", sum_squared(4));                   // prints: 70
    printf("%lu == 7219428434016265740\n", sum_squared(33)); // prints: 7219428434016265740
    //=================================================================================

    //=Task7===========================================================================
    printf("\nTest Task7 -------------------------\n");
    int input_array2[] = {1, 2, 3, 4, 5};
    printf("%d == 1\n", array_min(input_array2, 5)); // prints: 1
    printf("%d == 5\n", array_max(input_array2, 5)); // prints: 5
    printf("%d == -1\n", array_max(NULL, 5));        // prints: -1
    //=================================================================================

    //=Task8===========================================================================
    printf("\nTest Task8 -------------------------\n");
    int input_array3[] = {11, 12, 13, 14, 15};
    printf("%lu == 379\n", special_counter(input_array3, 5)); // prints: 379
    //=================================================================================

    //=Task9===========================================================================
    printf("\nTest Task9 -------------------------\n");
    int input_array4[] = {16, 17, 4, 3, 5, 2};
    int result_array2[6];
    int count = special_numbers(input_array4, 6, result_array2);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", result_array2[i]);
    }
    printf(" == 17 5 2\n"); // prints: 17 5 2
    //=================================================================================

    return 0;
}