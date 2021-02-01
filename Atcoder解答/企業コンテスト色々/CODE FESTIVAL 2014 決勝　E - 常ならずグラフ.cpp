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

vector<int> R;
int calc(int n, int up){
    if(up == 1){
        if(R[n] < R[n+1])return 1;
        else return -1;
    }
    else{
        if(R[n] > R[n+1])return -1;
        else return 1;
    } 
}

int main() {
    int N;cin >> N;
    R.resize(N);rep(i,N)cin >> R[i];

    int up = 1;
    int ans_a = 0;

    rep(i,N-1){
        if(up == calc(i,up))up *= -1;
        else ans_a++;
    }
    

    up = -1;
    int ans_b = 0;

    rep(i,N-1){
        if(up == calc(i,up))up *= -1;
        else ans_b++;
    }
    
    int ans = N - min(ans_a,ans_b);

    if(ans < 3)ans = 0;

    cout << ans << endl;
}


// CODE FESTIVAL 2014 決勝　E - 常ならずグラフ

// なかなかの糞問
// 問題の意味が取りづらい

// 貪欲でといた