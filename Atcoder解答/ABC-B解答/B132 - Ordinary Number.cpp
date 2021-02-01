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

bool Ci(int i,vector<int> &p){
    int p1 = p[i-1];
    int p2 = p[i];
    int p3 = p[i+1];
    bool ans = false;
    if(p1 < p2) if(p2 < p3) ans = true;
    if(p3 < p2) if(p2 < p1) ans = true;
    return ans;
}
int main(){
    int n;cin >> n;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    int ct = 0;
    bool ok = false;
    for(int k = 1;k < n-1;k++){
        ok = Ci(k,p);
        if(ok) ct++;
    }
    cout << ct << endl;
}
