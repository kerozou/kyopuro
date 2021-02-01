#include <bits/stdc++.h>
using namespace std;

// DFS で解ける問題。
// しかし、stringを参照渡しするとだいたいおかしな挙動になって、てんぱる。
// もはやこれ文字列っていうか文字の配列やん。

int N;
char a,b,c;

string S;
string res;


void DFS(int i,string &S,char x){ // i index , S result-1 , x abc,
    S[i-1] = x;

        if(i == 1){ // 初期条件

            for(int j = N-1; j+1 > 0 ;j--){
            	cout << S[j];
            }
  			cout << endl;

        return;
    }

    DFS(i-1,S,a);
    DFS(i-1,S,b);
    DFS(i-1,S,c);

}
int main(){

    cin >> N;
    a = 'a';
    b = 'b';
    c = 'c';

    S = " ";
    DFS(N,S,a);
    DFS(N,S,b);
    DFS(N,S,c);

}

// 20190518 AC