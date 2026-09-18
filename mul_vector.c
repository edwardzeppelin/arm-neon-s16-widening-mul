#include "dsp-lecture.h"
#include <stdio.h>

void
mul_vector_q15 (int_fast16_t n, int32_t * dst, int16_t * src1, int16_t * src2)
{
  int_fast16_t i;
  
  int32_t * ref = (int32_t *) alloca (n*sizeof(int32_t));

  mul_vector_ref_q15(n, ref, src1, src2);
  mul_vector_fast_q15(n, dst, src1, src2);

  for (i=0; i<n; i++)
    if (dst[i] != ref[i]) {
      fprintf (stderr, "Error: dst[%d] ref=0x%4.4x res=0x%4.4x\n",
	       i, ref[i], dst[i]);
      exit(1);
    }
}
