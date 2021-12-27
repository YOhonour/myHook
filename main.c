#include <linux/kernel.h>
#include <linux/module.h>

#include "khook/engine.c"

////////////////////////////////////////////////////////////////////////////////
// An example of using KHOOK
////////////////////////////////////////////////////////////////////////////////

#include <linux/fs.h>

KHOOK(inode_permission);
static int khook_inode_permission(struct inode *inode, int mask)
{
	int ret = 0;

	ret = KHOOK_ORIGIN(inode_permission, inode, mask);
	printk("%s(%p, %08x) = %d\n", __func__, inode, mask, ret);

	return ret;
}


////////////////////////////////////////////////////////////////////////////////

int init_module(void)
{
	return khook_init();
}

void cleanup_module(void)
{
	khook_cleanup();
}

MODULE_LICENSE("GPL\0but who really cares?");
