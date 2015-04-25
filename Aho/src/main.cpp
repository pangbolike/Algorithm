#include <iostream>
#include "CommTools.h"
#include "Aho.h"
using namespace std;

int main()
{
    Aho aho;
    char str[200];
    strcpy(str,"123456");
    aho.ins(str,strlen(str));
    strcpy(str,"fjdskfjdklsjfkldjslf");
    aho.ins(str,strlen(str));
    strcpy(str,"apple");
    aho.ins(str,strlen(str));
    aho.build();
    while(cin>>str){
        cout<<str<<endl;
        cout<<aho.search(str,strlen(str))<<endl;
    }
    return 0;
}
