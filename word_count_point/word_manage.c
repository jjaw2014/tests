#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage.h"

Word* word_header = NULL;

//初始化
void word_initialize(void)
{
    word_header = NULL;
}

//复制字符串
static char* my_strdup(char* src)
{
    char* dest;
    if((dest = malloc(sizeof(char) * strlen(src) + 1)) == NULL)
    {
        fprintf(stderr,"malloc error!");
        exit(-1);
    }

    strcpy(dest,src);
    return dest;
}

//增加一个单词
static Word* create_word(char *name)
{
    Word* new_word;
    if((new_word = malloc(sizeof(Word))) == NULL)
    {
        fprintf(stderr,"malloc error!");
        exit(-1);
    }

    new_word->name = my_strdup(name);
    new_word->count = 1;
    new_word->next = NULL;

    return new_word;
}

//追加单词
void add_word(char *word)
{
    Word *pos;
    Word *prev;
    Word *new_word;
    int result;

    prev = NULL;
    for(pos = word_header; pos != NULL; pos=pos->next)
    {
        result = strcmp(pos->name,word);
        if(result >= 0)
        {
            break;
        }
        prev = pos;
    }
    if(word_header != NULL && result == 0)
    {
        //相同单词
        pos->count++;
    }
    else
    {
        new_word = create_word(word);
        if(prev == NULL)
        {
            new_word->next = word_header;
            word_header = new_word;
        }
        else
        {
            new_word->next = pos;
            prev->next = new_word;

        }
    }
}

//打印
void dump_word(FILE *fp)
{
    Word* pos;
    for(pos = word_header; pos != NULL; pos = pos->next)
    {
        fprintf(fp,"%-20s%5d\n",pos->name,pos->count);
    }
}

//销毁链表
void word_finalize(void)
{
    Word* temp;
    while(word_header != NULL)
    {
        temp = word_header;
        word_header = word_header->next;

        free(temp->name);
        free(temp);
    }
}

//查找单词出现次数
int get_word_count(char *word)
{
    Word* pos;
    for(pos = word_header; pos != NULL; pos = pos->next)
    {
        if(strcmp(pos->name,word) == 0)
        {
            return pos->count;
        }
    }
    return 0;
}
