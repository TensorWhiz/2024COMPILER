.section .data
.global    base
.global    a
.global    ans
base:
        .quad   16
a:
        .zero   120000040
ans:
        .quad   0
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global getMaxNum
.global getNumPos
.global radixSort
.global main
getMaxNum:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     x11, x1
        mov     w9, #0
        mov     w10, w10
        mov     w9, #0
        mov     w9, #0
        mov     w12, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        mov     x13, x12
        b     bb_while_5_6_cond
bb_while_5_6_cond:

        cmp     w9, w10
        b.lt     bb_while_5_6_whilestms
        b     bb_while_5_6_bre
bb_while_5_6_whilestms:

        mov     x12, #4
        mul     x12, x12, x9
        add     x12, x11, x12
        ldr     x12, [x12]
        cmp     w12, w13
        b.gt     bb_if_9_7_true
        b     bb_if_9_7_false
bb_if_9_7_true:

        mov     x12, #4
        mul     x12, x12, x9
        add     x12, x11, x12
        ldr     x12, [x12]
        mov     w12, w12
        mov     x13, x12
        b     bb_if_9_7_end
bb_if_9_7_false:

        mov     x13, x13
        b     bb_if_9_7_end
bb_if_9_7_end:

        mov     w12, #1
        add     w9, w9, w12
        mov     w9, w9
        mov     x9, x9
        mov     x13, x13
        b     bb_while_5_6_cond
bb_while_5_6_bre:

        mov     w0, w13
        mov     sp, x29
        ret
getNumPos:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     w11, w1
        mov     w9, #0
        mov     w9, w10
        mov     w10, #0
        mov     w11, w11
        mov     w10, #0
        mov     w10, #1
        mov     w10, #0
        mov     w10, #0
        mov     w10, w10
        mov     x10, x10
        mov     x9, x9
        b     bb_while_5_16_cond
bb_while_5_16_cond:

        cmp     w10, w11
        b.lt     bb_while_5_16_whilestms
        b     bb_while_5_16_bre
bb_while_5_16_whilestms:

        adrp     x12, base
        add     x12, x12, #:lo12:base
        ldr     x12, [x12]
        sdiv     w9, w9, w12
        mov     w12, w9
        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        mov     x9, x12
        b     bb_while_5_16_cond
bb_while_5_16_bre:

        adrp     x10, base
        add     x10, x10, #:lo12:base
        ldr     x10, [x10]
        sdiv     w11, w9, w10
        adrp     x10, base
        add     x10, x10, #:lo12:base
        ldr     x10, [x10]
        mul     w10, w11, w10
        sub     w9, w9, w10
        mov     w0, w9
        mov     sp, x29
        ret
radixSort:

