#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<string, pair<int, int> > > vec(n);
  for (int i = 0; i < n; i++) {
    int no, hyouka;
    string namae;
    no = i+1 ;
    cin >>  namae >> hyouka;
    // 点数が高い順にソートしたいので、kokugoとsugakuを前方に持ってきてマイナスにする
    vec[i] = make_pair(namae, make_pair(-hyouka, no));
  }

  sort(vec.begin(), vec.end()); // これで想定通りにソートされる

  for (int i = 0; i < vec.size(); i++)
    // 番号は3番目に入れたのでsecond2つでアクセスする
    cout << vec[i].second.second << endl;

  return 0;
}