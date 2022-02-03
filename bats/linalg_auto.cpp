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

#define FlagInterface(T, name) py::class_<T>(m, name) \
	.def(py::init<>());


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

	ChainFunctorInterface(M3, SimplicialComplexDiagram, "F3Chain")
	DGLinearFunctorInterface(M3, CubicalComplexDiagram, "F3DGLinearFunctor")

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
