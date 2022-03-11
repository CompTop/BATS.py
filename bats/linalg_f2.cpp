#include "pybats.hpp"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;
using namespace bats;

// interface of common functions between F2 and other modP
#define BasicFieldInterface(F, name) py::class_<F>(m, name)\
.def(py::init<>())\
.def(py::init<int>())\
.def("to_int", &F::to_int, "convert to integer.")\
.def("__add__", &F::operator+)\
.def("__mul__", &F::operator*)\
.def("__sub__", py::overload_cast<const F&>(&F::operator-, py::const_))\
.def("__truediv__", &F::operator/)\
.def("__repr__", &F::str)\
.def("__str__", &F::str)

// interface for everything other than F2
#define FieldInterface(F, name) BasicFieldInterface(F, name)\
.def("__neg__", py::overload_cast<>(&F::operator-, py::const_));

#define SparseVectorInterface(F, name) py::class_<SparseVector<F, size_t>>(m, name)\
.def(py::init<>())\
.def(py::init<const std::vector<size_t>&, const std::vector<F>&>())\
.def(py::init<const std::vector<std::tuple<size_t, int>>&>(), "construct from a list of index-value tuples")\
.def("nzinds", &SparseVector<F, size_t>::nzinds)\
.def("nzvals", &SparseVector<F, size_t>::nzvals)\
.def("nnz", &SparseVector<F, size_t>::nnz, "number of non-zeros")\
.def("nzs", &SparseVector<F, size_t>::nzs, "tuple of lists: non-zero indices, and non-zero values")\
.def("permute", &SparseVector<F, size_t>::permute, "permute the indices")\
.def("sort", &SparseVector<F, size_t>::sort, "put non-zeros in sorted order")\
.def("__getitem__", py::overload_cast<size_t>(&SparseVector<F, size_t>::getval, py::const_))\
.def("__str__", &SparseVector<F, size_t>::str);
// .def("__getitem__", (F (SparseVector<F, size_t>::*)(size_t))(&SparseVector<F, size_t>::operator[]))

#define ColumnMatrixInterface(VT, name) py::class_<ColumnMatrix<VT>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t>())\
.def(py::init<size_t, size_t, std::vector<VT>&>())\
.def(py::init<const CSCMatrix<int, size_t> &>())\
.def("nrow", &ColumnMatrix<VT>::nrow, "number of rows.")\
.def("ncol", &ColumnMatrix<VT>::ncol, "number of columns.")\
.def("tolist", &ColumnMatrix<VT>::to_row_array, "return as C-style array")\
.def("T", &ColumnMatrix<VT>::T, "transpose")\
.def("permute_rows", &ColumnMatrix<VT>::permute_rows, "permute rows")\
.def("permute_cols", &ColumnMatrix<VT>::permute_cols, "permute columns")\
.def("append_column", [](ColumnMatrix<VT>& A, VT& v){A.append_column(v);}, "appends column")\
.def("nnz", [](ColumnMatrix<VT>& A){return A.nnz();}, "number of non-zeros")\
.def("__str__", &ColumnMatrix<VT>::str)\
.def("__mul__", py::overload_cast<const VT &>(&ColumnMatrix<VT>::operator*, py::const_))\
.def("__mul__", py::overload_cast<const ColumnMatrix<VT> &>(&ColumnMatrix<VT>::operator*, py::const_))\
.def("__getitem__", py::overload_cast<size_t>(&ColumnMatrix<VT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ColumnMatrix<VT>::operator[]))\
.def("__call__", &ColumnMatrix<VT>::operator());\
m.def("Mat", [](const CSCMatrix<int, size_t> &A, VT::val_type) { return ColumnMatrix<VT>(A); });\
m.def("Identity", [](size_t n, VT::val_type) { return ColumnMatrix<VT>::identity(n); });\
m.def("reduce_matrix", [](ColumnMatrix<VT>& A){ return reduce_matrix(A); });\
m.def("reduce_matrix", [](ColumnMatrix<VT>& A, bats::extra_reduction_flag f){ return reduce_matrix(A, f); });\
m.def("reduce_matrix", [](ColumnMatrix<VT>& A, ColumnMatrix<VT>& U){ return reduce_matrix(A, U); });\
m.def("reduce_matrix", [](ColumnMatrix<VT>& A, ColumnMatrix<VT>& U, bats::extra_reduction_flag f){ return reduce_matrix(A, U, f); });

// add factorizations if matrix is over a field
#define ColumnMatrixInterfaceField(VT, name) \
ColumnMatrixInterface(VT, name) \
m.def("LQU", [](const ColumnMatrix<VT> &A) { auto F = LQU(A); return std::make_tuple(F.L, F.E, F.U); }, "LQU factorization");\
m.def("LEUP", [](const ColumnMatrix<VT> &A) { auto F = LEUP(A); return std::make_tuple(F.L, F.E, F.U, F.P); }, "LEUP factorization");\
m.def("PLEU", [](const ColumnMatrix<VT> &A) { auto F = PLEU(A); return std::make_tuple(F.P, F.L, F.E, F.U); }, "PLEU factorization");\
m.def("UELP", [](const ColumnMatrix<VT> &A) { auto F = UELP(A); return std::make_tuple(F.U, F.E, F.L, F.P); }, "UELP factorization");\
m.def("PUEL", [](const ColumnMatrix<VT> &A) { auto F = PUEL(A); return std::make_tuple(F.P, F.U, F.E, F.L); }, "PUEL factorization");\
m.def("EL_L_commute", [](const ColumnMatrix<VT> &E, const ColumnMatrix<VT> &L) { return EL_L_commute(E, L); }, "E_L, L commutation");\
m.def("L_EL_commute", [](const ColumnMatrix<VT> &L, const ColumnMatrix<VT> &EL) { return L_EL_commute(L, EL); }, "L, E_L commutation");\
m.def("U_EU_commute", [](const ColumnMatrix<VT> &U, const ColumnMatrix<VT> &EU) { return U_EU_commute(U, EU); }, "U, E_U commutation");\
m.def("EU_U_commute", [](const ColumnMatrix<VT> &EU, const ColumnMatrix<VT> &U) { return EU_U_commute(EU, U); }, "E_U, U commutation");

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


