#include "include.h"

int main()
{
    int start1, end1, start2, end2;
    for(int offset, n, l1, l2; cin >> offset >> n >> l1 >> l2; )
    {
        if(offset >= l1)
        {
            start1 = end1 = l1;
            start2 = offset - l1;
            end2 = start2 + n;
        }
        else
        {
            start1 = offset;
            if(offset + n > l1)
            {
                end1 = l1;
                start2 = 0;
                end2 = n - ( l1 - offset);
            }
            else
            {
                end1 = n + offset;
                start2 = end2 = 0;
            }
        }
        cout << start1 << "," << end1 << "," << start2 << "," << end2 << endl;
    }

    return 0;
}

