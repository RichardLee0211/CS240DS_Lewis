#include<iostream>
#include<math.h>

using namespace std;

#define M 3

/**
 * namely, m*n, m*(n-1), ..., m*2, m
 */
int print_n_multiples_of_m_reverse(int n, int m){
    if(n != 0){
        cout<<m*n<<" ";
        print_n_multiples_of_m_reverse(n-1, m);
        return 0;
    }
    else
        return 0;
}

int main(){
    print_n_multiples_of_m_reverse(5, M);
    return 0;
}
