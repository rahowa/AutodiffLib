cmake_minimum_required(VERSION 3.15)
project(AutodiffModule)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(EXTERN_FUNCTIONS src/ExternalFunctional.h)
set(DUAL_NUMB src/DualNumber.h )
set(TOKENIZER src/Tokenizer.cpp src/Tokenizer.h)

add_executable(autodiff_exec main.cpp ${EXTERN_FUNCTIONS} ${DUAL_NUMB} ${TOKENIZER})
add_library(autodiff_lib ${EXTERN_FUNCTIONS} ${DUAL_NUMB} ${TOKENIZER})
