#include <iostream>
#include <map>
using namespace std;
int main(){
  int A, cnt=0;
  for(int i=0;i<3;i++){
    cin>>A;
    if(A==5) cnt++;
    else if(A==7) cnt--;
  }
  cout << (cnt==1?"YES":"NO") << endl;
}
