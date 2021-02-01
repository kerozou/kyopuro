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

LL f_and(LL a){
    return a;
}

LL f_or(LL a,int n){
    LL tmp = pow(2,n);
    return a + tmp;
}

int main() {
    int N;cin >> N;
    vector<string> S(N);
    rep(i,N)cin >> S[i];

    LL ct = 1;
    rep(i,N){
        if(S[i] == "AND"){
            ct = f_and(ct);
        }
        else{
            ct = f_or(ct,i+1);
        }
    }

    cout << ct << endl;
}

// ABC189 D - Logical Expression