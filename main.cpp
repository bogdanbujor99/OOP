#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

/* Prb1
vector<string> Sort(vector<string>v,bool (*Compare)(string n1,string n2)) {
    for (int i = 0; i <= v.size()-2; i++) {
        for (int j = i + 1; j <= v.size() - 1; j++)
            if (Compare(v[i], v[j]))
                swap(v[i], v[j]);
    }
    return v;
}


int main()
{
    vector<string>v = {"lambda","expressions","homework"};
    auto f = [](string n1, string n2) {
        if (n1.length() > n2.length())return true;
        else if (n1.length() < n2.length())return false;
        else {
            if (n1 > n2)return true;
            else return false;
        }
    };
    v=Sort(v, f);
    for (int i = 0; i <= v.size() - 1; i++)
        cout << v[i] << " ";
    return 0;
}
*/

/* Prb2
class Data {
public:
    string* v = new string[10];
    int index = 0;
    Data(initializer_list<string>a) {
        initializer_list<string>::iterator it;
        for (it = a.begin(); it != a.end(); it++) {
            v[index] = *it;
            index++;
        }
    }
    string First() {
        return v[0];
    }
    const string* begin() {
        return &v[0];
    }
    const string* end() {
        return &v[index];
    }
};

int main() {
    Data d ={ "POO","C++","homework" };
    auto f = [](Data d) {
        string max = d.First();
        for (auto element : d) {
            if (max.length() < element.length())
                max = element;
        }
        return max;
    };
    string big = f(d);
    cout << big;
}
*/

/* Prb3
class MyVector {
private:
    vector<int>v;
public:
    bool Add(int x) {
        int size = v.size();
        v.push_back(x);
        if (v.size() > size)return 1;
        else return 0;
    }
    bool Delete(int x) {
        int size = v.size();
        v.pop_back();
        if (v.size() < size)return 1;
        else return 0;
    }
    void Iterate(int (*Modulo5)(int x) ){
        for (int i = 0; i <= v.size() - 1; i++) {
            v[i] = Modulo5(v[i]);
        }
    }
    void Filter(bool (*Div3)(int x)) {
        vector<int>::iterator it;
        for (int i=0;i<=v.size()-1;i++){
            if (Div3(v[i])) {
                for (int j = i; j <= v.size() - 2; j++)
                    v[j] = v[j + 1];
                v.pop_back();
            }
        }
    }
    void Print() {
        for (int i = 0; i <= v.size() - 1; i++)cout << v[i] << " ";
    }
};

int main() {
    MyVector vector;
    vector.Add(2);
    vector.Add(8);
    vector.Add(34);
    auto f1 = [](int x) {
        return x % 5;
    };
    auto f2 = [](int x) {
        if (x % 3 == 0)return true;
        return false;
    };
    vector.Iterate(f1);
    vector.Filter(f2);
    vector.Print();
}
*/