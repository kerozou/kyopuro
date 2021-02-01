#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N,C;cin >> N >> C;
    vector<int> a(N);rep(i,N)cin >> a[i];
    map<int,int> gu;
    map<int,int> ki;

    rep(i,N){
        if(i % 2 == 0){
            gu[a[i]]++;
        }
        else ki[a[i]]++;
    }

    vector<pair<int,int>> g;
    vector<pair<int,int>> k;
    for(auto t : gu)g.push_back({t.S,t.F});
    for(auto t : ki)k.push_back({t.S,t.F});
    sort(rall(g));
    sort(rall(k));

    int ans = 1e9;

    if(N >= 4){
        int g1 = g[0].S;
        int g2 = g[1].S;
        int k1 = k[0].S;
        int k2 = k[1].S;

        if(g1 != k1)ans = (N-g[0].F-k[0].F)*C;
        else{
            ans = min(ans,(N-g[0].F-k[1].F)*C);
            ans = min(ans,(N-g[1].F-k[0].F)*C);
        }
    }
    else{
        if(N == 2){
            if(a[0] == a[1])ans = C;
            else ans = 0;
        }
        if(N == 3){
            ans = 0;
            if(a[0] != a[2]){
                ans = C;
            }
            else if(a[0] == a[1] && a[1] == a[2])ans = C;
        }
    }

    cout << ans << endl;


    
    
    

}


// 	ARC020 B - 縞模様

/*
    奇偶で列に出現する色の数をカウント。
    1番と2番に多い数をそれぞれもち、
    1.奇偶が違う色　（N-奇-偶)*C
    2.同じ色　→　(1,2)(2,1)の2つをminで更新

    N==2　N==3　は別で処理する
*/