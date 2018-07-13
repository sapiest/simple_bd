#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include <time.h>
#include <ctype.h>

//
// Created by toxaxab on 24.06.18.
//

int hash(const char *key) {
    const int p = 3;
    int h = 0;
    int k = 1;
    for (int i = 0; i < WORD_LEN; ++i) {
        if (key[i] == '\0') break;
        h += (key[i] * k + rubbish);
        k *= p;
    }
    h %= SIZE_TABLE;
    return abs(h);
}

void toLowerRus(unsigned char *key) {
    int code = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        if (key[i] == 32)
            code = 1;
        if (key[i] == '\n')
            key[i] = '\0';
        if (!((++code) % 2)) {
            if (key[i] > 143 && key[i] < 160) {
                key[i] += 32;
            } else if (key[i] > 159 && key[i] < 176) {
                key[i - 1] = 209;
                key[i] -= 32;
            }
        }
    }
}

void toUpperRus(unsigned char *key) {
    int code = 0;
    for (int i = 0; i < WORD_LEN; ++i) {
        int t = key[i];
        if (key[i] == 32)
            code = 1;
        if (key[i] == '\n')
            key[i] = '\0';
        if (!((++code) % 2)) {
            if (key[i] > 175 && key[i] < 192) {
                key[i] -= 32;
            } else if (key[i] > 127 && key[i] < 144) {
                key[i - 1] = 208;
                key[i] += 32;
            }
        }
    }
}

t_member *new_member(const char *name) {
    t_member *tmp = (t_member *) malloc(sizeof(t_member));
    strcpy(tmp->name, name);
    tmp->child = NULL;
    memset(tmp->pass, '\0',1);
    srand(time( NULL ) );
    tmp->pension = rand() % (MAX_pen - 500 + 1) + 500;
    return tmp;
}

int search(const char *key, t_member **elem, int h, t_member *members) {
    t_member *next = &members[h];
    while (next->child != NULL && (strcmp(next->name, key) != 0))
        next = next->child;
    if (strcmp(next->name, key) == 0) {
        *elem = next;
        return 0;
    }
    return 1;
}

void push(t_member *Head, const char *key, t_member **cur) {
    t_member *tmp = new_member(key);
    *cur = tmp;
    Head->child = tmp;
}

void add_to_table(const char *key, t_member **cur, int h, t_member *members) {
    t_member *next = &members[h];
    while (next->child != NULL && (strcmp(next->name, key) != 0))
        next = next->child;
    push(next, key, cur);
}

int auth(t_member **req, t_member *members) {
    static t_member *cur;
    static unsigned char name[WORD_LEN];
    static char pass[50];
    printf("Введите ФИО\n");
    getc(stdin);
    fgets(name, WORD_LEN, stdin);
    toUpperRus(name);
    int h = hash(name);
    if (search(name, &cur, h, members) == 1) {
        add_to_table(name, &cur, h, members);
        printf("Создайте пароль\n");
    }else  printf("Введите пароль\n");
    //getc(stdin);
    scanf("%s", pass);
    if(cur->pass[0] == '\0') {
        strcpy(cur->pass, pass);
        printinfile(members);
    }
    if(!strcmp(cur->pass,pass)){
        *req = cur;
        printf("%s %d руб\n", cur->name, cur->pension);
        return 0;
    }else{
        printf("Неверный пароль\n");
        return -1;
    }
}
