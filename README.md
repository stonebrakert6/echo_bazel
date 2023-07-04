Bazel compilation database generation testing

## Pre-requisites

1. Need a linux machine. Mine is Ubuntu 22.04
2. clang compiler toolchain. I am using version clang-16.
3. bazel. You can install bazel using following

- ``sudo wget -O /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-$([ $(uname -m) = "aarch64" ] && echo "arm64" || echo "amd64")``

- ``sudo chmod +x /usr/local/bin/bazel``

## Steps to reproduce the problem

##### 1. Clone this repsitory
``git clone https://github.com/stonebrakert6/echo_bazel && cd echo_bazel``

##### 2. Setup clang toolchain for bazel. This would generate file clang.bazelrc
``./setup_clang.sh <PATH_TO_CLANG_LLVM_DIRECTORY>``

e.g ./setup_clang.sh /home/stonebrakert6/build/llvm

##### 3. Build the project
``bazel build --verbose_failures --subcommands //main/...``

##### 4. Generate compilation database
``bazel run @hedron_compile_commands//:refresh_all``

##### 5. Copy compile_commands.json to output_base. This remove spurious compilation errors
``cp compile_commands.json `bazel info output_base` ``

##### 6. Run clangd in 'check' mode. This should cause clangd to crash with stacktrace
``clangd --log=verbose --check=external/com_google_tcmalloc/tcmalloc/tcmalloc.cc``
