//
// Created by 74746 on 2023/5/19.
//

#ifndef NEWPROJECT_VECTOR_H
#define NEWPROJECT_VECTOR_H
#include <iostream>
#include <array>
#include <numeric>
#include <mapidbg.h>
#include <valarray>
#include <initializer_list>

template<int dim, typename T>
class Vector {
public:
    std::vector<T> values {0};

    Vector()= default;
    Vector(std::initializer_list<T> list):values(list){}

    friend std::ostream& operator<<(std::ostream& os, const Vector<dim, T> &v) {
        os << "[" ;
        for(int i =0;i<dim-1;i++){
            os << v.values[i] << ", ";
        }
        os << v.values[dim-1] << "]";
        return os;
    }

    Vector<dim, T> operator+(const Vector<dim, T> &v) const{
        Vector<dim, T> result;
        for(int i = 0; i<dim; i++){
            result.values[i] = this->values[i]+v.values[i];
        }
        return result;
    }

    void operator+=(const Vector<dim, T> &v){
        for(int i = 0; i<dim; i++){
            this->values[i]+=v.values[i];
        }
    }

    Vector<dim, T> operator-(){
        Vector<dim, T> result;
        for(int i = 0; i<dim; i++){
            result.values[i] = -this->values[i];
        }
        return result;
    }

    Vector<dim, T> operator-(const Vector<dim, T> &v){
        Vector<dim, T> result;
        for(int i = 0; i<dim; i++){
            result.values[i] = this->values[i]-v.values[i];
        }
        return result;
    }

    void operator-=(const Vector<dim, T> &v){
        for(int i = 0; i<dim; i++){
            this->values[i]-=v.values[i];
        }
    }

    Vector<dim, T> operator*(const T t) const{
        Vector<dim, T> result;
        for(int i = 0; i<dim; i++){
            result.values[i] = this->values[i]*t;
        }
        return result;
    }

    friend Vector<dim, T> operator*(T t, const Vector<dim, T> v){
        return v.operator*(t);
    }

    void operator*=(T t){
        for(int i = 0; i<dim; i++){
            this->values[i]*=t;
        }
    }

    Vector<dim, T> operator/(T t) const{
        Vector<dim, T> result;
        for(int i = 0; i<dim; i++){
            result.values[i] = this->values[i]/t;
        }
        return result;
    }

    void operator/=(T t){
        for(int i = 0; i<dim; i++){
            this->values[i]/=t;
        }
    }

    T &operator[](int i){
        Assert(i>=0 && i <dim);
        return values[i];
    }

    T norm() const{
        T t =0;
        for(int i = 0; i<dim;i++){
            t += values[i]*values[i];
        }
        return std::sqrt(t);
    }

    T dot(const Vector<dim,T> v) const{
        T t = 0;
        for(int i = 0; i<dim; i++){
            t += this->values[i]*v.values[i];
        }
        return t;
    }

    Vector<dim, T> normalize() const{
        return *this/(this->norm());
    }

    static T dot(const Vector<dim,T> v1, const Vector<dim,T> v2){
        T t =0;
        for(int i = 0; i<dim;i++){
            t += v1.values[i]*v2.values[i];
        }
        return t;
    }

};

template<typename T>
class Vector2: public Vector<2, T>{

public:
    Vector2() = default;
    Vector2(T x, T y){
        this->values[0] = x;
        this->values[1] = y;
    }
    T &x = this->values[0];
    T &y = this->values[1];

};

template<typename T>
class Vector3: public Vector<3, T>{

public:
    Vector3() = default;
    Vector3(T x, T y, T z){
        this->values[0] = x;
        this->values[1] = y;
        this->values[2] = z;
    }
    T &x = this->values[0];
    T &y = this->values[1];
    T &z = this->values[2];


    Vector3<T> cross(Vector3<T> v) const{
        return Vector3<T>((y * v.z) - (z * v.y),
                          (z * v.x) - (x * v.z),
                          (x * v.y) - (y * v.x));
    }

    static Vector3<T> cross(Vector3<T> v1, Vector3<T> v2){
        return Vector3<T>((v1.y * v2.z) - (v1.z * v2.y),
                          (v1.z * v2.x) - (v1.x * v2.z),
                          (v1.x * v2.y) - (v1.y * v2.x));
    }

};


typedef Vector2<float> Vector2f;
typedef Vector3<float> Vector3f;
typedef Vector2<double> Vector2d;
typedef Vector3<double> Vector3d;

#endif //NEWPROJECT_VECTOR_H
