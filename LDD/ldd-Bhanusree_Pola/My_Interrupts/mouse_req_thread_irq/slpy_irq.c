#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/interrupt.h>
#include<linux/io.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/wait.h>
#include <linux/sched.h>


#define SHARED_IRQ 12 /*IRQ line for PS2/mouse*/
#define NAME "Myslpy"

int data_present=0;
wait_queue_head_t my_queue;
DECLARE_WAIT_QUEUE_HEAD(my_queue);

dev_t temp;

ssize_t mouseIRQ_read(struct file *, char __user *, size_t, loff_t *);
ssize_t mouseIRQ_write(struct file *, const char __user *, size_t, loff_t *);
int mouseIRQ_open(struct inode *, struct file *);
int mouseIRQ_close(struct inode *, struct file *);

struct file_operations fops = {
        .owner = THIS_MODULE,
        .read = mouseIRQ_read,
        .write = mouseIRQ_write,
        .open = mouseIRQ_open,
        .release = mouseIRQ_close
};

static int irq = SHARED_IRQ, id, irq_counter = 0;
module_param(irq,int,S_IRUGO);

/*Device methods */
ssize_t mouseIRQ_read(struct file *filp, char __user *usr, size_t size, loff_t *off)
{
        printk("Reading from device\n");
        if(data_present == 0)
        {
                printk("Process %d (%s) Going to Sleep\n",current->pid,current->comm);
                if(wait_event_interruptible(my_queue,(data_present==1)))
                {
                // error
                printk(KERN_ERR "Signal Occurs\n");
                }
                else
                {
                //success
                printk(KERN_INFO "Process awaken - Now Data is available\n");
                }
        }
        else
        {
        printk(KERN_INFO "Data is available\n");
        }
        return 0; //-EPERM;
}

ssize_t mouseIRQ_write(struct file *filp, const char __user *usr, size_t len, loff_t *off)
{
        printk("Trying to write into the device\n");
        return len; //-EPERM;
}

int mouseIRQ_open(struct inode *ino, struct file *filp)
{
        printk("device opened\n");
        return 0;
}

int mouseIRQ_close(struct inode *ino, struct file *filp)
{
        printk("device closed\n");
        return 0;
}

static irqreturn_t mouseIRQ_interrupt(int irq, void *id)
{
	printk("Inside the %s",__func__);
	return IRQ_WAKE_THREAD;
} 

static irqreturn_t mouse_threaded_interrupt(int irq, void *id)
{
	irq_counter++;
        printk("Inside the threaded_interrupt function\n");
        data_present=1;
        wake_up(&my_queue);
        printk("The count is %d\n",irq_counter);
	return IRQ_HANDLED;
}


static int mouseIRQ_init(void)
{
	int ret,result;
        result = register_chrdev(60, NAME, &fops);
        if(result < 0)
        {
                printk("Device could not be registered\n");
                return -EPERM;
        }
        printk("Driver registered with major %d\n", MAJOR(temp));
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	ret = request_threaded_irq(irq,mouseIRQ_interrupt,mouse_threaded_interrupt,IRQF_SHARED,"mouseIRQ_interrupt",&id);
	printk("Ret value:%d\n",ret);
	if(ret < 0)
	{
		printk ("<12>can't get interrupt 68\n");
                return -1;
	}
	return 0;
}
static void mouseIRQ_exit(void)
{
	unregister_chrdev(60, NAME);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	free_irq(irq,&id);
}
module_init(mouseIRQ_init);
module_exit(mouseIRQ_exit);

MODULE_AUTHOR("BHANU SREE");
MODULE_DESCRIPTION("SHARED IRQ FOR MOUSE");
MODULE_LICENSE("GPL");
