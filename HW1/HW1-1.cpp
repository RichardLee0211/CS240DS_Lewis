#include<iostream>

using namespace std;

#define M 3

/**
 * namely, m, m*2, m*3, m*4, ..., m*n
 */
int print_n_multiples_of_m(int n, int m){
    if(n != 0){
        print_n_multiples_of_m(n-1, m);
        cout<<m*n<<" ";
        return 0;
    }
    else
        return 0;
}

int main(){
    print_n_multiples_of_m(5, M);
    return 0;
}
