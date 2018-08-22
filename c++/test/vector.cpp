#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef struct ini{
	string strKey;
	string strVal;
        
        ini(const ini &a)
        {
            cout << this << "\tthis is first ini constructor" << endl;
            strKey = a.strKey;
            strVal = a.strVal;
        }
        ini(const char* key, const char* val)
        {
            cout << this << "\tthis is second ini constructor" << endl;
            strKey = key;
            strVal = val;
        }
        ~ini()
        {
            cout << "this is ini destructer" << endl;
        }

}INI;

vector<INI*> mVec;

bool vecFoo(const INI* m_ini)
{
	mVec.push_back((INI*)m_ini);
	vector<INI*>::iterator it = mVec.begin();
	while(it != mVec.end())
	{
		cout << *it << "\t" << (*it)->strKey << "\t" << (*it)->strVal << endl;
		it++;
	}
	return true;
}

int main()
{
	char a[10]="hello";
	char b[10]="world";
        char c='e';
        int d=12;
        for(int ix = 0; ix < 3; ix++)
        {
            INI* ini = new INI(a, b);
            vecFoo((const INI*)ini);
        }
        mVec.clear();
	return 0;
}
