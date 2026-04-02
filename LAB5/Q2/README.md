### Inference
Manual broadcast becomes slower as processes increase because the root sends data one-by-one to all processes. MPI_Bcast is faster and more scalable since it uses an optimized tree-based communication method.
