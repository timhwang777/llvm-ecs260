#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int fun1(int x, int y){
    return x + y;
}

int fun2(int x, int y){
    if(y > 0) y = -1 * y;
    else y = 0;

    return x + y;
}

int main(){
    int x, y;
    assert(fun1(x, y) == fun2(x, y));
    return 0;
}