#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;

int main(){
    int N;cin >> N;
    LL x,y; 
    vector<vector<pair<LL,LL>>> DP(N,vector<pair<LL,LL>>(N));
    vector<LL> X(N);
    vector<LL> Y(N);
    rep(k,N){
        cin >> X[k] >> Y[k] ;
    }

    rep(i,N){ // DP を作る(X[i]-X[j],Y[i]-Y[j])
        rep(j,N){

            if(i == j){
                DP[i][j] = make_pair(0,0);
                continue;
            }
            DP[i][j] = make_pair(X[i]-X[j],Y[i]-Y[j]);

        }
    }

    map<pair<LL,LL>,int> m;
    int max = 0;
    pair<LL,LL> zer = make_pair(0,0);
    rep(l,N){
        rep(p,N){
            if(DP[l][p] != zer){
                m[DP[l][p]]++;
                if(max < m[DP[l][p]]){
                    max = m[DP[l][p]];
                }
            }
            else{
                continue;
            }
        }
    }
    cout << N - max << endl;

}