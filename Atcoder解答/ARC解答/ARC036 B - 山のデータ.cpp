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
    vector<int> h(N);rep(i,N)cin >> h[i];
    int ans = 0;
    int ct = 0;
    bool up = true;
    int tmp = -1;
    rep(i,N){
        if(up){
            if(tmp > h[i])up = false;
            ct++;
            tmp = h[i];
        }
        else{
            if(tmp > h[i]){
                ct++;
                tmp = h[i];
            }
            else{
                ans = max(ans,ct);
                ct = 2;
                tmp = h[i];
                up = true;
            }
        }
    }
    ans = max(ans,ct);
    cout << ans << endl;
}

// ARC036 B - 山のデータ

/*
    山を登って処理するだけ
    現在の連続数をカウントして、次へ進む
    持っている情報は
    ・山の進度int
    ・昇り・下りのbool
    ・直前の高さ
    なので、これらを上手く使って進むだけ
*/