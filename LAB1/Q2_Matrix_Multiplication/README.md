In this question, the parallel implementation of matrix multiplication showed considerable performance improvement over the serial version. The 2D threading approach achieved better speedup than 1D threading due to improved workload distribution and better cache utilization.

1D Matrix Multiplication
| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 0.919956                 |
| 3              | 0.767318                 |
| 4              | 0.679285                 |
| 5              | 0.576821                 |
| 6              | 0.516749                 |
| 7              | 0.499091                 |
| 8              | 0.520290                 |
| 9              | 0.485900                 |
| 10             | 0.571730                 |
| 11             | 0.605598                 |
| 12             | 0.720786                 |

2D Matrix Multiplication
| No. of Threads | Execution Time (seconds) |
| -------------- | ------------------------ |
| 2              | 0.914642                 |
| 3              | 0.652942                 |
| 4              | 0.587082                 |
| 5              | 0.618995                 |
| 6              | 0.512936                 |
| 7              | 0.448649                 |
| 8              | 0.580598                 |
| 9              | 0.475766                 |
| 10             | 0.569172                 |
| 11             | 0.562154                 |
| 12             | 0.653956                 |
