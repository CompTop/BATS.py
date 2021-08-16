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

#define ChainComplexInterface(MT, name) py::class_<ChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const SimplicialComplex&>())\
.def(py::init<const DefaultLightSimplicialComplex&>())\
.def(py::init<const SimplicialComplex&, const SimplicialComplex&>(), "relative chain complex")\
.def(py::init<const CubicalComplex&>())\
.def("__getitem__", py::overload_cast<size_t>(&ChainComplex<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ChainComplex<MT>::operator[]))\
.def("maxdim", &ChainComplex<MT>::maxdim)\
.def("dim", [](const ChainComplex<MT>& C, size_t k){return C.dim(k);})\
.def("dim", [](const ChainComplex<MT>& C){return C.dim();})\
.def("clear_compress_apparent_pairs", &ChainComplex<MT>::clear_compress_apparent_pairs);

#define ChainMapInterface(m, MT, name) py::class_<ChainMap<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CellularMap&>())\
.def(py::init<const CellularMap&, const SimplicialComplex&, const SimplicialComplex&, const SimplicialComplex&, const SimplicialComplex&>(), "relative chain map")\
.def("__getitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<size_t>(&ChainMap<MT>::operator[]));

#define ReducedChainComplexInterface(MT, name) py::class_<ReducedChainComplex<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const ChainComplex<MT>&>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::clearing_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::standard_reduction_flag, bats::compression_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::clearing_flag>())\
.def(py::init<const ChainComplex<MT>&, bats::extra_reduction_flag, bats::compression_flag>())\
.def("__getitem__", &ReducedChainComplex<MT>::operator[]) \
.def("U", [](ReducedChainComplex<MT> &R, size_t k){return R.U[k];}, "basis matrix in specified dimension")\
.def("R", [](ReducedChainComplex<MT> &R, size_t k){return R.R[k];}, "reduced matrix in specified dimension")\
.def("hdim", &ReducedChainComplex<MT>::hdim)\
.def("get_preferred_representative", &ReducedChainComplex<MT>::get_preferred_representative, "get the preferred representative for homology class")\
.def("chain_preferred_representative", &ReducedChainComplex<MT>::chain_preferred_representative, "return the preferred representative of a chain")\
.def("find_preferred_representative", &ReducedChainComplex<MT>::find_preferred_representative)\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("to_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.to_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("from_hom_basis", [](const ReducedChainComplex<MT> &R, const MT::col_type &A, size_t k) {return R.from_hom_basis(A, k);})\
.def("maxdim", &ReducedChainComplex<MT>::maxdim);

#define DGVectorSpaceInterface(MT, name) py::class_<DGVectorSpace<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const SimplicialComplex&, int>())\
.def(py::init<const DefaultLightSimplicialComplex&, int>())\
.def(py::init<const CubicalComplex&, int>())\
.def("maxdim", &DGVectorSpace<MT>::maxdim);

#define DGLinearMapInterface(m, MT, name) py::class_<DGLinearMap<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const CellularMap&>())\
.def("__getitem__", py::overload_cast<ssize_t>(&DGLinearMap<MT>::operator[], py::const_))\
.def("__setitem__", py::overload_cast<ssize_t>(&DGLinearMap<MT>::operator[]));

#define ReducedDGVectorSpaceInterface(MT, name) py::class_<ReducedDGVectorSpace<MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const DGVectorSpace<MT>&>())\
.def("hdim", &ReducedDGVectorSpace<MT>::hdim)\
.def("maxdim", &ReducedDGVectorSpace<MT>::maxdim);

#define InducedMapInterface(m, MT) \
m.def("InducedMap",\
	(MT (*)(const ChainMap<MT> &, const ReducedChainComplex<MT> &, const ReducedChainComplex<MT>&, size_t))(&induced_map), \
	"Induced map on homology." \
);\
m.def("InducedMap",\
	(MT (*)(const DGLinearMap<MT> &, const ReducedDGVectorSpace<MT> &, const ReducedDGVectorSpace<MT>&, size_t))(&induced_map), \
	"Induced map on homology." \
);

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

#define ReducedFilteredChainComplexInterface(T, MT, name) py::class_<ReducedFilteredChainComplex<T, MT>>(m, name)\
.def(py::init<>())\
.def(py::init<const FilteredChainComplex<T, MT>&>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::clearing_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::standard_reduction_flag, bats::compression_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::compute_basis_flag>())\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::clearing_flag>())\
.def("nnz_U", &ReducedFilteredChainComplex<T, MT>::get_nnz_U, "get the number of non-zeros in U")\
.def("nnz_R", &ReducedFilteredChainComplex<T, MT>::get_nnz_R, "get the number of non-zeros in R")\
.def(py::init<const FilteredChainComplex<T, MT>&, bats::extra_reduction_flag, bats::compression_flag>())\
.def("reduced_complex", [](ReducedFilteredChainComplex<T, MT>& C){return C.RC;}, "underlying reduced complex")\
.def("val", [](ReducedFilteredChainComplex<T, MT>& C) {return C.val;}, "filtration values")\
.def("perm", [](ReducedFilteredChainComplex<T, MT>& C) {return C.perm;}, "permutation from original order")\
.def("dim", &ReducedFilteredChainComplex<T, MT>::dim)\
.def("maxdim", &ReducedFilteredChainComplex<T, MT>::maxdim)\
.def("representative", [](ReducedFilteredChainComplex<T, MT>& F, PersistencePair<T>& p){return F.representative(p, false); })\
.def("representative", [](ReducedFilteredChainComplex<T, MT>& F, PersistencePair<T>& p, bool perm){return F.representative(p, perm); })\
.def("persistence_pairs", [](ReducedFilteredChainComplex<T, MT>& F, size_t k){return F.persistence_pairs(k);} )\
.def("persistence_pairs", [](ReducedFilteredChainComplex<T, MT>& F, size_t k, bool perm){return F.persistence_pairs(k, perm);} )\
.def("update_filtration", &ReducedFilteredChainComplex<T, MT>::update_filtration, "update filtration with new values")\
.def("update_filtration_general", &ReducedFilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, SimplicialComplex>>>, "generally update filtration with updating information")\
.def("update_filtration_general", &ReducedFilteredChainComplex<T, MT>::update_filtration_general<Update_info<Filtration<T, DefaultLightSimplicialComplex>>>, "generally update filtration with updating information");


#define Update_infoInterface(T, CpxT, name) py::class_<Update_info<Filtration<T, CpxT>>>(m, name) \
	.def(py::init<const Filtration<T, CpxT>&, const Filtration<T, CpxT>&>())\
	.def("filtered_info", &Update_info<Filtration<T, CpxT>>::filtered_info, "if the cells in filtration are not sorted by their filtration values, we find filtered updating information")


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
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::standard_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, SimplicialComplex>&, T, bats::extra_reduction_flag, bats::compression_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("ReducedFilteredChainComplex", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::compute_basis_flag))(&__ReducedFilteredChainComplex));\
	m.def("reduce", (ReducedFilteredChainComplex<double, MT> (*)(const Filtration<double, DefaultLightSimplicialComplex>&, T, bats::standard_reduction_flag, bats::clearing_flag))(&__ReducedFilteredChainComplex));\
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

