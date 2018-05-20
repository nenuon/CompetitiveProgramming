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
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
//bc|abbbc|baca|aacb->最短は絶対4つ、最初の区間にない英単語を選ぶ、次の区間では一個前の区間で選んだ英単語の後ろにない最小の英単語を選ぶ
//aaba
int b[200005]; // ある区間でi以降(i含め)で出てきた文字の集合
int c[200005]; // ある区間でi以降の最小の文字
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  for(int i=s.length()-1;i>=0;i--){
    b[i]=b[i+1]|(1<<(s[i]-'a'));
    c[i]=c[i+1];
    while(b[i]&(1<<c[i]))c[i]++;
    if(c[i]==26){
      b[i]=c[i]=0;
    }
  }
  for(int i=0;i<s.length();++i){
    char x=c[i]+'a';
    cout<<x;
    while(i<s.length()&&x!=s[i])i++;
  }
  cout<<endl;
  return 0;
}