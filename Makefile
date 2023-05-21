COMPILER=gcc

chaining:
	@$(COMPILER) -c src/chaining/*.c -Iinclude/ -o bin/chaining.o
	@echo "Built chaining.o"
	@$(COMPILER) -c src/double_hashing/*.c -Iinclude/ -o bin/double_hashing.o
	@echo "Built double_hashing.o"
	@$(COMPILER) -c src/linear_probing/*.c -Iinclude/ -o bin/linear_probing.o
	@echo "Built linear_probing.o"
	@$(COMPILER) -c src/hashing_perfeito/*.c -Iinclude/ -o bin/hashing_perfeito.o
	@echo "Built hashing_perfeito.o"
	$(COMPILER) -c src/main.c -Iinclude/ -o bin/main.o
	@$(COMPILER) bin/chaining.o bin/double_hashing.o bin/linear_probing.o bin/hashing_perfeito.o bin/main.o -o hashing_methods
	@echo "Finished building hashing_methods"