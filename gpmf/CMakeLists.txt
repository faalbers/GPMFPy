pybind11_add_module(gpmf_bindings gpmf_bindings.cpp)
target_link_libraries(gpmf_bindings PRIVATE GPMF)
install(TARGETS gpmf_bindings DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
