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

using Data = pair<LL,vector<int>>;
int main(){
    vector<LL> N(3);    // A,B,Cのイテレータ
    int K;
    rep(i,3)cin >> N[i];cin >> K;
    vector<vector<LL>> v(3);        // A,B,Cの入力
    rep(iter,3){
        v[iter].resize(N[iter]);            // resize
        rep(i,N[iter])cin >> v[iter][i];    // 入力
        sort(rall(v[iter]));                // 入力されたデータを降順にソート
    }
    priority_queue<Data> que;               // 和と現在のA,B,Cのindex
    set<Data> se;                           // 順序付き集合
    que.push(Data(v[0][0] + v[1][0] + v[2][0],vector<int>({0,0,0})));   // answer  の初期値というか、最大値、先頭
    rep(k,K){
        auto c = que.top();que.pop();       // おそらく、queueはpairを持つとき、前列のintをpopする。
        cout << c.first << endl;

        // 次の三候補
        rep(iter,3){
            if(c.second[iter] + 1 < N[iter]){   // A,B,Cのうち、一つの順番を遅らせている。  この時、iter＋１が存在するかどうかを判定している。
                LL sum = c.first - v[iter][c.second[iter]] + v[iter][c.second[iter] + 1];   // c.firstはこの時前回の和 から　選んだイテレータの（つまりABCのいずれか）値を引いて、1つ進めたものを足してる。
                auto num = c.second; num[iter]++;      //　indexリストを更新
                auto d = Data(sum,num);                //  計算結果をData型にしている。

                // すでにpushされたもの以外
                if(!se.count(d)) se.insert(d),que.push(d);      //  順序も全く同じものが混入する恐れがあるので、一応チェックしてから追加している。
            }
        }
    }
}

// count(値) は、順序付集合に含まれる指定値の数を返す。set は重複を許さないので、0 または 1 を返す。 
// 処理時間は O(log N) である。

// 順序付集合にデータを追加するときは insert(値) を使用する。 
// 値は、ソートされた位置に挿入される。 
// なので、push_back(値) や push_front(値) は無い。挿入する位置を指定するのは無意味だからだ。

// けんちょんさんのコードそのまま