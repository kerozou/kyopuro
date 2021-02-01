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

using Data = pair<LL,LL>;
int main(){
    int N,M;cin >> N >> M;
    map<LL,vector<LL>> Work;
    rep(i,N){
        LL A,B;cin >> A >> B;
        Work[A].push_back(B);
    }
    LL sum = 0;
    priority_queue<LL> money;
    for(int i = 1;i<=M;i++){
        rep(j,Work[i].size()){
            money.push(Work[i][j]);
        }
        if(money.empty())continue;
        sum += money.top();
        money.pop();
    }
    cout << sum << endl;
}

// ABC137 	D - Summer Vacation
// ・そのときに選べる一番高い仕事をすればよさそうだけど・・・
//  3 5
//  5 10000
//  3 7800
//  4 5000
//  みたいなときに、 5 10000 と 3 7800 を選んじゃって死亡。

//  なので、このようなケースを考えると、締め切りから順に初日に向かって高い仕事を選んでいけばよさそう。

//  そのためには、二次元配列にv[A].push_back(B)することで締め切りまで何日目にできる仕事を格納できるはず。
//  しかし、二次元配列を作ってpush_backするとなると、その配列に入る仕事の数分の要素を確保しなければならないが、その日に入る仕事が0かもしれない。
//  そのとき、初期化できてない次元2の配列ボックスのサイズを.size()で参照したときにイテレータがぶっ壊れる。(1敗)

//  なので、どうせ配列内の報酬の値段リストは全部プライオリティキューにぶちこむので、indexを気にする必要はない。
//  このことから、何日目かを表す次元1の日付配列は日付が飛んでいてもいいはず。
//  ということは、日付がkeyとしての役割を果たせばいいので、二次元配列もどきを map で実装すれば解決する。

//  実装上の注意は以上で、考察としては
//  逆から考えて、できる仕事が増えていくと考え、さらに前日までに増えた仕事も引き続き選べると考えれば万事うまくいく。
