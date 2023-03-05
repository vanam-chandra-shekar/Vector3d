#include <iostream>
#include "vector3d.hpp"

using namespace std;

int main(){
    vector3d velocity{1,5,6};
    vector3d accleration {1,1,1};
    vector3d c {velocity};
    cout<<c.magnitude()<<endl;
}