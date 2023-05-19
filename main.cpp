#include <iostream>
#include "math/vector.h"


int main() {


   // Vector<3,float> x {1,2,1};
    //Vector<3,float> y {3,2,5};
    int t = 3;

    Vector3f x(3,4,5);
    Vector3f y(0,1,0);

    std::cout<<x.norm()<<std::endl;
    std::cout<< x.normalize() <<std::endl;

    return 0;



}





