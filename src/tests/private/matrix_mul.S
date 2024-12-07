.section .data
.global    M
.global    L
.global    N
M:
        .quad   0
L:
        .quad   0
N:
        .quad   0
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global mul
.global main
mul:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #56
        mov     x16, x0
        str     x16, [sp,#48]
        mov     x16, x1
        str     x16, [sp,#40]
        mov     x16, x2
        str     x16, [sp,#32]
        mov     x16, x3
        str     x16, [sp,#24]
        mov     x16, x4
        str     x16, [sp,#16]
        mov     x16, x5
        str     x16, [sp,#8]
        mov     x16, x6
        str     x16, [sp]
        mov     x15, x7
        ldr     x9, [x29]
        mov     x14, x9
        mov     w9, #0
        mov     w9, #0
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp]
        add     x13, x16, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp]
        add     x13, x16, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp]
        add     x13, x16, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        add     x13, x15, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        add     x13, x15, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        add     x13, x15, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        add     x13, x14, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        add     x13, x14, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w12, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w12, w12, w9
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#8]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w11, w9
        add     w9, w12, w9
        str     w9, [x13]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        add     x13, x14, x9
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x11, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w11, w11, w9
        mov     x10, #4
        mov     x9, #1
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x9, x16, x9
        ldr     x12, [x9]
        mov     x10, #4
        mov     x9, #2
        mul     x9, x10, x9
        ldr     x16, [sp,#16]
        add     x9, x16, x9
        ldr     x9, [x9]
        mul     w9, w12, w9
        add     w9, w11, w9
        mov     x11, #4
        mov     x10, #2
        mul     x10, x11, x10
        ldr     x16, [sp,#32]
        add     x10, x16, x10
        ldr     x10, [x10]
        mov     x12, #4
        mov     x11, #2
        mul     x11, x12, x11
        ldr     x16, [sp,#8]
        add     x11, x16, x11
        ldr     x11, [x11]
        mul     w10, w10, w11
        add     w9, w9, w10
        str     w9, [x13]
        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
main:

        sub     sp, sp, #24
bb2:

        mov     x16, #128
        sub     sp, sp, x16
        mov     w9, #0
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
        mov     w10, #3
        adrp     x9, N
        add     x9, x9, #:lo12:N
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, M
        add     x9, x9, #:lo12:M
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, L
        add     x9, x9, #:lo12:L
        str     w10, [x9]
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_35_cond
bb_while_5_35_cond:

        adrp     x10, M
        add     x10, x10, #:lo12:M
        ldr     x10, [x10]
        cmp     w9, w10
        b.lt     bb_while_5_35_whilestms
        b     bb_while_5_35_bre
bb_while_5_35_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-12
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-24
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-36
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-48
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-60
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-72
        add     x10, x29, x10
        add     x10, x10, x11
        str     w9, [x10]
        mov     w10, #1
        add     w9, w9, w10
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_35_cond
bb_while_5_35_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-12
        add     x9, x29, x9
        add     x16, x9, x10
        str     x16, [sp,#16]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-24
        add     x9, x29, x9
        add     x16, x9, x10
        str     x16, [sp,#8]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-36
        add     x9, x29, x9
        add     x16, x9, x10
        str     x16, [sp]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-48
        add     x9, x29, x9
        add     x15, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-60
        add     x9, x29, x9
        add     x14, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x9, x10, x9
        mov     x10, #-72
        add     x10, x29, x10
        add     x13, x10, x9
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-96
        add     x9, x29, x9
        add     x12, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-108
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-120
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x16, [sp,#16]
        mov     x0, x16
        ldr     x16, [sp,#8]
        mov     x1, x16
        ldr     x16, [sp]
        mov     x2, x16
        mov     x3, x15
        mov     x4, x14
        mov     x5, x13
        mov     x6, x12
        mov     x7, x11
        mov     x28, sp
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     sp, x28
        str     x9, [sp,#-80]
        sub     sp, sp, #80
        mov     x29, sp
        bl     mul
        add     sp, sp, #8
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_47_cond
bb_while_5_47_cond:

        adrp     x10, N
        add     x10, x10, #:lo12:N
        ldr     x10, [x10]
        cmp     w9, w10
        b.lt     bb_while_5_47_whilestms
        b     bb_while_5_47_bre
bb_while_5_47_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-96
        add     x10, x29, x10
        add     x10, x10, x11
        ldr     x10, [x10]
        mov     w10, w10
        mov     w0, w10
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
        mov     w10, #1
        add     w9, w9, w10
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_47_cond
bb_while_5_47_bre:

        mov     w9, #10
        mov     w10, w9
        mov     w9, #0
        mov     w9, w9
        mov     w0, w10
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
        mov     x9, x9
        b     bb_while_5_56_cond
bb_while_5_56_cond:

        adrp     x10, N
        add     x10, x10, #:lo12:N
        ldr     x10, [x10]
        cmp     w9, w10
        b.lt     bb_while_5_56_whilestms
        b     bb_while_5_56_bre
bb_while_5_56_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-108
        add     x10, x29, x10
        add     x10, x10, x11
        ldr     x10, [x10]
        mov     w10, w10
        mov     w0, w10
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
        mov     w10, #1
        add     w9, w9, w10
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_56_cond
bb_while_5_56_bre:

        mov     w9, #10
        mov     w10, w9
        mov     w9, #0
        mov     w9, w9
        mov     w0, w10
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
        mov     x9, x9
        b     bb_while_5_66_cond
bb_while_5_66_cond:

        adrp     x10, N
        add     x10, x10, #:lo12:N
        ldr     x10, [x10]
        cmp     w9, w10
        b.lt     bb_while_5_66_whilestms
        b     bb_while_5_66_bre
bb_while_5_66_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-120
        add     x10, x29, x10
        add     x10, x10, x11
        ldr     x10, [x10]
        mov     w10, w10
        mov     w0, w10
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
        mov     w10, #1
        add     w9, w9, w10
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_66_cond
bb_while_5_66_bre:

        mov     w9, #10
        mov     w9, w9
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
        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
