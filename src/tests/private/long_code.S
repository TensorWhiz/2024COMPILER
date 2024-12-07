.section .data
.global    n
n:
        .quad   0
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global bubblesort
.global insertsort
.global QuickSort
.global getMid
.global getMost
.global revert
.global arrCopy
.global calSum
.global avgPooling
.global main
bubblesort:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x9, x0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, w10
        mov     x13, x10
        b     bb_while_5_8_cond
bb_while_5_8_cond:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x11, [x10]
        mov     w10, #1
        sub     w10, w11, w10
        cmp     w13, w10
        b.lt     bb_while_5_8_whilestms
        b     bb_while_5_8_bre
bb_while_5_8_whilestms:

        mov     w10, #0
        mov     w10, w10
        mov     x12, x10
        b     bb_while_9_11_cond
bb_while_9_11_cond:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x10, [x10]
        sub     w11, w10, w13
        mov     w10, #1
        sub     w10, w11, w10
        cmp     w12, w10
        b.lt     bb_while_9_11_whilestms
        b     bb_while_9_11_bre
bb_while_9_11_whilestms:

        mov     w10, #1
        add     w10, w12, w10
        mov     w10, w10
        mov     x11, #4
        mul     x11, x11, x12
        add     x11, x9, x11
        ldr     x11, [x11]
        mov     x14, #4
        mul     x10, x14, x10
        add     x10, x9, x10
        ldr     x10, [x10]
        cmp     w11, w10
        b.gt     bb_if_13_13_true
        b     bb_if_13_13_false
bb_if_13_13_true:

        mov     w10, #1
        add     w10, w12, w10
        mov     w11, w10
        mov     x10, #4
        mul     x10, x10, x11
        add     x10, x9, x10
        ldr     x10, [x10]
        mov     w10, w10
        mov     x14, #4
        mul     x11, x14, x11
        add     x11, x9, x11
        mov     x14, #4
        mul     x14, x14, x12
        add     x14, x9, x14
        ldr     x14, [x14]
        str     w14, [x11]
        mov     x11, #4
        mul     x11, x11, x12
        add     x11, x9, x11
        str     w10, [x11]
        b     bb_if_13_13_end
bb_if_13_13_false:

        b     bb_if_13_13_end
bb_if_13_13_end:

        mov     w10, #1
        add     w10, w12, w10
        mov     w10, w10
        mov     x12, x10
        b     bb_while_9_11_cond
bb_while_9_11_bre:

        mov     w10, #1
        add     w10, w13, w10
        mov     w10, w10
        mov     x13, x10
        b     bb_while_5_8_cond
bb_while_5_8_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
insertsort:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x14, x0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #0
        mov     w10, #1
        mov     w10, w10
        mov     x12, x10
        b     bb_while_5_31_cond
bb_while_5_31_cond:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x10, [x10]
        cmp     w12, w10
        b.lt     bb_while_5_31_whilestms
        b     bb_while_5_31_bre
bb_while_5_31_whilestms:

        mov     x10, #4
        mul     x10, x10, x12
        add     x10, x14, x10
        ldr     x10, [x10]
        mov     w11, w10
        mov     w10, #1
        sub     w10, w12, w10
        mov     w10, w10
        mov     x10, x10
        b     bb_while_9_37_cond
bb_while_9_37_cond:

        movz     w9, #65535, LSL #16
        movk     w9, #65535, LSL #0
        cmp     w10, w9
        b.gt     bb23_37_next
        b     bb_while_9_37_bre
bb23_37_next:

        mov     x13, #4
        mul     x13, x13, x10
        add     x13, x14, x13
        ldr     x13, [x13]
        cmp     w11, w13
        b.lt     bb_while_9_37_whilestms
        b     bb_while_9_37_bre
