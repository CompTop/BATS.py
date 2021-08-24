#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;

//.def("add_recursive"(std::vector<cell_ind> (Filtration<T, CpxT>::*)(T, std::vector<size_t>&))(&Filtration<T, CpxT>::add_recursive))
#define FilteredComplexInterface(T, CpxT, name) py::class_<Filtration<T, CpxT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CpxT&, const std::vector<std::vector<T>>& >())\
.def("add", (cell_ind (Filtration<T, CpxT>::*)(T, std::vector<size_t>&))(&Filtration<T, CpxT>::add))\
.def("add_recursive", [](Filtration<T, CpxT> &F, T t, std::vector<size_t>& s){return F.add_recursive(t, s);})\
.def("complex", &Filtration<T, CpxT>::complex)\
.def("maxdim", &Filtration<T, CpxT>::maxdim)\
.def("ncells", &Filtration<T, CpxT>::ncells)\
.def("sublevelset", &Filtration<T, CpxT>::sublevelset)\
.def("vals", py::overload_cast<size_t>(&Filtration<T, CpxT>::vals, py::const_))\
.def("all_vals", py::overload_cast<>(&Filtration<T, CpxT>::vals, py::const_))

#define ZigzagComplexInterface(T, CpxT, name) py::class_<zigzag::ZigzagFiltration<CpxT, T>>(m, name)\
.def(py::init<>())\
.def(py::init<const CpxT&, const std::vector<std::vector<std::vector<std::pair<T, T>>>>& >())\
.def("add", [](zigzag::ZigzagFiltration<CpxT, T>& F, const T entr, const T exit, std::vector<size_t>& s){ return F.add(entr, exit, s); })\
.def("add_recursive", [](zigzag::ZigzagFiltration<CpxT, T>& F, const T entr, const T exit, std::vector<size_t>& s){ return F.add_recursive(entr, exit, s); })\
.def("complex", &zigzag::ZigzagFiltration<CpxT, T>::complex)\
.def("maxdim", &zigzag::ZigzagFiltration<CpxT, T>::maxdim)\
.def("ncells", &zigzag::ZigzagFiltration<CpxT, T>::ncells)\
.def("levelset", &zigzag::ZigzagFiltration<CpxT, T>::levelset)\
.def("vals", [](zigzag::ZigzagFiltration<CpxT, T>& F){ return F.vals(); })\
.def("vals", [](zigzag::ZigzagFiltration<CpxT, T>& F, size_t k){ return F.vals(k); });\
m.def("ZigzagBarcode", [](zigzag::ZigzagFiltration<CpxT, T>& F, size_t maxdim, F2){return zigzag::barcode(F, maxdim, F2(), no_optimization_flag(), standard_reduction_flag()); });\
m.def("ZigzagBarcode", [](zigzag::ZigzagFiltration<CpxT, T>& F, size_t maxdim, F2, extra_reduction_flag){return zigzag::barcode(F, maxdim, F2(), no_optimization_flag(), extra_reduction_flag()); });\
m.def("zigzag_levelsets", [](zigzag::ZigzagFiltration<CpxT, T>& X, T eps, T t0, T t1){return zigzag_levelsets(X, eps, t0, t1);});

#define SimplicialCpxInterface(T, name) py::class_<T>(m, name)\
	.def(py::init<>())\
	.def(py::init<size_t, size_t>())\
	.def("maxdim", &T::maxdim, "maximum dimension simplex")\
	.def("ncells", py::overload_cast<>(&T::ncells, py::const_), "number of cells")\
	.def("ncells", py::overload_cast<const size_t>(&T::ncells, py::const_), "number of cells in given dimension")\
	.def("add", [](T& X, std::vector<size_t>& s){return X.add(s);}, "add simplex")\
	.def("add_recursive", [](T& X, std::vector<size_t>& s){return X.add_recursive(s);}, "add simplex and missing faces")\
	.def("find_idx", [](const T& X, const std::vector<size_t>& s){return X.find_idx(s);})\
	.def("boundary", &T::boundary_csc)\
	.def("get_simplex", [](T& X, size_t dim, size_t i){return X.get_simplex(dim, i);})\
	.def("get_simplices", py::overload_cast<const size_t>(&T::get_simplices, py::const_), "Returns a list of all simplices in given dimension.")\
	.def("get_simplices", py::overload_cast<>(&T::get_simplices, py::const_), "Returns a list of all simplices.");


#define Update_infoInterface(T, CpxT, name) py::class_<Update_info<Filtration<T, CpxT>>>(m, name) \
	.def(py::init<const Filtration<T, CpxT>&, const Filtration<T, CpxT>&>())\
	.def("filtered_info", &Update_info<Filtration<T, CpxT>>::filtered_info, "if the cells in filtration are not sorted by their filtration values, we find filtered updating information")

