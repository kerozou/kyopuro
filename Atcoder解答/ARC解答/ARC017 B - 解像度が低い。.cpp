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
    int N,K;cin >> N >> K;
    vector<int> A(N);rep(i,N)cin >> A[i];

    vector<vector<int>> st(N);

    int ind = 0;
    rep(i,N-1){
        st[ind].push_back(A[i]);
        if(A[i] >= A[i+1])ind++;
    }   
    st[ind].push_back(A[N-1]);

    int ans = 0;
    for(auto t : st){
        int sz = t.size();
        if(sz >= K){
            ans += (sz - K + 1);
        }
    }

    cout << ans  << endl;
}

// ARC017 B - 解像度が低い。

/*
    連続している部分を抜き出して保存。
    あとは、そのサイズを図ってK以上ならsz-K+1をansに追加する
*/