bb_while_9_37_whilestms:

        mov     w13, #1
        add     w13, w10, w13
        mov     w15, w13
        mov     x13, #4
        mul     x13, x13, x15
        add     x13, x14, x13
        mov     x15, #4
        mul     x15, x15, x10
        add     x15, x14, x15
        ldr     x15, [x15]
        str     w15, [x13]
        mov     w13, #1
        sub     w10, w10, w13
        mov     w10, w10
        mov     x10, x10
        b     bb_while_9_37_cond
bb_while_9_37_bre:

        mov     w13, #1
        add     w10, w10, w13
        mov     w13, w10
        mov     x10, #4
        mul     x10, x10, x13
        add     x10, x14, x10
        str     w11, [x10]
        mov     w10, #1
        add     w10, w12, w10
        mov     w10, w10
        mov     x12, x10
        b     bb_while_5_31_cond
bb_while_5_31_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
QuickSort:

bb3:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #8
        mov     x16, x0
        str     x16, [sp]
        mov     w10, w1
        mov     w9, w2
        mov     w11, #0
        mov     w11, #0
        mov     w11, #0
        mov     w11, #0
        mov     w11, #0
        mov     w14, w10
        mov     w10, #0
        mov     w13, w9
        cmp     w14, w13
        b.lt     bb_if_5_52_true
        b     bb_if_5_52_false
bb_if_5_52_true:

        mov     w10, w14
        mov     w9, w13
        mov     x11, #4
        mul     x11, x11, x14
        ldr     x16, [sp]
        add     x11, x16, x11
        ldr     x11, [x11]
        mov     w12, w11
        mov     x10, x10
        mov     x9, x9
        b     bb_while_9_60_cond
bb_while_9_60_cond:

        cmp     w10, w9
        b.lt     bb_while_9_60_whilestms
        b     bb_while_9_60_bre
bb_while_9_60_whilestms:

        mov     x11, x9
        b     bb_while_13_62_cond
bb_while_13_62_cond:

        cmp     w10, w11
        b.lt     bb30_62_next
        b     bb_while_13_62_bre
bb30_62_next:

        mov     x9, #4
        mul     x9, x9, x11
        ldr     x16, [sp]
        add     x9, x16, x9
        ldr     x15, [x9]
        mov     w9, #1
        sub     w9, w12, w9
        cmp     w15, w9
        b.gt     bb_while_13_62_whilestms
        b     bb_while_13_62_bre
bb_while_13_62_whilestms:

        mov     w9, #1
        sub     w9, w11, w9
        mov     w9, w9
        mov     x11, x9
        b     bb_while_13_62_cond
bb_while_13_62_bre:

        cmp     w10, w11
        b.lt     bb_if_13_67_true
        b     bb_if_13_67_false
bb_if_13_67_true:

        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp]
        add     x15, x16, x9
        mov     x9, #4
        mul     x9, x9, x11
        ldr     x16, [sp]
        add     x9, x16, x9
        ldr     x9, [x9]
        str     w9, [x15]
        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x9, x9
        b     bb_if_13_67_end
bb_if_13_67_false:

        mov     x9, x10
        b     bb_if_13_67_end
bb_if_13_67_end:

        mov     x10, x9
        b     bb_while_13_73_cond
bb_while_13_73_cond:

        cmp     w10, w11
        b.lt     bb30_73_next
        b     bb_while_13_73_bre
bb30_73_next:

        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp]
        add     x9, x16, x9
        ldr     x9, [x9]
        cmp     w9, w12
        b.lt     bb_while_13_73_whilestms
        b     bb_while_13_73_bre
bb_while_13_73_whilestms:

        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        b     bb_while_13_73_cond
bb_while_13_73_bre:

        cmp     w10, w11
        b.lt     bb_if_13_78_true
        b     bb_if_13_78_false
bb_if_13_78_true:

        mov     x9, #4
        mul     x9, x9, x11
        ldr     x16, [sp]
        add     x15, x16, x9
        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp]
        add     x9, x16, x9
        ldr     x9, [x9]
        str     w9, [x15]
        mov     w9, #1
        sub     w9, w11, w9
        mov     w9, w9
        mov     x9, x9
        b     bb_if_13_78_end
