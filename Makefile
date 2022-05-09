
base_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

compile_commands_file_src := $(base_dir)build/compile_commands.json
compile_commands_file_dest := $(base_dir)compile_commands.json

all:
	@mkdir -p $(base_dir)build && \
	cd $(base_dir)build && \
	cmake -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_COMPILER=g++ .. && \
	ninja && \
	ctest -V
lsp:
	if [ -f $(compile_commands_file_dest) ]; then unlink $(compile_commands_file_dest); fi
	ln -s $(compile_commands_file_src) $(compile_commands_file_dest)
