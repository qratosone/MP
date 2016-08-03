#ifndef your_vector_H
#define your_vector_H
class vector{
private:
    int size;
    int number;
    int * data;
public:
    vector(int size);
    vector(vector &v);
    vector();
    ~vector();
    void insert(int value);
    void expand();
    void show();
    void sort_array();
};
#endif