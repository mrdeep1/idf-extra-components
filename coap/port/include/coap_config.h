/*
 * libcoap configure implementation for ESP32 platform.
 *
 * Uses libcoap software implementation for failover when concurrent
 * configure operations are in use.
 *
 * coap.h -- main header file for CoAP stack of libcoap
 *
 * Copyright (C) 2010-2012,2015-2016 Olaf Bergmann <bergmann@tzi.org>
 *               2015 Carsten Schoenert <c.schoenert@t-online.de>
 *
 * Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
 *
 * This file is part of the CoAP library libcoap. Please see README for terms
 * of use.
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Always enabled in ESP-IDF */
#ifndef WITH_POSIX
#define WITH_POSIX
#endif

#include "coap_config_posix.h"

#define HAVE_STDIO_H
#define HAVE_ASSERT_H

#define PACKAGE_STRING PACKAGE_NAME PACKAGE_VERSION

/* it's just provided by libc. i hope we don't get too many of those, as
 * actually we'd need autotools again to find out what environment we're
 * building in */
#define HAVE_STRNLEN 1

#define HAVE_LIMITS_H

#define COAP_RESOURCES_NOHASH

/* Note: If neither of COAP_CLIENT_SUPPORT or COAP_SERVER_SUPPORT is set,
   then libcoap sets both for backward compatability */
#ifdef CONFIG_COAP_CLIENT_SUPPORT
#define COAP_CLIENT_SUPPORT 1
#endif /* CONFIG_COAP_CLIENT_SUPPORT */

#ifdef CONFIG_COAP_SERVER_SUPPORT
#define COAP_SERVER_SUPPORT 1
#endif /* CONFIG_COAP_SERVER_SUPPORT */

#ifdef CONFIG_COAP_TCP_SUPPORT
#define COAP_DISABLE_TCP 0
#else /* ! CONFIG_COAP_TCP_SUPPORT */
#define COAP_DISABLE_TCP 1
#endif /* ! CONFIG_COAP_TCP_SUPPORT */

#endif /* _CONFIG_H_ */
