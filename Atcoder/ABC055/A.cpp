#include <iostream>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int ans = 0;
    int n;cin>>n;
    ans=n*800-(n/15)*200;
    cout << ans << endl;
}
