// char[]からStringに変換
文字列リテラルなどのアドレスをそのまま渡す。

char c_str[] = {"hello world!"};
std::string s_str = c_str;




// Stringからchar*に変換
c_str()を使う

std::string str = "hello world!"
const char* cstr = str.c_str();






// intからStringに変換

int num = 4321;
str = std::to_string(num);




// stringの途中で特定の文字だけ飛ばして入力を得たい時
// ARC 010 B - 超大型連休 のような問題の入力を得るときに使う奴

    int M, D;
    scanf("%d/%d", &M, &D);

    // %D と %D の間に / を入れると / だけ飛ばされる。　つまり、間に入れるのは何の文字でもいい。
    // int は d
    // char は c
    // string は s

    // しかし、自分で良くわかってないからどうしてもヤバい時だけ使う


// Stringからintに変換

std::string numStr = "1234";
int num = std::stoi(numStr);

// LL なら　stol

// int -> char

int i = 8;
char c = '0' + i;


// char -> int

char c = '4';
int i = c - '0';