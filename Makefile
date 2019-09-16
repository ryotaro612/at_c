
base_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all:
	@mkdir -p $(base_dir)build && \
       	cd $(base_dir)build && \
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_CXX_COMPILER=clang++ .. && \
	make && \
	ctest -V

lsp: $(base_dir)compile_commands.json

$(base_dir)compile_commands.json:
	ln -s $(base_dir)build/compile_commands.json $(base_dir)compile_commands.json
