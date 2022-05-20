#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;

// ReducedFilteredChainComplex for field type T
#define AutoReducedChainComplexInterface(T) \
{\
	using VT = SparseVector<T, size_t>;\
	using MT = ColumnMatrix<VT>;\
	m.def("ReducedChainComplex", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::standard_reduction_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::extra_reduction_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::extra_reduction_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::extra_reduction_flag, bats::clearing_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::extra_reduction_flag, bats::compression_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const SimplicialComplex&, T, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("ReducedChainComplex", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::standard_reduction_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::extra_reduction_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::extra_reduction_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::extra_reduction_flag, bats::clearing_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::extra_reduction_flag, bats::compression_flag))(&__ReducedChainComplex));\
	m.def("reduce", (ReducedChainComplex<MT> (*)(const DefaultLightSimplicialComplex&, T, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedChainComplex));\
	m.def("reduce", [](const ChainComplex<MT>& C) {return ReducedChainComplex(C); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::standard_reduction_flag) {return ReducedChainComplex(C, bats::standard_reduction_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::standard_reduction_flag, bats::compute_basis_flag) {return ReducedChainComplex(C, bats::standard_reduction_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::standard_reduction_flag, bats::clearing_flag) {return ReducedChainComplex(C, bats::standard_reduction_flag(), bats::clearing_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::standard_reduction_flag, bats::compression_flag) {return ReducedChainComplex(C, bats::standard_reduction_flag(), bats::compression_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag) {return ReducedChainComplex(C, bats::standard_reduction_flag(), bats::compression_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::extra_reduction_flag) {return ReducedChainComplex(C, bats::extra_reduction_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::extra_reduction_flag, bats::compute_basis_flag) {return ReducedChainComplex(C, bats::extra_reduction_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::extra_reduction_flag, bats::clearing_flag) {return ReducedChainComplex(C, bats::extra_reduction_flag(), bats::clearing_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::extra_reduction_flag, bats::compression_flag) {return ReducedChainComplex(C, bats::extra_reduction_flag(), bats::compression_flag()); });\
	m.def("reduce", [](const ChainComplex<MT>& C, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag) {return ReducedChainComplex(C, bats::extra_reduction_flag(), bats::compression_flag(), bats::compute_basis_flag()); });\
}

// ReducedFilteredChainComplex for field type T
#define AutoReducedFilteredChainComplexInterface(T) \
{\
	using VT = SparseVector<T, size_t>;\
	using MT = ColumnMatrix<VT>;\
	m.def("ReducedFilteredChainComplex", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::clearing_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("ReducedFilteredChainComplex", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::extra_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::extra_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::extra_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("ReducedFilteredChainComplex", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T, bats::standard_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, CubicalComplex>&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C) {return ReducedFilteredChainComplex(C); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::standard_reduction_flag) {return ReducedFilteredChainComplex(C, bats::standard_reduction_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::standard_reduction_flag, bats::compute_basis_flag) {return ReducedFilteredChainComplex(C, bats::standard_reduction_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::standard_reduction_flag, bats::clearing_flag) {return ReducedFilteredChainComplex(C, bats::standard_reduction_flag(), bats::clearing_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::standard_reduction_flag, bats::compression_flag) {return ReducedFilteredChainComplex(C, bats::standard_reduction_flag(), bats::compression_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag) {return ReducedFilteredChainComplex(C, bats::standard_reduction_flag(), bats::compression_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::extra_reduction_flag) {return ReducedFilteredChainComplex(C, bats::extra_reduction_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::extra_reduction_flag, bats::compute_basis_flag) {return ReducedFilteredChainComplex(C, bats::extra_reduction_flag(), bats::compute_basis_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::extra_reduction_flag, bats::clearing_flag) {return ReducedFilteredChainComplex(C, bats::extra_reduction_flag(), bats::clearing_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::extra_reduction_flag, bats::compression_flag) {return ReducedFilteredChainComplex(C, bats::extra_reduction_flag(), bats::compression_flag()); });\
	m.def("reduce", [](const FilteredChainComplex<double, MT>& C, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag) {return ReducedFilteredChainComplex(C, bats::extra_reduction_flag(), bats::compression_flag(), bats::compute_basis_flag()); });\
}



#define ChainFunctorInterface(MT, DT, name)\
m.def(name, [](const DT& diag) {return ChainFunctor<MT>(diag);});\
m.def("ChainFunctor", [](const DT& diag, typename MT::val_type) {return ChainFunctor(diag, typename MT::val_type());});

#define DGLinearFunctorInterface(MT, DT, name) m.def(name, &(DGLinearFunctor<MT, DT>));

#define AutoChainFunctorInterface(DT, FT) \
m.def("Chain", (Diagram<ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>, ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>> (*)(const DT&, FT))(&__ChainFunctor)); \

#define SimpleChainFunctorInterface(m, FT) \
m.def("Chain", [](const CellularMap & A, FT) { return ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>(A); });\
m.def("Chain", [](const CellularMap & f, const SimplicialComplex &X, const SimplicialComplex &A, const SimplicialComplex &Y, const SimplicialComplex &B, FT) { return ChainMap<ColumnMatrix<SparseVector<FT, size_t>>>(f, X, A, Y, B); });\
m.def("Chain", [](const SimplicialComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });\
m.def("Chain", [](const SimplicialComplex &X, const SimplicialComplex &A, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X, A); });\
m.def("Chain", [](const CubicalComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });\
m.def("Chain", [](const CellComplex &X, FT) {return ChainComplex<ColumnMatrix<SparseVector<FT, size_t>>>(X); });


#define BarcodeInterface(NT, MT) \
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim){return barcode(D, hdim); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::divide_conquer){return barcode(D, hdim, flags::divide_conquer()); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::rightward){return barcode(D, hdim, flags::rightward()); });\
m.def("barcode", [](const Diagram<NT, MT>& D, size_t hdim, flags::leftward){return barcode(D, hdim, flags::leftward()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D){return barcode(D); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::divide_conquer){return barcode(D, flags::divide_conquer()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::rightward){return barcode(D, flags::rightward()); });\
m.def("barcode", [](const Diagram<NT, std::vector<MT>>& D, flags::leftward){return barcode(D, flags::leftward()); });



#define HomFunctorInterface(MT, name) \
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D) {return Hom(D);});\
m.def(name, [](const Diagram<ChainComplex<MT>, ChainMap<MT>> &D, bool topd) {return Hom(D, topd);});\
m.def(name, [](const Diagram<DGVectorSpace<MT>, DGLinearMap<MT>> &D, size_t k) {return Hom(D, k);});\
m.def(name, [](const Diagram<DGVectorSpace<MT>, DGLinearMap<MT>> &D) {return Hom(D);});\
m.def(name, [](const Diagram<DGVectorSpace<MT>, DGLinearMap<MT>> &D, bool topd) {return Hom(D, topd);});\
BarcodeInterface(ReducedChainComplex<MT>, MT)\
BarcodeInterface(ReducedDGVectorSpace<MT>, MT)\
BarcodeInterface(size_t, MT)

PYBIND11_MODULE(linalg_auto, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

		AutoReducedChainComplexInterface(F2)
		AutoReducedChainComplexInterface(F3)

		AutoReducedFilteredChainComplexInterface(F2)
		AutoReducedFilteredChainComplexInterface(F3)

		m.def("union_find_pairs", [](FilteredChainComplex<double, M2> &X){ return union_find_pairs(X); });
		m.def("union_find_pairs", [](FilteredChainComplex<double, M3> &X){ return union_find_pairs(X); });
		m.def("rips_union_find_pairs", &rips_union_find_pairs<double>, "find Rips pairs");

		ChainFunctorInterface(M2, SimplicialComplexDiagram, "F2Chain")
		DGLinearFunctorInterface(M2, SimplicialComplexDiagram, "F2DGLinearFunctor")
		InducedMapInterface(m, M2)

		ChainFunctorInterface(M3, SimplicialComplexDiagram, "F3Chain")
		DGLinearFunctorInterface(M3, CubicalComplexDiagram, "F3DGLinearFunctor")
		InducedMapInterface(m, M3)

		AutoChainFunctorInterface(SimplicialComplexDiagram, F2)
		AutoChainFunctorInterface(CubicalComplexDiagram, F2)
		AutoChainFunctorInterface(CellComplexDiagram, F2)
		SimpleChainFunctorInterface(m, F2)
		HomFunctorInterface(M2, "Hom")

		AutoChainFunctorInterface(SimplicialComplexDiagram, F3)
		AutoChainFunctorInterface(CubicalComplexDiagram, F3)
		AutoChainFunctorInterface(CellComplexDiagram, F3)
		SimpleChainFunctorInterface(m, F3)
		HomFunctorInterface(M3, "Hom")

		m.def("RipsHom", [](SetDiagram& D, DataSet<double>& X, Euclidean& M, std::vector<double>& rmax, size_t hdim, F2) {return RipsHom(D, X, M, rmax, hdim, F2()); });
}
