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
    vector<int> retu;
    if(N == 1){
        retu.push_back(1);
    }
    else{
        rep(i,N){
            if(i == N-1){
                retu.push_back(1);
                break;
            }
            if(S[i] != S[i+1])retu.push_back(1);
            else{
                retu.push_back(2);
                i++;
            }
        }
    }

    LL ans = 1;
    rep(i,retu.size()){
        if(i == 0){
            if(retu[i] == 1)ans *= 3;
            else ans *= 6;
        }
        else{
            if(retu[i-1] == 1 && retu[i] == 1)ans *= 2;
            else if(retu[i-1] == 1 && retu[i] == 2)ans *= 2;
            else if(retu[i-1] == 2 && retu[i] == 2)ans *= 3;
            else if(retu[i-1] == 2 && retu[i] == 1)ans *= 1;
            ans %= MOD;
        }
    }

    ans %= MOD;
    cout << ans << endl;
}

// ABC071 	D - Coloring Dominoes

// 解説pdfそのまんまの内容　自力AC

// ただ、retuを形成するときに、最後尾に１が来るときにi = i+1の判定が入らなくなっちゃうので、
// i = N-1 で 1 を追加すること。

