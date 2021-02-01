#include <bits/stdc++.h>
using namespace std;

// 方針
// 条件を満たす時、N = m*商 + m が成立するときで、N = k(m+1)　∀k　∈　自然数　とあらわせる。
// このとき、Nは約数に　ｋ　と　ｍ＋１　をもつことを意味する。
// すなわち、自然数ｍは　「Nの約数　－　１」　に限定される。
// よって、Nの約数を列挙し、約数-1　に関して数え上げればいい。

// 約数の列挙
// 約数は配列に収納しておく。
// このとき、動的に配列を作っておくとよさそう。（vector）
// ちなみに、約数の列挙はO(√n)で作る必要あり。

vector<long long int> div(long long int n){
    vector<long long int> list;
    for(long long int i = 1;i*i < n;i++){
        if(n % i == 0){
            list.push_back(i);

            if(i * i != n)list.push_back(n / i);
        }
    }
    sort(list.begin(),list.end(),greater<long long int>()); //greaterつけると降順
    return list;

}

int main(){
    long long int N;
    cin >> N;
    vector<long long int> div_list = div(N);
    long long int count = 0;
    long long int temp = 0;


   
    for(int j = 0; j < div_list.size();j++){
        temp = div_list[j] - 1 ;
        if(temp == 0)continue;
       
        if((N / temp) == (N % temp)){
            count += temp;
        
        }

    }
    cout << count << endl;
}
    
// 2019 0512 AC

//追記
// どうやら、使用メモリのKBとMBを勘違いしてたらしく、昨日の間違いはメモリ使用量ではなかった。
// なので、なにかワンケースがとれていなかったらしい。
// あと、この正解コードを書くのに、エラー136がめちゃくちゃでて困った。
// これは、どうやら　0除算　をすると発生するらしい。
// if()の中身でやってたり、forループの int i = 0 で発生したりする。
