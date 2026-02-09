In this question, the parallel implementation of matrix multiplication showed considerable performance improvement over the serial version. The 2D threading approach achieved better speedup than 1D threading due to improved workload distribution and better cache utilization.

1D Matrix Multiplication
| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 7.886953                 |
| 3              | 14.245350                |
| 4              | 11.373993                |
| 5              | 10.702409                |
| 6              | 12.353829                |
| 7              | 12.555386                |
| 8              | 11.012545                |
| 9              | 13.526352                |
| 10             | 12.413990                |
| 11             | 15.063118                |
| 12             | 13.379920                |

2D Matrix Multiplication
| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 3.532760                 |
| 3              | 3.204738                 |
| 4              | 3.433706                 |
| 5              | 3.012966                 |
| 6              | 3.311818                 |
| 7              | 3.607897                 |
| 8              | 3.347843                 |
| 9              | 3.393361                 |
| 10             | 4.537635                 |
| 11             | 3.951667                 |
| 12             | 4.756428                 |