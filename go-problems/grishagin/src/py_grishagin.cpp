#include <pybind11/pybind11.h>
#include "grishagin_function.hpp"

namespace py = pybind11;
using namespace vagrish;

PYBIND11_MODULE(py_grishagin_functions, m) {
    py::class_<GrishaginFunction>(m, "GrishaginFunction")
        .def(py::init<>())
        .def("Calculate", &GrishaginFunction::Calculate)
        .def("SetFunctionNumber", &GrishaginFunction::SetFunctionNumber)
        .def("GetFunctionNumber", &GrishaginFunction::GetFunctionNumber)
        .def("GetDimension", &GrishaginFunction::GetDimension)
        .def("GetConstraintsNumber", &GrishaginFunction::GetConstraintsNumber)
        .def("GetOptimumPoint", &GrishaginFunction::GetOptimumPoint)
        .def("GetOptimumValue", &GrishaginFunction::GetOptimumValue)
        .def("GetBounds", &GrishaginFunction::GetBounds)
        ;
}
