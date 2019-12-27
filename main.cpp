#include <cmath>
#include <iostream>

#include "DualNumber.h"

//using namespace dop;

template <typename T>
dop::DualNumber<T> squaredDifference(dop::DualNumber<T> y, const dop::DualNumber<T>& y_hat){
    dop::DualNumber diff = y - y_hat;
    return diff * diff;
}

template <typename T>
dop::DualNumber<T> anyFunction(dop::DualNumber<T> x,
        dop::DualNumber<T> y, dop::DualNumber<T> z){
    return dop::primToDn<T>(3) * x * x;
}


int main() {
    dop::DualNumber x{3.0f, {1, 0, 0}};
    dop::DualNumber y{5.0f, {0, 1, 0}};
    dop::DualNumber z{2.0f, {0, 0, 1}};
    dop::DualNumber result = anyFunction(x, y, z);
//    dop::DualNumber result = sin(dop::DualNumber(0.5, {1}));
    std::cout << "Fucntion result: " << result.real << "\n";
    std::cout << "Partial derivatives: ";
    for(const auto res: result.epsilon){
        std::cout << res << " ";
    }
    return 0;
}