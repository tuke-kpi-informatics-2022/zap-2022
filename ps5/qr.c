#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_NUM 8

void encode_char(const char character, bool bits[8])
{
    int *right_shift_num = (int *)malloc(sizeof(int));
    int *true_num = (int *)malloc(sizeof(int));

    *(true_num) = (int)true;

    for (int bit_num = BITS_NUM - 1, arr_i = 0; bit_num > -1 && arr_i < BITS_NUM;)
    {
        *(right_shift_num) = (int)(character >> bit_num--);
        bits[arr_i++] = (bool)((int)*(right_shift_num) & (int)*(true_num));
    }

    free(right_shift_num);
    free(true_num);
}
char decode_byte(const bool bits[8])
{
    int *decimal_num = (int *)malloc(sizeof(int));
    int *true_num = (int *)malloc(sizeof(int));

    *(true_num) = (int)true;
    *(decimal_num) = 0;

    for (int i = 0; i < BITS_NUM; i++)
    {
        *(decimal_num) <<= ((bool)*(true_num));
        *(decimal_num) += (int)bits[i];
    }

    char symbol = (char)*(decimal_num);

    free(decimal_num);
    free(true_num);

    return (char)symbol;
}

void encode_string(const char string[], bool bytes[strlen(string) + 1][8])
{
    int *string_size = (int *)malloc(sizeof(int));
    void (*function_pointer)(const char, bool *) = &encode_char;

    *(string_size) = strlen(string) + 1;

    for (int i = 0; i < *(string_size); i++)
    {
        function_pointer(string[i], bytes[i]);
    }

    free(string_size);
}
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    char (*function_pointer)(const bool *) = &decode_byte;

    for (int i = 0; i < rows; i++)
    {
        string[i] = function_pointer(bytes[i]);
    }
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset * 8][cols], const int rows, bool bytes[rows][8])
{
    int *row_index_blocks = (int *)malloc(sizeof(int));
    int *row_index_bytes = (int *)malloc(sizeof(int));

    for (int offset_i = 0; offset_i < offset; offset_i++)
    {
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < BITS_NUM; j++)
            {
                *(row_index_blocks) = (int)(j + (offset_i * BITS_NUM));
                *(row_index_bytes) = (int)(i + (cols * offset_i));
                blocks[*(row_index_blocks)][i] = (bool)((*(row_index_bytes) >= rows) ? (bool)false : (bool)bytes[*(row_index_bytes)][j]);
            }
        }
    }

    free(row_index_blocks);
    free(row_index_bytes);
}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset * BITS_NUM][cols], const int rows, bool bytes[rows][8])
{
    int *row_index_blocks = (int *)malloc(sizeof(int));
    int *row_index_bytes = (int *)malloc(sizeof(int));

    for (int offset_i = 0; offset_i < offset; offset_i++)
    {
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < BITS_NUM; j++)
            {
                *(row_index_blocks) = (int)(j + (offset_i * BITS_NUM));
                *(row_index_bytes) = (int)(i + (cols * offset_i));

                if (*(row_index_bytes) < rows)
                {
                    bytes[*(row_index_bytes)][j] = (bool)blocks[*(row_index_blocks)][i];
                }
            }
        }
    }

    free(row_index_blocks);
    free(row_index_bytes);
}

int main()
{
    return 0;
}
