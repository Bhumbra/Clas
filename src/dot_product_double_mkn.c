//------------------------------------------------------------------------------
# include "dot_product_double_mkn.h"

//------------------------------------------------------------------------------
void dot_product_double_mkn_4x4x4(double* _Out, 
																	double* _In0, 
																	double* _In1, 
																	volatile const uint64_t m, 
																	volatile const uint64_t k,
																	volatile const uint64_t n,
																	volatile uint64_t OutS,
																	volatile uint64_t In0S, 
																	volatile uint64_t In0s, 
																	volatile uint64_t In1S,
																	volatile uint64_t Arch) { 
	switch (Arch) {
		case 1: {
			DOT_PRODUCT_DOUBLE_MKN_4X4X4_1 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
		case 2: {
			DOT_PRODUCT_DOUBLE_MKN_4X4X4_2 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
		default: {
			DOT_PRODUCT_DOUBLE_MKN_4X4X4_0 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
	}
}

//------------------------------------------------------------------------------
void dot_product_double_mkn_1x1x8(double* _Out, 
																	double* _In0, 
																	double* _In1, 
																	volatile const uint64_t m, 
																	volatile const uint64_t k,
																	volatile const uint64_t n,
																	volatile uint64_t OutS,
																	volatile uint64_t In0S, 
																	volatile uint64_t In0s, 
																	volatile uint64_t In1S,
																	volatile uint64_t Arch) { 
	switch (Arch) {
		case 1: {
			DOT_PRODUCT_DOUBLE_MKN_1X1X8_1 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
		case 2: {
			DOT_PRODUCT_DOUBLE_MKN_1X1X8_2 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
		default: {
			DOT_PRODUCT_DOUBLE_MKN_1X1X8_0 (_Out, _In0, _In1, m, k, n,
																			OutS, In0S, In0s, In1S);
			return;
		}
	}
}

//------------------------------------------------------------------------------

