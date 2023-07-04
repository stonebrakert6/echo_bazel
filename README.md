Bazel compilation database generation testing

# Run the following

1. bazel build --verbose_failures --subcommands //main/...

2. bazel run @hedron_compile_commands//:refresh_all

3. clangd --log=verbose --check=external/com_google_tcmalloc/tcmalloc/tcmalloc.cc 
