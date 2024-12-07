.section .data
.global    max
.global    a
.global    b
.global    kernelid
max:
        .quad   1073741824
a:
        .zero   40000000
b:
        .zero   40000000
kernelid:
        .zero   40000
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global checkrange
.global mod
.global reduce
.global getvalue
.global convn
.global memmove
.global main
checkrange:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     w9, #0
        mov     w9, w10
        mov     x10, x9
        b     bb_while_5_3_cond
bb_while_5_3_cond:

        adrp     x9, max
        add     x9, x9, #:lo12:max
        ldr     x9, [x9]
        cmp     w10, w9
        b.gt     bb_while_5_3_whilestms
        b     bb_while_5_3_bre
bb_while_5_3_whilestms:

        adrp     x9, max
        add     x9, x9, #:lo12:max
        ldr     x9, [x9]
        sub     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        b     bb_while_5_3_cond
bb_while_5_3_bre:

        mov     x10, x10
        b     bb_while_5_4_cond
bb_while_5_4_cond:

        mov     w9, #0
        cmp     w10, w9
        b.lt     bb_while_5_4_whilestms
        b     bb_while_5_4_bre
bb_while_5_4_whilestms:

        adrp     x9, max
        add     x9, x9, #:lo12:max
        ldr     x9, [x9]
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        b     bb_while_5_4_cond
bb_while_5_4_bre:

        mov     w0, w10
        mov     sp, x29
        ret
mod:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w11, w0
        mov     w10, w1
        mov     w9, #0
        mov     w11, w11
        mov     w9, #0
        mov     w10, w10
        sdiv     w9, w11, w10
        mul     w9, w9, w10
        sub     w9, w11, w9
        mov     w0, w9
        mov     sp, x29
        ret
reduce:

bb3:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w11, w0
        mov     w10, w1
        mov     w9, w2
        mov     w12, #0
        mov     w12, #0
        mov     w12, #0
        mov     w12, #0
        mov     w12, #0
        mov     w12, #0
        mov     w12, #0
        mov     w11, w11
        mov     w12, #0
        mov     w10, w10
        mov     w12, #0
        mov     w9, w9
        mov     w12, #0
        cmp     w11, w12
        b.eq     bb_if_5_12_true
        b     bb_if_5_12_false
bb_if_5_12_true:

        add     w9, w10, w9
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     checkrange
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w0, w9
        mov     sp, x29
        ret
bb_if_5_12_false:

        b     bb_if_5_12_end
bb_if_5_12_end:

        mov     w12, #1
        cmp     w11, w12
        b.eq     bb_if_5_15_true
        b     bb_if_5_15_false
bb_if_5_15_true:

        mov     w11, #0
        mov     w12, w11
        mov     w11, #1
        mov     w11, w11
        mov     x13, x12
        mov     x12, x11
        b     bb_while_9_19_cond
bb_while_9_19_cond:

        adrp     x11, max
        add     x11, x11, #:lo12:max
        ldr     x11, [x11]
        cmp     w12, w11
        b.lt     bb_while_9_19_whilestms
        b     bb_while_9_19_bre
bb_while_9_19_whilestms:

        sdiv     w11, w10, w12
        mov     w0, w11
        mov     w11, #2
        mov     w1, w11
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x11, x0
        sdiv     w14, w9, w12
        mov     w0, w14
        mov     w14, #2
        mov     w1, w14
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x14, x0
        cmp     w11, w14
        b.eq     bb_if_13_20_true
        b     bb_if_13_20_false
bb_if_13_20_true:

        mov     w11, #2
        mul     w11, w13, w11
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_20_end
bb_if_13_20_false:

        mov     w11, #2
        mul     w13, w13, w11
        mov     w11, #1
        add     w11, w13, w11
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_20_end
bb_if_13_20_end:

        mov     w11, #2
        mul     w11, w12, w11
        mov     w11, w11
        mov     x13, x13
        mov     x12, x11
        b     bb_while_9_19_cond
bb_while_9_19_bre:

        mov     w0, w13
        mov     sp, x29
        ret
bb_if_5_15_false:

        b     bb_if_5_15_end
bb_if_5_15_end:

        mov     w12, #2
        cmp     w11, w12
        b.eq     bb_if_5_30_true
        b     bb_if_5_30_false
bb_if_5_30_true:

        cmp     w10, w9
        b.gt     bb_if_9_31_true
        b     bb_if_9_31_false
bb_if_9_31_true:

        mov     w0, w10
        mov     sp, x29
        ret
bb_if_9_31_false:

        mov     w0, w9
        mov     sp, x29
        ret
bb_if_5_30_false:

        b     bb_if_5_30_end
