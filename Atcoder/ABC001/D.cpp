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
string roundString(string s, bool bef){
    string ret = "";
    if(bef){
        ret += s.substr(0,3);
        if(s[3]>='5') ret += "5";
        else ret += "0";
    }
    else{
        if(s[3]=='0'){
            ret = s;
        }
        else if(s[3]-'0'<=5){
            ret += s.substr(0,3);
            ret += "5";
        }
        else{
            ret += s.substr(0,2);
            ret += to_string((s[2]-'0')+1);
            ret += "0";
            if(ret[2]=='6'){
                string tmp = "";
                tmp += ret[0];
                tmp += to_string((ret[1]-'0')+1);
                tmp += "00";
                ret = tmp;
            }
        }
    }
    return ret;
}

vector<string> vs;
int main(){
    int n;
    cin >> n;
    FOR(i,0,n){
        string s;
        cin >> s;
        vs.push_back(s);
    }
    sort(vs.begin(), vs.end());

    string start = roundString(vs[0].substr(0,4), 1);
    string finish = roundString(vs[0].substr(5,4), 0);

    if(n==1){
        cout << start << "-" << finish << endl;
        return 0;
    }
    FOR(i,1,n){
        string nextstart = roundString(vs[i].substr(0,4), 1) ;
        string nextfinish = roundString(vs[i].substr(5,4), 0);
        if(finish < nextstart){
            cout << start << "-" << finish << endl;
            start = nextstart;
            finish = nextfinish;
        }
        else{
            finish = finish > nextfinish ? finish : nextfinish;
        }
    }
    cout << start << "-" << finish << endl;
    return 0;
}
