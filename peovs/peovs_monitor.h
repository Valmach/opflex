/*
* Copyright (c) 2014 Cisco Systems, Inc. and others.
*               All rights reserved.
*
* This program and the accompanying materials are made available under
* the terms of the Eclipse Public License v1.0 which accompanies this
* distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*/
#ifndef PEOVS_MONITOR_H
#define PEOVS_MONITOR_H 1

#include <stdbool.h>
#include "ovsdb/table.h"
#include "column.h"
#include "ovs-thread.h"

/* need to variablize PE_OVSDB_* below */
#define PE_OVSDB_SOCK "unix:/var/run/openvswitch/db.sock" /* TODO: replace with */
#define PE_OVSDB_SOCK_PATH "/var/run/openvswitch/db.sock" /*       pe_config_defaults */
#define PE_OVSDB_NAME "Open_vSwitch"                      /*       in policy_enforcer.h */

struct monitored_table {
    struct ovsdb_table_schema *table;
    struct ovsdb_column_set columns;
};

typedef struct _pe_monitor_thread_mgmt pe_monitor_thread_mgmt_t;

struct _pe_monitor_thread_mgmt {
    struct ovs_mutex *lock;
    pthread_cond_t *quit_notice;
};

void *pe_monitor_init(void *);

#endif //PEOVS_MONITOR_H