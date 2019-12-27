//
// Created by Валентин Евсеенко on 12/27/19.
//

#ifndef AUTODIFFMODULE_EXTERNALFUNCTIONAL_H
#define AUTODIFFMODULE_EXTERNALFUNCTIONAL_H
//
// Created by Валентин Евсеенко on 12/27/19.
//

#include <vector>
#include <cmath>


template <typename T>
std::vector<T> operator + (const std::vector<T> &first,
                           const std::vector<T> &second){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), second.begin(), std::back_inserter(result),
                   [](float a, float b){ return a + b;});
    return result;
}

template <typename T>
std::vector<T> operator - (const std::vector<T> &first,
                           const std::vector<T> &second){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), second.begin(), std::back_inserter(result),
                   [](T a, T b){ return a - b;});
    return result;
}

template <typename T>
std::vector<T> operator -- (const std::vector<T> &first){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), std::back_inserter(result),
                   [](T a){ return --a;});
    return result;
}

template <typename T>
std::vector<T> operator ++ (const std::vector<T> &first){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), std::back_inserter(result),
                   [](float a){ return ++a;});
    return result;
}

template <typename T>
std::vector<T> operator * (const std::vector<T> &first, float times){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), std::back_inserter(result),
                   [&times](T a){ return a * times;});
    return result;
}

template <typename T>
std::vector<T> operator * (float number, const std::vector<T> &times){
    std::vector<T> result{};
    result.reserve(times.size());

    std::transform(times.begin(), times.end(), std::back_inserter(result),
                   [&number](T a){ return a * number;});
    return result;
}

template <typename T>
std::vector<T> operator / (const std::vector<T> &first, float times){
    std::vector<T> result{};
    result.reserve(first.size());

    std::transform(first.begin(), first.end(), std::back_inserter(result),
                   [&times](T a){ return a / times;});
    return result;
}

template <typename T>
std::vector<T> sin(std::vector<T> x){
    std::for_each(x.begin(), x.end(),
                  [](T element){ return std::sin(element);});
    return x;
}

template <typename T>
std::vector<T> cos(std::vector<T> x){
    std::for_each(x.begin(), x.end(),
                  [](T element){ return std::cos(element);});
    return x;
}

template <typename T>
int sign(T x){
    return x < 0? -1 : 1;
}

#endif //AUTODIFFMODULE_EXTERNALFUNCTIONAL_H
