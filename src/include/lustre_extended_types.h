/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; -*-
 * vim:expandtab:shiftwidth=4:tabstop=4:
 */
/*
 * Copyright (C) 2009 CEA/DAM
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the CeCILL License.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license (http://www.cecill.info) and that you
 * accept its terms.
 */

/**
 * \file   lustre_extended_types.h 
 * \brief  Specific types for handling lustre data.
 */
#ifndef _LUSTRE_EXTRA_TYPES_H
#define _LUSTRE_EXTRA_TYPES_H

#ifdef _LUSTRE
#ifndef LPX64
#define LPX64 "%#llx"
#endif

#ifndef LPX64i
#define LPX64i "%llx"
#endif

#ifndef LPU64
#define LPU64 "%llu"
#endif

#include <sys/types.h>
#include <asm/types.h>
#endif

#include <assert.h>
#define LASSERT assert

#ifndef _LUSTRE_API_HEADER
#include <lustre/liblustreapi.h>
#else
#include <lustre/lustreapi.h>
#endif

#ifndef DFID_NOBRACE
#define DFID_NOBRACE SFID
#endif
#ifndef XATTR_NAME_LOV
#define XATTR_NAME_LOV "trusted.lov"
#endif

/* missing prototypes in lustre1.8 */
#if defined(HAVE_LLAPI_GETPOOL_INFO) && !defined(_HAVE_FID)
extern int llapi_get_poollist(const char *name, char **poollist, int list_size,
                              char *buffer, int buffer_size);
extern int llapi_get_poolmembers(const char *poolname, char **members,
                                 int list_size, char *buffer, int buffer_size);
#endif

#ifndef HAVE_OBD_STATFS
struct obd_statfs {
        __u64           os_type;
        __u64           os_blocks;
        __u64           os_bfree;
        __u64           os_bavail;
        __u64           os_files;
        __u64           os_ffree;
        __u8            os_fsid[40];
        __u32           os_bsize;
        __u32           os_namelen;
        __u64           os_maxbytes;
        __u32           os_state;       /* positive error code on server */
        __u32           os_spare1;
        __u32           os_spare2;
        __u32           os_spare3;
        __u32           os_spare4;
        __u32           os_spare5;
        __u32           os_spare6;
        __u32           os_spare7;
        __u32           os_spare8;
        __u32           os_spare9;
};
#endif

#ifdef HAVE_CHANGELOG_EXTEND_REC
    #define CL_REC_TYPE struct changelog_ext_rec
#else
    #define CL_REC_TYPE struct changelog_rec
#endif

#endif
