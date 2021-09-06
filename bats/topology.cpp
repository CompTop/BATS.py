#include "pybats.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


namespace py = pybind11;
using namespace bats;

#define FilteredComplexInterface(T, CpxT, name) \
m.def("Filtration", [](CpxT& X, std::vector<std::vector<T>>& vals) {return Filtration<T, CpxT>(X, vals);});\
py::class_<Filtration<T, CpxT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CpxT&, const std::vector<std::vector<T>>& >())\
.def("add", (cell_ind (Filtration<T, CpxT>::*)(T, std::vector<size_t>&))(&Filtration<T, CpxT>::add))\
.def("add_recursive", [](Filtration<T, CpxT> &F, T t, std::vector<size_t>& s){return F.add_recursive(t, s);})\
.def("complex", &Filtration<T, CpxT>::complex)\
.def("maxdim", &Filtration<T, CpxT>::maxdim)\
.def("ncells", &Filtration<T, CpxT>::ncells)\
.def("sublevelset", &Filtration<T, CpxT>::sublevelset)\
.def("update_filtration", &Filtration<T, CpxT>::update_filtration)\
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

#define MetricInterface(M, name) py::class_<M>(m, name)\
.def(py::init<>())\
.def("__call__", (Matrix<double> (M::*)(const DataSet<double>&, const DataSet<double>&) const)(&M::operator()), "returns Matrix of pairwise distances");


#define FilteredEdgeInterface(T, name) py::class_<filtered_edge<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, T>());

// define filtration interfaces for metric
#define FiltrationInterface(M) \
m.def("RipsFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const M&, double, size_t))(&RipsFiltration));\
m.def("LightRipsFiltration", (Filtration<double, DefaultLightSimplicialComplex> (*)(const DataSet<double>&, const M&, double, size_t))(&RipsFiltration));\
m.def("RipsCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const bats::Cover&, const M&, double, size_t))(&RipsFiltration));\
m.def("DowkerFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const M&, double, size_t))(&DowkerFiltration));\
m.def("DowkerCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const M&, const bats::Cover&, double, size_t))(&DowkerFiltration));\
m.def("RipsFiltration_extension", [](const DataSet<double>& X, const M& dist, double rmax,  size_t dmax) {return RipsFiltration_extension<SimplicialComplex>(X, dist, rmax, dmax);}, "Rips Filtration with inverse map returned");\
m.def("LightRipsFiltration_extension", [](const DataSet<double>& X, const M& dist, double rmax,  size_t dmax) {return RipsFiltration_extension<DefaultLightSimplicialComplex>(X, dist, rmax, dmax);}, "Rips Filtration with inverse map returned");

// define landmark interfaces for metric
#define LandmarkInterface(M) \
m.def("greedy_landmarks", (DataSet<double> (*)(const DataSet<double>&, const size_t, const M&, const size_t))(&greedy_landmarks));\
m.def("hausdorff_landmarks", (DataSet<double> (*)(const DataSet<double>&, const double, const M&, const size_t))(&hausdorff_landmarks));\
m.def("landmark_cover", (bats::Cover (*)(const DataSet<double>&, const DataSet<double>&, const M&, const size_t))(&landmark_cover));\
m.def("landmark_eps_cover", (bats::Cover (*)(const DataSet<double>&, const DataSet<double>&, const M&, double))(&landmark_eps_cover));\
m.def("approx_center", (size_t (*)(const DataSet<double>&, const M&, size_t, size_t))(&approx_center));\
m.def("greedy_landmarks_hausdorff", (std::tuple<std::vector<size_t>, std::vector<double>> (*)(const DataSet<double>&, const M&, const size_t))(&greedy_landmarks_hausdorff));
// m.def("approx_center", (size_t (*)(const DataSet<double>&, const M&, size_t))(&approx_center));
// m.def("approx_center", (size_t (*)(const DataSet<double>&, const M&))(&approx_center), "Find index approximately in the center using an iterative landmarking procedure.");

