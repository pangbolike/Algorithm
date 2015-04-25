/*
*Author : pangbolike
*Date : 2015/04/25
*A new method for Aho-Corasick
*/
#include "Aho.h"

node::node(){
    Cnt = 0;
    Fail = NULL;
    memset(Kids,0,sizeof(Kids));
    memset(Next,0,sizeof(Next));
}
Aho::Aho()
{
    NodeArr = new node[AHO_MEM_MID_SIZE];
    MaxSize = AHO_MEM_MID_SIZE;
    Root = NodeArr;
    pos = 1;
}
Aho::Aho(unsigned int mem_size)
{
    mem_size = mem_size < AHO_MEM_MIN_SIZE ? AHO_MEM_MIN_SIZE : mem_size > AHO_MEM_MAX_SIZE ? AHO_MEM_MAX_SIZE : mem_size;
    NodeArr = new node[mem_size];
    MaxSize = mem_size;
    Root = NodeArr;
    pos = 1;
}
Aho::~Aho()
{
    delete NodeArr;
}
bool Aho::ins(char str[],unsigned len1){
    unsigned len2 = 2 * len1;
    char *hex_str = new char[len2];
    Convert2hex(str,hex_str,len1,len2);

    node *p = Root;
    unsigned i = 0;
    unsigned char index = 0;
    while(i < len2)
    {
        index = hex_str[i];
        if (p->Kids[index] == NULL)
        {
            if (pos >= MaxSize)
            {
                delete hex_str;
                return false;
            }
            p->Kids[index] = &NodeArr[pos++];
        }
        p = p->Kids[index];
        i++;
    }
    p->Cnt++;
    delete hex_str;
    return true;
}

bool Aho::build()
{
    std::queue<node *> q;
    node *p1,*p2;
    unsigned char i,j;
    q.push(Root);
    while(!q.empty())
    {
        p1 = q.front();
        q.pop();
        for (i = 0 ; i < NODE_ARR_SIZE ; i++)
        {
            if (p1->Kids[i] != NULL)
            {
                if (p1 == Root)
                {
                    p1->Kids[i]->Fail = Root;
                }
                else
                {
                    p2 = p1;
                    while((p2 = p2->Fail) != NULL)
                    {
                        if (p2->Kids[i] != NULL)
                        {
                            p1->Kids[i]->Fail = p2->Kids[i];
                            break;
                        }
                    }
                    if (p2 == NULL)
                    {
                        p1->Kids[i]->Fail = Root;
                    }
                }
                for (j = 0 ;j < NODE_ARR_SIZE ; j++)
                {
                    if (p1->Kids[i]->Kids[j] != NULL) continue;
                    else if (p1->Kids[i]->Fail->Kids[j] != NULL)
                    {
                        p1->Kids[i]->Next[j] = p1->Kids[i]->Fail;
                    }
                    else
                    {
                        p1->Kids[i]->Next[j] = p1->Kids[i]->Fail->Next[j];
                    }
                }
                q.push(p1->Kids[i]);
            }
        }
    }
    return true;
}
bool Aho::search(char str[],unsigned len1)
{
    unsigned len2 = 2 * len1;
    char *hex_str = new char[len2];
    Convert2hex(str,hex_str,len1,len2);
    unsigned i = 0;
    unsigned char index = 0;
    node *p = Root;
    while(i < len2)
    {
        index = hex_str[i];
        if (p->Kids[index] != NULL)
        {
            p = p->Kids[index];
            if (p->Cnt != 0)
            {
                delete hex_str;
                return true;
            }
            i++;
        }
        else
        {
            p = p->Next[index];
            if (p == NULL)
            {
                p = Root;
                i++;
            }
        }

    }
    delete hex_str;
    return false;
}



