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
    string S;cin >> S;

    vector<int> ruiB(N+1);
    vector<int> ruiW(N+1);

    vector<int> col(N);

    rep(i,N){
        int t = 1;
        if(S[i] == '#')t *= -1;
        col[i] = t;
    }

    rep(i,N){
        if(col[i] == 1){
            ruiW[i+1] = ruiW[i] + 1;
            ruiB[i+1] = ruiB[i];
        }
        else{
            ruiW[i+1] = ruiW[i];
            ruiB[i+1] = ruiB[i] + 1;
        }
    }

    int ans = 1e6;
    rep(i,N){
        int lb = ruiB[i+1];
        int lw = ruiW[i+1];
        int rb = ruiB[N] - lb;
        int rw = ruiW[N] - lw;

        int tmp = min(lb+rb,lw+rw);
        tmp = min(tmp,lb+rw);
        ans = min(ans,tmp);
    }

    cout << ans << endl;
}

// Tenka1 Programmer Beginner Contest 2019  C - Stones

/*
    あり得る場合はある一点を境に
    ・白黒
    ・白白
    ・黒黒
    となり場合のみである。

    なので、あらかじめある点までの黒白の石の累積和を取っておく。
    ある点を選んだ時の上記3パターンを作るときに操作する必要のある石の数とansのminを取り続ければいい。
*/