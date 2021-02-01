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

int main(){
    int N;cin >> N;
    string S;cin >> S;
    int ct = 0;
    rep(i,1000){
        int a = i / 100;
        int b = (i / 10)%10;
        int c = i % 10;
        bool o = false;
        bool k = false;
        rep(j,N){
            int t = S[j] - '0';
            if(k)if(t == c){
                ct++;
                break;
            }
            if(o)if(t == b)k = true;
            if(t == a)o = true;
        }
    }
    cout << ct << endl;
}

