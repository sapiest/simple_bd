//
// Created by toxaxab on 24.06.18.
//

#include <stdio.h>
#include <ctype.h>
#include "auth.h"
#include "define.h"

int code();

int decode();

int get_word(char *str, FILE *f) {
    int index = 0;
    int c = 0;
    while ((c = getc(f)) == ' '){}
    if(c == EOF)
        return EOF;
    str[index] = c;
    while ((c = getc(f)) != '\n' && c != EOF)
        str[++index] = c;
    str[++index] = '\0';
    if ((str[0] != '\0' && c != 10 && c != EOF))
        return 1;
    else
        return 0;
}

void push_new(t_member *Head, const char *key, int pension, char *pass) {
    t_member *tmp = (t_member*)malloc(sizeof(t_member));
    tmp->pension = pension;
    tmp->child = NULL;
    strcpy(tmp->pass, pass);
    strcpy(tmp->name, key);
    Head->child = tmp;
}

void add_to_table_new(int h, int pension , char *pass, const char *key, t_member *members) {
    t_member *next = &members[h];
    while (next->child != NULL && (strcmp(next->name, key) != 0))
        next = next->child;
    push_new(next, key, pension, pass);
}

void initialize_mem(t_member *members) {
    decode();
    FILE *file = fopen(outputDECODER, "rb");
    if (!file)
        return;
    static char name[WORD_LEN];
    int h, amount;
    char pass[PASS_LENGH];
    while (!feof(file)) {
        fscanf(file, "%d", &h);
        fscanf(file, "%d", &amount);
        fscanf(file, "%s", pass);
        if(get_word(name,file) == EOF)return;
        add_to_table_new(h, amount, pass, name, members);
        //printf("%d %d %s %s\n", h, amount, pass, name);
    }
    remove(outputDECODER);
}

void printinfile(t_member *members) {
    FILE *file = fopen(inputCODER, "wb");
    for (int i = 0; i < SIZE_TABLE; ++i) {
        if (members[i].child == NULL) continue;
        t_member *current = members[i].child;
        while (current != NULL) {
            if(current->pass[0] == '\0') break;
            fprintf(file, "%d %d %s %s\n", i, current->pension, current->pass, current->name);
            //printf("%d %d %s %s\n", i, current->pension, current->pass, current->name);
            current = current->child;
        }
        //free(current);
    }
    fclose(file);
    code();
    remove(inputCODER);
}