bb3:

        sub     sp, sp, #16
        mov     x16, #192
        sub     sp, sp, x16
        mov     w12, w0
        mov     x16, x1
        str     x16, [sp,#8]
        mov     w10, w2
        mov     w9, w3
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w13, #0
        mov     w16, w12
        str     w16, [sp]
        mov     w12, #0
        mov     w15, w10
        mov     w10, #0
        mov     w13, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x12, x9
        b     bb_while_5_29_cond
bb_while_5_29_cond:

        adrp     x9, base
        add     x9, x9, #:lo12:base
        ldr     x9, [x9]
        cmp     w12, w9
        b.lt     bb_while_5_29_whilestms
        b     bb_while_5_29_bre
bb_while_5_29_whilestms:

        mov     x9, #4
        mul     x10, x9, x12
        mov     x9, #-64
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #0
        str     w9, [x10]
        mov     x9, #4
        mul     x10, x9, x12
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #0
        str     w9, [x10]
        mov     x9, #4
        mul     x10, x9, x12
        mov     x9, #-192
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #0
        str     w9, [x10]
        mov     w9, #1
        add     w9, w12, w9
        mov     w9, w9
        mov     x12, x9
        b     bb_while_5_29_cond
bb_while_5_29_bre:

        movz     w11, #65535, LSL #16
        movk     w11, #65535, LSL #0
        ldr     w16, [sp]
        cmp     w16, w11
        b.eq     bb_if_5_36_true
        b     bb29_36_next
bb29_36_next:

        mov     w9, #1
        add     w9, w15, w9
        cmp     w9, w13
        b.ge     bb_if_5_36_true
        b     bb_if_5_36_false
bb_if_5_36_true:

        mov     sp, x29
        ret
bb_if_5_36_false:

        b     bb_if_5_36_end
bb_if_5_36_end:

        mov     w9, w15
        mov     x12, x9
        b     bb_while_9_44_cond
bb_while_9_44_cond:

        cmp     w12, w13
        b.lt     bb_while_9_44_whilestms
        b     bb_while_9_44_bre
bb_while_9_44_whilestms:

        mov     x9, #4
        mul     x9, x9, x12
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mov     w0, w9
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w11, w9
        mov     x9, #4
        mul     x9, x9, x12
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mov     w0, w9
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
        mov     x9, #4
        mul     x10, x9, x10
        mov     x9, #-192
        add     x9, x29, x9
        add     x14, x9, x10
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-192
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x10, [x9]
        mov     w9, #1
        add     w9, w10, w9
        str     w9, [x14]
        mov     w9, #1
        add     w9, w12, w9
        mov     w9, w9
        mov     x12, x9
        b     bb_while_9_44_cond
bb_while_9_44_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        str     w15, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x11, #4
        mov     x10, #0
        mul     x11, x11, x10
        mov     x10, #-192
        add     x10, x29, x10
        add     x10, x10, x11
        ldr     x10, [x10]
        add     w10, w15, w10
        str     w10, [x9]
        mov     w9, #1
        mov     w9, w9
        mov     x11, x9
        b     bb_while_9_55_cond
bb_while_9_55_cond:

        adrp     x9, base
        add     x9, x9, #:lo12:base
        ldr     x9, [x9]
        cmp     w11, w9
        b.lt     bb_while_9_55_whilestms
        b     bb_while_9_55_bre
bb_while_9_55_whilestms:

        mov     w9, #1
        sub     w9, w11, w9
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x11
        mov     x12, #-64
        add     x12, x29, x12
        add     x12, x12, x9
        mov     x9, #4
        mul     x9, x9, x10
        mov     x10, #-128
        add     x10, x29, x10
        add     x9, x10, x9
        ldr     x9, [x9]
        str     w9, [x12]
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-128
        add     x9, x29, x9
        add     x13, x9, x10
        mov     x9, #4
        mul     x9, x9, x11
        mov     x10, #-64
        add     x10, x29, x10
        add     x9, x10, x9
        ldr     x12, [x9]
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-192
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x9, [x9]
        add     w9, w12, w9
        str     w9, [x13]
        mov     w9, #1
        add     w9, w11, w9
        mov     w9, w9
        mov     x11, x9
        b     bb_while_9_55_cond
bb_while_9_55_bre:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x9
        b     bb_while_9_62_cond
bb_while_9_62_cond:

        adrp     x9, base
        add     x9, x9, #:lo12:base
        ldr     x9, [x9]
        cmp     w14, w9
        b.lt     bb_while_9_62_whilestms
        b     bb_while_9_62_bre
bb_while_9_62_whilestms:

        b     bb_while_13_63_cond
bb_while_13_63_cond:

        mov     x9, #4
        mul     x10, x9, x14
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x10, [x9]
        mov     x9, #4
        mul     x9, x9, x14
        mov     x11, #-128
        add     x11, x29, x11
        add     x9, x11, x9
        ldr     x9, [x9]
        cmp     w10, w9
        b.lt     bb_while_13_63_whilestms
        b     bb_while_13_63_bre
bb_while_13_63_whilestms:

        mov     x9, #4
        mul     x10, x9, x14
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x9, [x9]
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mov     w9, w9
        mov     x10, x9
        b     bb_while_17_66_cond
bb_while_17_66_cond:

        mov     w0, w10
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        cmp     w9, w14
        b.ne     bb_while_17_66_whilestms
        b     bb_while_17_66_bre
bb_while_17_66_whilestms:

        mov     w13, w10
        mov     w0, w13
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x10
        mov     x10, #-64
        add     x10, x29, x10
        add     x9, x10, x9
        ldr     x9, [x9]
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mov     w12, w9
        mov     w0, w13
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
        mov     x9, #4
        mul     x10, x9, x10
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x9, [x9]
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        str     w13, [x9]
        mov     w0, w13
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w11, w9
        mov     w0, w13
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getNumPos
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
        mov     x9, #4
        mul     x10, x9, x10
        mov     x9, #-64
        add     x9, x29, x9
        add     x13, x9, x10
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x10, [x9]
        mov     w9, #1
        add     w9, w10, w9
        str     w9, [x13]
        mov     x10, x12
        b     bb_while_17_66_cond
bb_while_17_66_bre:

        mov     x9, #4
        mul     x9, x9, x14
        mov     x11, #-64
        add     x11, x29, x11
        add     x9, x11, x9
        ldr     x9, [x9]
        mov     w11, w9
        mov     x9, #4
        mul     x9, x9, x11
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        str     w10, [x9]
        mov     x9, #4
        mul     x10, x9, x14
        mov     x9, #-64
        add     x9, x29, x9
        add     x10, x9, x10
        mov     x9, #4
        mul     x9, x9, x14
        mov     x11, #-64
        add     x11, x29, x11
        add     x9, x11, x9
        ldr     x11, [x9]
        mov     w9, #1
        add     w9, w11, w9
        str     w9, [x10]
        b     bb_while_13_63_cond
bb_while_13_63_bre:

        mov     w9, #1
        add     w9, w14, w9
        mov     w9, w9
        mov     x14, x9
        b     bb_while_9_62_cond
bb_while_9_62_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        str     w15, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x11, #4
        mov     x10, #0
        mul     x11, x11, x10
        mov     x10, #-192
        add     x10, x29, x10
        add     x10, x10, x11
        ldr     x10, [x10]
        add     w10, w15, w10
        str     w10, [x9]
        mov     w9, #0
        mov     w9, w9
        mov     x11, x9
        b     bb_while_9_92_cond
bb_while_9_92_cond:

        adrp     x9, base
        add     x9, x9, #:lo12:base
        ldr     x9, [x9]
        cmp     w11, w9
        b.lt     bb_while_9_92_whilestms
        b     bb_while_9_92_bre
bb_while_9_92_whilestms:

        mov     w9, #0
        cmp     w11, w9
        b.gt     bb_if_13_93_true
        b     bb_if_13_93_false
bb_if_13_93_true:

        mov     w9, #1
        sub     w9, w11, w9
        mov     w9, w9
        mov     x10, #4
        mul     x12, x10, x11
        mov     x10, #-64
        add     x10, x29, x10
        add     x10, x10, x12
        mov     x12, #4
        mul     x12, x12, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x9, x9, x12
        ldr     x9, [x9]
        str     w9, [x10]
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-128
        add     x9, x29, x9
        add     x12, x9, x10
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x10, [x9]
        mov     x9, #4
        mul     x9, x9, x11
        mov     x13, #-192
        add     x13, x29, x13
        add     x9, x13, x9
        ldr     x9, [x9]
        add     w9, w10, w9
        str     w9, [x12]
        b     bb_if_13_93_end
bb_if_13_93_false:

        b     bb_if_13_93_end
bb_if_13_93_end:

        mov     w9, #1
        ldr     w16, [sp]
        sub     w10, w16, w9
        mov     x9, #4
        mul     x12, x9, x11
        mov     x9, #-64
        add     x9, x29, x9
        add     x9, x9, x12
        ldr     x12, [x9]
        mov     x9, #4
        mul     x9, x9, x11
        mov     x13, #-128
        add     x13, x29, x13
        add     x9, x13, x9
        ldr     x9, [x9]
        mov     w0, w10
        ldr     x16, [sp,#8]
        mov     x1, x16
        mov     w2, w12
        mov     w3, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     radixSort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #1
        add     w9, w11, w9
        mov     w9, w9
        mov     x11, x9
        b     bb_while_9_92_cond
bb_while_9_92_bre:

        mov     sp, x29
        ret
main:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w9, #0
        mov     w9, #0
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getint
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x12, x9
        b     bb_while_5_113_cond
bb_while_5_113_cond:

        cmp     w12, w10
        b.lt     bb_while_5_113_whilestms
        b     bb_while_5_113_bre
bb_while_5_113_whilestms:

        mov     x9, #4
        mul     x11, x9, x12
        adrp     x9, a
        add     x9, x9, #:lo12:a
        add     x11, x9, x11
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getint
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        str     w9, [x11]
        mov     w9, #1
        add     w9, w12, w9
        mov     w9, w9
        mov     x12, x9
        b     bb_while_5_113_cond
bb_while_5_113_bre:

        mov     w9, #97
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     _sysy_starttime
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x11, #4
        mov     x9, #0
        mul     x11, x11, x9
        adrp     x9, a
        add     x9, x9, #:lo12:a
        add     x11, x9, x11
        mov     w9, #8
        mov     w0, w9
        mov     x1, x11
        mov     w9, #0
        mov     w2, w9
        mov     w3, w10
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     radixSort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_123_cond
bb_while_5_123_cond:

        cmp     w9, w10
        b.lt     bb_while_5_123_whilestms
        b     bb_while_5_123_bre
bb_while_5_123_whilestms:

        adrp     x11, ans
        add     x11, x11, #:lo12:ans
        ldr     x12, [x11]
        mov     x11, #4
        mul     x13, x11, x9
        adrp     x11, a
        add     x11, x11, #:lo12:a
        add     x11, x11, x13
        ldr     x11, [x11]
        mov     x13, #4
        mul     x14, x13, x9
        adrp     x13, a
        add     x13, x13, #:lo12:a
        add     x13, x13, x14
        ldr     x14, [x13]
        mov     w13, #2
        add     w13, w13, w9
        sdiv     w14, w14, w13
        mov     w13, #2
        add     w13, w13, w9
        mul     w13, w14, w13
        sub     w11, w11, w13
        mul     w11, w9, w11
        add     w12, w12, w11
        adrp     x11, ans
        add     x11, x11, #:lo12:ans
        str     w12, [x11]
        mov     w11, #1
        add     w9, w9, w11
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_123_cond
bb_while_5_123_bre:

        adrp     x9, ans
        add     x9, x9, #:lo12:ans
        ldr     x10, [x9]
        mov     w9, #0
        cmp     w10, w9
        b.lt     bb_if_5_128_true
        b     bb_if_5_128_false
bb_if_5_128_true:

        adrp     x9, ans
        add     x9, x9, #:lo12:ans
        ldr     x10, [x9]
        mov     w9, #0
        sub     w10, w9, w10
        adrp     x9, ans
        add     x9, x9, #:lo12:ans
        str     w10, [x9]
        b     bb_if_5_128_end
bb_if_5_128_false:

        b     bb_if_5_128_end
bb_if_5_128_end:

        mov     w9, #117
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     _sysy_stoptime
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        adrp     x9, ans
        add     x9, x9, #:lo12:ans
        ldr     x9, [x9]
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     putint
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #10
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     putch
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
