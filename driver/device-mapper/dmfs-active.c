/*
 * dmfs-active.c
 *
 * Copyright (C) 2001 Sistina Software
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2, or (at
 * your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU CC; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <linux/config.h>
#include <linux/fs.h>

static ssize_t dmfs_active_read(struct file *file, char *buf, size_t size, loff_t *pos)
{
	down(&inode->i_sem);

	up(&inode->i_sem);
}

static ssize_t dmfs_active_write(struct file *file, const char *buf, size_t size, loff_t *pos)
{
	down(&inode->i_sem);

	up(&inode->i_sem);
}

static int dmfs_active_sync(struct file *file, struct dentry *dentry, int datasync)
{
	return 0;
}

static struct dm_table_file_operations = {
/* 	llseek:		generic_file_llseek, */
	read:		dmfs_active_read,
	write:		dmfs_active_write,
	open:		dmfs_active_open,
	fsync:		dmfs_active_sync,
};

static struct dmfs_active_inode_operations = {
};

int dmfs_create_active(struct inode *dir, int mode)
{
	struct inode *inode = new_inode(dir->i_sb);

	if (inode) {
		inode->i_mode = mode | S_IFREG;
		inode->i_uid = current->fsuid;
		inode->i_gid = current->fsgid;
		inode->i_blksize = PAGE_CACHE_SIZE;
		inode->i_blocks = 0;
		inode->i_rdev = NODEV;
		inode->i_atime = inode->i_ctime = inode->i_mtime = CURRENT_TIME;
		inode->i_fop = &dmfs_active_file_operations;
		inode->i_op = &dmfs_active_inode_operations;
	}

	return inode;
}

