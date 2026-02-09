In this question we have parallelized the DAXPY operation using OpenMP thereby significantly reducing execution time as the number of threads increased. However, after a certain number of threads, speedup saturated due to memory bandwidth limitations and thread management overhead.

| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 0.000341                 |
| 3              | 0.000560                 |
| 4              | 0.000783                 |
| 5              | 0.000785                 |
| 6              | 0.001689                 |
| 7              | 0.002103                 |
| 8              | 0.003977                 |
| 9              | 0.002626                 |
| 10             | 0.002783                 |
| 11             | 0.005353                 |
| 12             | 0.016066                 |