#define FlagInterface(T, name) py::class_<T>(m, name) \
	.def(py::init<>());

PYBIND11_MODULE(libbats, m) {
    m.doc() = "Basic Applied Topology Subprograms interface";

    BasicFieldInterface(F2, "F2")
        .def("__neg__", py::overload_cast<>(&F2::operator-));

    FieldInterface(F3, "F3")
    FieldInterface(F5, "F5")
    FieldInterface(FQ, "Rational")

    SparseVectorInterface(int, "IntVector")
    SparseVectorInterface(F2, "F2Vector")
    SparseVectorInterface(F3, "F3Vector")
    SparseVectorInterface(FQ, "RationalVector")

    ColumnMatrixInterface(VInt, "IntMat")
	m.def("Mat", [](const CSCMatrix<int, size_t> &A) { return ColumnMatrix<VInt>(A); });
    ColumnMatrixInterfaceField(V2, "F2Mat")
    ColumnMatrixInterfaceField(V3, "F3Mat")
    ColumnMatrixInterfaceField(VQ, "RationalMat")

    py::class_<CSCMatrix<int, size_t>>(m, "CSCMatrix")
        .def(py::init<>())
        .def(py::init<size_t, size_t, const std::vector<size_t> &, const std::vector<size_t> &, const std::vector<int> &>())
        .def("__call__", &CSCMatrix<int, size_t>::getval)
		.def("nrow", &CSCMatrix<int, size_t>::nrow, "number of rows.")\
		.def("ncol", &CSCMatrix<int, size_t>::ncol, "number of columns.")\
        .def("print", py::overload_cast<>(&CSCMatrix<int, size_t>::print, py::const_));

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

    ChainComplexInterface(M2, "F2ChainComplex")
    ChainComplexInterface(M3, "F3ChainComplex")
    ChainComplexInterface(M5, "F5ChainComplex")
    ChainComplexInterface(MQ, "RationalChainComplex")

    ChainMapInterface(m, M2, "F2ChainMap")
    ChainMapInterface(m, M3, "F3ChainMap")
    ChainMapInterface(m, M5, "F5ChainMap")
    ChainMapInterface(m, MQ, "RationalChainMap")

	FlagInterface(bats::no_optimization_flag, "no_optimization_flag")
	FlagInterface(bats::clearing_flag, "clearing_flag")
	FlagInterface(bats::compression_flag, "compression_flag")
	FlagInterface(bats::standard_reduction_flag, "standard_reduction_flag")
	FlagInterface(bats::extra_reduction_flag, "extra_reduction_flag")
	FlagInterface(bats::compute_basis_flag, "compute_basis_flag")

    ReducedChainComplexInterface(M2, "ReducedF2ChainComplex")
    ReducedChainComplexInterface(M3, "ReducedF3ChainComplex")
    ReducedChainComplexInterface(M5, "ReducedF5ChainComplex")
    ReducedChainComplexInterface(MQ, "ReducedRationalChainComplex")

	DGVectorSpaceInterface(M2, "F2DGVectorSpace")
	DGVectorSpaceInterface(M3, "F3DGVectorSpace")
	DGLinearMapInterface(m, M2, "F2DGLinearMap")
	DGLinearMapInterface(m, M3, "F3DGLinearMap")
	ReducedDGVectorSpaceInterface(M2, "ReducedF2DGVectorSpace")
	ReducedDGVectorSpaceInterface(M3, "ReducedF3DGVectorSpace")

	InducedMapInterface(m, M2)
	InducedMapInterface(m, M3)

    AutoReducedChainComplexInterface(F3)
    AutoReducedChainComplexInterface(F2)
    AutoReducedChainComplexInterface(F5)
    AutoReducedChainComplexInterface(FQ)

    FilteredChainComplexInterface(double, M2, "FilteredF2ChainComplex")
    FilteredChainComplexInterface(double, M3, "FilteredF3ChainComplex")
    FilteredChainComplexInterface(double, M5, "FilteredF5ChainComplex")
    FilteredChainComplexInterface(double, MQ, "FilteredRationalChainComplex")

    ReducedFilteredChainComplexInterface(double, M2, "ReducedFilteredF2ChainComplex")
    ReducedFilteredChainComplexInterface(double, M3, "ReducedFilteredF3ChainComplex")
    ReducedFilteredChainComplexInterface(double, M5, "ReducedFilteredF5ChainComplex")
    ReducedFilteredChainComplexInterface(double, MQ, "ReducedFilteredRationalChainComplex")

    AutoReducedFilteredChainComplexInterface(F2)
    AutoReducedFilteredChainComplexInterface(F3)
    AutoReducedFilteredChainComplexInterface(F5)
    AutoReducedFilteredChainComplexInterface(FQ)

    PersistencePairInterface(double, "PersistencePair")
    PersistencePairInterface(size_t, "PersistencePair_int")
	ZigzagPairInterface(double, "ZigzagPair")

	Update_infoInterface(double, SimplicialComplex, "UpdateInfoFiltration");
	Update_infoInterface(double, DefaultLightSimplicialComplex, "UpdateInfoLightFiltration");

	// Filtration extension
	m.def("lower_star_filtration", [](const SimplicialComplex& X, std::vector<double>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const DefaultLightSimplicialComplex& X, std::vector<double>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const CubicalComplex& X, std::vector<std::vector<double>>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");
	m.def("lower_star_filtration", [](const CubicalComplex& X, std::vector<std::vector<std::vector<double>>>& f0) {return lower_star_filtration(X, f0);}, "extend function on 0-cells to filtration");


}
