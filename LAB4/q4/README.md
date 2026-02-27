# Inference
Dot product remains correct for all p because each process computes its chunk and MPI_Reduce sums partial products. Distribution changes local contributions, but final reduced result stays 120.
