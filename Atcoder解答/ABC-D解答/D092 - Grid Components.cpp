#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;
  string s[100];
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(i<50) s[i].push_back('.');
      else s[i].push_back('#');
    }
  }
  int cnt = 0;
  for(int i = 0; i < 50; i += 2){
    if(cnt == b-1) break;
    for(int j = 0; j < 100; j += 2){
      if(cnt == b-1) break;
      s[i][j] = '#';
      cnt++;
    }
  }
  cnt = 0;
  for(int i = 51; i < 100; i += 2){
    if(cnt == a-1) break;
    for(int j = 0; j < 100; j += 2){
      if(cnt == a-1) break;
      s[i][j] = '.';
      cnt++;
    }
  }
  cout << 100 << " " <<  100 << endl;
  for(int i = 0; i < 100; i++){
    cout << s[i] << endl;
  }

  return 0;
}


// ABC092 	D - Grid Components

// 極端なケースが許される問題。
// 特にグリッドに条件はしていされていないので、二つに分けたでっかいプールに隙間をあけてA、Bの数だけ埋めてけばいい。

// 公式放送が神ってる

// https://ykmaku.hatenablog.com/entry/2018/09/03/153250