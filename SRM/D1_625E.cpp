#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

class PalindromePermutations {
    public:
    double palindromeProbability(string word) {
        double bunsi = 0.0, bunbo = 0.0;
        int n = word.length();
        int cnt[26]; CLR(cnt);
        FOR(i,0,n) {
            cnt[word[i]-'a']++;
        }
        int odd = 0;
        FOR(i,0,26) odd += cnt[i]%2 == 1;
        if(n%2==0&&odd) return 0.0;
        if(n%2==1&&odd!=1) return 0.0;
        double factorial[n+1];
        factorial[0] = 1;
        FOR(i,0,n) factorial[i+1] = factorial[i] * (i+1);
        bunbo = factorial[n];
        FOR(i,0,26) bunbo /= factorial[cnt[i]];
        bunsi = factorial[n/2];
        FOR(i,0,26) bunsi /= factorial[cnt[i]/2];
        return bunsi/bunbo;
    }
};
