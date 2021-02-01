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
    int N;cin >> N;
    vector<int> T(N);rep(i,N)cin >> T[i];
    map<int,int> m;
    rep(i,N)m[T[i]]++;

    sort(all(T));
    LL ans = 0;
    LL num = 1;

    int tmp = N;
    rep(i,N){
        ans += (T[i]*tmp);
        tmp--;
    }

    for(auto t : m){
        int c = t.S;
        while(c > 1){
            num *= c;
            num %= MOD;
            c--;
        }
    }

    cout << ans << endl;
    cout << num << endl;
}

// ARC035 B - アットコーダー王国のコンテスト事情

/*
    T[i]が短い順に解くのが最適。
    解いている間も他の問題達のペナルティは溜まっていく。

    解法の数は同じ秒数の問題を解く順番できまるので、mapでカウントしてそれぞれの回数の階乗を数えればいい。
*/