#include "include.h"

int strIndex(int pos, char* t);
int strIndex0(int pos, char* t);

char str[]="abcaabcadac";

int main()
{
    char t[] = "abcad";
    int ix=strIndex0(8, t);
    cout << ix << endl;
    return 0;
}

int strIndex(int pos, char* t)
{
    int i=pos,j=1;
    while(i<=11 && j<=5)
    {
        if(str[i-1]==t[j-1])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
    }
    if(j>5)
        return i-5;
    else
        return 0;
}

int strIndex0(int pos, char* t)
{
    for(int i = pos; i<=11-5+1; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(str[i+j-1]!=t[j])
                break;
            if(j==4)
                return i;
        }
    }
    return 0;
}

