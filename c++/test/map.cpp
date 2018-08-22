#include <iostream>
#include <stdio.h>
#include <map>


using namespace std;

void addMap(map<int,string> *m_map)
{
    char buff[16] = {'\0'};
    map<int,string>::iterator it;
	for(int ix = 0; ix < 10000000; ix++)
    {
        it = m_map->find(ix);
        if(it == m_map->end())
        {
            snprintf(buff, 13, "this is %d", ix);
            m_map->insert(pair<int,string>(ix, buff));
		//	cout << m_map->size() << "\t"
		//		 << sizeof(m_map) << endl;
        }
    }
}
    
int main()
{
    map<int,string> m_map;
    map<int,string>::iterator it;

    addMap(&m_map);
    it = m_map.begin();
    for(;it != m_map.end();it++)
    {
        //cout << it->first << "\t" << &it->first << "\t" << it->second << "\t" << &it->second << endl;
    }
	cout << m_map.size() << "\t"
		 << sizeof(m_map) << endl;
	return 0;
}

