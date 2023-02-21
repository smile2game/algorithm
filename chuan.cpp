#include <iostream>
using namespace std;
 
void test(int &a){
    a = 3;
    cout << &a << " " << a << endl;
}
 
int main(void){
    int a = 1;
    cout << &a << " " << a << endl;
    test(a);
    cout << &a << " " << a << endl;
    return 0;
}