bb_if_5_30_end:

        mov     w12, #3
        cmp     w11, w12
        b.eq     bb_if_5_34_true
        b     bb_if_5_34_false
bb_if_5_34_true:

        mov     w11, #0
        mov     w13, w11
        mov     w11, #1
        mov     w11, w11
        mov     x12, x11
        mov     x11, x13
        b     bb_while_9_39_cond
bb_while_9_39_cond:

        adrp     x13, max
        add     x13, x13, #:lo12:max
        ldr     x13, [x13]
        cmp     w12, w13
        b.lt     bb_while_9_39_whilestms
        b     bb_while_9_39_bre
bb_while_9_39_whilestms:

        sdiv     w13, w10, w12
        mov     w0, w13
        mov     w13, #2
        mov     w1, w13
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x14, x0
        mov     w13, #1
        cmp     w14, w13
        b.eq     bb_if_13_40_true
        b     bb37_40_next
bb37_40_next:

        sdiv     w13, w9, w12
        mov     w0, w13
        mov     w13, #2
        mov     w1, w13
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x14, x0
        mov     w13, #1
        cmp     w14, w13
        b.eq     bb_if_13_40_true
        b     bb_if_13_40_false
bb_if_13_40_true:

        mov     w13, #2
        mul     w13, w11, w13
        mov     w11, #1
        add     w11, w13, w11
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_40_end
bb_if_13_40_false:

        mov     w13, #2
        mul     w11, w11, w13
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_40_end
bb_if_13_40_end:

        mov     w11, #2
        mul     w11, w12, w11
        mov     w11, w11
        mov     x12, x11
        mov     x11, x13
        b     bb_while_9_39_cond
bb_while_9_39_bre:

        mov     w0, w11
        mov     sp, x29
        ret
bb_if_5_34_false:

        b     bb_if_5_34_end
bb_if_5_34_end:

        mov     w12, #4
        cmp     w11, w12
        b.eq     bb_if_5_50_true
        b     bb_if_5_50_false
bb_if_5_50_true:

        mov     w11, #0
        mov     w13, w11
        mov     w11, #1
        mov     w11, w11
        mov     x12, x11
        mov     x11, x13
        b     bb_while_9_54_cond
bb_while_9_54_cond:

        adrp     x13, max
        add     x13, x13, #:lo12:max
        ldr     x13, [x13]
        cmp     w12, w13
        b.lt     bb_while_9_54_whilestms
        b     bb_while_9_54_bre
bb_while_9_54_whilestms:

        sdiv     w13, w10, w12
        mov     w0, w13
        mov     w13, #2
        mov     w1, w13
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x14, x0
        mov     w13, #1
        cmp     w14, w13
        b.eq     bb37_55_next
        b     bb_if_13_55_false
bb37_55_next:

        sdiv     w13, w9, w12
        mov     w0, w13
        mov     w13, #2
        mov     w1, w13
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     mod
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x14, x0
        mov     w13, #1
        cmp     w14, w13
        b.eq     bb_if_13_55_true
        b     bb_if_13_55_false
bb_if_13_55_true:

        mov     w13, #2
        mul     w13, w11, w13
        mov     w11, #1
        add     w11, w13, w11
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_55_end
bb_if_13_55_false:

        mov     w13, #2
        mul     w11, w11, w13
        mov     w11, w11
        mov     x13, x11
        b     bb_if_13_55_end
bb_if_13_55_end:

        mov     w11, #2
        mul     w11, w12, w11
        mov     w11, w11
        mov     x12, x11
        mov     x11, x13
        b     bb_while_9_54_cond
bb_while_9_54_bre:

        mov     w0, w11
        mov     sp, x29
        ret
bb_if_5_50_false:

        b     bb_if_5_50_end
bb_if_5_50_end:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
getvalue:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x9, x0
        mov     w14, w1
        mov     w12, w2
        mov     w11, w3
        mov     w10, w4
        mov     w13, #0
        mov     w13, #0
        mov     w13, w14
        mov     w14, #0
        mov     w12, w12
        mov     w14, #0
        mov     w11, w11
        mov     w14, #0
        mov     w10, w10
        mov     w14, #0
        cmp     w11, w14
        b.lt     bb_if_5_69_true
        b     bb20_69_next
bb20_69_next:

        mov     w14, #0
        cmp     w10, w14
        b.lt     bb_if_5_69_true
        b     bb31_69_next
bb31_69_next:

        cmp     w11, w13
        b.ge     bb_if_5_69_true
        b     bb42_69_next
bb42_69_next:

        cmp     w10, w12
        b.ge     bb_if_5_69_true
        b     bb_if_5_69_false
bb_if_5_69_true:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
bb_if_5_69_false:

        b     bb_if_5_69_end
