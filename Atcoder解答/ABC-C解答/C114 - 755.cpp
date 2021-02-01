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

//      C114 - 755 
//  DFSでシンプルに解く。
//  高々3^10なので、60000程度。

//  今回のDFSは
//  現在の値　+　次の桁　の時の判定をする。

LL cnt;                     //答え  参照渡ししてvoidDFS内でカウントアップ
LL N;   
bool three = false;
bool five = false;
bool seven = false;
vector<int> keta;
int Nsize;

unsigned GetDigit(unsigned num){        //int,LLの桁拾い
    if(num == 0)return 1;
    return log10(num)+1;
}

void DFS(LL n,int nex,LL &cnt,vector<int> &k){  //DFS関数　voidにしてcntとvectorを参照渡しする。

    if(n*10+nex > N)return;     //現在の値にnexを桁として足すとアウトならreturn
    int nsize = GetDigit(n);    //現在値の桁GET

    if(n == 0){                 //初期値
        k[0] = nex;
    }
    else{
        k[nsize] = nex;         //桁のケツに 次の桁の数値を入れてる。
    }

    for(int i = nsize+1;i<Nsize;i++){   //DFSで桁の値を再利用されないように、一回ごとにケツとそれ以降の桁を初期化してる。
        k[i] = 0;
    }
    rep(i,Nsize){                       //3,5,7あるかどうかの判定
        if(k[i] == 3)three = true;
        if(k[i] == 5)five = true;
        if(k[i] == 7)seven = true;
    }

    if(three && five && seven)cnt++;    //ここで、357のカウントが増える。

    three = false;                      //これで357カウントのリセット
    five = false;
    seven = false;


    
    DFS(n*10 + nex,3,cnt,keta);         //next 3
    DFS(n*10 + nex,5,cnt,keta);         //next 5
    DFS(n*10 + nex,7,cnt,keta);         //next 7
    return;
}

int main(){
    cin >> N;
    Nsize = GetDigit(N);                //標準入力の桁GET
    keta.resize(Nsize);                 //桁取得後にリサイズ
    DFS(0,3,cnt,keta);                  //3 start
    DFS(0,5,cnt,keta);                  //5 start
    DFS(0,7,cnt,keta);                  //7 start
    cout << cnt << endl;
}