#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N;cin >> N;
    LL Y;cin >> Y;
    int a = -1;
    int b = -1;
    int c = -1;
    LL ans;
    bool ok = false;

    if(1000*N == Y){
        a = 0;
        b = 0;
        c = N;
    }
    else if(5000*N == Y){
        a = 0;
        b = N;
        c = 0;
    }
    else if(10000*N == Y){
        a = N;
        b = 0;
        c = 0;
    }

    else if(1000*N < Y){
        rep(i,N) {
            rep(j,N-i){
                ans = 10000*i + 5000*j + 1000*(N-i-j);
                if(ans == Y){
                    ok = true;
                    a = i;
                    b = j;
                    c = (N-i-j);
                    break;
                }
            }
            if(ok)break;
        }
    }

    cout << a << " " << b << " " << c << endl;
}

// ABC085 C - Otoshidama
// ・純粋に全探索すると、O(N^3)になるのでOUT。　なので、1000円札の枚数を決め打ちしてO(N^2)に減らす。

// 全体の枚数 N が決まってることを利用して、1000円札の枚数を　c = N-a-b　とおくと、1万円札a枚と5千円札b枚さえ求めればよくなる。
// rep(i,N) rep(j,N-i) で求まる。

// また、例外として、単一でクリアできる場合も分けてる。