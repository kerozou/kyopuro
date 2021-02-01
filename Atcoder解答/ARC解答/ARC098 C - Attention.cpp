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
    LL N;cin >> N;
    string S;cin >> S;

    vector<LL> L(N+1);
    vector<LL> R(N+1);
    L[0] = 0;
    R[0] = 0;
    rep(i,N){
        if(S[i] == 'W')L[i] = 1;
        else R[i] = 1;
    }
    vector<LL> ruiL(N+1);
    vector<LL> ruiR(N+1);

    rep(i,N){
        ruiL[i+1] = ruiL[i] + L[i];
        ruiR[i+1] = ruiR[i] + R[i]; 
    }

    LL ans = 1e9;

    rep(i,N){
        LL tmp = ruiL[i] + ruiR[N] - ruiR[i];
        if(S[i] == 'E')tmp--;
        ans = min(ans,tmp);
    }

    cout << ans << endl;
}

// ARC098 C - Attention

/*
    i人目がEを向いてるときその一人分引くことをわすれてはいけない。
*/