// Copyright (c) 2016 The Ilcoin Core developers
// All Rights Reserved. Ilgamos International 2017©

/** Functions for measurement of CPU cycles */
#ifndef H_PERF
#define H_PERF

#include <stdint.h>

#if defined(__i386__)

static inline uint64_t perf_cpucycles(void)
{
    uint64_t x;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (x));
    return x;
}

#elif defined(__x86_64__)

static inline uint64_t perf_cpucycles(void)
{
    uint32_t hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)lo)|(((uint64_t)hi)<<32);
}
#else

uint64_t perf_cpucycles(void);

#endif

void perf_init(void);
void perf_fini(void);

#endif // H_PERF