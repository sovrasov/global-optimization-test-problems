#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "problem_wrapper.hpp"
#include "grishagin_function.hpp"

namespace py = pybind11;
using namespace vagrish;

GOTestProblemWrapper<double> create_grishagin_function(int idx)
{
  auto f = std::make_shared<GrishaginFunction>();
  f->SetFunctionNumber(idx);
  return GOTestProblemWrapper<double>(f);
}

PYBIND11_MODULE(go_problems, m) {
    m.def("create_grishagin_function", &create_grishagin_function, "Create Grishagin problem");

    py::class_<GOTestProblemWrapper<double>>(m, "GOTestProblemWrapper")
        .def("Calculate", &GOTestProblemWrapper<double>::Calculate, py::arg("y"), py::arg("fNumber") = 0)
        .def("GetDimension", &GOTestProblemWrapper<double>::GetDimension)
        .def("GetConstraintsNumber", &GOTestProblemWrapper<double>::GetConstraintsNumber)
        .def("GetOptimumPoint", &GOTestProblemWrapper<double>::GetOptimumPoint)
        .def("GetOptimumValue", &GOTestProblemWrapper<double>::GetOptimumValue)
        .def("GetBounds", &GOTestProblemWrapper<double>::GetBounds)
        .def("GetCalculationsStatistics", &GOTestProblemWrapper<double>::GetCalculationsStatistics)
        ;
}
