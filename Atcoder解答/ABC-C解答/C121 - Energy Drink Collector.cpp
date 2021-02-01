#include <bits/stdc++.h>
using namespace std;

//　基本方針は安い順に並び替えて総当りだが、この問題ではstd::pairを使うことが重要。
//  以下が自分で途中まで書いた奴

/* int main(){
    int N,M;
    cin >> N >> M ;
    long long int A,B;
    vector<long long int> Ai(N+1);
    vector<long long int> Bi(N+1);

    for(int i = 0;i < N;i++){ // 配列化 O(N)
        cin >> Ai[i] >> Bi[i] ;
    }

    sort(Ai.begin(),Ai.last());

} */

//　ここで問題になるのは、sortでAiを昇順にしても、その商品の個数を知れないという点である。
//  これをpairで解決する。

//  pairは pair<int,int> のように型、型を宣言する。
//  そんで、これをint とかと同じようにぶち込めばおｋ
//  vector<pair<int,string>> ???(N); てな感じ

//  細かい使い方は良く分からんけど、とりあえず配列の中に2つのデータを保管できると考えればいい。
//  Classの定義とかでもいいんだけど、pairの便利なところは定義がいらないのと、sortが各キーに対して使えることらしい
//  基本的にpairのsortはfirstとsecondがそれぞれ昇順になるっぽい。
//  つまり、(1,2),(1,6),(2,5),(2,7),(5,5)とかそんな感じ。

int main(){
    int N;
    long long M;
    cin >> N >> M;
    vector<pair<long long ,long long>> v(N);
    
    for (int i = 0;i < N;i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(),v.end());

    long long res = 0;
    for(int i = 0; i < N && M > 0;i++){
        res += v[i].first * min(M,v[i].second);
        M -= min(M, v[i].second);

    }
    cout << res << endl;
}

// けんちょんさんのコードそのまま。
// この問題から学び取れること滅茶苦茶多かった。
// 値段と個数　とか対になるもので尚且つソートが必要になりそうなものとかはこのパターンが使えそう。

// 20190515 AC