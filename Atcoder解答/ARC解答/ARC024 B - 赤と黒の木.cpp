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
    vector<int> v(N);
    rep(i,N){
        int a ;cin >> a;
        if(a == 0)a = -1;
        v[i] = a;
    }

    vector<int> c;
    int p = 1;
    int col = v[0];

    rep(i,N){
        if(i == 0)continue;
        if(col == v[i])p++;
        else{
            c.push_back(p);
            p = 1;
            col *= -1;
        }
        if(i == N-1){
            c.push_back(p);
        }
    }


    if(col == v[0] && c.size() != 1){
        c[c.size()-1] += c[0];
        c[0] = 0;
    }

    int ans = 1;
    int ma = 0;
    for(auto t : c){
        if(t >= 3){
            ma = max(ma,t);
        }
    }

    ans += (ma-1)/2;
    if(c.size() == 1)ans = -1;
    cout << ans << endl;
}

// ARC024 B - 赤と黒の木

/*
    3個以上の連続をカウントして、連続する個数の最大値を取得。
    なお、ケツと頭がつながるときはそれ相応の処理がいる。
    あとは、(max-1)/2 + 1 が答えになる。

    これは、実際に連続したノードを書いてみて、内側をオセロみたいに反転させていくと理解できる。
*/