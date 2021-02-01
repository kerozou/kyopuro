#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    cin >> N;
   // long long int I ;
    long long int sum = N - 1;
  //  long long int *pN = &N ;
    //long int IK;
    long int x = 0;

    for (int i = 2;i < N;i++){
        long long int start = N / i ;
        long long int end = N /(i + 1) ; 
       if (i == 100000) {
            x = 100001;
            break;
    }

        for (long long int j = start ; j > end ; j--){

            if (N % j == i){
                sum += j ;
              //  I = i;
               //  if( i > 100000) IK += 1;
                break ;
            }
            else if (N % j > i) {
             //  I = i;
                break ;
            }
            else {
                continue ;
            }

        }

    }

    if(x > 100000){
        int op ;
        for(int y = 100001;y < 1000000;y++){
            if (y > 995030)break;
            
            op = (N-y)%y;
            if (op == 0){
                sum += (N-y) / y ;
            }
            else{
                continue;
            }


        }
    }

    cout << sum << endl;
   // cout << I << "  "<<IK << endl;
}