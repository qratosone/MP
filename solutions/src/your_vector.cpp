#include "your_vector.h"
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

vector::vector(int size){
    this->size=size;
    number=0;
    data=new int[size];
}
vector::vector(vector &v){
    size=v.size;
    number=v.number;
    data=new int[size];
    for (int i = 0; i <number ; ++i) {
        data[i]=v.data[i];
    }
}
vector::vector(){
    size=5;
    data=new int[size];
    number=0;
}
vector::~vector(){
    delete[] data;        
}
void vector::insert(int value){
    if(number==size){
        expand();
    }
    data[number]=value;
    number++;
}
void vector::expand(){
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
void vector::show(){
    for (int i = 0; i <number ; ++i) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void vector::sort_array(){
    sort(data,data+number);
}