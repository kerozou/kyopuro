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
    int S;cin >> S;
    vector<mint> v(2021,0);
    v[0] = 1;
    rep(i,2000)rep(j,2001){
        if(3 <= j && j + i <= 2000){
            v[j+i] += v[i];
        }
    }
    cout << v[S].val() << endl;
}

// ABC178 D - Redistribution