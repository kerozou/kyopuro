#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

typedef struct hat{
    int x;
    int y;
    int z;
}hat;

int main(){
    int N;cin >> N;
    vector<int> A(N);
    vector<hat> h(N+1);
    rep(i,N)cin >> A[i];
    rep(i,N+1){
        if(i == 0){
            h[0] = (hat){0,0,0};
            continue;
        }
        int a = h[i-1].x;
        int b = h[i-1].y;
        int c = h[i-1].z;
        if(a == A[i-1])h[i] = (hat){a+1,b,c};
        else if(b == A[i-1])h[i] = (hat){a,b+1,c};
        else h[i] = (hat){a,b,c+1};
    }
    
    LL ans = 1;
    rep(i,N){
        hat t = h[i];
        int ct  = 0;
        if(t.x == A[i])ct++;
        if(t.y == A[i])ct++;
        if(t.z == A[i])ct++;
        ans *= ct;
        ans %= MOD; 
    }

    cout << ans << endl;
}

