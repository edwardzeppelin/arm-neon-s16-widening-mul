#include "dsp-lecture.h"

void
mul_vector_ref_q15(int_fast16_t n, int32_t* dst, int16_t* src1, int16_t* src2)
{
    int_fast16_t i;

	for (int i = 0; i < n; ++i) {
		dst[i] = (int32_t)src1[i] * (int32_t)src2[i];
	}
}