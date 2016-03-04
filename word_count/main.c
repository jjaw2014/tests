#include <stdio.h>
#include "word_manage.h"
#include "get_word.h"
#define WORD_LEN_MAX (1024)

int main(int argc,char **argv)
{
    char buf[WORD_LEN_MAX];
    FILE *fp;
    //文件读取
    if(argc == 1)
    {
         fprintf(stderr,"%s:not file.",argv[0]);
         return 0;
    }
    else
    {
        fp = fopen(argv[1],"r");
        if(fp == NULL)
        {
            fprintf(stderr,"%s:%s can not open.",argv[0],argv[1]);
            return 0;
        }
    }

    //初始化
    word_initialize();

    //读取并添加单词
    while(get_word(buf,WORD_LEN_MAX,fp)!=EOF)
    {
        add_word(buf);
    }

    fclose(fp);
    //输出结果
    dump_word(stdout);

    //制空处理
    word_finalize();

    printf("-------------------------\n");

    return 0;
}

