#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//a = 1, K = 8 とすると、a mod K ≡ 1;
//a + b mod K ≡ 0 を実現しようとすると、 b mod K ≡ 7 が必要。
//以下ではこの性質を利用して、aを固定してからb,cの条件を絞り、十分性を確かめている。

//つまり、固定されたaをKで割ったあまりでb,cの候補は分類できる　→　剰余類問題といえる。
//しかも、余り同士の計算は合同式を使って、法が等しい時は　和差積　で閉じているので、a,b,cはKで割ったあまりとして定義していい。
//num[]は[1,N]のKで割ったあまりの一致する個数をカウントしておいて、indexとしてa,b,cを利用できるようにしておく。これによってO(N)でいける。


int main(){
    int N,K;cin >> N >> K;
    vector<LL> num(K,0);
    rep(i,N)num[(i+1)%K]++;   //num[x] は　Kで割ってx余る数が[1,N]にいくつあるか
    LL res = 0;
    rep(a,K){
        int b = (K-a) % K;  //a mod K と K-a mod K　の和は K mod K になり、その値は0のはず。
        int c = (K-a) % K;  //a+b,a+cの合同式が一致するので、a+b mod K ,a+c mod K が一致。なので、b,cともに K-a mod K となる。というか,ともに0になるのでこうならざるを得ない。
        if( (b+c) % K != 0)continue;    //aの固定により、b,cの必要条件 K-a mod K が確定したので、十分条件 b+c mod K の確認をしている。
        res += num[a] * num[b] * num[c];    //a,b,cはもともと同じ数字を取りうるので、個数をそのまんま掛け合わせればいい。
    }
    cout << res << endl;   
}

//aが動いていて、それに対して一組の(b,c)が候補としてあがり、確定するので、すべてのaに対して、b,cが決まる。
//なので、該当する組み合わせはすべて掃き出され、上のようにそれぞれの余りの個数の積の和をとることで確定する。

//2019/08/13AC
//けんちょんさんの丸写し。