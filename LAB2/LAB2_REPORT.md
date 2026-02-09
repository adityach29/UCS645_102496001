# ASSIGNMENT 2 - REPORT

### 1. Introduction

Parallel computing is an important technique used to improve the performance of computationally intensive applications by dividing work among multiple processor cores. OpenMP provides a simple shared-memory model that allows programs to be parallelized using threads with minimal changes to the code.
In this lab, three different problems — Molecular Dynamics simulation, Smith–Waterman sequence alignment, and Heat Diffusion — were parallelized using OpenMP. The objective of this experiment is to measure execution time and analyze the scalability of each algorithm using performance metrics such as speedup and efficiency.

### 2. Experimental Setup

All programs were implemented in C++ and compiled using the GNU compiler with OpenMP support. The following configuration was used:
Language: C++
Compiler: g++
Flags: -O3, -fopenmp
Threads tested: 1 to 16
Execution time was recorded for each thread count, and performance metrics were calculated accordingly.

### 3. Methodology

To evaluate the performance of parallel programs, execution time was measured for different numbers of threads. From these measurements, speedup and efficiency were calculated.
Speedup measures how much faster the parallel program runs compared to the serial version:

Speedup = T₁ / Tₚ

Efficiency measures how effectively the threads are utilized:

Efficiency = Speedup / p

where T₁ is the serial time, Tₚ is the parallel time, and p is the number of threads.
Graphs were plotted for Threads vs Time, Threads vs Speedup, and Threads vs Efficiency.

### 4. Problem Description
Q1 – Molecular Dynamics

This problem computes particle interactions using the Lennard–Jones potential. Since every particle interacts with every other particle, the computational complexity is high, making it suitable for parallelization.

Q2 – Smith–Waterman

This algorithm performs local sequence alignment using dynamic programming. Each cell depends on previous cells, creating data dependencies that limit parallel execution.

Q3 – Heat Diffusion

This problem simulates temperature changes over a 2D grid. Each cell update depends only on neighboring values, allowing independent computations and efficient parallelization.

### 5. Results

Q1:  
| Threads | Time (s)  | Speedup | Efficiency |
| ------- | --------- | ------- | ---------- |
| 1       | 0.0521734 | 1.00000 | 1.00000    |
| 2       | 0.0273089 | 1.91049 | 0.95525    |
| 3       | 0.0258095 | 2.02148 | 0.67383    |
| 4       | 0.0242876 | 2.14815 | 0.53704    |
| 5       | 0.0254052 | 2.05365 | 0.41073    |
| 6       | 0.0279842 | 1.86439 | 0.31073    |
| 7       | 0.0291494 | 1.78986 | 0.25569    |
| 8       | 0.0216636 | 2.40834 | 0.30104    |
| 9       | 0.0187734 | 2.77911 | 0.30879    |
| 10      | 0.0210401 | 2.47971 | 0.24797    |
| 11      | 0.0219840 | 2.37324 | 0.21575    |
| 12      | 0.0194074 | 2.68832 | 0.22403    |
| 13      | 0.0327441 | 1.59336 | 0.12257    |
| 14      | 0.0250472 | 2.08300 | 0.14879    |
| 15      | 0.0285918 | 1.82477 | 0.12165    |
| 16      | 0.0267096 | 1.95335 | 0.12209    |
<img width="800" height="482" alt="Screenshot 2026-02-08 212743" src="https://github.com/user-attachments/assets/abbaa1a4-6995-42f5-afbd-97ee25a9a4af" />

The graph shows that speedup increases initially but saturates after 8–9 threads due to synchronization and atomic overhead.

