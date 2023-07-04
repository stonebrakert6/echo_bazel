Bazel compilation database generation testing

# Run the following

1. ``bazel build --verbose_failures --subcommands //main/...``

2. ``bazel run @hedron_compile_commands//:refresh_all``

3. ``cp compile_commands.json `bazel info output_base``

4. ``clangd --log=verbose --check=external/com_google_tcmalloc/tcmalloc/tcmalloc.cc``
