//
// Created by toxaxab on 01.06.18.
//
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <memory.h>
#include "define.h"

typedef struct t_node_coder{
    struct t_node_coder *CHILD[DEFAULT_K];
    unsigned long long int mask[4];
    int code;
}t_node_coder;
static t_node_coder HEAP_C[MAX_SIZE], *last = HEAP_C, *curr;

FILE *out;
FILE *inp;

void setbit(t_node_coder *head, const int position){
    int i = (int)(position / 64);
    head->mask[i] = ((head->mask[i] | ((unsigned long long int) 1 << position)));
}

int checkbit(t_node_coder *head, const int position) {
    int i = (int)(position / 64);
    return ((head->mask[i] & ((unsigned long long int) 1 << position)) != 0);
}

void set_defaultmask(){
    for (int i = 0; i < SIZE_MASK; ++i) {
        last->mask[i] = 0;
    }
}

t_node_coder *new_node(){
    set_defaultmask();
    return last++;
}

void *del_node(){
    last = HEAP_C;
}

void initializeHEAPCODER(t_node_coder *Head){
    for (int i = 0; i < DEFAULT_K; ++i) {
        setbit(Head,i);
        Head->CHILD[i] = new_node();
        Head->CHILD[i]->code = i;
    }
}

void print_code(int code, t_stream* stream, int count_size){
    for (int i = count_size; i >= 0; --i) {
        put_bit(((code & (1 << i))!= 0), stream);
    }
}

size_t read_text(void *ptr, size_t so, size_t count, FILE *file){
    return fread(ptr,so,count,file);
}

int code() {
    unsigned char head = 0;
    int len = 0;
    inp = fopen(inputCODER, "rb");
    if(!inp) {
        puts("No FILE");
        return -1;
    }
    out = fopen(outputCODER, "wb");
    t_stream *stream_out = fopen_bit(out, BUFF_SIZE);
    t_node_coder *root = new_node();
    initializeHEAPCODER(root);
    curr = root;
    int k = DEFAULT_K;
    int countb = DEFAULT_B;
    int p2 = DEFAULT_P2;
    static unsigned char buffer[BUF_SIZE];
    read_text(&head, 1, 1, inp);
    curr = curr->CHILD[head];
    while(!feof(inp)){
        //memset(buffer, '\0', BUF_SIZE);
        len = read_text(buffer, 1, BUF_SIZE, inp);
        for (int i = 0; i < len; ++i) {
            if(checkbit(curr,buffer[i])){
                curr = curr->CHILD[buffer[i]];
                continue;
            }
            if(k < n) {
                if(k > p2) {
                    p2 <<= 1;
                    ++countb;
                }
                print_code(curr->code, stream_out, countb);
                setbit(curr, buffer[i]);
                curr = curr->CHILD[buffer[i]] = new_node();
                curr->code = k++;
                curr = root->CHILD[buffer[i]];
                continue;
            }
            print_code(curr->code, stream_out, countb);
            del_node();
            root = new_node();
            initializeHEAPCODER(root);
            setbit(root,buffer[i]);
            curr = root->CHILD[buffer[i]];
            print_code(curr->code, stream_out, countb);
            k = DEFAULT_K;
            p2 = DEFAULT_P2;
            countb = DEFAULT_B;
            curr = root;
        }
    }
    if(curr->code != 0) {
        if(k > p2) {
            ++countb;
        }
        print_code(curr->code, stream_out, countb);
    }
    fclose_bit(stream_out);
    fclose(inp);
    fclose(out);
    return 0;
}