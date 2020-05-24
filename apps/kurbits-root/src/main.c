/*
 * Copyright 2020, Viktor Sannum
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(SANNUM_BSD)
 */

#include <sel4platsupport/bootinfo.h>
#include <sel4platsupport/io.h>

int main(void)
{
    seL4_BootInfo *info = platsupport_get_bootinfo();
    printf("Hello kurbits world 2!\n");

    printf("    CSlot   \tPaddr           \tSize\tType\n");
    for (seL4_CPtr slot = info->untyped.start; slot != info->untyped.end; slot++) {
        seL4_UntypedDesc *desc = &info->untypedList[slot - info->untyped.start];
        printf("%8p\t%16p\t2^%d\t%s\n", (void *) slot, (void *) desc->paddr, desc->sizeBits, desc->isDevice ? "device untyped" : "untyped");
    }

    printf("Goodbye kurbits!\n");

    return 0;
}
