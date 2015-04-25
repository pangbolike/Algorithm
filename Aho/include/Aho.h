#ifndef AHO_H_INCLUDED
#define AHO_H_INCLUDED

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "CommTools.h"
#include <queue>
#include <iostream>

#define NODE_ARR_SIZE 16
#define AHO_MEM_MAX_SIZE 4194304
#define AHO_MEM_MID_SIZE 1048576
#define AHO_MEM_MIN_SIZE 262144

struct node{
    int Cnt;
    node *Kids[NODE_ARR_SIZE];
    node *Next[NODE_ARR_SIZE];
    node *Fail;
    node();
};

class Aho{
private:
    node *Root;
    node *NodeArr;
    unsigned int pos;
    unsigned int MaxSize;

public:
    Aho();
    Aho(unsigned int mem_size);
    ~Aho();
    bool ins(char str[],unsigned len1);
    bool build();
    bool search(char str[],unsigned len1);

};

#endif // AHO_H_INCLUDED
