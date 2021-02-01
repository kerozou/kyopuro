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
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    map<int,int> L;
    rep(i,N){
        L[a[i]] = 0;
        L[a[i]-1] = 0;
        L[a[i]+1] = 0;
    }
    rep(i,N){
        L[a[i]]++;
        L[a[i]-1]++;
        L[a[i]+1]++;
    }
    vector<int> X;
    for(auto itr = L.begin();itr != L.end();itr++){
        if(itr -> F == -1)continue;
        X.push_back(itr -> S);
    }
    sort(rall(X));
    cout << X[0] << endl;
}

//ABC072 - C - Together
//・A[i]の±1と0をそれぞれmapで作っておく。

// 各数列の要素は同時に±1と0を更新することはないので、独立に考えることができる。
// なので、それぞれ1ずつ動かしたものを全部mapにカウントさせておく。
// そんでもって、それをitrで掃き、keyが-1の時を除いてvector化する。
// それをソートして一番大きいものを捕まえてくればいい。
