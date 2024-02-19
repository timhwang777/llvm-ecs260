#include<iostream>
#include<vector>
#include <cassert>

using namespace std;

unsigned fun1(unsigned x){
    unsigned res = 0;
    vector<unsigned> v1(x);
    for(int i=0 ; i<x ; i++) v1[i] = i + 2;
    for(auto j : v1) res += j;
    return res;
}

unsigned fun2(unsigned x){
    unsigned res = 0;
    vector<unsigned> v2(x);
    for(int i=0 ; i<x ; i++) v2[i] = i + 2;
    for(int j=0 ; j<x ; j++){
        if(j == x - 2) break;
        res += j;
    }
    return res;
}

int main(){
    unsigned x;
    assert(fun1(x) == fun2(x));
    return 0;
}