bb_if_5_69_end:

        mul     w11, w11, w12
        add     w10, w11, w10
        mov     w11, w10
        mov     x10, #4
        mul     x10, x10, x11
        add     x9, x9, x10
        ldr     x9, [x9]
        mov     w0, w9
        mov     sp, x29
        ret
convn:

bb5:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #56
        mov     w12, w0
        mov     x16, x1
        str     x16, [sp,#48]
        mov     x16, x2
        str     x16, [sp,#40]
        mov     w11, w3
        mov     w10, w4
        mov     w9, w5
        mov     w13, #0
        mov     w13, #0
        mov     w16, w12
        str     w16, [sp,#32]
        mov     w12, #0
        mov     w16, w11
        str     w16, [sp,#24]
        mov     w11, #0
        mov     w16, w10
        str     w16, [sp,#16]
        mov     w10, #0
        mov     w16, w9
        str     w16, [sp,#8]
        mov     w9, #0
        mov     w9, #0
        mov     w10, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #1
        mov     w16, w9
        str     w16, [sp]
        mov     x15, x10
        b     bb_while_5_81_cond
bb_while_5_81_cond:

        ldr     w16, [sp]
        ldr     w17, [sp]
        cmp     w16, w17
        b.eq     bb_while_5_81_whilestms
        b     bb_while_5_81_bre
bb_while_5_81_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x9
        b     bb_while_9_83_cond
bb_while_9_83_cond:

        ldr     w16, [sp]
        ldr     w17, [sp]
        cmp     w16, w17
        b.eq     bb_while_9_83_whilestms
        b     bb_while_9_83_bre
bb_while_9_83_whilestms:

        mov     w9, #0
        mov     w10, w9
        mov     w9, #2
        ldr     w16, [sp,#8]
        sdiv     w9, w16, w9
        sub     w9, w15, w9
        mov     w9, w9
        mov     x13, x9
        mov     x10, x10
        b     bb_while_13_86_cond
bb_while_13_86_cond:

        ldr     w16, [sp]
        ldr     w17, [sp]
        cmp     w16, w17
        mov     x11, x10
        b.eq     bb_while_13_86_whilestms
        b     bb_while_13_86_bre
bb_while_13_86_whilestms:

        mov     w9, #2
        ldr     w16, [sp,#8]
        sdiv     w9, w16, w9
        sub     w9, w14, w9
        mov     w9, w9
        mov     x11, x10
        mov     x10, x9
        b     bb_while_17_88_cond
bb_while_17_88_cond:

        ldr     w16, [sp]
        ldr     w17, [sp]
        cmp     w16, w17
        mov     x12, x11
        b.eq     bb_while_17_88_whilestms
        b     bb_while_17_88_bre
bb_while_17_88_whilestms:

        ldr     x16, [sp,#48]
        mov     x0, x16
        ldr     w16, [sp,#24]
        mov     w1, w16
        ldr     w16, [sp,#16]
        mov     w2, w16
        mov     w3, w13
        mov     w4, w10
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getvalue
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        ldr     w16, [sp,#32]
        mov     w0, w16
        mov     w1, w11
        mov     w2, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     reduce
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w11, w9
        mov     w9, #1
        add     w9, w10, w9
        mov     w10, w9
        mov     w9, #2
        ldr     w16, [sp,#8]
        sdiv     w9, w16, w9
        add     w9, w14, w9
        cmp     w10, w9
        b.ge     bb_if_21_91_true
        b     bb_if_21_91_false
bb_if_21_91_true:

        mov     x12, x11
        b     bb_while_17_88_bre
bb_if_21_91_false:

        b     bb_if_21_91_end
bb_if_21_91_end:

        mov     x11, x11
        mov     x10, x10
        b     bb_while_17_88_cond
bb_while_17_88_bre:

        mov     w9, #1
        add     w9, w13, w9
        mov     w10, w9
        mov     w9, #2
        ldr     w16, [sp,#8]
        sdiv     w9, w16, w9
        add     w9, w15, w9
        cmp     w10, w9
        b.ge     bb_if_17_94_true
        b     bb_if_17_94_false
bb_if_17_94_true:

        mov     x11, x12
        b     bb_while_13_86_bre
bb_if_17_94_false:

        b     bb_if_17_94_end
bb_if_17_94_end:

        mov     x13, x10
        mov     x10, x12
        b     bb_while_13_86_cond
bb_while_13_86_bre:

        ldr     w16, [sp,#16]
        mul     w9, w15, w16
        add     w9, w9, w14
        mov     w10, w9
        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp,#40]
        add     x9, x16, x9
        str     w11, [x9]
        mov     w9, #1
        add     w9, w14, w9
        mov     w9, w9
        ldr     w16, [sp,#16]
        cmp     w9, w16
        b.ge     bb_if_13_99_true
        b     bb_if_13_99_false
bb_if_13_99_true:

        b     bb_while_9_83_bre
bb_if_13_99_false:

        b     bb_if_13_99_end
bb_if_13_99_end:

        mov     x14, x9
        b     bb_while_9_83_cond
bb_while_9_83_bre:

        mov     w9, #1
        add     w9, w15, w9
        mov     w9, w9
        ldr     w16, [sp,#24]
        cmp     w9, w16
        b.ge     bb_if_9_102_true
        b     bb_if_9_102_false
bb_if_9_102_true:

        b     bb_while_5_81_bre
bb_if_9_102_false:

        b     bb_if_9_102_end
bb_if_9_102_end:

        mov     x15, x9
        b     bb_while_5_81_cond
bb_while_5_81_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
memmove:

bb6:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x13, x0
        mov     x12, x1
        mov     w10, w2
        mov     w9, #0
        mov     w10, w10
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_113_cond
bb_while_5_113_cond:

        cmp     w9, w10
        b.lt     bb_while_5_113_whilestms
        b     bb_while_5_113_bre
bb_while_5_113_whilestms:

        mov     x11, #4
        mul     x11, x11, x9
        add     x11, x13, x11
        mov     x14, #4
        mul     x14, x14, x9
        add     x14, x12, x14
        ldr     x14, [x14]
        str     w14, [x11]
        mov     w11, #1
        add     w9, w9, w11
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_113_cond
bb_while_5_113_bre:

        mov     sp, x29
        ret
main:

bb7:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #24
        mov     w9, #0
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
        mov     w15, w9
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
        mov     w14, w9
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
        mov     w13, w9
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
        mov     x9, x9
        b     bb_while_5_126_cond
bb_while_5_126_cond:

        cmp     w9, w10
        b.lt     bb_while_5_126_whilestms
        b     bb_while_5_126_bre
bb_while_5_126_whilestms:

        mov     x11, #4
        mul     x12, x11, x9
        adrp     x11, a
        add     x11, x11, #:lo12:a
        add     x12, x11, x12
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
        mov     x11, x0
        str     w11, [x12]
        mov     w11, #1
        add     w9, w9, w11
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_126_cond
bb_while_5_126_bre:

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
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_132_cond
bb_while_5_132_cond:

        cmp     w9, w10
        b.lt     bb_while_5_132_whilestms
        b     bb_while_5_132_bre
bb_while_5_132_whilestms:

        mov     x11, #4
        mul     x12, x11, x9
        adrp     x11, kernelid
        add     x11, x11, #:lo12:kernelid
        add     x12, x11, x12
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
        mov     x11, x0
        str     w11, [x12]
        mov     w11, #1
        add     w9, w9, w11
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_132_cond
bb_while_5_132_bre:

        mov     w12, w10
        mov     w9, #209
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
        mov     w9, #0
        mov     w9, w9
        mov     x11, x9
        b     bb_while_5_140_cond
bb_while_5_140_cond:

        cmp     w11, w12
        b.lt     bb_while_5_140_whilestms
        b     bb_while_5_140_bre
bb_while_5_140_whilestms:

        mov     x9, #4
        mul     x10, x9, x11
        adrp     x9, kernelid
        add     x9, x9, #:lo12:kernelid
        add     x9, x9, x10
        ldr     x16, [x9]
        str     x16, [sp,#16]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        adrp     x9, a
        add     x9, x9, #:lo12:a
        add     x16, x9, x10
        str     x16, [sp,#8]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        adrp     x9, b
        add     x9, x9, #:lo12:b
        add     x9, x9, x10
        ldr     w16, [sp,#16]
        mov     w0, w16
        ldr     x16, [sp,#8]
        mov     x1, x16
        mov     x2, x9
        mov     w3, w14
        mov     w4, w13
        mov     w5, w15
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     convn
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        adrp     x9, a
        add     x9, x9, #:lo12:a
        add     x16, x9, x10
        str     x16, [sp]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        adrp     x9, b
        add     x9, x9, #:lo12:b
        add     x10, x9, x10
        mul     w9, w14, w13
        ldr     x16, [sp]
        mov     x0, x16
        mov     x1, x10
        mov     w2, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     memmove
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #1
        add     w9, w11, w9
        mov     w9, w9
        mov     x11, x9
        b     bb_while_5_140_cond
bb_while_5_140_bre:

        mov     w9, #312
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
        mul     w11, w14, w13
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        adrp     x9, a
        add     x9, x9, #:lo12:a
        add     x9, x9, x10
        mov     w0, w11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     putarray
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
