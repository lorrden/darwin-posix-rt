darwin-posix-rt
===============

Darwin implementations of some of the functions in the POSIX RT standard that are missing in OS X. 

Currently implemented are:
	- clock\__gettime for CLOCK\_REALTIME and CLOCK\_MONOTONIC

To build use the supplied Makefile, it is not that fancy at the moment so you
should be able to customize it if you want to.

The license is GPL 2 or later OR LGPL 3 or later.
