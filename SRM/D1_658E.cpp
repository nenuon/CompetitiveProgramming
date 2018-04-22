class OddEvenTree {
    public:
    vector<int> getTree(vector<string> x) {
        int n=x.size();
        int gr[n];
        CLR(gr);
        gr[0]=1;
        int ch=1;
        int top1=0,top2=n;
        FOR(i,1,n){
            if(x[0][0]==x[0][i]){
                gr[i]=1;
                ch |= 1;
            }else{
                gr[i]=2;
                ch |= 2;
                top2=min(top2,i);
            }
        }
        vector<int> ng(1,-1);
        // 木を構築できない
        if(ch!=3){
            return ng;
        }
        // 矛盾しないか確認
        FOR(y,1,n){
            FOR(i,0,n){
                if(i==y)continue;
                if(x[y][y]==x[y][i]){
                    if(gr[y]!=gr[i]){
                        return ng;
                    }
                }else{
                    if(gr[y]==gr[i]){
                        return ng;
                    }
                }
            }
        }
        vector<int> ans;
        FOR(i,1,n){
            if(gr[i]==1){
                ans.push_back(top2);
            }
            if(gr[i]==2){
                ans.push_back(top1);
            }
            ans.push_back(i);
        }
        return ans;
    }
};
