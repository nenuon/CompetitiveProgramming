class BichromePainting {
    public:
    string isThatPossible(vector<string> board, int k) {
        int n=board[0].length();
        int cnt1=0,cnt2=0;
        bool used[n][n];
        CLR(used);
        FOR(i,0,n)FOR(j,0,n)cnt1+=(board[i][j]=='B');
        while(1){
            bool change=false;
            FOR(y,0,n){
                FOR(x,0,n){
                    if(y+k-1>=n||x+k-1>=n)break;
                    int cntB=0,cntW=0;
                    FOR(Y,y,y+k){
                        FOR(X,x,x+k){
                            if(used[Y][X])continue;
                            cntB+=(board[Y][X]=='B');
                            cntW+=(board[Y][X]=='W');
                        }
                    }
                    if(cntB==0&&cntW==0)continue;
                    if(cntB==0||cntW==0){
                        change=true;
                        FOR(Y,y,y+k){
                            FOR(X,x,x+k){
                                used[Y][X]=true;
                            }
                        }
                        cnt2+=cntB;
                    }
                }
            }
            if(!change)break;
        }
        return cnt1 == cnt2 ? "Possible" : "Impossible";
    }
};
