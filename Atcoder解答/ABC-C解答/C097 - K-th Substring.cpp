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

// この問題の場合は　|s| <= 5000　かつ　K <= 5　なので、sのもつ各文字につき1~5文字のstringを作って、全部探索しても高々25000通りしかない。
// なので、それら全部を配列Lにpush_backしてソートして辞書順に並び替え、強引に頭からチェックしていく。

int main(){
    // 入力
    string s;cin >> s;
    int K; cin >> K;

    // 配列Lの作成
    vector<string> L;
    rep(i,s.size()){
        for(int j = 1;j <= 5;j++){
            if(i+j > s.size())break;
            L.push_back(s.substr(i,j));
        }
    }
    sort(all(L));

    // ct は　L　の頭からいくつ異なる文字列が出現したかを数えている（同じ文字列は個数カウントしないので）
    // ans は　ct　に合わせてずれたindexを補正している。
    int ct = 1;
    int ans = 0;
    rep(i,L.size()){
        if(K == ct){
            cout << L[ans] << endl;
            break;
        }
        else{
            if(L[i] == L[i+1]){     // 文字列が一致するとき、次の文字列に進む。
                ans++;
            }
            else{                   // 文字列が異なるとき、個数をカウントして次の文字列に進む。
                ct++;           
                ans++;
            }
        }
    }
}