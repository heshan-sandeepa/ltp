// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *
 *   Copyright (c) International Business Machines Corp., 2001
 */

/*
 * hugetlb.h - common definitions for the hugepage tests
 */

#ifndef __HUGETLB_H
#define __HUGETLB_H

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "old_tmpdir.h"
#include "mem.h"

#define SHM_RD	0400
#define SHM_WR	0200
#define SHM_RW	(SHM_RD|SHM_WR)

#ifndef SHM_HUGETLB
#define SHM_HUGETLB	04000	/* segment is mapped via hugetlb */
#endif

/*
 * to get the lower nine permission bits
 * from shmid_ds.ipc_perm.mode
 */
#define MODE_MASK	0x01FF

key_t shmkey;			/* an IPC key generated by ftok() */

int getipckey(void);
int getuserid(char *user);
void rm_shm(int shm_id);

char *nr_opt;
char *Hopt;
void check_hugepage(void);
long save_nr_hugepages(void);
void restore_nr_hugepages(void);
void limit_hugepages(long *hpages);

#endif /* hugetlb.h */
