# ifndef products_hxx
# define products_hxx

# include "clas.hxx"
# include "ewise.txx"
# include "outer.txx"
# include "inner.txx"
# include "mmdot.txx"

namespace clas {
# ifndef CLAS_HEADERS_ONLY
ewise<double, uint64_t> EWISE_DOUBLE_UINT64_T;
outer<double, uint64_t> OUTER_DOUBLE_UINT64_T;
inner<double, uint64_t> INNER_DOUBLE_UINT64_T;
mmdot<double, uint64_t> MMDOT_DOUBLE_UINT64_T;
# endif
//------------------------------------------------------------------------------
void clas_ewise_product_double (double* Out, 
																double* In0, 
																double* In1, 
																volatile const uint64_t m, 
																volatile const uint64_t k,
																volatile const uint64_t p,
																volatile const uint64_t q,
																bool i0c = false,
																bool i1b = false,
																double* In2 = 0,
																volatile uint64_t NT = 0,
																volatile double FT = 1.,
																volatile uint64_t D = 0,
																volatile uint64_t R = 0,
																volatile uint64_t A = 0);
//------------------------------------------------------------------------------
void clas_outer_product_double (double* Out, 
																double* In0, 
																double* In1, 
																volatile const uint64_t m, 
																volatile const uint64_t k,
																volatile const uint64_t p,
																volatile const uint64_t q,
																bool i0c = false,
																bool i1b = false,
																double* In2 = 0,
																volatile uint64_t NT = 0,
																volatile double FT = 1.,
																volatile uint64_t D = 0,
																volatile uint64_t R = 0,
																volatile uint64_t A = 0);
//------------------------------------------------------------------------------
void clas_inner_product_double (double* Out, 
																double* In0, 
																double* In1, 
																volatile const uint64_t m, 
																volatile const uint64_t k,
																volatile const uint64_t p,
																volatile const uint64_t q,
																bool i0c = false,
																bool i1b = false,
																double* In2 = 0,
																volatile uint64_t NT = 0,
																volatile double FT = 1.,
																volatile uint64_t D = 0,
																volatile uint64_t R = 0,
																volatile uint64_t A = 0);
//------------------------------------------------------------------------------
void clas_mmdot_product_double (double* Out, 
																double* In0, 
																double* In1, 
																volatile const uint64_t m, 
																volatile const uint64_t k,
																volatile const uint64_t n,
																volatile bool OutT = false,
																volatile bool In0T = false,
																volatile bool In1T = false,
																volatile bool ColM = false,
																double* In2 = 0,
																volatile uint64_t NT = 0,
																volatile double FT = 1.,
																volatile uint64_t D = 0,
																volatile uint64_t R = 0,
																volatile uint64_t A = 0);
//------------------------------------------------------------------------------
} // namespace
//------------------------------------------------------------------------------
#endif

