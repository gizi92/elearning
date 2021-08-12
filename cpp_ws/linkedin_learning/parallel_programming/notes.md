# Parallel computing architectures
## Flynn's Taxonomy

| Instruction vs Data Streams | Description               | 
| --------------------------- | ------------------------- |
|  **SISD**                   | Sequential Computer with single processing unit |
|  **SIMD**                   | Multi processor parallel computer. They execute the same instruction on different data element (for ex. GPUs)|
|  **MISD**                   | Each CPU executes their own separate instruction on the same data |
|  **MIMD**                   | Every CPU executes their own instruction on different data |

# Parallel Programming Model
- Single Program, Multiple Data (SPMD)
    - Every CPU executes the same program on multiple data (most common)
- Multiple Program, Multiple Data (MPMD)
    - Every CPU executes different program. One processing node is the host/manager, which farms out data to the other nodes, which execute other programs, and return the processed data to the host/manager (functional decomposition)

# Shared VS Distributed Memory

Memory Speed < Processor Speed

## Shared Memory
- All processors access the same memory with global address space
- Architectures:
    - Uniform memory access (UMA): All processors have equal access to the memory (equally fast)
        - Symmetric Multiprocessing (SMP): Multiple CPUs connected to the same shared memory through a **system bus**
        - Lookup: cache coherency
    - Non-uniform memory access (NUMA): Connecting multiple SMP systems together via system bus
        - don't scale well
        - synchronization of shared memory access is up to the programmer

## Distributed Memory
- Each processor has it's own local memory with it's own address space.
- Concept of global address space doesn't exist
- All processors are connected through a network (for ex. ethernet)
- Change in the processor's local memory is not reflected to the others
- Data communication between processors is up to the programmer
- this architecture is scalable

| Process | Thread |
| ------- | ------ |
| Includes code, data, and state information<br> Independent instance of a running program<br> Separate address space | Independent path of execution<br> Subset of a process<br> Operating system schedules threads for execution |


> NOTE: Threads that belong to the same process share the process's address space, which gives them access to the same resources and memory, including the programs's executable code and data. Sharing data between processes is not that trivial.

# Inter-Process Communication (IPC)
- Sockets and pipes
- Shared memory
- Remote procedure calls

# Threads vs Processes
- Are "lightweight - require less overhead to create and terminate
- Operating systems can switch between threads faster than processes