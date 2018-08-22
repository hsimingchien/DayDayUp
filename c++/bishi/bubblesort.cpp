#include <iostream>
#include <stdlib.h>

using namespace std;
const int __len_array = 10;

int bubbleSort1(int a[]);
int bubbleSort2(int a[]);
int main()
{
    cout << "__len_array is: " << __len_array << endl;
    int b[__len_array],c[__len_array];
    cout << "b[] is: " ;
    for(int ix = 0; ix < __len_array ; ix++)
    {
        b[ix] = rand() % __len_array;
        c[ix] = b[ix];
        cout << b[ix] << "\t" ;
    }
    cout << endl;
    cout << "--------------------" << endl;

    int count = bubbleSort1(b);
    cout << "---bubbleSort1 end--- count is:" << count << endl;

    for(int iz = 0; iz < __len_array; iz++)
        cout << b[iz] << "\t";
    cout << endl;

    cout << endl << "c[] is: " ;
    for(int iz = 0; iz < __len_array; iz++)
        cout << c[iz] << "\t";
    cout << endl;
    
    count = bubbleSort2(c);
    cout << "---bubbleSort2 end--- count is:" << count << endl;

    for(int iz = 0; iz < __len_array; iz++)
        cout << c[iz] << "\t";
    cout << endl;
    
    return 0;
}

int bubbleSort1(int a[])
{
    cout << "---bubbleSort1---" << endl;
    int tmp = 0, count = 0;
    for(int ix = 0; ix < __len_array -1; ix++)
    {
        for(int iy = ix + 1; iy < __len_array; iy ++)
        {
            if(a[ix] < a[iy])
            {
                tmp = a[ix];
                a[ix] = a[iy];
                a[iy] = tmp;
                for(int iz = 0; iz < __len_array; iz++)
                    cout << a[iz] << "\t";
                cout << endl;
            }
            count++;
        }
    }
    return count;
}

int bubbleSort2(int a[])
{
    cout << "---bubbleSort2---" << endl;
    int tmp = 0, count = 0 , flag = 1;
    for(int ix = 0; ix < (__len_array -1) && flag == 1; ix++)
    {
        flag = 0;
        for(int iy = 0; iy < (__len_array - 1 - ix); iy ++)
        {
            if(a[iy + 1] < a[iy])
            {
                tmp = a[iy];
                a[iy] = a[iy + 1];
                a[iy + 1] = tmp;
                flag = 1;

                for(int iz = 0; iz < __len_array; iz++)
                    cout << a[iz] << "\t";
                cout << endl;
            }
            count++;
        }
    }
    return count;
}
