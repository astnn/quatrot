// Some text describing library

#ifndef QUARTERNION_H
#define QUARTERNION_H

#include <complex>
#include <iostream> // Supplies std::cout

// TODO: Limit template to work for float, double, and double long. int and similar will give problems with multiplications and divisions.

// Forward declerations TODO: Are they necesary?
template<typename T> class Quarternion;
/*template<> class Quarternion<float>;
template<> class Quarternion<double>;
template<> class Quarternion<long double>;
*/
template<typename T>
    class Quarternion
    {
    private:
        T a;
        T b;
        T c;
        T d;
    public:
        typedef T value_type;


        Quarternion() : a{T()}, b{T()}, c{T()}, d{T()} {}; // Initialise to type default, i.e. zero
        Quarternion(T i_a, T i_b, T i_c, T i_d) : a{i_a}, b{i_b}, c{i_c}, d{i_d} {};
        ~Quarternion() {};

        // Accessors
        T a() const { return a; };
        T b() const { return b; };
        T c() const { return c; };
        T d() const { return d; };


        Quarternion& operator+=(const Quarternion y);
        Quarternion& operator-=(const Quarternion y);
        // TODO: Overload +=/-/ with scalar input. Expand to addition and subtraction.
        Quarternion& operator*=(const Quarternion y);

    };

template<typename T>
    Quarternion<T>& Quarternion<T>::operator+=(const Quarternion y)
    {
        a+=y.r();
        b+=y.i();
        c+=y.j();
        d+=y.k();
        return *this;
    };

template<typename T>
    Quarternion<T>& Quarternion<T>::operator-=(const Quarternion y)
    {
        a-=y.r();
        b-=y.i();
        c-=y.j();
        d-=y.k();
        return *this;
    };

template<typename T>
    Quarternion<T>& Quarternion<T>::operator*=(const Quarternion<T> y)
    {
        T a_out = a*y.a() - b*y.b() - c*y.c() - d*y.d();
        T b_out = a*y.b() + b*y.a() + c*y.d() - d*y.c();
        T c_out = a*y.c() - b*y.d() + c*y.a() + d*y.b();
              d = a*y.d() + b*y.c() - c*y.b() + d*y.a();

        a = a_out;
        b = b_out;
        c = c_out;

        return *this;
    }

// Addition opereator
template<typename T>
Quarternion<T> operator+(const Quarternion<T>& lhs, const Quarternion<T>& rhs)
{
    Quarternion<T> res = lhs;
    res += rhs;
    return res;
}

// Subtraction opereator
template<typename T>
Quarternion<T> operator-(const Quarternion<T>& lhs, const Quarternion<T>& rhs)
{
    Quarternion<T> res = lhs;
    res -= rhs;
    return res;
}

// Multiplication operator
template<typename T>
Quarternion<T> operator*(const Quarternion<T>& lhs, const Quarternion<T>& rhs)
{
    Quarternion<T> res = lhs;
    res *= rhs;
    return res;
}

// Insertion operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const Quarternion<T> q)
{
    os << "(" << q.r() << ", " << q.i() << ", " << q.j() << ", " << q.k() << ")";
    return os;
}




#endif // QUARTERNION_H