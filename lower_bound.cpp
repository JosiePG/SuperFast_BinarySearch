// searches for the first element that is bigger than or equal to x

#include <iostream>

int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
const int n = sizeof(t)/sizeof(t[0]);

// textbook binary search implementation
int naive_lower_bound(int x){

    int l = 0 , r = n - 1;

    while(l<r){
        int m = (l+r) /2;
        if(t[m] >= x){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    return t[l];

}

//stl implementation
int stl_lower_bound(int x){
    int* base = t;
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



int main(){

    


    //std::cout << naive_lower_bound(5) << std::endl;
    // std::cout << stl_lower_bound(6) <<std::endl;
    std::cout <<branchless_stl_lower_bound(17) << std::endl;

    return 0;

}