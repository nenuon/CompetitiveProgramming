#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> AA[100000];

int tree(int a){
    int ans,i;
    vector<int> tmp;
    for(i=0;i<AA[a].size();i++){
        tmp.push_back(tree(AA[a][i]-1));
    }
    sort(tmp.begin(),tmp.end());
    ans=0;
    for(i=0;i<tmp.size();i++){
        ans=max(ans,tmp[i])+1;
    }
    return ans;
}

int main(void){
    int i,j,N,a,ans;
    cin >> N;
    for(i=2;i<=N;i++){
        cin >> a;
        AA[a-1].push_back(i);
    }
    cout << tree(0) << endl;;
    return 0;
}