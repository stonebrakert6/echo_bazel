Bazel compilation database generation testing

# Pre-requisites

1. Need a linux machine. Mine is Ubuntu 22.04
2. clang compiler toolchain. I am using version clang-16.
3. bazel. You can install bazel using following

``sudo wget -O /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-$([ $(uname -m) = "aarch64" ] && echo "arm64" || echo "amd64")``

``sudo chmod +x /usr/local/bin/bazel``

# Steps to reproduce the problem

### Setup clang toolchain for bazel
1. ``./setup_clang.sh <PATH_TO_CLANG_LLVM_DIRECTORY>``
e.g ./setup_clang.sh /home/stonebrakert6/build/llvm

### Build the project
2. ``bazel build --verbose_failures --subcommands //main/...``

### Generate compilation database
3. ``bazel run @hedron_compile_commands//:refresh_all``

### Copy compile_commands.json to output_base. This remove spurious compilation errors
4. ``cp compile_commands.json `bazel info output_base``

5. ``clangd --log=verbose --check=external/com_google_tcmalloc/tcmalloc/tcmalloc.cc