#define FilteredChainComplexInterface(T, MT, name) py::class_<FilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const Filtration<T, SimplicialComplex>&>())\
.def(py::init<const Filtration<T, DefaultLightSimplicialComplex>&>())\
.def(py::init<const Filtration<T, CubicalComplex>&>())\
.def("val", [](FilteredChainComplex<T, MT>& C) {return C.val;}, "filtration values.")\
.def("perm", [](FilteredChainComplex<T, MT>& C) {return C.perm;}, "permutation from original order")\
.def("update_filtration", &FilteredChainComplex<T, MT>::update_filtration, "update filtration with new values")\
.def("update_filtration_general", &FilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, SimplicialComplex>>>, "general update Filtered Chain Complex with updating information")\
.def("update_filtration_general", &FilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, DefaultLightSimplicialComplex>>>, "general update Filtered Chain Complex with updating information");





#define PersistencePairInterface(T, name) py::class_<PersistencePair<T>>(m, name)\
.def(py::init<>())\
.def(py::init<size_t, size_t, size_t, T, T>(), "initialize with hdim, birth_ind, death_ind, birth, death.")\
.def("dim", &PersistencePair<T>::get_dim)\
.def("birth_ind", &PersistencePair<T>::get_birth_ind)\
.def("death_ind", &PersistencePair<T>::get_death_ind)\
.def("birth", &PersistencePair<T>::get_birth)\
.def("death", &PersistencePair<T>::get_death)\
.def("length", &PersistencePair<T>::length)\
.def("mid", &PersistencePair<T>::mid)\
.def("__str__", &PersistencePair<T>::str);

#define ZigzagPairInterface(T, name) py::class_<zigzag::ZigzagPair<T>>(m, name)\
.def(py::init<>())\
.def("dim", &zigzag::ZigzagPair<T>::get_dim)\
.def("birth_ind", &zigzag::ZigzagPair<T>::get_birth_ind)\
.def("death_ind", &zigzag::ZigzagPair<T>::get_death_ind)\
.def("birth", &zigzag::ZigzagPair<T>::get_birth)\
.def("death", &zigzag::ZigzagPair<T>::get_death)\
.def("length", &zigzag::ZigzagPair<T>::length)\
.def("mid", &zigzag::ZigzagPair<T>::mid)\
.def("__str__", &zigzag::ZigzagPair<T>::str);

#define FlagInterface(T, name) py::class_<T>(m, name) \
	.def(py::init<>());


PYBIND11_MODULE(linalg_f2, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

	#ifdef BATS_OPCOUNT
	m.def("reset_field_ops", [](){bats::field_ops = 0; return;}, "Set global counter for field operations to be zero.");
	m.def("get_field_ops", [](){return bats::field_ops;}, "return global counter of field operations.");
	m.def("reset_column_ops", [](){bats::column_ops = 0; return;}, "Set global counter for column operations to be zero");
	m.def("get_column_ops", [](){return bats::column_ops;}, "return global counter of column operations");
	#endif

	BasicFieldInterface(F2, "F2")
        .def("__neg__", py::overload_cast<>(&F2::operator-));

    SparseVectorInterface(F2, "F2Vector")

	ColumnMatrixInterfaceField(V2, "F2Mat")

	ChainComplexInterface(M2, "F2ChainComplex")

	ChainMapInterface(m, M2, "F2ChainMap")

	ReducedChainComplexInterface(M2, "ReducedF2ChainComplex")

	DGVectorSpaceInterface(M2, "F2DGVectorSpace")
	DGLinearMapInterface(m, M2, "F2DGLinearMap")
	ReducedDGVectorSpaceInterface(M2, "ReducedF2DGVectorSpace")
	FilteredDGVectorSpaceInterface(double, M2, "FilteredF2DGVectorSpace")
	ReducedFilteredDGVectorSpaceInterface(double, M2, "ReducedFilteredF2DGVectorSpace")

	FilteredChainComplexInterface(double, M2, "FilteredF2ChainComplex")

	ReducedFilteredChainComplexInterface(double, M2, "ReducedFilteredF2ChainComplex")

	DiagramInterface(F2ChainComplex, F2ChainMap, "F2ChainDiagram")
	DiagramInterface(ReducedF2ChainComplex, M2, "F2HomDiagram")
	DiagramInterface(ReducedF2ChainComplex, std::vector<M2>, "F2HomDiagramAll")
	DiagramInterface(F2DGVectorSpace, F2DGLinearMap, "F2DGLinearDiagram")
	DiagramInterface(ReducedF2DGVectorSpace, M2, "F2DGHomDiagram")
	DiagramInterface(ReducedF2DGVectorSpace, std::vector<M2>, "F2DGHomDiagramAll")
	DiagramInterface(size_t, M2, "F2Diagram")

}
