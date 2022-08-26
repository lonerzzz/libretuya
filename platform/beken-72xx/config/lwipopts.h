/* Copyright (c) Kuba Szczodrzyński 2022-06-27. */

#pragma once

#include "lwip-2.0.2/port/lwipopts.h"

#include <sys/time.h>

// mDNS support
#undef MEMP_NUM_UDP_PCB
#define LWIP_NUM_NETIF_CLIENT_DATA 1
#define MEMP_NUM_UDP_PCB		   (MAX_SOCKETS_UDP + 2 + 1)

#define ip_addr	  ip4_addr
#define ip_addr_t ip4_addr_t
