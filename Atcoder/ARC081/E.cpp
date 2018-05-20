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
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
string en = "abcdefghijklmnopqrstuvwxyz";
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string A; cin >> A;
  FOR(i,1,5) {
    set<string> SET;
    for(int j = 0; j + i <= A.length(); j++) {
      SET.insert(A.substr(j, i));
    }
    if(i == 1) {
      FOR(j,0,26) {
        string s = "";
        s += en[j];
        if(SET.count(s) == 0) {
          cout << s << endl;
          return 0;
        }
      }
    }
    if(i == 2) {
      FOR(j,0,26) {
        FOR(k,0,26) {
          string s = "";
          s += en[j];
          s += en[k];
          if(SET.count(s) == 0) {
            cout << s << endl;
            return 0;
          }
        }
      }
    }
    if(i == 3) {
      FOR(j,0,26) {
        FOR(k,0,26) {
          FOR(l,0,26) {
            string s = "";
            s += en[j];
            s += en[k];
            s += en[l];
            if(SET.count(s) == 0) {
              cout << s << endl;
              return 0;
            }
          }
        }
      }
    }
    if(i == 4) {
      FOR(j,0,26) {
        FOR(k,0,26) {
          FOR(l,0,26) {
            FOR(m,0,26) {
              string s = "";
              s += en[j];
              s += en[k];
              s += en[l];
              s += en[m];
              if(SET.count(s) == 0) {
                cout << s << endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
}