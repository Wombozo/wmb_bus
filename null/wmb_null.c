/**
 * @file wmb-null.c
 * @author Guillaume LAVIGNE
 * @date 01/11/2020
 * @brief Module that acts like device node /dev/null
 */

#ifndef _WMBBUS_NULL_H
#define _WMBBUS_NULL_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Guillaume Lavigne");
MODULE_DESCRIPTION("Module that acts like device node /dev/null");

static dev_t device;

static int __init
null_init(void)
{
  int error = 0;
  if ((error = alloc_chrdev_region(&device, 0, 1, "wmb_null1")) < 0)
  {
    goto err_register;
  }
  printk(KERN_INFO "Module %s loaded\n", THIS_MODULE->name);
  return 0;
err_register:
  return error;
}

static void __exit
null_exit(void)
{
  unregister_chrdev_region(device, 1);
  printk(KERN_INFO "Module %s unloaded\n", THIS_MODULE->name);
}

module_init(null_init);
module_exit(null_exit);

#endif /* _WMBBUS_NULL_H */