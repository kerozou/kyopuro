#include <bits/stdc++.h>
using namespace std;

// 前回のあらすじ
// n番目を抜き去ったgcdを求めるgcd()関数を作り、その後にmaxのループにぶち込もうと考えた俺氏。
// しかし、一見完璧に見えたその作戦にも穴があったのだ。

// ためしに、maxループの中にgcd関数を入れてみてほしい。
// すると、実行速度はO(N^2)に比例することがすぐに分かるだろう。

// ここで俺氏は力尽きたのだった。

// そこで、新たな改善案として、累積和っぽいメモ化を使って、左側gcdと右側gcdを作り出すことにした。
// これ自体は模範解答の中に存在したのだが、俺氏はこの手法の何が優れているのかをきちんと理解できていなかった。
// この手法の優れているところは、左と右を一組選び出すことが可能なことである。
// つまり、O(N)のオーダー（NlogAかもしれん）の前処理一回、maxループのオーダーO(N)を足したもの、
// すなわち、O(NlogA + NlogA)もしくはO(2N)で完了することが出来る点が優れているのである。

// 以上をかくぞ

// leftは　i　までのgcd　すなわち　i-1　のgcdを取得。
// なので、i == 0 の時はそのままイコール


// 追記
// std::gcd() は　C++17　で追加されたライブラリである。
// 競技プログラミングではC++14環境なので、自前で用意する必要がある。
// その際に、混同しないようにGCDと大文字表記しておくとよさそう。

int GCD(int a,int b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

int main(){
    long long int N,A;
    cin >> N;
    long long int Z[N+1]; // 整数がつまってる

    for (long long int i = 0; i < N ;i++){ // 標準入力で配列にぶちこむ
        cin >> A;
        Z[i] = A;
    }

    vector<long long int> left(N+1,1);
    vector<long long int> right(N+1,1);

    long long int temp = Z[0];

    for(long long int j = 0; j < N;j++){ //gcdリスト取得 left
        if(j == 0){
            left[j] = 1 ;
            continue;
        }
        if(j == 1){
            left[j] = Z[j-1];
            continue;
        }
        temp = GCD(temp,Z[j-1]) ;
        left[j] = temp;
    }

    
    temp = Z[N-1] ;
    for(long long int k = N-1; k >= 0 ;k--){ //gcdリスト取得 right
        if(k == N-1){
            right[k] = 1;
            continue;
        }
        if(k == N-2){
            right[k] = Z[k+1];
            continue;
        }
        temp = GCD(temp,Z[k+1]);
        right[k] = temp;
    }


    temp = 0;
    long long int maxz = 0;

    for(long long int l = 0;l < N;l++){ // max_roop
        if(l == 0){
            temp = right[l] ; //特殊な場合を除く
        }
        else if(l == N-1){ //特殊な場合を除く
            temp = left[l] ;
        }
        else { // メインの比較
            temp = GCD(left[l],right[l]);
        }

        // maxz の書き換え

        if(temp > maxz){
            maxz = temp;
        }
        else {
            continue;
        }     
    }


    cout << maxz << endl;
}