// define discrete morozov zigzag interfaces for metric
#define ZZZooInterface(M) \
m.def("DiscreteMorozovZigzag", \
	(std::tuple<SimplicialComplexDiagram, std::vector<double>> (*)(const DataSet<double>&, const M&, double, size_t))(&DiscreteMorozovZigzag), \
	"discrete Morozov Zigzag (dM-ZZ) construction." \
);\
m.def("DiscreteMorozovZigzagSets", \
	(std::tuple<Diagram<std::set<size_t>, std::vector<size_t>>, std::vector<double>> (*)(const DataSet<double>&, const M&, double))(&DiscreteMorozovZigzagSets), \
	"SetDiagram for discrete Morozov Zigzag (dM-ZZ) construction." \
);\
m.def("OscillatingRipsZigzagSets",\
	[](const DataSet<double>& X, const M& dist, double rho, double eps) {return OscillatingRipsZigzagSets(X, dist, rho, eps);}, \
	"SetDiagram for Oscillating Rips Zigzag constrution."\
);

// define RipsComplex interface
#define RipsInterface(M) \
m.def("RipsComplex",\
	(SimplicialComplex (*)(const DataSet<double>&, const M&, double, size_t))(&RipsComplex), \
	"Rips Complex constructed from data set and metric." \
);


#define MetricInterfaceAll(M, name) \
MetricInterface(M, name)\
FiltrationInterface(M)\
LandmarkInterface(M)\
ZZZooInterface(M)\
RipsInterface(M)

#define FreudenthalInterface(name, CpxT) \
m.def(name, [](size_t m, size_t n){return Freudenthal<CpxT>(m,n);});\
m.def(name, [](size_t n1, size_t n2, size_t n3){return Freudenthal<CpxT>(n1,n2,n3);});\
m.def(name, [](size_t n1, size_t n2, size_t n3, size_t i0, size_t i1, size_t j0, size_t j1, size_t k0, size_t k1){return Freudenthal<CpxT>(n1, n2, n3, i0, i1, j0, j1, k0, k1);});\
m.def(name, [](CubicalComplex& X, size_t n1, size_t n2, size_t n3){return Freudenthal<CpxT>(X, n1, n2, n3);});