Q2:
| Threads | Time (s)   | Speedup | Efficiency | Best Score |
| ------- | ---------- | ------- | ---------- | ---------- |
| 1       | 0.0129325  | 1.00000 | 1.00000    | 3000       |
| 2       | 0.00726138 | 1.78100 | 0.89050    | 3000       |
| 3       | 0.00615201 | 2.10216 | 0.70072    | 3000       |
| 4       | 0.00500887 | 2.58192 | 0.64548    | 3000       |
| 5       | 0.157162   | 0.08229 | 0.01646    | 3000       |
| 6       | 0.0299704  | 0.43151 | 0.07192    | 3000       |
| 7       | 0.0326702  | 0.39585 | 0.05655    | 3000       |
| 8       | 0.0334000  | 0.38720 | 0.04840    | 3000       |
| 9       | 0.700919   | 0.01845 | 0.00205    | 3000       |
| 10      | 0.0501802  | 0.25772 | 0.02577    | 3000       |
| 11      | 0.0185888  | 0.69572 | 0.06325    | 3000       |
| 12      | 0.0355924  | 0.36335 | 0.03028    | 3000       |
| 13      | 0.0490937  | 0.26343 | 0.02026    | 3000       |
| 14      | 0.0376145  | 0.34382 | 0.02456    | 3000       |
| 15      | 0.0710542  | 0.18201 | 0.01213    | 3000       |
| 16      | 0.190487   | 0.06789 | 0.00424    | 3000       |
<img width="745" height="436" alt="Screenshot 2026-02-08 221942" src="https://github.com/user-attachments/assets/4fe4b0a9-a8b2-47f7-8465-c31006403918" />

The graph indicates poor scalability, as speedup drops sharply at higher threads because of strong data dependencies between diagonals.

Q3:
| Threads | Time (s) | Speedup | Efficiency | Center Value |
| ------- | -------- | ------- | ---------- | ------------ |
| 1       | 0.833156 | 1.00000 | 1.00000    | 12.0901      |
| 2       | 0.519109 | 1.60497 | 0.80249    | 12.0901      |
| 3       | 0.536641 | 1.55254 | 0.51751    | 12.0901      |
| 4       | 0.412131 | 2.02158 | 0.50540    | 12.0901      |
| 5       | 0.340808 | 2.44465 | 0.48893    | 12.0901      |
| 6       | 0.338964 | 2.45795 | 0.40966    | 12.0901      |
| 7       | 0.275470 | 3.02449 | 0.43207    | 12.0901      |
| 8       | 0.249931 | 3.33354 | 0.41669    | 12.0901      |
| 9       | 0.252772 | 3.29608 | 0.36623    | 12.0901      |
| 10      | 0.261221 | 3.18947 | 0.31895    | 12.0901      |
| 11      | 0.301335 | 2.76489 | 0.25135    | 12.0901      |
| 12      | 0.275082 | 3.02875 | 0.25240    | 12.0901      |
| 13      | 0.253369 | 3.28831 | 0.25295    | 12.0901      |
| 14      | 0.254820 | 3.26959 | 0.23354    | 12.0901      |
| 15      | 0.269135 | 3.09568 | 0.20638    | 12.0901      |
| 16      | 0.276090 | 3.01770 | 0.18861    | 12.0901      |
<img width="624" height="326" alt="Screenshot 2026-02-08 222548" src="https://github.com/user-attachments/assets/41c06c3e-3704-4940-896f-239f2b797023" />

The graph shows near-linear speedup up to 8–10 threads, confirming that the algorithm scales well due to independent grid computations.


### 6. Discussion

The results indicate that the performance of parallel programs depends strongly on the structure of the algorithm.
Heat diffusion showed the best scalability because grid computations are independent and evenly distributed among threads. Molecular dynamics achieved moderate speedup but suffered from synchronization overhead and atomic updates. Smith–Waterman exhibited poor scalability due to strong data dependencies and frequent synchronization between diagonals.
These behaviors are consistent with Amdahl’s Law, which states that the serial portion of a program limits the maximum achievable speedup.

### 7. Comparison of Algorithms

| Algorithm          | Scalability | Reason                   |
| ------------------ | ----------- | ------------------------ |
| Molecular Dynamics | Moderate    | synchronization overhead |
| Smith–Waterman     | Poor        | strong data dependency   |
| Heat Diffusion     | Best        | independent computations |

From the comparison, heat diffusion clearly provides the highest performance improvement, while Smith–Waterman provides the least benefit from parallelization.

### 8. Observations

Execution time decreases initially with increasing threads
Speedup improves up to a certain limit and then saturates
Efficiency decreases as thread count increases
Heat diffusion shows the best parallel performance
Smith–Waterman shows limited scalability due to dependencies

### 9. Conclusion

This experiment demonstrates that parallel performance depends on the nature of the algorithm. Problems with independent and uniform computations scale efficiently, while dependency-heavy algorithms show limited improvement. Heat diffusion achieved the best scalability, molecular dynamics showed moderate improvement, and Smith–Waterman showed the least performance gain.
Thus, effective parallelization requires minimizing dependencies, reducing synchronization, and ensuring balanced workloads across threads.
