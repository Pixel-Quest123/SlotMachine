add_library(PrivateLibrary STATIC rng.cpp)
target_include_directories(PrivateLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../public)