bb_if_13_78_false:

        mov     x9, x11
        b     bb_if_13_78_end
bb_if_13_78_end:

        mov     x10, x10
        mov     x9, x9
        b     bb_while_9_60_cond
bb_while_9_60_bre:

        mov     x9, #4
        mul     x9, x9, x10
        ldr     x16, [sp]
        add     x9, x16, x9
        str     w12, [x9]
        mov     w9, #1
        sub     w9, w10, w9
        mov     w9, w9
        ldr     x16, [sp]
        mov     x0, x16
        mov     w1, w14
        mov     w2, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     QuickSort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        ldr     x16, [sp]
        mov     x0, x16
        mov     w1, w9
        mov     w2, w13
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     QuickSort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        b     bb_if_5_52_end
bb_if_5_52_false:

        b     bb_if_5_52_end
bb_if_5_52_end:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
getMid:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x9, x0
        mov     w10, #0
        mov     w10, #0
        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x11, [x10]
        mov     w10, #2
        sdiv     w11, w11, w10
        mov     w10, #2
        mul     w11, w11, w10
        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x10, [x10]
        cmp     w11, w10
        b.eq     bb_if_5_98_true
        b     bb_if_5_98_false
bb_if_5_98_true:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x11, [x10]
        mov     w10, #2
        sdiv     w10, w11, w10
        mov     w12, w10
        mov     w10, #1
        sub     w10, w12, w10
        mov     w11, w10
        mov     x10, #4
        mul     x10, x10, x12
        add     x10, x9, x10
        ldr     x12, [x10]
        mov     x10, #4
        mul     x10, x10, x11
        add     x9, x9, x10
        ldr     x9, [x9]
        add     w10, w12, w9
        mov     w9, #2
        sdiv     w9, w10, w9
        mov     w0, w9
        mov     sp, x29
        ret
bb_if_5_98_false:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x11, [x10]
        mov     w10, #2
        sdiv     w10, w11, w10
        mov     w11, w10
        mov     x10, #4
        mul     x10, x10, x11
        add     x9, x9, x10
        ldr     x9, [x9]
        mov     w0, w9
        mov     sp, x29
        ret
getMost:

bb5:

        mov     x16, #4000
        sub     sp, sp, #8
        sub     sp, sp, x16
        mov     x16, x0
        str     x16, [sp]
        mov     w9, #0
        mov     w9, #0
        mov     w10, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_112_cond
bb_while_5_112_cond:

        mov     w11, #1000
        cmp     w9, w11
        b.lt     bb_while_5_112_whilestms
        b     bb_while_5_112_bre
bb_while_5_112_whilestms:

        mov     x11, #4
        mul     x12, x11, x9
        mov     x11, #-4000
        add     x11, x29, x11
        add     x12, x11, x12
        mov     w11, #0
        str     w11, [x12]
        mov     w11, #1
        add     w9, w9, w11
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_112_cond
bb_while_5_112_bre:

        mov     w9, #0
        mov     w11, w9
        mov     w9, #0
        mov     w9, w9
        mov     x14, x11
        mov     x13, x9
        mov     x12, x10
        b     bb_while_5_120_cond
bb_while_5_120_cond:

        adrp     x9, n
        add     x9, x9, #:lo12:n
        ldr     x9, [x9]
        cmp     w14, w9
        b.lt     bb_while_5_120_whilestms
        b     bb_while_5_120_bre
bb_while_5_120_whilestms:

        mov     x9, #4
        mul     x9, x9, x14
        ldr     x16, [sp]
        add     x9, x16, x9
        ldr     x9, [x9]
        mov     w11, w9
        mov     x9, #4
        mul     x9, x9, x11
        mov     x10, #-4000
        add     x10, x29, x10
        add     x15, x10, x9
        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-4000
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x10, [x9]
        mov     w9, #1
        add     w9, w10, w9
        str     w9, [x15]
        mov     x9, #4
        mul     x9, x9, x11
        mov     x10, #-4000
        add     x10, x29, x10
        add     x9, x10, x9
        ldr     x9, [x9]
        cmp     w9, w13
        b.gt     bb_if_9_124_true
        b     bb_if_9_124_false
