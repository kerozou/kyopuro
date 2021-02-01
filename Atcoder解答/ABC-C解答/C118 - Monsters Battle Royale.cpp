#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++)

// 全体の最大公約数に一致するというまさかの展開
// 細かい証明は調べればよろし
// gcd(a,b) = gcd(b,b-a) から　ユークリッドの互助法的に二匹の時は解ける。
// あとは帰納法なりなんなりで証明すればよさそう。
// とりあえず、数字のランダム引き算で最小になるときは「最大公約数」と覚えておくことがポイント

int GCD(int a,int b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

int main(){
    int N; cin >> N;
    vector<int> mons(N+1);

    int i,j;


    rep(i,N){       
        cin >> mons[i];
    }



    int temp = mons[0];

    rep(j,N){
        temp = GCD(temp,mons[j]);
    }

    cout << temp << endl;
}
// 20190528AC

// なんかvector使って cin >> mons[i]; ってやろうとしたら　バグッた
// なにやらイテレータ破壊だかっていう現象っぽい。
// vectorはコンテナだから、コンテナに動的に追加するとイテレータがなんちゃらでやばいらしい

// 追記
// vectorは定義の際に[]ではなく()を使うことに注意。
// ()にしたら普通に通った。
// 逆にvector<int> mons;としてサイズを定義しないでcinループして追加していったらエラー139がでた。
// おそらくスタックオーバーフローってやつがおきてる。

