# REPORT

### Introduction

Correlation matrix computation is a fundamental operation used in data analytics, scientific computing, signal processing, and machine learning. It measures the linear relationship between pairs of vectors and requires significant computational effort for large datasets. The objective of this lab is to implement three versions of correlation computation:
Sequential baseline implementation.
Parallel implementation using OpenMP.
Optimized parallel implementation using algorithmic improvements.
The experiment evaluates performance by varying:
Number of threads
Matrix size
This lab demonstrates the importance of combining parallel programming techniques with algorithmic optimization to achieve high performance.

### Methodology and Implementation

The correlation between two vectors is calculated as:

Correlation = Covariance(A,B) / (sqrt(Var(A)) * sqrt(Var(B)))

Where:
Mean and variance are computed for each row.
Covariance is computed for each pair of rows.
Results are stored in the lower triangular matrix.

### Mode 0 – Sequential Baseline

In this version:
Mean and variance are computed for each row.
For every pair (i, j), covariance is computed.
All computations are performed in double precision.
No parallelism is used.
Time complexity ≈ O(n²m), where:
n = number of vectors
m = vector length
This implementation serves as the baseline for comparison.

### Mode 1 – OpenMP Parallel Implementation

In this version:
Means and variances are precomputed.
Outer loops are parallelized using:
#pragma omp parallel for
Each thread processes independent row pairs.
Redundant computations are reduced.
Parallelism reduces execution time by distributing work among multiple CPU cores.

### Mode 2 – Optimized Parallel Implementation

This version includes algorithmic optimization:
Each row is normalized once.
Correlation is computed using dot products.
Loop unrolling improves instruction-level parallelism.
OpenMP parallelization is applied.
This reduces redundant calculations and improves cache locality, resulting in significant speedup.

### Performance Evaluation
Thread Scaling (Matrix Size = 400 × 800)

Baseline sequential time ≈ 109 ms

Mode 1 Results
| Threads | Time (ms) | Speedup (T1/Tp) | Efficiency |
| ------- | --------- | --------------- | ---------- |
| 1       | 42.50     | 2.56            | 2.56       |
| 2       | 16.48     | 6.62            | 3.31       |
| 4       | 8.70      | 12.53           | 3.13       |
| 8       | 9.21      | 11.83           | 1.48       |
| 16      | 12.10     | 9.01            | 0.56       |
<img width="606" height="352" alt="Screenshot 2026-02-15 233309" src="https://github.com/user-attachments/assets/1aa7beb6-5e0e-4479-85c4-49eaf2dc8823" />


Mode 2 Results
| Threads | Time (ms) | Speedup (vs baseline 109ms) | Efficiency |
| ------- | --------- | --------------------------- | ---------- |
| 1       | 17.53     | 6.22                        | 6.22       |
| 2       | 6.46      | 16.88                       | 8.44       |
| 4       | 4.57      | 23.86                       | 5.96       |
| 8       | 13.28     | 8.21                        | 1.02       |
| 16      | 11.31     | 9.64                        | 0.60       |
<img width="599" height="351" alt="Screenshot 2026-02-15 233415" src="https://github.com/user-attachments/assets/306770fa-7650-4acc-9958-93d700862233" />


### Inference – Thread Scaling

Execution time decreases significantly as the number of threads increases up to 4 threads. Beyond 8 threads, performance degradation is observed due to:

OpenMP thread management overhead

Memory bandwidth limitations

WSL virtualization scheduling effects

Mode 2 achieves the best performance at 4 threads (≈ 4.57 ms), demonstrating that algorithmic optimization contributes more to performance improvement than parallelization alone.

Parallel efficiency decreases after 8 threads due to diminishing returns.

### Matrix Size Scaling (Threads = 8)
Sequential Results
| Size       | Time (ms) |
| ---------- | --------- |
| 200 × 400  | 21.69     |
| 400 × 800  | 103.23    |
| 800 × 1200 | 618.96    |

Mode 1 (8 threads)
| Size       | Time (ms) |
| ---------- | --------- |
| 200 × 400  | 20.91     |
| 400 × 800  | 14.51     |
| 800 × 1200 | 46.29     |

Mode 2 (8 threads)
| Size       | Time (ms) |
| ---------- | --------- |
| 200 × 400  | 2.78      |
| 400 × 800  | 8.98      |
| 800 × 1200 | 25.01     |


### Inference – Matrix Scaling

Sequential execution time increases rapidly with matrix size due to quadratic complexity.

Parallel and optimized implementations scale much better. Larger matrices benefit more from parallelization because the ratio of computation to overhead increases.

Mode 2 shows superior scalability and provides maximum improvement for large datasets.

### Speedup Analysis

Speedup = Sequential Time / Parallel Time

Example (400 × 800):

Mode 1 at 4 threads:
109 / 8.70 ≈ 12.5×

Mode 2 at 4 threads:
109 / 4.57 ≈ 23.8×

This demonstrates substantial performance gain due to optimization and parallelization.

### perf Analysis

Example perf output:

task-clock ≈ 112 ms for sequential
CPU utilization increases with thread count in parallel modes.

Because WSL2 does not expose hardware performance counters, only task-clock metric was used for evaluation.

This limitation does not affect comparative performance analysis between implementations.

### Observations

Precomputing means and variances significantly reduces redundant work.

Algorithmic optimization yields greater improvement than parallelization alone.

Optimal performance achieved at moderate thread counts (around 4).

Performance saturates beyond 8 threads due to overhead.

Larger matrices benefit more from parallel execution.

Cache locality plays a major role in optimized implementation.


### Conclusion

The optimized OpenMP implementation significantly outperforms the sequential baseline. Maximum performance was achieved at 4 threads for medium-sized matrices. The experiment demonstrates that combining algorithmic optimization with parallelization leads to substantial performance improvements.

Although parallel scalability is limited by memory bandwidth and overhead, the optimized implementation achieves nearly 24× speedup compared to the baseline.

This lab successfully demonstrates the importance of efficient parallel programming and algorithmic design in high-performance computing.
