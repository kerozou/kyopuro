// C++ で　__int128 を使うために必要なもの。
// __int128 は operater << を使うために以下の記述がいる。
// cin は　適当にLLとかに突っ込んでから変換するか、stringでとってきて parse をかます。


#include <bits/stdc++.h>
using namespace std;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

int main() {
  string s = "187821878218782187821878218782";
  __int128 x = parse(s);
  x *= 2;
  cout << x << endl;
}