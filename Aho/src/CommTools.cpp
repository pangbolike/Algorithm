/*
*Author : pangbolike
*Date : 2015/04/25
*A new method for Aho-Corasick
*/
#include "CommTools.h"
#include <iostream>
bool Convert2hex(char str1[],char str2[],unsigned len1,unsigned len2)
{
    if (len1 * 2 > len2)
        return false;
    unsigned char *p1 = (unsigned char *)str1;
    unsigned char *p2 = (unsigned char *)str2;
    for (unsigned i=0 ;i < len1 ; i++){
        p2[2*i] = p1[i] >> 4;
        p2[2*i+1] = p1[i] & 0xf;
    }

    return true;
}
