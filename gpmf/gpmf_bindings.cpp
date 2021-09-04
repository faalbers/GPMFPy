#include <pybind11/pybind11.h>
#include "GPMF.hpp"
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <vector>

struct testStruct {
    int x;
    double y;
};

namespace py = pybind11;

PYBIND11_MODULE(gpmf_bindings, m)
{
    m.doc() = "GPMF Gopro metadata library";
    
    py::class_<GPMF::sampleEntryType>( m, "sampleEntry" )
        .def_readonly("value", &GPMF::sampleEntryType::value)
        .def_readonly("unit", &GPMF::sampleEntryType::unit)
        .def_readonly("info", &GPMF::sampleEntryType::info)
        ;
    
    py::class_<GPMF::sampleType>( m, "sample" )
        .def_readonly("entries", &GPMF::sampleType::entries)
        .def_readonly("time", &GPMF::sampleType::time)
        .def_readonly("duration", &GPMF::sampleType::duration)
        ;

    py::class_<GPMF::GPMF>( m, "GPMF" )
        .def(py::init<std::string>())
        .def("printHierarchyData", &GPMF::GPMF::printHierarchyData, "print hierarchy with data",
            py::arg("fullLists") = false)
        .def("printHierarchy", &GPMF::GPMF::printHierarchy)
        .def("getAcceleration", &GPMF::GPMF::getAcceleration)
        .def("getGyroscope", &GPMF::GPMF::getGyroscope)
        ;
}
