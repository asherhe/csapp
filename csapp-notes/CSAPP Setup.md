---
date created: 2022/06/22 10:00:30 pm
date modified: 2022/06/26 9:05:40 pm
---

# Setting up the CSAPP environment

## Step 1: Install Debian 11 on PVE

## Step 2: Install Necessary Packages

- GCC (C compiler)
- OpenSSL (required for CMake installation)
- CMake
- Git

When running `make`, the C compiler may not be able to find certain libraries for some reason. The error would look somewhat like this

```
fatal error: bits/libc-header-start.h: No such file or directory
```

Simply installing the package `gcc-multilib` (via `sudo apt-get install gcc-multilib`) will fix this.

Also Linux may deny access to some executables:

```
bash: ./dlc: Permission denied
```

To fix this run `chmod u+x [executable name]` which will change the permissions a bit.

## Step 3: Initializing Git SSH

[See this thing on Github](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

Because two-factor authentication and stuff, directly entering a Github username and password won't do. Instead we have to use SSH.

Basically generate a SSH key with `ssh-keygen` (remember to use the Ed25519 algorithm because it's safe), using your Github email address

```
ssh-keygen -t ed25519 -C "email@example.com"
```

Then start a SSH agent with `eval "$(ssh-agent -s)"`, and then `ssh-add ~/.ssh/id_ed25519` (or whichever **private** key file was generated)

Add the SSH **public** key to your Github account.

Git should then work.
