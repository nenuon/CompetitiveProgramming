#include<iostream>
#include<math.h>
using namespace std;

int main(void){
    int x, y, xx, yy;
    cin >> x >> y;
    xx = abs(x);
    yy = abs(y);

    if(x==0 && y>0) cout << y-x << endl;
    else if(x==0 && y<0) cout << x-y+1 << endl;
    else if(x>0 && y==0) cout << x-y+1 << endl;
    else if(x<0 && y==0) cout << y-x << endl;
    else if(x>0 && y>0){
        if(x<y) cout << y-x << endl;
        else cout << x-y+2 << endl; 
    }
    else if(x<0 && y<0){
        if(x>y) cout << x-y+2 << endl;
        else cout << y-x << endl;
    }
    else{
        cout << abs(xx-yy)+1 << endl;
    }

    return 0;
}