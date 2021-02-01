#include <bits/stdc++.h>
using namespace std;
// 方針
// 連結文字列のうち、内部に”AB"を含むものはその数を直接sumに足せばいい。
// その他で問題になるのが、

// 1,左にB,右にAをもつ
// 2,左にB
// 3,右にA
// 4,どちらもない

// の４つだが、4は無視していい。

// c1,c2,c3 をそれぞれ、1,2,3の数とすると

// 1, if(c1 == 0 ) のとき
//      2,3の数で決まり、min(2,3)　によってABの数はきまる。

// 2, if(c1 != 0 ) && ( c2,c3 が両方とも0ではない ) のとき
//      1と同様に min(2,3) を考えた後、”AB"のAとB間に1を挟んでいくと、そのぶんだけABの数は増える。

// 3, if(c1 != 0 ) && c2 == 0 && c3 == 0 のとき
//      初めに一つ両端のどちらかにA、Bが必要なので、その分をひいて　1の数 - 1 個のABがうまれる。

// 以上を作る。
// その際、ABを含む、1234の判別を可能にする関数か何かを作る必要がありそう。



// 反省点
// 1234に分類するところまでは思いついたが、内部にABを含むものをどう処理していいか思いつかず、飛ばしてしまった。
// 冷静に考えて、ABはそのまま足せばいいはずなのに、C問題だから難しいと思って飛ばしちゃった。


//（参照渡しではnullは渡せないので、
//  値がnullになる可能性があるものは変更の可能性がなくてもpointerで渡しましょう。）

int check_AB(string &S,int *pc){
    int res = 0;
    if(S[0] == 'B' && S[S.size() - 1] == 'A'){
        pc[0] += 1;
    }
    else if (S[0] == 'B'){
        pc[1] += 1;
    }
    else if (S[S.size() - 1] == 'A'){
        pc[2] += 1;
    }

    for (int i = 0;i < S.size() - 1 ;i++){
        if(S[i] == 'A' && S[i + 1] == 'B'){
            res += 1;
        }
    }
    return res;
}



int main(){
    int N;
    cin >> N;
    string S;
    
    int count = 0;
    int c[3] = {0,0,0};

    for (int j = 0;j<N;j++){
        cin >> S ;
        count += check_AB(S,c);
      //  cout << c[0] << ' ' << c[1] << ' ' << c[2] << endl; 　c[i]の内部の確認用ループ
    }

    if(c[0] == 0){ // case 1
        count += min(c[1],c[2]);
    }
    else if(c[1] == 0 && c[2] == 0){ // case 3
        count += c[0] - 1 ;
    }
    else { // case 2
        count += min(c[1],c[2]) + c[0] ;
    }

    cout << count << endl;

}
// 2019 0512 AC 