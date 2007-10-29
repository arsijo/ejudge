/* -*- c -*- */
/* $Id$ */

#ifndef __REPORT_PLUGIN_H__
#define __REPORT_PLUGIN_H__

/* Copyright (C) 2007 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "ejudge_plugin.h"
#include "ej_types.h"
#include "iterators.h"

#include <stdio.h>

struct ejudge_cfg;
struct xml_tree;

/* version of the plugin interface structure */
#define REPORT_PLUGIN_IFACE_VERSION 1

struct http_request_info;
struct contest_desc;
struct contest_extra;

struct report_plugin_iface
{
  struct ejudge_plugin_iface b;
  int report_plugin_version;

  void *(*init)(void);
  void (*finalize)(void *);
};

#endif /* __REPORT_PLUGIN_H__ */
