# ASSIGNMENT - 5
## REPORT


### Introduction

This assignment investigates the principles of parallel and distributed computing using the Message Passing Interface (MPI). The objective is to understand how computational problems behave under parallel execution and to evaluate scalability, communication overhead, synchronization cost, and load balancing strategies.

### Theory
##### Parallel Speedup

Speedup is defined as:

S(p)=T1​/Tp​​
	​

Where:

𝑇1 = serial execution time

𝑇𝑝 = parallel execution time with p processes

Ideal speedup is linear:

𝑆(𝑝)=𝑝

However, in real systems, speedup is limited by communication and synchronization overhead.

##### Efficiency

𝐸(𝑝)=𝑆(𝑝)/𝑝
	​

Efficiency measures how effectively processes are utilized.

 ##### Amdahl’s Law

Amdahl’s Law states that the maximum theoretical speedup is limited by the serial portion of a program:

𝑆(𝑝)=1/(𝑓+(1−(𝑓/𝑝)))


Where:

𝑓 = fraction of serial work

This explains why speedup eventually saturates as processes increase.

#### Q1 – DAXPY (Data Parallelism)

###### Description

Implements the operation:
X[i]=a⋅X[i]+Y[i]

The data is divided among processes using:

MPI_Scatter

Local computation

MPI_Gather

###### Outputs

| Version | Time (seconds) |
| ------- | -------------- |
| Serial  | 0.000213       |


| Processes (NP) | Time (seconds) |
| -------------- | -------------- |
| 1              | 0.000224       |
| 2              | 0.000139       |
| 4              | 0.006450       |
| 8              | 0.035673       |


###### Observations

<img width="597" height="364" alt="image" src="https://github.com/user-attachments/assets/ea0af65f-ebb0-4b4a-8131-cc18ba284634" />

Best performance at NP=2.

Performance degrades significantly at NP=4 and NP=8.

###### Inference

For small data sizes, communication overhead (Scatter/Gather) dominates computation, causing poor scalability at higher process counts.

#### Q2 – Broadcast Race (MyBcast vs MPI_Bcast)
###### Description

Two broadcast methods were compared:

Manual broadcast using MPI_Send and MPI_Recv

Optimized MPI_Bcast

###### Output

| Processes (NP) | Manual (seconds) | MPI_Bcast (seconds) |
| -------------- | ---------------- | ------------------- |
| 2              | 0.025098         | 0.022356            |
| 4              | 0.068553         | 0.087492            |
| 6              | 0.120855         | 0.125833            |
| 8              | 0.211277         | 0.078700            |

###### Observations

<img width="492" height="293" alt="image" src="https://github.com/user-attachments/assets/eb77baae-4c70-40fb-9f96-da0b2a257407" />

Manual broadcast time increases steadily as NP increases.

MPI_Bcast is significantly faster at NP=8.

###### Inference

MPI_Bcast scales better than manual broadcast because it uses optimized tree-based communication instead of linear sends.

#### Q3 – Distributed Dot Product
###### Description

Total dot product of a large dataset (500 million operations) was computed using:

MPI_Bcast

Local computation

MPI_Reduce

##### Output
| Version | Time (seconds) |
| ------- | -------------- |
| Serial  | 0.969270       |


| Processes (NP) | Time (seconds) |
| -------------- | -------------- |
| 1              | 1.098865       |
| 2              | 0.565433       |
| 4              | 0.312094       |
| 8              | 0.492262       |


###### Observations

<img width="489" height="291" alt="image" src="https://github.com/user-attachments/assets/c9f56d76-51b0-4960-ade4-8850a4ed6c4f" />

Strong speedup from NP=1 to NP=4.

Performance decreases at NP=8.

###### Inference

High computation-to-communication ratio gives good scalability initially, but synchronization and reduction overhead limit performance at higher processes.

#### Q4 – Prime Number Search (Master–Slave)
###### Description

Dynamic scheduling was implemented:

Master assigns numbers

Slaves test primality

Results returned dynamically

###### Output
| Version | Time (seconds) |
| ------- | -------------- |
| Serial  | 0.019546       |

| Processes (NP) | Time (seconds) |
| -------------- | -------------- |
| 2              | 0.285959       |
| 4              | 0.194860       |
| 8              | 0.194034       |

###### Observations


Parallel execution is slower than serial.

Slight improvement from NP=2 to NP=4/8.

###### Inference

Frequent communication between master and slaves introduces overhead, making parallel execution inefficient for this problem size.

#### Q5 – Perfect Number Search (Master–Slave)
###### Description

Similar to Q4 but checks for perfect numbers by computing divisor sums.

###### Output
| Version | Time (seconds) |
| ------- | -------------- |
| Serial  | 0.113418       |

| Processes (NP) | Time (seconds) |
| -------------- | -------------- |
| 2              | 0.333947       |
| 4              | 0.279995       |
| 6              | 0.139397       |
| 8              | 0.141374       |

###### Observations

<img width="498" height="295" alt="image" src="https://github.com/user-attachments/assets/8cad9d45-8e0d-4cf5-922d-812834bab5dc" />

Parallel initially slower than serial.

Performance improves significantly at NP=6 and NP=8.

###### Inference

As workload increases, parallel computation begins to offset communication overhead, improving scalability.

#### Conclusion

This assignment demonstrates that parallel performance is highly dependent on the balance between computation and communication. While computation-heavy tasks such as distributed dot product exhibit strong scalability, communication-intensive tasks suffer from overhead that limits speedup. The broadcast comparison confirms that optimized collective operations outperform manual message passing. Additionally, dynamic master–slave models improve load balancing but introduce coordination bottlenecks. Overall, the results validate Amdahl’s Law, showing that increasing process count does not guarantee proportional speedup due to inherent serial components and communication overhead.
