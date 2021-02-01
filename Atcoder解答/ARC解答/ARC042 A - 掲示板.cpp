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
    int N,M;cin >> N >> M;
    deque<int> q;
    vector<int> a(M);rep(i,M)cin >> a[i];

    for(int i = 1;i <= N;i++){
        q.push_back(i);
    }

    rep(i,M){
        q.push_front(a[i]);
    }

    vector<bool> ok(N+1);
    int ct = 0;

    rep(i,q.size()){
        if(ct == N)break;     
        if(!ok[q[i]]){
            ok[q[i]] = true;
            cout << q[i] << endl;
            ct++;
        }
    }
}

// ARC042 A - 掲示板

/*
    追加して削除してを愚直にやるとO(N*M) ≒ 10^10 になるので、できない。
    なので、dequeの頭に値を追加していく。
    そのあとに、出現したものをチェックしながら一個ずつ吐き出していけばいい。
    これは１～Nまでの要素が少なくとも一つ以上詰まったdeque内をN回吐き出すために高々N+M回調べるのでおｋ
*/