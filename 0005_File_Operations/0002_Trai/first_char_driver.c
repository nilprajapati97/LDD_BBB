#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static dev_t first; // Global variable for the first device number

static int __init ofcd_init(void) /* Constructor */
{
	int ret;

	printk(KERN_INFO "Hello: ofcd registered");

	alloc_chrdev_region(&first, 0, 3, "Infinite_first_driver");

	//TODO 1: Register the char driver with name ofcd with 1 minor
	printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));
	return 0;
}

static void __exit ofcd_exit(void) /* Destructor */
{
	//TODO 2: //unregister the char driver
	
	unregister_chrdev_region(first, 3);
	
	printk(KERN_INFO "Bye: ofcd unregistered");
}

module_init(ofcd_init);
module_exit(ofcd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(" NIL PRAJAPATI < nil.prajapati97@yahoo.com >");
MODULE_DESCRIPTION("Our First Character Driver");
