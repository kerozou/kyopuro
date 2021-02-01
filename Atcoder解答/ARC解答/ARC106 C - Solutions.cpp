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
    int N,M;cin >> N >> M;

    if(M == 0){
        int ans = 1;
        rep(i,N)cout << ans++ << " " << ans++ << endl;
    }
    else if(M < 0 || M >= N-1)cout << -1 << endl;
    else{
        vector<pair<int,int>> ans;
        int start = 2;
        int end = 3;
        int ct = 0;
        rep(i,N){
            if(ct <= M){
                ans.push_back({start,end});
                start += 2;
                end += 2;
            }
            else if(ct == M+1){
                ans.push_back({1,end+1});
                start += 3;
                end += 3;
            }
            else{
                ans.push_back({start,end});
                start += 2;
                end += 2;
            }
            ct++;
        }
        rep(i,N)cout << ans[i].F << " " << ans[i].S << endl;
    }
}



// ARC106 C - Solutions

/*
    区間スケジューリング　と　その逆の場合の操作を比較する問題。
    M の場合分けをあれこれ考えて、M個の独立した区間を包含する区間を一つ用意してあげるといい。
*/