MEMORY
{
 ram (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
 rom (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
 ccm (rwx) : ORIGIN = 0x10000000, LENGTH = 64K
}

/*INCLUDE stm32f103x8.ld*/
INCLUDE cortex-m-generic.ld


