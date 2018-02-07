#pragma once


#include <stdint.h>

// It is virtually impossible to get more than
// one solution per stream hash calculation
// Leave room for up to 4 results. A power
// of 2 here will yield better CUDA optimization
#define SEARCH_RESULTS 4

typedef struct {
	uint32_t count;
	struct {
		// One word for gid and 8 for mix hash
		uint32_t gid;
		uint32_t pad0;
		uint64_t mix[4];
		uint32_t pad[6]; // pad to size power of 2
	} result[SEARCH_RESULTS];
} search_results;

