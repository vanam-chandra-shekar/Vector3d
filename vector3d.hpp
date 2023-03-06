#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_
#include <iostream>

class vector3d
{
    friend vector3d operator*(const double &lhs,const vector3d &rhs);
    friend vector3d operator+(const vector3d &lhs,const vector3d &rhs);
    friend vector3d operator-(const vector3d &lhs ,const vector3d &rhs);
    friend std::ostream &operator<<(std::ostream &os , const vector3d &out );
    friend std::istream &operator>>(std::ostream &is, vector3d &in);
    public:
        double x , y ,z;
        vector3d(double X=0.0f, double Y=0.0f,double Z=0.0f);
        vector3d(const vector3d &rhs);
        double dot(const vector3d &b);
        vector3d cross(const vector3d &b);
        vector3d &operator=(const vector3d &rhs);
        vector3d operator-() const;
        double magnitude() const;
        vector3d normalize() const;
};

#endif