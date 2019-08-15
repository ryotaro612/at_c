
base_dir := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

all:
	@cd $(base_dir)build && \
	cmake .. && make && ctest -V
