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
    LL N;cin >> N;
    vector<LL> A(N);
    vector<LL> B(N);
    rep(i,N)cin >> A[i] >> B[i];

    vector<LL> point(N);
    rep(i,N)point[i] = 2*A[i] + B[i];

    sort(rall(point));

    LL sum = 0;
    LL lim = 0;
    LL ct = 0;
    rep(i,N)lim += A[i];

    rep(i,N){
        if(sum > lim)break;
        ct++;
        sum += point[i];
    }

    cout << ct << endl;
}

// ABC187 D - Choose Me