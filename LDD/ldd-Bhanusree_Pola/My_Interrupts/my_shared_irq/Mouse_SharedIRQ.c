#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/interrupt.h>
#include<linux/io.h>

#define SHARED_IRQ 12 /*IRQ line for PS2/mouse*/

static int irq = SHARED_IRQ, id, irq_counter = 0;
module_param(irq,int,S_IRUGO);

static irqreturn_t my_interrupt(int irq, void *id)
{
	irq_counter++;
	printk("Inside the my_interrupt\n");
	printk("The count is %d\n",irq_counter);
	return IRQ_HANDLED;
}

static int my_init(void)
{
	int ret;
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	ret = request_irq(irq,my_interrupt,IRQF_SHARED,"my_interrupt",&id);
	printk("Ret value:%d\n",ret);
	if(ret < 0)
	{
		printk ("<12>can't get interrupt 68\n");
                return -1;
	}
	return 0;
}
static void my_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	free_irq(irq,&id);
}
module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("BHANU SREE");
MODULE_DESCRIPTION("SHARED IRQ FOR MOUSE");
MODULE_LICENSE("GPL");
