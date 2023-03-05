#include "vector3d.hpp"
#include<iostream>
#include <math.h>

vector3d::vector3d(double X,double Y,double Z)
    :x{X},y{Y},z{Z}{}

vector3d::vector3d(const vector3d &rhs)
    :x{rhs.x},y{rhs.y},z{rhs.z}{}

double vector3d::dot(const vector3d &b)
{
    return ((x*b.x)+(y*b.y)+(z*b.z));
}

vector3d vector3d::cross(const vector3d &b)
{
    double s1 {((y*b.z)-(z-b.y))};
    double s2 {((z*b.x)-(x-b.z))};
    double s3 {((z*b.y)-(y-b.x))};
    return vector3d(s1,s2,s3);
}

void vector3d::display()
{
    std::cout<<x<<"i+"<<y<<"j+"<<z<<"k"<<std::endl;
}

vector3d &vector3d::operator=(const vector3d &rhs)
{
    if(this==&rhs){
        return *this;
    }else{
        x = rhs.x; y= rhs.y ; z = rhs.z;
        return *(this); 
    }
}

vector3d operator*(const double &lhs,const vector3d &rhs)
{
    return vector3d(lhs*rhs.x,lhs*rhs.y,lhs*rhs.z);
}

vector3d vector3d::operator-() const
{
    return vector3d(-1*x,-1*y,-1*z);
}

vector3d operator+(const vector3d &lsh,const vector3d &rhs)
{
    double X,Y,Z;
    X = lsh.x+rhs.x; Y =lsh.y+rhs.y; Z= lsh.z+rhs.z;
    return vector3d(X,Y,Z);
}

double vector3d::magnitude() const
{
    double m {0};
    m = std::sqrt(x*x+y*y+z*z);
    return m;
}

vector3d vector3d::normalize() const
{
    double X,Y,Z;
    double mag = this->magnitude();
    if(mag==1){
        return *this;
    }else
    {
        X = x/mag; Y = y/mag; Z = z/mag;
        return vector3d(X,Y,Z);
    }
    
}