bb_if_9_124_true:

        mov     x9, #4
        mul     x10, x9, x11
        mov     x9, #-4000
        add     x9, x29, x9
        add     x9, x9, x10
        ldr     x9, [x9]
        mov     w10, w9
        mov     w9, w11
        mov     x10, x10
        mov     x9, x9
        b     bb_if_9_124_end
bb_if_9_124_false:

        mov     x10, x13
        mov     x9, x12
        b     bb_if_9_124_end
bb_if_9_124_end:

        mov     w11, #1
        add     w11, w14, w11
        mov     w11, w11
        mov     x14, x11
        mov     x13, x10
        mov     x12, x9
        b     bb_while_5_120_cond
bb_while_5_120_bre:

        mov     w0, w12
        mov     sp, x29
        ret
revert:

bb6:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x13, x0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w10, w9
        mov     w9, #0
        mov     w9, w9
        mov     x11, x9
        mov     x10, x10
        b     bb_while_5_139_cond
bb_while_5_139_cond:

        cmp     w10, w11
        b.lt     bb_while_5_139_whilestms
        b     bb_while_5_139_bre
bb_while_5_139_whilestms:

        mov     x9, #4
        mul     x9, x9, x10
        add     x9, x13, x9
        ldr     x9, [x9]
        mov     w9, w9
        mov     x12, #4
        mul     x12, x12, x10
        add     x12, x13, x12
        mov     x14, #4
        mul     x14, x14, x11
        add     x14, x13, x14
        ldr     x14, [x14]
        str     w14, [x12]
        mov     x12, #4
        mul     x12, x12, x11
        add     x12, x13, x12
        str     w9, [x12]
        mov     w9, #1
        add     w9, w10, w9
        mov     w10, w9
        mov     w9, #1
        sub     w9, w11, w9
        mov     w9, w9
        mov     x11, x9
        mov     x10, x10
        b     bb_while_5_139_cond
bb_while_5_139_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
arrCopy:

bb7:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x12, x0
        mov     x11, x1
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_152_cond
bb_while_5_152_cond:

        adrp     x10, n
        add     x10, x10, #:lo12:n
        ldr     x10, [x10]
        cmp     w9, w10
        b.lt     bb_while_5_152_whilestms
        b     bb_while_5_152_bre
bb_while_5_152_whilestms:

        mov     x10, #4
        mul     x10, x10, x9
        add     x10, x11, x10
        mov     x13, #4
        mul     x13, x13, x9
        add     x13, x12, x13
        ldr     x13, [x13]
        str     w13, [x10]
        mov     w10, #1
        add     w9, w9, w10
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_152_cond
bb_while_5_152_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
calSum:

bb8:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x12, x0
        mov     w10, w1
        mov     w9, #0
        mov     w11, w10
        mov     w9, #0
        mov     w9, #0
        mov     w13, w9
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x10, x9
        mov     x13, x13
        b     bb_while_5_164_cond
bb_while_5_164_cond:

        adrp     x9, n
        add     x9, x9, #:lo12:n
        ldr     x9, [x9]
        cmp     w10, w9
        b.lt     bb_while_5_164_whilestms
        b     bb_while_5_164_bre
bb_while_5_164_whilestms:

        mov     x9, #4
        mul     x9, x9, x10
        add     x9, x12, x9
        ldr     x9, [x9]
        add     w9, w13, w9
        mov     w9, w9
        sdiv     w13, w10, w11
        mul     w13, w13, w11
        sub     w14, w10, w13
        mov     w13, #1
        sub     w13, w11, w13
        cmp     w14, w13
        b.ne     bb_if_9_166_true
        b     bb_if_9_166_false
