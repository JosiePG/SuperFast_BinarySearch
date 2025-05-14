// searches for the first element that is bigger than or equal to x

//TODO:
// think about how to avoid negative effects from cach assoicativity 
// when arrays are power of 2 as they can kick eachouther out of cache sets

#include <iostream>

// array
int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
// len of array
const int n = sizeof(a)/sizeof(a[0]);
//eytzinger array layout
int e[n+1];


// textbook binary search implementation
int naive_lower_bound(int x){

    int l = 0 , r = n - 1;

    while(l<r){
        int m = (l+r) /2;
        if(a[m] >= x){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return a[l];

}

//stl implementation
int stl_lower_bound(int x){
    int* base = a;
    int len = n;

    while(len>1){
        int half = len / 2;

        //branch
        std::cout << base[half-1] <<std::endl;

        if(base[half-1]<x){
            base+=half;
        }
        len-=half;
        
    }return *base;


}

// branchless stl implementation 

int branchless_stl_lower_bound(int x){
    int* base = a;
    int len = n;

    while(len>1){
        int half = len / 2;
        len-=half;
        __builtin_prefetch(&base[len/2-1]);
        __builtin_prefetch(&base[len/2 - 1 + half]);
        base += (base[half-1]<x) * half;

        
    }return *base;


}

void eytzinger(int k = 1){
    static int i = 0;
    if(k<=n){
        eytzinger(2*k);
        e[k] = a[i++];
        eytzinger((2*k)+1);
    }

}

int eytzinger_lower_bound(int x){
    int k = 1;
    while(k<=n){
        __builtin_prefetch(e+k*16);
        k = 2*k+(e[k] < x);

    }
    k>>=__builtin_ffs(~k);
    return e[k];
}

int main(){

    


    // std::cout << naive_lower_bound(5) << std::endl;
    // std::cout << stl_lower_bound(6) <<std::endl;
    // std::cout <<branchless_stl_lower_bound(17) << std::endl;
    eytzinger();
    //aligning the eytzinger array
    int* e = static_cast<int*>(::operator new(4 * (n + 1), static_cast<std::align_val_t>(64)));
    std::cout << eytzinger_lower_bound(17) << std::endl;

    return 0;

}