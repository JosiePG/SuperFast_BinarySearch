// searches for the first element that is bigger than or equal to x

#include <iostream>

int t[] = {1,2,3,4,4,6,7,8};
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

int main(){
    


    std::cout << naive_lower_bound(5) << std::endl;

    return 1;

}