bb_if_9_166_true:

        mov     x13, #4
        mul     x13, x13, x10
        add     x14, x12, x13
        mov     w13, #0
        str     w13, [x14]
        mov     x13, x9
        b     bb_if_9_166_end
bb_if_9_166_false:

        mov     x13, #4
        mul     x13, x13, x10
        add     x13, x12, x13
        str     w9, [x13]
        mov     w9, #0
        mov     w9, w9
        mov     x13, x9
        b     bb_if_9_166_end
bb_if_9_166_end:

        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        mov     x13, x13
        b     bb_while_5_164_cond
bb_while_5_164_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
avgPooling:

bb9:

        mov     x16, #0
        sub     sp, sp, x16
        mov     x11, x0
        mov     w10, w1
        mov     w9, #0
        mov     w9, #0
        mov     w10, w10
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w14, w9
        mov     w9, #0
        mov     w13, w9
        mov     w9, #0
        mov     w12, w9
        mov     x9, x14
        mov     x13, x13
        mov     x12, x12
        b     bb_while_5_183_cond
bb_while_5_183_cond:

        adrp     x14, n
        add     x14, x14, #:lo12:n
        ldr     x14, [x14]
        cmp     w9, w14
        b.lt     bb_while_5_183_whilestms
        b     bb_while_5_183_bre
bb_while_5_183_whilestms:

        mov     w14, #1
        sub     w14, w10, w14
        cmp     w9, w14
        b.lt     bb_if_9_184_true
        b     bb_if_9_184_false
bb_if_9_184_true:

        mov     x14, #4
        mul     x14, x14, x9
        add     x14, x11, x14
        ldr     x14, [x14]
        add     w13, w13, w14
        mov     w13, w13
        mov     x13, x13
        mov     x12, x12
        b     bb_if_9_184_end
bb_if_9_184_false:

        mov     w14, #1
        sub     w14, w10, w14
        cmp     w9, w14
        b.eq     bb_if_13_187_true
        b     bb_if_13_187_false
bb_if_13_187_true:

        mov     x14, #4
        mov     x12, #0
        mul     x12, x14, x12
        add     x12, x11, x12
        ldr     x12, [x12]
        mov     w12, w12
        mov     x15, #4
        mov     x14, #0
        mul     x14, x15, x14
        add     x15, x11, x14
        sdiv     w14, w13, w10
        str     w14, [x15]
        mov     x13, x13
        mov     x12, x12
        b     bb_if_13_187_end
bb_if_13_187_false:

        mov     x14, #4
        mul     x14, x14, x9
        add     x14, x11, x14
        ldr     x14, [x14]
        add     w13, w13, w14
        sub     w12, w13, w12
        mov     w14, w12
        sub     w13, w9, w10
        mov     w12, #1
        add     w12, w13, w12
        mov     w13, w12
        mov     x12, #4
        mul     x12, x12, x13
        add     x12, x11, x12
        ldr     x12, [x12]
        mov     w12, w12
        mov     x15, #4
        mul     x13, x15, x13
        add     x15, x11, x13
        sdiv     w13, w14, w10
        str     w13, [x15]
        mov     x13, x14
        mov     x12, x12
        b     bb_if_13_187_end
bb_if_13_187_end:

        mov     x13, x13
        mov     x12, x12
        b     bb_if_9_184_end
bb_if_9_184_end:

        mov     w14, #1
        add     w9, w9, w14
        mov     w9, w9
        mov     x9, x9
        mov     x13, x13
        mov     x12, x12
        b     bb_while_5_183_cond
bb_while_5_183_bre:

        adrp     x9, n
        add     x9, x9, #:lo12:n
        ldr     x9, [x9]
        sub     w10, w9, w10
        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        b     bb_while_5_201_cond
bb_while_5_201_cond:

        adrp     x9, n
        add     x9, x9, #:lo12:n
        ldr     x9, [x9]
        cmp     w10, w9
        b.lt     bb_while_5_201_whilestms
        b     bb_while_5_201_bre
