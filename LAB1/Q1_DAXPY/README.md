In this question we have parallelized the DAXPY operation using OpenMP thereby significantly reducing execution time as the number of threads increased. However, after a certain number of threads, speedup saturated due to memory bandwidth limitations and thread management overhead.

| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 0.000141                 |
| 3              | 0.000157                 |
| 4              | 0.000163                 |
| 5              | 0.000129                 |
| 6              | 0.000143                 |
| 7              | 0.000143                 |
| 8              | 0.000148                 |
| 9              | 0.000192                 |
| 10             | 0.000150                 |
| 11             | 0.000155                 |
| 12             | 0.000162                 |