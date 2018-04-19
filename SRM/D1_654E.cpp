class SquareScores {
    public:
    double calcexpectation(vector<int> p, string s) {
        int n=s.length();
        vector<double> dp(n+1,0.0);
        vector<vector<double> > pp(26,vector<double>(n+1,0.0));// j回通過する確率
        FOR(i,0,p.size()){
            FOR(j,0,n+1){
                if(j==0)pp[i][j]=1;
                else pp[i][j]=pp[i][j-1]*p[i]/100.0;
            }
        }
        FOR(i,0,n){
            if(s[i]=='?'){
                FOR(k,0,p.size()){
                    char c=k+'a';
                    int cnt=1,hatena=0;
                    bool plus=true;
                    for(int j=i-1;j>=0;j--){
                        if(s[j]==c){
                            cnt++;
                        }
                        else if(s[j]=='?'){
                            // ?の直前で終わる
                            dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena]*p[k]/100.0*(1.0-p[c-'a']/100.0);
                            hatena++;
                            cnt++;
                        }
                        else{
                            dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena]*p[k]/100.0;
                            plus=false;
                            break;
                        }
                    }
                    if(plus){
                        dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena]*p[k]/100.0;
                    }
                }
            }else{
                char c=s[i];
                int cnt=0,hatena=0;
                bool plus=true;
                for(int j=i;j>=0;j--){
                    if(s[j]==c){
                        cnt++;
                    }
                    else if(s[j]=='?'){
                        // ?の直前で終わる
                        dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena]*(1.0-p[c-'a']/100.0);
                        hatena++;
                        cnt++;
                    }
                    else{
                        dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena];
                        plus=false;
                        break;
                    }
                }
                if(plus){
                    dp[i+1]+=(dp[i]+cnt)*pp[c-'a'][hatena];
                }
            }
        }
        return dp[n];
    }
};
