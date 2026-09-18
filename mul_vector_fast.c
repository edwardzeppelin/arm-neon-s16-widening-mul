#include "dsp-lecture.h"

void
mul_vector_fast_q15(int_fast16_t n, int32_t* dst, int16_t* src1, int16_t* src2) 
{
	int vect_div = n - (n % 4);
	int16x4_t buf1, buf2;
	int32x4_t result;
	
	for (int i = 0; i < vect_div; i += 4) {
		buf1 = vld1_s16(&src1[i]);
		buf2 = vld1_s16(&src2[i]);
		
		result = vmull_s16(buf1, buf2);
		
		vst1q_s32(&dst[i], result);
	}
    
	for (int i = vect_div; i < n; i++) {
		dst[i] = (int32_t)src1[i] * (int32_t)src2[i];
	}
}