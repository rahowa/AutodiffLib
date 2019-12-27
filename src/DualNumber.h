//
// Created by Валентин Евсеенко on 12/27/19.
//

#ifndef AUTODIFFMODULE_DUALNUMBER_H
#define AUTODIFFMODULE_DUALNUMBER_H


#include <cmath>
#include <iostream>
#include <vector>

#include "ExternalFunctional.h"

namespace dop {

    template <typename T>
    struct DualNumber{

        DualNumber<T> (T real, std::vector<T>  epsilon):
                real(real), epsilon(std::move(epsilon)){};

        DualNumber<T> operator + (const DualNumber<T>& other){
            return {this->real + other.real,
                    this->epsilon + other.epsilon};
        }

        DualNumber<T> operator - (const DualNumber<T>& other){
            return  {this->real - other.real,
                     this->epsilon - other.epsilon};
        }

        DualNumber<T> operator * (const DualNumber<T>& other){
            return {this->real * other.real,
                    this->epsilon * other.real + this->real * other.epsilon};
        }

        DualNumber<T> operator / (const DualNumber<T>& other){
            return {this->real / other.real,
                    (this->epsilon / other.real) - (this->real / other.real) * (other.epsilon/other.real)};
        }

        void operator -- (){
            --this->real;
            --this->epsilon;
        }

        void operator ++ (){
            ++this->real;
            ++this->epsilon;
        }

        T real{};
        std::vector<T> epsilon{}; // not eˆ2 == 0 coeff, but second real number
    };


    template <typename T>
    DualNumber<T> sin(const DualNumber<T>& argument){
        return {std::sin(argument.real),
                std::cos(argument.real) * argument.epsilon};
    }

    template <typename T>
    DualNumber<T> cos(const DualNumber<T>& argument){
        return {std::cos(argument.real),
                -std::sin(argument.real) * argument.epsilon};
    }

    template <typename T>
    DualNumber<T> pow(const DualNumber<T>& argument, float power){
        if (argument.real != 0.0f)
            return {std::pow(argument.real, power),
                    std::pow(argument.real, power) * power * (argument.epsilon / argument.real)};
        else return argument;
    }

    template <typename T>
    DualNumber<T> exp(const DualNumber<T>& argument){
        return {std::exp(argument.real), argument.epsilon * std::exp(argument.real)};
    }

    template <typename T>
    DualNumber<T> ln(const DualNumber<T>& argument){
        if (argument.real > 0.0f)
            return {std::log(argument.real), argument.epsilon/argument.real};
        else return argument;
    }

    template <typename T>
    DualNumber<T> abs(const DualNumber<T>& argument) {
        if (argument.real != 0.0f)
            return {std::abs(argument.real), argument.epsilon * sign(argument.real)};
        else return argument;
    }

    template <class T, class Primitive> DualNumber<T> primToDn(Primitive x){
        auto f_x = static_cast<T>(x);
        return {f_x, {0}};
    }
}


template <typename T>
std::ostream& operator << (std::ostream& ostream, const dop::DualNumber<T>& number);


#endif //AUTODIFFMODULE_DUALNUMBER_H
