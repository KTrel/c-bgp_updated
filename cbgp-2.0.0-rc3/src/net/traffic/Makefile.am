# Compile experimental features ?
if WITH_EXPERIMENTAL
  OPT_EXPERIMENTAL = -D__EXPERIMENTAL__
else
  OPT_EXPERIMENTAL =
endif

AM_CFLAGS = $(OPT_EXPERIMENTAL)

noinst_LTLIBRARIES = libnet_traffic.la
libnet_traffic_la_CFLAGS= $(LIBGDS_CFLAGS)

INCLUDES = -I..

libnet_traffic_la_SOURCES = \
	stats.h \
	stats.c
