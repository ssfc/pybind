#include <pybind11/embed.h>
#include <iostream>
namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // 启动python解释器

    // 假设你有个python的myfunc.py文件，里面有def process(val):
    py::object sys = py::module_::import("sys");
    sys.attr("path").attr("insert")(1, "/你的py文件路径/");

    py::object myfunc_module = py::module_::import("myfunc");
    double cxx_value = 123.45;

    // 调用python函数
    py::object py_result = myfunc_module.attr("process")(cxx_value);

    double c_result = py_result.cast<double>(); // 若你希望返回double
    std::cout << "Python computed: " << c_result << std::endl;
}