PYBIND11_MODULE(complex, m) {

    py::class_<cell_ind>(m, "cell_ind")
        .def(py::init<>())
        .def(py::init<size_t, size_t>())
        .def("__str__", &cell_ind::str);

    py::class_<CellComplex>(m, "CellComplex")
        .def(py::init<>())
        .def("maxdim", &CellComplex::maxdim, "maximum dimension cell")
        .def("ncells", py::overload_cast<>(&CellComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&CellComplex::ncells, py::const_), "number of cells in given dimension")
		.def("add_vertex", &CellComplex::add_vertex, "add vertex to cell complex")
		.def("add_vertices", &CellComplex::add_vertices, "add vertices to cell complex")
        .def("add", (size_t (CellComplex::*)(const std::vector<size_t>&, const std::vector<int>&, size_t))( &CellComplex::add ), "add cell in dimension k by specifying boundary and coefficients.")
        .def("boundary", &CellComplex::boundary_csc);

	SimplicialCpxInterface(SimplicialComplex, "SimplicialComplex")
	SimplicialCpxInterface(DefaultLightSimplicialComplex, "LightSimplicialComplex")

	m.def("TriangulatedProduct", [](const SimplicialComplex &X, const SimplicialComplex& Y){ return TriangulatedProduct(X, Y);} );

    py::class_<CubicalComplex>(m, "CubicalComplex")
        .def(py::init<>())
        .def(py::init<size_t>())
        .def("maxdim", &CubicalComplex::maxdim, "maximum dimension cube")
        .def("ncells", py::overload_cast<>(&CubicalComplex::ncells, py::const_), "number of cells")
        .def("ncells", py::overload_cast<const size_t>(&CubicalComplex::ncells, py::const_), "number of cells in given dimension")
        .def("add", (cell_ind (CubicalComplex::*)(std::vector<size_t>&))( &CubicalComplex::add ), "add cube")
        .def("add_recursive", (std::vector<cell_ind> (CubicalComplex::*)(const std::vector<size_t>&))( &CubicalComplex::add_recursive ), "add cube as well as faces")
        .def("find_idx", py::overload_cast<const std::vector<size_t> &>(&CubicalComplex::find_idx))
        .def("boundary", &CubicalComplex::boundary_csc, "integer boundary matrix")
        .def("skeleton", &CubicalComplex::skeleton, "k-skeleton of complex")
        .def("get_cube", py::overload_cast<size_t, size_t>(&CubicalComplex::get_cube, py::const_), "get cube in given dimension")
        .def("load_cubes", &CubicalComplex::load_cubes, "load cubes from a csv file.")
        .def("get_cubes", py::overload_cast<const size_t>(&CubicalComplex::get_cubes, py::const_), "Returns a list of all cubes in given dimension.")
        .def("get_cubes", py::overload_cast<>(&CubicalComplex::get_cubes, py::const_), "Returns a list of all cubes.");



    FilteredComplexInterface(double, SimplicialComplex, "FilteredSimplicialComplex");
	FilteredComplexInterface(double, DefaultLightSimplicialComplex, "FilteredLightSimplicialComplex");
	FilteredComplexInterface(double, CubicalComplex, "FilteredCubicalComplex")\
	.def(py::init<size_t>());

	// Zigzag barcodes
	ZigzagComplexInterface(double, CubicalComplex, "ZigzagCubicalComplex")
	ZigzagComplexInterface(double, SimplicialComplex, "ZigzagSimplicialComplex")
	m.def("extend_zigzag_filtration", [](std::vector<double>& f0, SimplicialComplex& X, double eps){return zigzag::extend_zigzag_filtration(f0, X, eps); });
	m.def("zigzag_toplex", [](std::vector<std::vector<std::vector<double>>>& img){return zigzag_toplex(img);});


    py::class_<CellularMap>(m, "CellularMap")
        .def(py::init<>())
        .def(py::init<size_t>())
		.def(py::init<SimplicialComplex, SimplicialComplex>())
		.def(py::init<DefaultLightSimplicialComplex, DefaultLightSimplicialComplex>())
		.def(py::init<CubicalComplex, CubicalComplex>())
        .def("__getitem__", py::overload_cast<size_t>(&CellularMap::operator[], py::const_))\
        .def("__setitem__", [](CellularMap &M, size_t k, ColumnMatrix<VInt> &A){return M[k] = A;} );
	m.def("IdentityMap", (CellularMap (*)(const SimplicialComplex &))(&CellularMap::identity));

	m.def("SimplicialMap", [](const SimplicialComplex& X, const SimplicialComplex& Y){return SimplicialMap(X, Y);}, "Inclusion map of simplicial complexes");
	m.def("SimplicialMap", [](const SimplicialComplex& X, const SimplicialComplex& Y, const std::vector<size_t>& f){return SimplicialMap(X, Y, f);}, "simplicial map extended from function on vertices");
    m.def("CubicalMap", &CubicalMap);

	Update_infoInterface(double, SimplicialComplex, "UpdateInfoFiltration");
	Update_infoInterface(double, DefaultLightSimplicialComplex, "UpdateInfoLightFiltration");


	// Filtration extension
	m.def("lower_star_filtration", [](const SimplicialComplex& X, std::vector<double>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const DefaultLightSimplicialComplex& X, std::vector<double>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const CubicalComplex& X, std::vector<std::vector<double>>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const CubicalComplex& X, std::vector<std::vector<std::vector<double>>>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");


}
