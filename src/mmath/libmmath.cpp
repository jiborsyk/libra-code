#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "libmmath.h"

using namespace boost::python;
//using namespace libmmath;
//using libmmath::VECTOR;
//using libmmath::MATRIX;
//using libmmath::CMATRIX;
//using libmmath::MATRIX3x3;
//using libmmath::QUATERNION;
//using libmmath::DATA;

namespace libmmath{

using namespace libspecialfunctions;
using namespace liblinalg;
using namespace libgraph;
using namespace liboperators;
using namespace librandom;
using namespace libdata;
using namespace libann;
using namespace libmeigen;
using namespace libsymmetry;

void export_Mathematics_objects(){


  class_<Timer>("Timer",init<>())
      .def("__copy__", &generic__copy__<Timer>)
      .def("__deepcopy__", &generic__deepcopy__<Timer>)

      .def("start", &Timer::start)
      .def("stop", &Timer::stop)
      .def("show", &Timer::show)

  ;




}// export_Mathematics_objects()




#ifdef CYGWIN
BOOST_PYTHON_MODULE(cygmmath){
#else
BOOST_PYTHON_MODULE(libmmath){
#endif

  // Register converters:
  // See here: https://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
  //to_python_converter<std::vector<DATA>, VecToList<DATA> >();
  export_linalg_objects();
  export_SpecialFunctions_objects();
  export_GRAPH_objects();
  export_Operators_objects();
  export_Random_objects();
  export_Data_objects();
  export_NeuralNetwork_objects();
  export_mEigen_objects();
  export_Mathematics_objects();
  export_symmetry_objects();

}


}// libmmath

