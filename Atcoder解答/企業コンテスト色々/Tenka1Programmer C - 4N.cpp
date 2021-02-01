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
    bool ok = false;
    for(LL h = 1;h <= 3500;h++){
        for(LL n = 1;n <= 3500;n++){
            LL si = N*h*n;
            LL bo = 4*h*n-N*(h+n);
            if(bo <= 0)continue;
            if(si % bo == 0){
                cout << h  << " " << n << " " << si/bo << endl;
                ok = true;
                break;
            }
        }
        if(ok)break;
    }
}

// Tenka1Programmer 	C - 4/N

/*
    2数を固定して1つの変数を作る。
    そして、2重ループを回して、wが整数なるかをチェック
*/