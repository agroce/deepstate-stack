all:
	clang++ Stack.cpp -o stack -ldeepstate
	clang++ Stack.cpp -o stack_pureswarm -ldeepstate -DDEEPSTATE_PURE_SWARM
	clang++ Stack.cpp -o stack_probswarm_8 -ldeepstate -DDEEPSTATE_PROB_SWARM -DDEEPSTATE_SWARM_MAX_PROB_RATIO=8

	clang++ Stack.cpp -o stack_LF -fsanitize=fuzzer -ldeepstate_LF
	clang++ Stack.cpp -o stack_pureswarm_LF -fsanitize=fuzzer -ldeepstate_LF -DDEEPSTATE_PURE_SWARM
	clang++ Stack.cpp -o stack_probswarm_8_LF -fsanitize=fuzzer -ldeepstate_LF -DDEEPSTATE_PROB_SWARM -DDEEPSTATE_SWARM_MAX_PROB_RATIO=8

	afl-clang++ Stack.cpp -o stack_AFL -ldeepstate_AFL
	afl-clang++ Stack.cpp -o stack_pureswarm_AFL -ldeepstate_AFL -DDEEPSTATE_PURE_SWARM
	afl-clang++ Stack.cpp -o stack_probswarm_8_AFL -ldeepstate_AFL -DDEEPSTATE_PROB_SWARM -DDEEPSTATE_SWARM_MAX_PROB_RATIO=8

