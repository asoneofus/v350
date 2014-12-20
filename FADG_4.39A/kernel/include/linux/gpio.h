#ifndef __LINUX_GPIO_H
#define __LINUX_GPIO_H

/* see Documentation/gpio.txt */

#ifdef CONFIG_GENERIC_GPIO
#include <asm/gpio.h>

#else

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/errno.h>

struct device;

/*
 * Some platforms don't support the GPIO programming interface.
 *
 * In case some driver uses it anyway (it should normally have
 * depended on GENERIC_GPIO), these routines help the compiler
 * optimize out much GPIO-related code ... or trigger a runtime
 * warning when something is wrongly called.
 */

static inline int gpio_is_valid(int number)
{
	return 0;
}

static inline int gpio_request(unsigned gpio, const char *label)
{
	return -ENOSYS;
}

static inline void gpio_free(unsigned gpio)
{
	might_sleep();

	/* GPIO can never have been requested */
	WARN_ON(1);
}

static inline int gpio_direction_input(unsigned gpio)
{
	return -ENOSYS;
}

static inline int gpio_direction_output(unsigned gpio, int value)
{
	return -ENOSYS;
}

static inline int gpio_set_debounce(unsigned gpio, unsigned debounce)
{
	return -ENOSYS;
}

static inline int gpio_get_value(unsigned gpio)
{
	/* GPIO can never have been requested or set as {in,out}put */
	WARN_ON(1);
	return 0;
}

static inline void gpio_set_value(unsigned gpio, int value)
{
	/* GPIO can never have been requested or set as output */
	WARN_ON(1);
}

static inline int gpio_cansleep(unsigned gpio)
{
	/* GPIO can never have been requested or set as {in,out}put */
	WARN_ON(1);
	return 0;
}

static inline int gpio_get_value_cansleep(unsigned gpio)
{
	/* GPIO can never have been requested or set as {in,out}put */
	WARN_ON(1);
	return 0;
}

static inline void gpio_set_value_cansleep(unsigned gpio, int value)
{
	/* GPIO can never have been requested or set as output */
	WARN_ON(1);
}

static inline int gpio_export(unsigned gpio, bool direction_may_change)
{
	/* GPIO can never have been requested or set as {in,out}put */
	WARN_ON(1);
	return -EINVAL;
}

static inline int gpio_export_link(struct device *dev, const char *name,
				unsigned gpio)
{
	/* GPIO can never have been exported */
	WARN_ON(1);
	return -EINVAL;
}

static inline int gpio_sysfs_set_active_low(unsigned gpio, int value)
{
	/* GPIO can never have been requested */
	WARN_ON(1);
	return -EINVAL;
}

static inline void gpio_unexport(unsigned gpio)
{
	/* GPIO can never have been exported */
	WARN_ON(1);
}

static inline int gpio_to_irq(unsigned gpio)
{
	/* GPIO can never have been requested or set as input */
	WARN_ON(1);
	return -EINVAL;
}

static inline int irq_to_gpio(unsigned irq)
{
	/* irq can never have been returned from gpio_to_irq() */
	WARN_ON(1);
	return -EINVAL;
}

#endif

/* FIH, JiaHao, 2010/09/09 { */
/* special for 7015 to map old gpio define */
/* path: linux/gpio.h -> asm/gpio.h -> mach/gpio.h -> mach/gpio-v1.h */
/* reference: ./android/kernel/arch/arm/mach-msm/include/mach/gpio-v1.h */
#ifdef CONFIG_FIH_FXX

/* GPIO TLMM: Direction */
#define GPIO_INPUT	GPIO_CFG_INPUT
#define GPIO_OUTPUT	GPIO_CFG_OUTPUT

/* GPIO TLMM: Pullup/Pulldown */
#define GPIO_NO_PULL	GPIO_CFG_NO_PULL
#define GPIO_PULL_DOWN	GPIO_CFG_PULL_DOWN
#define GPIO_KEEPER	GPIO_CFG_KEEPER
#define GPIO_PULL_UP	GPIO_CFG_PULL_UP

/* GPIO TLMM: Drive Strength */
#define	GPIO_2MA	GPIO_CFG_2MA
#define	GPIO_4MA	GPIO_CFG_4MA
#define	GPIO_6MA	GPIO_CFG_6MA
#define	GPIO_8MA	GPIO_CFG_8MA
#define	GPIO_10MA	GPIO_CFG_10MA
#define	GPIO_12MA	GPIO_CFG_12MA
#define	GPIO_14MA	GPIO_CFG_14MA
#define	GPIO_16MA	GPIO_CFG_16MA

/* GPIO TLMM: */
#define GPIO_ENABLE	GPIO_CFG_ENABLE
#define GPIO_DISABLE	GPIO_CFG_DISABLE

#endif /* CONFIG_FIH_FXX */
/* FIH, JiaHao, 2010/09/09 } */

#endif /* __LINUX_GPIO_H */
