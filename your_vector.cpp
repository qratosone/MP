#include <iostream>
#include <cstdio>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
class vector{
private:
    int size;
    int number;
    int * data;
public:
    vector(int size){
        this->size=size;
        number=0;
        data=new int[size];
    }
    vector(vector &v){
        size=v.size;
        number=v.number;
        data=new int[size];
        for (int i = 0; i <number ; ++i) {
            data[i]=v.data[i];
        }
    }
    vector(){
        size=5;
        data=new int[size];
        number=0;
    }
    ~vector(){
        
    }
    void insert(int value){
        if(number==size){
            expand();
        }
        data[number]=value;
        number++;
    }
    void expand(){

        int *temp=new int[size];
        for (int i = 0; i < size; ++i) {
            temp[i]=data[i];
        }
        delete[] data;

        data=new int[2*size];
        for(int i=0;i<size;i++){
            data[i]=temp[i];
        }
        size=size*2;
        delete [] temp;

    }
    void show(){
        for (int i = 0; i <number ; ++i) {
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    void sort_array(){
        sort(data,data+number);
    }
};


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
