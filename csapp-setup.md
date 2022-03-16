# Setting up the CSAPP environment

## Step 1: Install Debian 11 on PVE

## Step 2: Install Necessary Packages

- GCC (C compiler)
- OpenSSL (required for CMake installation)
- CMake

When running `make`, the C compiler may not be able to find certain libraries for some reason. The error would look somewhat like this

```
fatal error: bits/libc-header-start.h: No such file or directory
```

Simply installing the package `gcc-multilib` (via `sudo apt-get install gcc-multilib`) will fix this.