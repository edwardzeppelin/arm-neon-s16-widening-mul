# ARM NEON 16-bit to 32-bit Widening Vector Multiplication

Performance benchmark and verification framework for 16-bit to 32-bit widening vector multiplication accelerated using **ARM NEON SIMD intrinsics** (`vmull_s16` and `vst1q_s32`).

## Key Features
* **Full-Precision Widening Multiplication**: Multiplies two 16-bit signed vector elements (`int16x4_t`) into 32-bit signed vector results (`int32x4_t`) without truncation or scaling loss.
* **128-Bit Vector Store**: Uses `vst1q_s32` to store four 32-bit results simultaneously into the destination array.
* **Tail Element Handling**: Includes a scalar fallback loop executing `(int32_t)src1[i] * (int32_t)src2[i]` for vector lengths not divisible by 4.
* **Runtime Benchmarking**: Evaluates execution time (`clock()`) in CPU cycles between the scalar C reference loop and the ARM NEON implementation.

## Project Structure
* `mul_vector_fast.c` — NEON SIMD implementation using `vmull_s16` and `vst1q_s32`.
* `mul_vector_ref.c` — Scalar reference implementation.
* `mul_vector_tb.c` — Performance testbench with randomized inputs and execution timer.
* `mul_vector.c` — Verification layer comparing NEON output against reference results.
* `dsp-lecture.h` — Header declaring function prototypes and ARM NEON include headers.

## Build & Run

```bash
gcc -O2 -mfpu=neon mul_vector_tb_2.c mul_vector_2.c mul_vector_fast_2.c mul_vector_ref_2.c -o neon_mul32_test
./neon_mul32_test
```
