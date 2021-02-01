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
    vector<string> S(N);
    rep(i,N)cin >> S[i];
    int L[N][26] = {0};
    rep(i,N){
        string K = S[i];
        rep(j,S[i].size()){
            int tmp = K[j] - 'a';
            L[i][tmp]++;
        }
    }
    char c = 97 + 2;

    vector<int> ct(N,0);    //tmp
    vector<int> ans(26);     //何個のアルファベットが使えるか
    rep(i,26){
        rep(j,N){
            ct[j] = L[j][i];
        }
        sort(all(ct));
        ans[i] = ct[0];
    }
    string UNKO;
    rep(i,26){
        char big = 97 + i;
        int lim = ans[i];
        rep(j,lim){
            UNKO.push_back(big);
        }
    }
    cout << UNKO << endl;
}

// 文字コードを巧みに使え！