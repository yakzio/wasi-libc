// Copyright (c) 2015-2016 Nuxi, https://nuxi.nl/
//
// SPDX-License-Identifier: BSD-2-Clause

#include <common/time.h>

#include <sys/time.h>

#include <wasi/api.h>

#ifdef __wasilibc_unmodified_upstream
int gettimeofday(struct timeval *restrict tp, ...) {
#else
int gettimeofday(struct timeval *restrict tp, void *tz) {
#endif
  __wasi_timestamp_t ts = 0;
#ifdef __wasilibc_unmodified_upstream // generated constant names
  (void)__wasi_clock_time_get(__WASI_CLOCK_REALTIME, 1000, &ts);
#else
  (void)__wasi_clock_time_get(__WASI_CLOCKID_REALTIME, 1000, &ts);
#endif
  *tp = timestamp_to_timeval(ts);
  return 0;
}
