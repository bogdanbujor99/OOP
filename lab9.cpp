#include <iostream>
using namespace std;

struct nod {
	int key;
	const char* value;
	int index;
};

template<class T1,class T2>
class Map {
public:
	nod* v=new nod[10];
	T1 k=0;
	Map& operator[](T1 value) {
		bool ok = 0;
		for (T1 i = 0; i <= k-1; i++)
			if (v[i].key == value) {
				ok = 1;
				v[i].value = "null";
			}
	
		if (ok == 0) {
			v[k].key = value;
			v[k].index = k;
		}

		return (*this);
	}
	bool operator=(T2 s) {
		bool ok = 0;
		for (T1 i = 0; i <= k-1; i++) 
			if (v[i].value == "null")
			{
				v[i].value = s;
				ok = 1;
			}
		if (ok == 0) {
		    v[k].value = s;
			k++;
		}
		return false;
	}
	void Set(T1 key, T2 s) {
		v[k].key = key;
		v[k].value = s;
		v[k].index = k;
		k++;
	}
	bool Get(const T1& key, const T2& value) {
		for (T1 i = 0; i <= k - 1; i++) {
			if (v[i].key == key) {
				v[i].value = value;
				return true;
			}
		}
		return false;
	}
	bool Delete(const T1& key) {
		T1 j;
		for (T1 i = 0; i <= k - 1; i++)
			if (v[i].key == key)j = i;
		for (T1 i = j; i <= k - 1; i++)
			v[i] = v[i + 1];
		k--;
		return false;

	}
	bool Includes(const Map<T1, T2>& map) {
		T1 x[10], i=0;
		Map<T1, T2>mapp = map;
		for (auto [key, value, index] : mapp)
		{
			x[i] = key;
			i++;
		}

		for (T1 i = 0; i <= k - 1; i++) {
			if (v[i].key != x[i])return false;
		}
		return true;
	}
	T1 Count() {
		return k;
	}
	void Clear() {
		
		for (T1 i = 0; i <= k - 1; i++)
		{
			v[i].key = NULL;
			v[i].index = NULL;
			v[i].value = NULL;
		}
		k = 0;
	}
	const nod* begin() {
		return &v[0];
	}
	const nod* end() {
		return &v[k];
	}
};

int main() {
	Map<int,const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	cout << endl << "Dupa Set(15,'FII'):" << endl;
	m.Set(15, "FII");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	cout << endl << "Dupa Get(20,'laborator'):" << endl;
	m.Get(20, "laborator");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	cout << endl << "Dupa Delete(20):" << endl;
	m.Delete(20);
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	cout << endl;
	Map<int, const char*>map;
	map[10] = "C++";
	map[30] = "Poo";
	map[15] = "FII";
	if (m.Includes(map) == 1)cout << "map este inclusa in m";
	else cout << "map nu este inclusa in m";
	cout << endl;
	return 0;
}