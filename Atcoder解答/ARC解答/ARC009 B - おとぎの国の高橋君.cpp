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
    vector<int> b(10);rep(i,10)cin >> b[i];
    int N;cin >> N;
    vector<string> a(N);rep(i,N)cin >> a[i];

    vector<string> x(N);
    vector<pair<int,int>> ch(N);
    rep(i,N){
        x[i] = a[i];
        ch[i].S = i;
    }

    vector<int> hen(10);
    rep(i,10)hen[b[i]] = i;

    rep(i,N){
        int lim = x[i].size();
        rep(j,lim){
            int tmp = x[i][j] - '0';
            x[i][j] = '0' + hen[tmp];
        }
    }
    rep(i,N){
        ch[i].F = std::stoi(x[i]);
    }

    sort(all(ch));

    for(auto t : ch){
        cout << a[t.S] << endl;
    }

}

// ARC009 B - おとぎの国の高橋君

/*
    0 が必ずb0にくるので、すべての配列要素biを普通の順番0~9に一文字ずつ対応させる。
    この際stringが扱いやすい。
    辞書順ソートすると文字数関係なくソートされちゃうので、一旦intに戻す。
    そしてソートしたあとにソート前の数字を呼び出す必要があるので、あらかじめindexをpairで保存しておく。
    あとは、ソート後にindexを読み込んでもとの入力配列aを出力するだけ
/*