#include <pybind11/pybind11.h>
#include "GPMF.hpp"

namespace py = pybind11;

PYBIND11_MODULE(gpmf_bindings, m)
{
    m.doc() = "GPMF Gopro metadata library";
    
}
