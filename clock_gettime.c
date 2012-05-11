/*
  Copyright (c) 2012 Mattias Holm.
 
  This file is part of the darwin posix rt compatiblity library. From
  here on called DPRT Compat Lib.
  
  The library is free software; you can redistribute and / or modify it
  under the terms of either
  
  - the GNU Lesser General Public License as published by the Free
  Software Foundation; either version 3 of the License or (at
  your option) any later version.

  or

  - the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at
  your option) any late version.

  or both in parallel, as here.

  DPRT Compat Lib is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copies of the GNU General Public License
  and the GNU Lesser General Public License along with this program;
  if not, see <http://www.gnu.org/licenses/>.
*/

#include "darwin-posix-rt.h"

#include <mach/mach.h>
#include <mach/clock.h>
#include <mach/mach_time.h>
#include <time.h>

#include <errno.h>

int
clock_gettime(int clock_id, struct timespec *ts)
{
  mach_timespec_t mts;
  clock_serv_t clock_serv;
  switch (clock_id) {
  case CLOCK_REALTIME:
    (void) host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &clock_serv);
    break;
  case CLOCK_MONOTONIC:
    (void) host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &clock_serv);
    break;
  default:
    errno = EINVAL;
    return -1;
  }
 
  (void) clock_get_time(clock_serv, &mts);
  ts->tv_sec = mts.tv_sec;
  ts->tv_nsec = mts.tv_nsec;
  return 0;
}
