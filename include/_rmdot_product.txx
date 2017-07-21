# ifndef _rmdot_product_txx
# define _rmdot_product_txx
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
# include <iostream>
using namespace std;

# include "clas_unroll.txx"
//------------------------------------------------------------------------------
# include "_replicate.txx"
# include "_rmdot_product_1.txx"
# include "_rmdot_product_2.txx"
# include "_rmdot_product_4.txx"
# include "_rmdot_product_8.txx"

//------------------------------------------------------------------------------
template <class T, class U>
static inline void rmdot_product_1 (T* Out, 
																		T* In0, 
																		T* In1, 
																		volatile const U m,
																		volatile const U k,
																		volatile const U n, 
																		volatile U OutS = 0, 
																		volatile U In0S = 0, 
																		volatile U In1s = 0, 
																		volatile U U1 = 0) { 
	U h = m;
	switch (U1) {
		case 1: {
			for (; h; h--) {
				rmdot_product_1x1 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 2: {
			for (; h; h--) {
				rmdot_product_1x2 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 4: {
			for (; h; h--) {
				rmdot_product_1x4 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 8: {
			for (; h; h--) {
				rmdot_product_1x8 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 16: {
			for (; h; h--) {
				rmdot_product_1x16(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		default: {
			for (; h; h--) {
				rmdot_product_1x32(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
	}
}

//------------------------------------------------------------------------------
template <class T, class U>
static inline void rmdot_product_2 (T* Out, 
																		T* In0, 
																		T* In1, 
																		volatile const U m, 
																		volatile const U k,
																		volatile const U n,
																		volatile U OutS = 0, 
																		volatile U In0S = 0, 
																		volatile U In1s = 0, 
																		volatile U U1 = 0) { 
	U h = m >> 1;
	U mod = m & 1;
	switch (U1) {
		case 1: {
			for (; h; h--) {
				rmdot_product_2x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x1 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 2: {
			for (; h; h--) {
				rmdot_product_2x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x2 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 4: {
			for (; h; h--) {
				rmdot_product_2x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x4 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 8: {
			for (; h; h--) {
				rmdot_product_2x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x8 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 16: {
			for (; h; h--) {
				rmdot_product_2x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x16(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		default: {
			for (; h; h--) {
				rmdot_product_2x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
			}
			if (mod) {
				rmdot_product_1x32(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
	}
}

//------------------------------------------------------------------------------
template <class T, class U>
static inline void rmdot_product_4 (T* Out, 
																		T* In0, 
																		T* In1, 
																		volatile const U m, 
																		volatile const U k,
																		volatile const U n,
																		volatile U OutS = 0, 
																		volatile U In0S = 0, 
																		volatile U In1s = 0, 
																		volatile U U1 = 0) { 
	U h = m >> 2;
	U mod = m & 3;
	switch (U1) {
		case 1: {
			for (; h; h--) {
				rmdot_product_4x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x1 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 2: {
			for (; h; h--) {
				rmdot_product_4x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x2 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 4: {
			for (; h; h--) {
				rmdot_product_4x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x4 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 8: {
			for (; h; h--) {
				rmdot_product_4x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x8 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 16: {
			for (; h; h--) {
				rmdot_product_4x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x16(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		default: {
			for (; h; h--) {
				rmdot_product_4x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
			}
			if (mod > 1) {
				rmdot_product_2x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x32(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
	}
}

//------------------------------------------------------------------------------
template <class T, class U>
static inline void rmdot_product_8 (T* Out, 
																		T* In0, 
																		T* In1, 
																		volatile const U m, 
																		volatile const U k,
																		volatile const U n,
																		volatile U OutS = 0, 
																		volatile U In0S = 0, 
																		volatile U In1s = 0, 
																		volatile U U1 = 0) { 
	U h = m >> 3;
	U mod = m & 7;
	switch (U1) {
		case 1: {
			for (; h; h--) {
				rmdot_product_8x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x1 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x1 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 2: {
			for (; h; h--) {
				rmdot_product_8x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x2 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x2 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 4: {
			for (; h; h--) {
				rmdot_product_8x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x4 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x4 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 8: {
			for (; h; h--) {
				rmdot_product_8x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x8 (Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x8 (Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		case 16: {
			for (; h; h--) {
				rmdot_product_8x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x16(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x16(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
		default: {
			for (; h; h--) {
				rmdot_product_8x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 8;
				In0 += In0S * 8;
			}
			if (mod > 3) {
				rmdot_product_4x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 4;
				In0 += In0S * 4;
				mod &= 3;
			}
			if (mod > 1) {
				rmdot_product_2x32(Out, In0, In1, k, n, In0S, In1s); 
				Out += OutS * 2;
				In0 += In0S * 2;
				mod &= 1;
			}
			if (mod) {
				rmdot_product_1x32(Out, In0, In1, k, n, In1s); 
				Out += OutS;
				In0 += In0S;
			}
			return;
		}
	}
}

//------------------------------------------------------------------------------
template <class T, class U>
static inline void rmdot_product_0 (T* Out, 
																		T* In0, 
																		T* In1, 
																		volatile const U m,
																		volatile const U k,
																		volatile const U n, 
																		volatile U OutS = 0, 
																		volatile U In0S = 0, 
																		volatile U In1s = 0, 
																		T* In2 = 0,
																		volatile U In2S = 0, 
																		volatile U In2s = 0, 
																		volatile U U0 = 0,
																		volatile U U1 = 0) { 
	if (In2 != Out) {
		replicate_0(Out, m, n, In2, OutS, In2S, (U)1, In2s, U0, U1);
	}
	switch (U0) {
		case 1: {
			return rmdot_product_1(Out, In0, In1, m, k, n, OutS, In0S, In1s, U1);
		}
		case 2: {
			return rmdot_product_2(Out, In0, In1, m, k, n, OutS, In0S, In1s, U1);
		}
		case 4: {
			return rmdot_product_4(Out, In0, In1, m, k, n, OutS, In0S, In1s, U1);
		}
		default: {
			return rmdot_product_8(Out, In0, In1, m, k, n, OutS, In0S, In1s, U1);
		}
	}
}
//------------------------------------------------------------------------------
#endif
