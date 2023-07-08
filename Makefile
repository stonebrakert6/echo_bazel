
.PHONY : all build cdb clean clobber

all : build

build :
	bazel build --explain=log_build.txt --verbose_explanations --verbose_failures --subcommands //main/...
	cp bazel-bin/main/a.out .

cdb :
	python3 ~/Dropbox/tools/cc_modify.py compile_commands.json

clean :
	bazel clean

clobber :
	bazel clean --expunge
