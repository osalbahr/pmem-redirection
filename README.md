# ld-preload-practice
Practicing LD_PRELOAD

- Try running `test.sh` in each directory for some `LD_PRELOAD` magic

##  Installation
This project was built on [NCSU ARC Cluster](https://arcb.csc.ncsu.edu/~mueller/cluster/arc/), which uses CentOS Linux 7 (Core) x87_64. You might need to add some needed dependancies that don't exist on your system. Try `cat fetch.txt` for more system information.

### [Memkind Library](https://github.com/memkind/memkind)
See [memkind#building-and-installing](https://github.com/memkind/memkind#building-and-installing).

Because I don't have root permissions, I am installing in `$HOME/.local`.
```
./autogen.sh
./configure --prefix=$HOME/.local
make
make install
```

You'd also want to add the following to your `.bashrc`:
```
# man memkind
export MANPATH=$MANPATH:$HOME/.local/share

# For some reason, this is needed in addition to `-L`
export LD_LIBRARY_PATH=$HOME/.local/lib

# TODO: maybe do the same for #include and ld's lib, instead of `-I` and `-L` respectively
```

You can choose to install it at a system level, or to another directory. You might need to modify some of the scripts to account for this change. I recommend running the following command at the top-level of the repo to find where `.local` is hardcoded:
```
grep -r '[.]local'
```

## Debugging

If you have root access, you might want to use your favorite package manager.

I was debating using [Homebrew](https://en.wikipedia.org/wiki/Homebrew_(package_manager)) since it can technically streamline installing from source, even without initally having root access, but is not officially supported. I also just wanted to try out installing from source more anyways.

### [ltrace](https://en.wikipedia.org/wiki/Ltrace)

For debugging a ["realloc error"](https://github.com/osalbahr/ld-preload-practice/commit/f960fd33ded086b86eb7c23222dba63567f96b96), I wanted to have `ltrace` as follows. See their [INSTALL](https://gitlab.com/cespedes/ltrace/-/blob/main/INSTALL) for instructions.

```
git clone https://gitlab.com/cespedes/ltrace.git
cd ltrace
./autogen.sh
./configure --prefix=$HOME/.local
make
make install

# You can also use
./autogen.sh && ./configure --prefix=$HOME/.local && make && make install
```

### [valgrind](https://en.wikipedia.org/wiki/Valgrind)

To further investigate the memory error, I wanted to have `valgrind`. See https://valgrind.org/downloads
```
curl -O https://sourceware.org/pub/valgrind/valgrind-3.21.0.tar.bz2
cd valgrind-3.21.0
./configure --prefix=$HOME/.local
make
make install

# You can also use
curl -O https://sourceware.org/pub/valgrind/valgrind-3.21.0.tar.bz2 && cd valgrind-3.21.0 && ./configure --prefix=$HOME/.local && make && make install
```
