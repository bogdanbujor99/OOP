#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator()(pair<string,int>p1, pair<string,int> p2) const {
        if (p1.second < p2.second)return 1;
        else if (p1.second == p2.second) {
            if (p1.first> p2.first)return 1;
        }
        return 0;
    }
};
 
int main()
{
    map<string, int>CUVINTE;
    string s;
    getline(cin, s);
    string cuvant;
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == ' ') {
            if(cuvant!="")
            CUVINTE[cuvant]++;
            string a;
            cuvant = a;
        }
        else  if (*it == ','){
            if (cuvant != "")
            CUVINTE[cuvant]++;
            string a;
            cuvant = a;
        }
        else if (*it == '.') {
            if (cuvant != "")
            CUVINTE[cuvant]++;
            string a;
            cuvant = a;
        }
        else  if (*it == '!') {
            if (cuvant != "")
            CUVINTE[cuvant]++;
            string a;
            cuvant = a;
        }
        else if (*it == '?') {
            if (cuvant != "")
            CUVINTE[cuvant]++;
            string a;
            cuvant = a;
        }
        else {
            if (*it >= 'A' && *it <= 'Z')*it = *it + 32;
            cuvant.push_back(*it);
        }
    }
    pair <string, int>c;
    priority_queue < pair<string,int>, vector<pair<string, int>> , Compare> Priority;

    for (map<string, int>::iterator it = CUVINTE.begin(); it != CUVINTE.end(); it++) {
        pair<string, int>c;
        c.first = it->first;
        c.second = it->second;
        Priority.push(c);
    }
}