bb_while_5_201_whilestms:

        mov     x9, #4
        mul     x9, x9, x10
        add     x12, x11, x9
        mov     w9, #0
        str     w9, [x12]
        mov     w9, #1
        add     w9, w10, w9
        mov     w9, w9
        mov     x10, x9
        b     bb_while_5_201_cond
bb_while_5_201_bre:

        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
main:

bb10:

        mov     x16, #256
        sub     sp, sp, x16
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
        mov     w10, #32
        adrp     x9, n
        add     x9, x9, #:lo12:n
        str     w10, [x9]
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #7
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #1
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #23
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #2
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #89
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #3
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #26
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #4
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #282
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #5
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #254
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #6
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #27
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #7
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #5
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #8
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #83
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #9
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #273
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #10
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #574
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #11
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #905
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #12
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #354
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #13
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #657
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #14
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #935
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #15
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #264
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #16
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #639
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #17
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #459
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #18
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #29
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #19
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #68
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #20
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #929
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #21
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #756
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #22
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #452
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #23
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #279
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #24
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #58
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #25
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #87
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #26
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #96
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #27
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #36
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #28
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #39
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #29
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #28
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #30
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #1
        str     w9, [x10]
        mov     x10, #4
        mov     x9, #31
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x10, x9, x10
        mov     w9, #290
        str     w9, [x10]
        mov     w9, #0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     revert
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_250_cond
bb_while_5_250_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_250_whilestms
        b     bb_while_5_250_bre
bb_while_5_250_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_250_cond
bb_while_5_250_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     bubblesort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_257_cond
bb_while_5_257_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_257_whilestms
        b     bb_while_5_257_bre
bb_while_5_257_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_257_cond
bb_while_5_257_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getMid
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, w9
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
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     getMost
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, w9
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
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     bubblesort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_270_cond
bb_while_5_270_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_270_whilestms
        b     bb_while_5_270_bre
bb_while_5_270_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_270_cond
bb_while_5_270_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     insertsort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_279_cond
bb_while_5_279_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_279_whilestms
        b     bb_while_5_279_bre
bb_while_5_279_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_279_cond
bb_while_5_279_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     w10, #31
        mov     w12, w10
        mov     x11, #4
        mov     x10, #0
        mul     x11, x11, x10
        mov     x10, #-256
        add     x10, x29, x10
        add     x10, x10, x11
        mov     x0, x10
        mov     w1, w9
        mov     w2, w12
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     QuickSort
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     x9, x9
        b     bb_while_5_289_cond
bb_while_5_289_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_289_whilestms
        b     bb_while_5_289_bre
bb_while_5_289_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_289_cond
bb_while_5_289_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        mov     w9, #4
        mov     w1, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     calSum
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_298_cond
bb_while_5_298_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_298_whilestms
        b     bb_while_5_298_bre
bb_while_5_298_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_298_cond
bb_while_5_298_bre:

        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-128
        add     x9, x29, x9
        add     x11, x9, x10
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x11
        mov     x1, x9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     arrCopy
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     x10, #4
        mov     x9, #0
        mul     x10, x10, x9
        mov     x9, #-256
        add     x9, x29, x9
        add     x9, x9, x10
        mov     x0, x9
        mov     w9, #3
        mov     w1, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     avgPooling
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w9, #0
        mov     w9, w9
        mov     x9, x9
        b     bb_while_5_307_cond
bb_while_5_307_cond:

        mov     w10, #32
        cmp     w9, w10
        b.lt     bb_while_5_307_whilestms
        b     bb_while_5_307_bre
bb_while_5_307_whilestms:

        mov     x10, #4
        mul     x11, x10, x9
        mov     x10, #-256
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
        b     bb_while_5_307_cond
bb_while_5_307_bre:

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
        mov     w9, #0
        mov     w0, w9
        mov     sp, x29
        ret
