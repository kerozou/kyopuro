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
    LL X,Y,A,B;cin >> X >> Y >> A >> B;

    // 何回か X *= A を行った結果を格納
    vector<LL> Arui;
    Arui.push_back(X);
    __int128 tmp = X;
    for(LL i = 1;i <= 100;i++){
        tmp *= A;
        if(tmp < Y)Arui.push_back(tmp);
        else break;
    }

    // Y以下の Arui 全ての場合を試す
    LL ans = 0;
    LL ct = -1;
    for(auto t : Arui){
        ct++;
        LL ct_tmp = (Y-1 - t)/B;
        ans = max(ans,ct + ct_tmp);
    }

    cout << ans << endl;
}

// ABC180 D - Takahashi Unevolved