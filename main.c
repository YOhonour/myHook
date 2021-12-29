#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/string.h>

#include "khook/engine.c"

////////////////////////////////////////////////////////////////////////////////
// An example of using KHOOK
////////////////////////////////////////////////////////////////////////////////

//#include <linux/fs.h>
// KHOOK(inode_permission);
// static int khook_inode_permission(struct inode *inode, int mask)
// {
// 	int ret = 0;

// 	ret = KHOOK_ORIGIN(inode_permission, inode, mask);
// 	printk("ljh2021 %s(%p, %08x) = %d\n", __func__, inode, mask, ret);

// 	return ret;
// }

#include <linux/netdevice.h>
#define VNI_HEAD 0x01020901
// 1921的大端表示，linux主机字节序和网络字节序都是大端,也即 1->9->2->1
#define size_t u32
KHOOK(dev_queue_xmit);
char ThisRunningFlag = 0;
static int khook_dev_queue_xmit(struct sk_buff *skb)
{
	
	int ret = 0;
	unsigned int skbLen = skb->len;
	printk("ljh msg: hook begin\n");
	// if(ThisRunningFlag==1){//额外代码之执行一次
	// 	u32 skbLen = skb->len;
	// 	char* buf = (char*)malloc(sizeof(char)*(skbLen));
	// 	memcpy(buf,skb->head,skbLen);
	// 	size_t i = 0;
	// 	printk("ljh\n");
	// 	printk("截获数据:\n");
	// 	for (i = 0; i < skbLen; i++)
	// 	{
	// 		printk("%0X,",buf[i]);

	// 	}
	// 	printk("输出完毕!\n");
	// 	ThisRunningFlag=0;

	// 	ret = KHOOK_ORIGIN(dev_queue_xmit, skb);
	// 	printk("ljh msg :%s(%p) = %d,skb->len:%d\n", __func__, skb, ret,skbLen);
	// }
	ret = KHOOK_ORIGIN(dev_queue_xmit, skb);
	// printk("ljh msg :%s(%p) = %d\n", __func__, skb, ret);
	printk("ljh msg :%s(%p) = %d,skb->len:%d\n", __func__, skb, ret,skbLen);
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
