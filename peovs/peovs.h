/*
* Copyright (c) 2014 Cisco Systems, Inc. and others.
*               All rights reserved.
*
* This program and the accompanying materials are made available under
* the terms of the Eclipse Public License v1.0 which accompanies this
* distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*/

#ifndef PEOVS_H
#define PEOVS_H 1

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "config-file.h"

/* initialization for configuration data */
#define PE_INITIALIZE {"pe_initialize",pe_initialize}
#define PEOVS_SECTION "peovs"

/* data */
typedef enum {
    STOPPED,
    INITIALIZING,
    DATA_PUSH,
    MONITORING,
    WORKERS_RUNNING,
    READY,
    TERMINATING
} pe_state_t;
/*
 * TODO: for conf-file.c need to flush this stuff out
static struct option_ele pe_config_defaults[] = {
    {PE_SECTION, "pe_ring_buffer_length", "1000"},
//    {PE_SECTION, "pe_test_pop_thread_count", "20"},
//    {PE_SECTION, "pe_test_max_pop_count", "50"},
    {PE_SECTION, "pe_max_worker_count", "10"},
    {PE_SECTION, "pe_ovsdb_sock", "unix:/var/run/openvswitch/db.sock"},
    {PE_SECTION, "pe_ovsdb_sock_path", "/var/run/openvswitch/db.sock"},
    {PE_SECTION, "pe_ovsdb_name", "Open_vSwitch"},
    {PE_SECTION, "pe_ovs_cmd_path", "/usr/bin"},
    {PE_SECTION, "pe_sys_cmd_path", "/usr/sbin"},
    {PE_SECTION, "pe_ovs_script_path", "/usr/share/openvswitch/scripts"},
    {NULL, NULL, NULL}
};
*/

/* prototypes */
void *pe_start(void *);
pe_state_t pe_get_state(void);
extern bool pe_initialize(void);

#endif //PEOVS_H