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
    vector<LL> a(N);rep(i,N)cin >> a[i];

    map<int,int> m;
    rep(i,N){
        int tmp = a[i];
        while(tmp % 2 == 0){
            tmp /= 2;
        }
        m[tmp]++;
    }

    cout << m.size() << endl;
}

// ABC019 C019 - 高橋くんと魔法の箱

/*
    2^30 > 10^9 なので、とりあえず出てきたa[i]を2で割り続ける。
    そのとき残った奇数がユニークな数なので、これの数をカウントする。
    mapで保管して、サイズを出力すればいい。
*/