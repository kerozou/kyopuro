#include<bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
using mint = modint1000000007;
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
    LL N,W;cin >> N >> W;
    vector<LL> S(N);
    vector<LL> T(N);
    vector<LL> P(N);
    rep(i,N)cin >> S[i] >> T[i] >> P[i];

    vector<pair<LL,LL>> ev;
    rep(i,N){
        ev.push_back({S[i],P[i]});
        ev.push_back({T[i],-1*P[i]});
    }   
    sort(all(ev));

    LL now = 0;
    bool ok = true;
    for(auto [x,y] : ev){
        now += y;
        if(W < now)ok = false;
    }

    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

// ABC183 D - Water Heater