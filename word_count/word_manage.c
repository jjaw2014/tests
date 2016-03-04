#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "word_manage.h"

Word word_array[WORD_NUM_MAX];
int num_of_word;

//初始化
void word_initialize(void)
{
    num_of_word = 0;
}

//添加一个单词
static void shift_array(int index)
{
    int src;
    for(src = num_of_word - 1; src >= index; src--)
    {
        word_array[src+1] = word_array[src];
    }
    num_of_word++;
}

//复制字符串
static char* my_strdup(char *src)
{
    char *dest;
    if((dest = malloc(sizeof(char) * (strlen(src) + 1))) == NULL)
    {
        fprintf(stderr,"malloc error!");
        exit(-1);
    }
    else
    {
        strcpy(dest,src);
    }
    return dest;
}

//追加单词
void add_word(char *word)
{
    int i;
    int result;
    for(i = 0; i < num_of_word; i++)
    {
        result = strcmp(word_array[i].name,word);
        if(result >= 0)
        {
            break;
        }
    }

    if(num_of_word != 0 && result == 0)
    {
        //发现相同的单词
        word_array[i].count++;
    }
    else
    {
        shift_array(i);
        word_array[i].name = my_strdup(word);
        word_array[i].count = 1;
    }
}

//输出单词
void dump_word(FILE *fp)
{
    int i;
    for(i = 0; i < num_of_word; i++)
    {
        fprintf(fp,"%-20s%5d\n",word_array[i].name,word_array[i].count);
    }
}

//结束销毁数组
void word_finalize(void)
{
    int i;
    for(i = 0; i < num_of_word; i++)
    {
        free(word_array[i].name);
        word_array[i].name = NULL;
        word_array[i].count = 0;
    }
    num_of_word = 0;
}

//查询相关单词次数
int get_word_count(char *word)
{
    int left = 0;
    int right = num_of_word - 1;
    int mid;
    int result;

    while(left <= right)
    {
        mid = (left+right) / 2;
        result = strcmp(word_array[mid].name,word);
        if(result < 0)
        {
            left = mid + 1;
        }
        else if(result > 0)
        {
            right = mid - 1;
        }
        else
        {
            return word_array[mid].count;
        }
    }
    return 0;
}
