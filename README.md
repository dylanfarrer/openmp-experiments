# openmp-experiments
A directory of simple C programs that use the openmp toolkit for parallelising tasks.
The Makefile assumes GCC-14 is installed on a Mac OS.

# configuring your env
To set the default thread count, run the config script.
```bash
./config.sh
```

# running
To compile all examples:
```bash
make
```

To compile individual examples:
```bash
make <example>
```

To run examples:
```bash
./build/<example>
```

To clean:
```bash
make clean
```

# tutorials
Visit this intro first:
https://curc.readthedocs.io/en/latest/programming/OpenMP-C.html

More in-depth:
https://hpc-tutorials.llnl.gov/openmp/

OpenMP references:
https://www.openmp.org/resources/refguides/
