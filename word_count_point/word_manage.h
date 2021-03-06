#ifndef WORD_MANAGE_H
#define WORD_MANAGE_H
#include "word_manage_p.h"

void word_initialize(void);
void add_word(char *word);
void dump_word(FILE *fp);
void word_finalize(void);
int get_word_count(char *word);

#endif // WORD_MANAGE_H
