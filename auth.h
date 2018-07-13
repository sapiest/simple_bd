//
// Created by toxaxab on 24.06.18.
//

#ifndef PEPE2023_AUTH_H
#define PEPE2023_AUTH_H

#define WORD_LEN 100
#define SIZE_TABLE 11
#define rubbish 'j'
#define MAX_pen 2000000
#define PASS_LENGH 50

typedef struct t_member{
    char name[WORD_LEN];
    struct t_member* child;
    char pass[PASS_LENGH];
    int pension;
}t_member;

void printinfile(t_member* members);

void initialize_mem(t_member *members);

int auth(t_member **req, t_member *members);

#endif //PEPE2023_AUTH_H
