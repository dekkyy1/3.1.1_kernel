cmd_arch/arm/kernel/fiqasm.o := /home/dejan/android/toolchains/arm-eabi-linaro-4.6.2/bin/arm-eabi-gcc -Wp,-MD,arch/arm/kernel/.fiqasm.o.d  -nostdinc -isystem /home/dejan/android/toolchains/arm-eabi-linaro-4.6.2/bin/../lib/gcc/arm-eabi/4.6.2/include -I/home/dejan/3.1.10_kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include /home/dejan/3.1.10_kernel/include/linux/kconfig.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-tegra/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -gdwarf-2        -c -o arch/arm/kernel/fiqasm.o arch/arm/kernel/fiqasm.S

source_arch/arm/kernel/fiqasm.o := arch/arm/kernel/fiqasm.S

deps_arch/arm/kernel/fiqasm.o := \
  /home/dejan/3.1.10_kernel/include/linux/kconfig.h \
    $(wildcard include/config/h.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/foo.h) \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/linkage.h \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/smp.h) \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/hwcap.h \
  /home/dejan/3.1.10_kernel/arch/arm/include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
    $(wildcard include/config/cpu/use/domains.h) \

arch/arm/kernel/fiqasm.o: $(deps_arch/arm/kernel/fiqasm.o)

$(deps_arch/arm/kernel/fiqasm.o):
