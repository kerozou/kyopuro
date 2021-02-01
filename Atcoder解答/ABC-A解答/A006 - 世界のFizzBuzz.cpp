#include <bits/stdc++.h>
using namespace std;
int main(){
    int N ;
    cin >> N ;
    if(N == 3){
        cout << "YES" << endl;
    }
    else if(N % 3 == 0){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}