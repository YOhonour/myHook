#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xeeab4c1e, "module_layout" },
	{ 0x7f7b1cfd, "unregister_kprobe" },
	{ 0x9d447e54, "register_kprobe" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x999e8297, "vfree" },
	{ 0xfb578fc5, "memset" },
	{ 0xc5850110, "printk" },
	{ 0xcb970751, "stop_machine" },
	{ 0x6d289335, "init_task" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x2fbefc53, "wake_up_process" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x69acdf38, "memcpy" },
	{ 0x1ef3d720, "param_ops_long" },
	{ 0xe3fffae9, "__x86_indirect_thunk_rbp" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8DFC04684343D8E3CB38248");
