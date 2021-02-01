#include <bits/stdc++.h>
using namespace std;
int main(){
    int N ;
    cin >> N;
    int sum;
    if(N % 2 == 0){
        cout << N / 2 << endl;
    }
    else {
        cout << (N + 2) / 2 << endl;
    }
}