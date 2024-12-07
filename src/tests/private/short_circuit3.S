.section .data
.global    a
.global    b
.global    d
a:
        .quad   0
b:
        .quad   0
d:
        .quad   0
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global set_a
.global set_b
.global set_d
.global main
set_a:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     w9, #0
        mov     w10, w10
        adrp     x9, a
        add     x9, x9, #:lo12:a
        str     w10, [x9]
        adrp     x9, a
        add     x9, x9, #:lo12:a
        ldr     x9, [x9]
        mov     w0, w9
        mov     sp, x29
        ret
set_b:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     w9, #0
        mov     w10, w10
        adrp     x9, b
        add     x9, x9, #:lo12:b
        str     w10, [x9]
        adrp     x9, b
        add     x9, x9, #:lo12:b
        ldr     x9, [x9]
        mov     w0, w9
        mov     sp, x29
        ret
set_d:

bb3:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w10, w0
        mov     w9, #0
        mov     w10, w10
        adrp     x9, d
        add     x9, x9, #:lo12:d
        str     w10, [x9]
        adrp     x9, d
        add     x9, x9, #:lo12:d
        ldr     x9, [x9]
        mov     w0, w9
        mov     sp, x29
        ret
main:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
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
        mov     w10, #2
        adrp     x9, a
        add     x9, x9, #:lo12:a
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, b
        add     x9, x9, #:lo12:b
        str     w10, [x9]
        mov     w9, #0
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_a
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     w9, #0
        cmp     w10, w9
        b.ne     bb26_13_next
        b     bb_if_5_13_false
bb26_13_next:

        mov     w9, #1
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_b
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     w9, #0
        cmp     w10, w9
        b.ne     bb_if_5_13_true
        b     bb_if_5_13_false
bb_if_5_13_true:

        b     bb_if_5_13_end
bb_if_5_13_false:

        b     bb_if_5_13_end
bb_if_5_13_end:

        adrp     x9, a
        add     x9, x9, #:lo12:a
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
        mov     w9, #32
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
        adrp     x9, b
        add     x9, x9, #:lo12:b
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
        mov     w9, #32
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
        mov     w10, #2
        adrp     x9, a
        add     x9, x9, #:lo12:a
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, b
        add     x9, x9, #:lo12:b
        str     w10, [x9]
        mov     w9, #0
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_a
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     w9, #0
        cmp     w10, w9
        b.ne     bb26_18_next
        b     bb_if_5_18_false
bb26_18_next:

        mov     w9, #1
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_b
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     w9, #0
        cmp     w10, w9
        b.ne     bb_if_5_18_true
        b     bb_if_5_18_false
bb_if_5_18_true:

        b     bb_if_5_18_end
bb_if_5_18_false:

        b     bb_if_5_18_end
bb_if_5_18_end:

        adrp     x9, a
        add     x9, x9, #:lo12:a
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
        mov     w9, #32
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
        adrp     x9, b
        add     x9, x9, #:lo12:b
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
        mov     w9, #1
        mov     w9, w9
        mov     w11, #2
        adrp     x10, d
        add     x10, x10, #:lo12:d
        str     w11, [x10]
        mov     w10, #1
        cmp     w9, w10
        b.ge     bb21_24_next
        b     bb_if_5_24_false
bb21_24_next:

        mov     w10, #3
        mov     w0, w10
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_d
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x11, x0
        mov     w10, #0
        cmp     w11, w10
        b.ne     bb_if_5_24_true
        b     bb_if_5_24_false
bb_if_5_24_true:

        b     bb_if_5_24_end
bb_if_5_24_false:

        b     bb_if_5_24_end
bb_if_5_24_end:

        adrp     x10, d
        add     x10, x10, #:lo12:d
        ldr     x10, [x10]
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
        mov     w10, #32
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
        mov     w10, #1
        cmp     w9, w10
        b.le     bb_if_5_26_true
        b     bb21_26_next
bb21_26_next:

        mov     w9, #4
        mov     w0, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     set_d
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        mov     w9, #0
        cmp     w10, w9
        b.ne     bb_if_5_26_true
        b     bb_if_5_26_false
bb_if_5_26_true:

        b     bb_if_5_26_end
bb_if_5_26_false:

        b     bb_if_5_26_end
bb_if_5_26_end:

        adrp     x9, d
        add     x9, x9, #:lo12:d
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
        mov     w13, w9
        mov     w9, #1
        mov     w12, w9
        mov     w9, #2
        mov     w11, w9
        mov     w9, #3
        mov     w10, w9
        mov     w9, #4
        mov     w9, w9
        b     bb_while_5_37_cond
bb_while_5_37_cond:

        mov     w14, #0
        cmp     w13, w14
        b.ne     bb23_37_next
        b     bb_while_5_37_bre
bb23_37_next:

        mov     w14, #0
        cmp     w12, w14
        b.ne     bb_while_5_37_whilestms
        b     bb_while_5_37_bre
bb_while_5_37_whilestms:

        mov     w14, #32
        mov     w0, w14
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
        b     bb_while_5_37_cond
bb_while_5_37_bre:

        mov     w14, #0
        cmp     w13, w14
        b.ne     bb_if_5_38_true
        b     bb20_38_next
bb20_38_next:

        mov     w14, #0
        cmp     w12, w14
        b.ne     bb_if_5_38_true
        b     bb_if_5_38_false
bb_if_5_38_true:

        mov     w14, #67
        mov     w0, w14
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
        b     bb_if_5_38_end
bb_if_5_38_false:

        b     bb_if_5_38_end
bb_if_5_38_end:

        cmp     w13, w12
        b.ge     bb_if_5_39_true
        b     bb23_39_next
bb23_39_next:

        cmp     w12, w13
        b.le     bb_if_5_39_true
        b     bb_if_5_39_false
bb_if_5_39_true:

        mov     w13, #72
        mov     w0, w13
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
        b     bb_if_5_39_end
bb_if_5_39_false:

        b     bb_if_5_39_end
bb_if_5_39_end:

        cmp     w11, w12
        b.ge     bb23_40_next
        b     bb_if_5_40_false
bb23_40_next:

        cmp     w9, w10
        b.ne     bb_if_5_40_true
        b     bb_if_5_40_false
bb_if_5_40_true:

        mov     w11, #73
        mov     w0, w11
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
        b     bb_if_5_40_end
bb_if_5_40_false:

        b     bb_if_5_40_end
bb_if_5_40_end:

        mov     w11, #0
        cmp     w12, w11
        b.ne     bb36_41_next
        b     bb23_41_next
bb23_41_next:

        cmp     w10, w10
        b.lt     bb_if_5_41_true
        b     bb36_41_next
bb36_41_next:

        cmp     w9, w9
        b.ge     bb_if_5_41_true
        b     bb_if_5_41_false
bb_if_5_41_true:

        mov     w11, #74
        mov     w0, w11
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
        b     bb_if_5_41_end
bb_if_5_41_false:

        b     bb_if_5_41_end
bb_if_5_41_end:

        mov     w11, #0
        cmp     w12, w11
        b.ne     bb23_42_next
        b     bb_if_5_42_true
bb23_42_next:

        cmp     w10, w10
        b.lt     bb36_42_next
        b     bb_if_5_42_false
bb36_42_next:

        cmp     w9, w9
        b.ge     bb_if_5_42_true
        b     bb_if_5_42_false
bb_if_5_42_true:

        mov     w9, #75
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
        b     bb_if_5_42_end
bb_if_5_42_false:

        b     bb_if_5_42_end
bb_if_5_42_end:

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
