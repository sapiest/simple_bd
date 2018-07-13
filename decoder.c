//
// Created by toxaxab on 01.06.18.
//
#include <stdio.h>
#include <memory.h>
#include "define.h"

typedef struct t_node_decoder {
    long long parent;
    unsigned char val;
} t_node_decoder;
t_node_decoder HEAP_D[MAX_SIZE];


FILE *out;
FILE *inp;
t_stream *stream_in;
t_stream *stream_out;
int countb = DEFAULT_B;
int p2 = DEFAULT_P2;
int k = DEFAULT_K;
void initializeHEAP() {
    for (int i = 0; i < 256; ++i) {
        HEAP_D[i].val = i;
        HEAP_D[i].parent = i;
    }
}

void del_Heap() {
    memset(HEAP_D, 0, MAX_SIZE * sizeof(t_node_decoder));
}

int get_value(long long pos){
    static char CUR[BUF_SIZE];
    int i = 0;
    CUR[i] = HEAP_D[pos].val;
    while (pos != HEAP_D[pos].val){
        pos = HEAP_D[pos].parent;
        CUR[++i] = HEAP_D[pos].val;
    }
    return CUR[i];
}

void print_symbol(long long pos) {
    static char CUR[BUF_SIZE];
    int i = 0;
    CUR[i] = HEAP_D[pos].val;
    while (pos != HEAP_D[pos].val){
        pos = HEAP_D[pos].parent;
        CUR[++i] = HEAP_D[pos].val;
    }
    for (int j = i; j >= 0; --j) {
        fputc(CUR[j],out);
    }
}

int read_code(unsigned int *cur, t_stream *stream, int count_size) {
    *cur = 0;
    int bit = 0;
    for (int i = countb; i >= 0; --i) {
        bit = fread_bit(stream);
        if (bit == 1)
            *cur |= 1 << i;
        else if(bit == 0)
            *cur &= ~(1 << i);
        else return 1;
    }
}

int decode() {
    inp = fopen(inputDECODER, "rb");
    if(!inp)
        return -1;
    out = fopen(outputDECODER, "wb");
    stream_in = fopen_bit(inp, 0);
    stream_out = fopen_bit(out, BUFF_SIZE);
    int start = 0;
    unsigned int current = 0;
    initializeHEAP();
    while (1) {
        if(bit_feof(stream_in) == EOF)
            break;
        if(read_code(&current, stream_in, countb) == 1){
            break;
        }
        if(countb == 7){
            print_symbol(current);
            start = current;
            p2 <<= 1;
            ++countb;
            continue;
        }
        if(k < n){
            if(current < k)
                HEAP_D[k].val = get_value(current);
            else
                HEAP_D[k].val = get_value(start);
            HEAP_D[k].parent = start;
            start = current;
            print_symbol(current);
            k++;
            if(k >= p2) {
                p2 <<= 1;
                ++countb;
            }
            continue;
        }
        del_Heap();
        initializeHEAP();
        countb = DEFAULT_B;
        p2 = DEFAULT_P2;
        k = DEFAULT_K;
        print_symbol(current);
        start = current;
    }
    fclose_bit(stream_out);
    fclose(inp);
    fclose(out);
    return 0;
}