PYBIND11_MODULE(topology, m) {

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
	m.def("lower_star_backwards", [](
		const std::vector<std::vector<double>>& grad_dgms,
    	const std::vector<std::vector<int>>& bdinds,
    	const std::vector<std::vector<size_t>>& imap) {return lower_star_backwards(grad_dgms, bdinds, imap); }, "compute gradient on function from gradient on lower star filtration diagram");

	MetricInterfaceAll(Euclidean, "Euclidean")
	MetricInterfaceAll(L1Dist, "L1Dist")
	MetricInterfaceAll(LInfDist, "LInfDist")
	MetricInterfaceAll(CosineDist, "CosineDist")
	MetricInterfaceAll(RPCosineDist, "RPCosineDist")
	MetricInterfaceAll(AngleDist, "AngleDist")
	MetricInterfaceAll(RPAngleDist, "RPAngleDist")

	m.def("enclosing_radius",
		[](const Matrix<double>& M){return enclosing_radius(M);},
		"Enclosing radius from matrix of pairwise distances"
	);

	FilteredEdgeInterface(double, "FilteredEdge")

	m.def("bivariate_cover", &bivariate_cover);

	// RipsFiltration on distance matrix
	m.def("RipsFiltration",
		[](const Matrix<double>& M, double r, size_t k){return RipsFiltration<SimplicialComplex>(M, r, k);},
		"Rips Filtration using built using pairwise distances."
	);
	// RipsFiltration on distance matrix
	m.def("LightRipsFiltration",
		[](const Matrix<double>& M, double r, size_t k){return RipsFiltration<DefaultLightSimplicialComplex>(M, r, k);},
		"Rips Filtration using built using pairwise distances."
	);

	// RipsFiltration on distance matrix
	m.def("RipsFiltration_extension",
		[](const Matrix<double>& M, double r, size_t k){return RipsFiltration_extension<SimplicialComplex>(M, r, k);},
		"Rips Filtration built using pairwise distances Rips with inverse map returned."
	);
	// RipsFiltration on distance matrix
	m.def("LightRipsFiltration_extension",
		[](const Matrix<double>& M, double r, size_t k){return RipsFiltration_extension<DefaultLightSimplicialComplex>(M, r, k);},
		"Rips Filtration built using pairwise distances with inverse map returned."
	);

	m.def("RipsComplex",
		[](const Matrix<double>& M, double r, size_t k){ return RipsComplex<SimplicialComplex>(M, r, k);},
		"Rips Complex constructed from pairwise distances."
	);
	m.def("LightRipsComplex",
		[](const Matrix<double>& M, double r, size_t k){ return RipsComplex<DefaultLightSimplicialComplex>(M, r, k);},
		"Rips Complex constructed from pairwise distances."
	);

	m.def("FlagComplex",
		[](const std::vector<size_t> &edges, const size_t n, const size_t maxdim) {return FlagComplex<SimplicialComplex>(edges, n, maxdim);},
		"Flag complex constructed from a (flattened) list of edges."
	);
	m.def("LightFlagComplex",
		[](const std::vector<size_t> &edges, const size_t n, const size_t maxdim) {return FlagComplex<DefaultLightSimplicialComplex>(edges, n, maxdim);},
		"Flag complex constructed from a (flattened) list of edges."
	);



	// m.def("FlagFiltration", (Filtration<double, SimplicialComplex> (*)(std::vector<filtered_edge<double>>&, const size_t, const size_t, const double))(&FlagFiltration));
	m.def("WitnessFiltration", (Filtration<double, SimplicialComplex> (*)(const DataSet<double>&, const DataSet<double>&, const Euclidean&, double, size_t))(&WitnessFiltration));
	m.def("DowkerFiltration", (Filtration<double, SimplicialComplex> (*)(const Matrix<double>&, double, size_t))(&DowkerFiltration));
	m.def("DowkerCoverFiltration", (Filtration<double, SimplicialComplex> (*)(const Matrix<double>&, const bats::Cover&, double, size_t))(&DowkerFiltration));

	m.def("Nerve", (SimplicialComplex (*)(const bats::Cover&, const size_t))(&Nerve));

	m.def("random_landmarks", (DataSet<double> (*)(const DataSet<double>&, const size_t))(&random_landmarks));
	m.def("greedy_landmarks_hausdorff", (std::tuple<std::vector<size_t>, std::vector<double>> (*)(const Matrix<double>&, const size_t))(&greedy_landmarks_hausdorff));

	m.def("sample_sphere", (DataSet<double> (*)(const size_t, const size_t))(&sample_sphere));
	m.def("force_repel_rp", (void (*)(DataSet<double>&, double))(&force_repel_rp));

	// demo extra
	m.def("SierpinskiDiagram",
		&serpinski_diagram,
		"Diagram of Sierpinski triangle iterations."
	);

	// Freudenthal constructions
	FreudenthalInterface("Freudenthal", SimplicialComplex)
	FreudenthalInterface("LightFreudenthal", DefaultLightSimplicialComplex)
	// Cubes
	m.def("Cube", [](size_t m, size_t n){return Cube(m,n);});\
	m.def("Cube", [](size_t n1, size_t n2, size_t n3){return Cube(n1,n2,n3);});\
	m.def("Cube", [](size_t n1, size_t n2, size_t n3, size_t i0, size_t i1, size_t j0, size_t j1, size_t k0, size_t k1){return Cube(n1, n2, n3, i0, i1, j0, j1, k0, k1);});

	DiagramInterface(bats::Cover, std::vector<size_t>, "CoverDiagram")
	DiagramInterface(std::set<size_t>, std::vector<size_t>, "SetDiagram")
	DiagramInterface(SimplicialComplex, CellularMap, "SimplicialComplexDiagram")
	DiagramInterface(CubicalComplex, CellularMap, "CubicalComplexDiagram")
	DiagramInterface(CellComplex, CellularMap, "CellComplexDiagram")



	// NerveFunctor
    m.def("NerveDiagram", py::overload_cast<const CoverDiagram&, const size_t>(&Nerve));

	// zigzag diagram of sets
	m.def("ZigzagSetDiagram", &linear_subset_union_diagram, "Create a zigzag diagram of sets and pairwise unions.");

	// Rips functor
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const double, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");
	m.def("Rips", (SimplicialComplexDiagram (*)(const SetDiagram&, const DataSet<double>&, const Euclidean&, const std::vector<double>&, const size_t))(&Rips), "Construct a diagram of Rips complexes from a SetDiagram.");

}
