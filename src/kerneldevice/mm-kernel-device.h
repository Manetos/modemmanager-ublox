/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details:
 *
 * Copyright (C) 2016 Velocloud, Inc.
 */

#ifndef MM_KERNEL_DEVICE_H
#define MM_KERNEL_DEVICE_H

#include <glib.h>
#include <glib-object.h>

#define MM_TYPE_KERNEL_DEVICE            (mm_kernel_device_get_type ())
#define MM_KERNEL_DEVICE(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), MM_TYPE_KERNEL_DEVICE, MMKernelDevice))
#define MM_KERNEL_DEVICE_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  MM_TYPE_KERNEL_DEVICE, MMKernelDeviceClass))
#define MM_IS_KERNEL_DEVICE(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MM_TYPE_KERNEL_DEVICE))
#define MM_IS_KERNEL_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  MM_TYPE_KERNEL_DEVICE))
#define MM_KERNEL_DEVICE_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  MM_TYPE_KERNEL_DEVICE, MMKernelDeviceClass))

typedef struct _MMKernelDevice MMKernelDevice;
typedef struct _MMKernelDeviceClass MMKernelDeviceClass;

struct _MMKernelDevice {
    GObject parent;
};

struct _MMKernelDeviceClass {
    GObjectClass parent;

    const gchar * (* get_subsystem)   (MMKernelDevice *self);

    const gchar * (* get_name)        (MMKernelDevice *self);

    const gchar * (* get_driver)      (MMKernelDevice *self);

    const gchar * (* get_sysfs_path)  (MMKernelDevice *self);

    gboolean      (* is_candidate)    (MMKernelDevice *self,
                                       gboolean        manual_scan);

    const gchar * (* get_parent_sysfs_path) (MMKernelDevice *self);

    const gchar * (* get_physdev_uid) (MMKernelDevice *self);

    guint16       (* get_physdev_vid) (MMKernelDevice *self);

    guint16       (* get_physdev_pid) (MMKernelDevice *self);

    gboolean      (* cmp) (MMKernelDevice *a, MMKernelDevice *b);

    gboolean      (* has_property)            (MMKernelDevice *self, const gchar *property);
    const gchar * (* get_property)            (MMKernelDevice *self, const gchar *property);
    gboolean      (* get_property_as_boolean) (MMKernelDevice *self, const gchar *property);
    gint          (* get_property_as_int)     (MMKernelDevice *self, const gchar *property);
};

GType mm_kernel_device_get_type (void);

const gchar *mm_kernel_device_get_subsystem   (MMKernelDevice *self);
const gchar *mm_kernel_device_get_name        (MMKernelDevice *self);
const gchar *mm_kernel_device_get_driver      (MMKernelDevice *self);
const gchar *mm_kernel_device_get_sysfs_path  (MMKernelDevice *self);

gboolean     mm_kernel_device_is_candidate    (MMKernelDevice *self,
                                               gboolean        manual_scan);

const gchar *mm_kernel_device_get_parent_sysfs_path  (MMKernelDevice *self);

const gchar *mm_kernel_device_get_physdev_uid (MMKernelDevice *self);
guint16      mm_kernel_device_get_physdev_vid (MMKernelDevice *self);
guint16      mm_kernel_device_get_physdev_pid (MMKernelDevice *self);

gboolean     mm_kernel_device_cmp (MMKernelDevice *a, MMKernelDevice *b);

gboolean     mm_kernel_device_has_property            (MMKernelDevice *self, const gchar *property);
const gchar *mm_kernel_device_get_property            (MMKernelDevice *self, const gchar *property);
gboolean     mm_kernel_device_get_property_as_boolean (MMKernelDevice *self, const gchar *property);
gint         mm_kernel_device_get_property_as_int     (MMKernelDevice *self, const gchar *property);

#endif /* MM_KERNEL_DEVICE_H */
