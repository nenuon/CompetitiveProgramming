#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int ToInteger(const string& s){
	istringstream istr(s);
	int v;
	istr >> v;
	return v;
}

string ToString(const int& v){
	ostringstream ostr;
	ostr << v;
	return ostr.str();
}


int maketime(string s, bool bef){
    int ret;
    int hh = ToInteger(s.substr(0,2));
    int mm = ToInteger(s.substr(2,2));
    ret = hh * 60 + mm;
    if(bef){
        ret -= ret%5;
    }
    else{
        if(ret%5!=0){
            ret += -ret%5 + 5;
        }
    }
    return ret;
}


string makeStringTime(int t){
    string ret = "";
    int hh = t / 60;
    int mm = t % 60;
    if(hh>=10){
        ret += ToString(hh);
    }
    else{
        ret += "0" + ToString(hh);
    }
    if(mm>=10){
        ret += ToString(mm);
    }
    else{
        ret += "0" + ToString(mm);
    }
    return ret;
}

vector<string> vs;
vector<int> imos(24*60/5+1+1);

int main(){
    int n;
    cin >> n;
    FOR(i,0,n){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    int len = imos.size();
    FOR(i,0,len) imos[i] = 0;
    FOR(i,0,n){
        int start = maketime(vs[i].substr(0,4) ,1);
        int finish = maketime(vs[i].substr(5,4), 0);
        imos[start/5]++;
        if(finish/5<imos.size()) imos[finish/5]--;
    }

    int sum0 = 0;
    int sum1 = 0;
    FOR(i,0,len-1){
        int s, f;
        sum0 += imos[i];
        sum1 = sum0 + imos[i+1];
        if(sum0<=0 && sum1>0) s = (i+1) * 5;
        else if(sum0>0 && sum1<=0){
            f = (i+1) * 5;
            string start = makeStringTime(s);
            string finish = makeStringTime(f);
            cout << start << "-" << finish << endl;
        }
    }
    return 0;
}
