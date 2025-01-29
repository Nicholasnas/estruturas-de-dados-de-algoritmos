#include <iostream>

using namespace std;

struct Person{
    char name[10];
    u_int8_t age;
    u_int8_t height;
};

void f2(char *p){
    cout << "From f2: " << &p << endl;
}
void f1(char *p){
    cout << "From f1: " << &p << endl;
    f2(p);
}

int main(){
    Person pessoa = {"Lucas", 20, 60};
    cout << "pessoa: " << &pessoa << endl;
    cout << "name: " << &pessoa.name << endl;
    cout << "age: " << &pessoa.age << endl;
    cout << "height: " << &pessoa.height << endl;

    char hello[] = "Hello World!";
    char * palavra = hello;
    cout << "From hello main: " << &hello << endl;
    cout << "From main: " << &palavra << endl;
    f1(palavra);
    return 0;
}