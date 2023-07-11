
.PHONY : all build cdb clean clobber

all : build

build :
	./setup_clang.sh /home/kartik/build/git_llvm
	bazel build --explain=log_build.txt --verbose_explanations --verbose_failures --subcommands //main/...
	cp bazel-bin/main/a.out .

cdb :
	bazel run //:refresh_compile_commands
	python3 ~/Dropbox/tools/cc_modify.py compile_commands.json

release :
	bazel build --explain=log_build.txt --verbose_explanations --verbose_failures --subcommands --compilation_mode=opt //main/...
	cp bazel-bin/main/a.out .

clean :
	bazel clean

clobber :
	bazel clean --expunge
