#include <cstdio>
#include "your_vector.h"
using std::cin;
int main(){
    freopen("testcase.in","r",stdin);
    vector v1(5);
    for (int i = 0; i <7 ; ++i) {
        v1.insert(i);
    }
    v1.show();
    vector v2(v1);
    int input;
    for (int i=0;i<5;i++){
        cin>>input;
        v2.insert(input);
    }
    v2.show();
    v1.show();
    v2.sort_array();
    v2.show();
    return 0;
}
