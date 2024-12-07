.section .data
.global    arr1
.global    arr2
arr1:
        .zero   268800
arr2:
        .zero   268800
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global loop1
.global loop2
.global loop3
.global main
loop1:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #88
        mov     w12, w0
        mov     w10, w1
        mov     w9, #0
        mov     w16, w12
        str     w16, [sp,#32]
        mov     w9, #0
        mov     w16, w10
        str     w16, [sp,#24]
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_3_34_cond
bb_while_3_34_cond:

        ldr     w16, [sp,#16]
        ldr     w17, [sp,#32]
        cmp     w16, w17
        b.lt     bb21_34_next
        b     bb_while_3_34_bre
bb21_34_next:

        ldr     w16, [sp,#16]
        ldr     w17, [sp,#24]
        cmp     w16, w17
        b.lt     bb_while_3_34_whilestms
        b     bb_while_3_34_bre
bb_while_3_34_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_5_36_cond
bb_while_5_36_cond:

        mov     w9, #2
        ldr     w16, [sp,#8]
        cmp     w16, w9
        b.lt     bb_while_5_36_whilestms
        b     bb_while_5_36_bre
bb_while_5_36_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_7_38_cond
bb_while_7_38_cond:

        mov     w9, #3
        ldr     w16, [sp]
        cmp     w16, w9
        b.lt     bb_while_7_38_whilestms
        b     bb_while_7_38_bre
bb_while_7_38_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x15, x9
        b     bb_while_9_40_cond
bb_while_9_40_cond:

        mov     w9, #4
        cmp     w15, w9
        b.lt     bb_while_9_40_whilestms
        b     bb_while_9_40_bre
bb_while_9_40_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x9
        b     bb_while_11_42_cond
bb_while_11_42_cond:

        mov     w9, #5
        cmp     w14, w9
        b.lt     bb_while_11_42_whilestms
        b     bb_while_11_42_bre
bb_while_11_42_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x13, x9
        b     bb_while_13_44_cond
bb_while_13_44_cond:

        mov     w9, #6
        cmp     w13, w9
        b.lt     bb_while_13_44_whilestms
        b     bb_while_13_44_bre
bb_while_13_44_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x12, x9
        b     bb_while_15_46_cond
bb_while_15_46_cond:

        mov     w9, #2
        cmp     w12, w9
        b.lt     bb_while_15_46_whilestms
        b     bb_while_15_46_bre
bb_while_15_46_whilestms:

        mov     x9, #26880
        ldr     x16, [sp,#16]
        mul     x10, x9, x16
        adrp     x9, arr1
        add     x9, x9, #:lo12:arr1
        add     x16, x9, x10
        str     x16, [sp,#80]
        mov     x10, #26880
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#80]
        add     x10, x16, x9
        mov     x9, #13440
        ldr     x16, [sp,#8]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#72]
        mov     x10, #13440
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#72]
        add     x10, x16, x9
        mov     x9, #4480
        ldr     x16, [sp]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#64]
        mov     x10, #4480
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#64]
        add     x10, x16, x9
        mov     x9, #1120
        mul     x9, x9, x15
        add     x16, x10, x9
        str     x16, [sp,#56]
        mov     x10, #1120
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#56]
        add     x10, x16, x9
        mov     x9, #224
        mul     x9, x9, x14
        add     x16, x10, x9
        str     x16, [sp,#48]
        mov     x10, #224
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x10, x16, x9
        mov     x9, #28
        mul     x9, x9, x13
        add     x16, x10, x9
        str     x16, [sp,#40]
        mov     x10, #28
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x10, x16, x9
        mov     x9, #4
        mul     x9, x9, x12
        add     x10, x10, x9
        ldr     w16, [sp,#16]
        ldr     w17, [sp,#8]
        add     w9, w16, w17
        ldr     w16, [sp]
        add     w9, w9, w16
        add     w9, w9, w15
        add     w9, w9, w14
        add     w9, w9, w13
        add     w9, w9, w12
        ldr     w16, [sp,#32]
        add     w9, w9, w16
        ldr     w16, [sp,#24]
        add     w9, w9, w16
        str     w9, [x10]
        mov     w9, #1
        add     w9, w12, w9
        mov     w9, w9
        mov     x12, x9
        b     bb_while_15_46_cond
bb_while_15_46_bre:

        mov     w9, #1
        add     w9, w13, w9
        mov     w9, w9
        mov     x13, x9
        b     bb_while_13_44_cond
bb_while_13_44_bre:

        mov     w9, #1
        add     w9, w14, w9
        mov     w9, w9
        mov     x14, x9
        b     bb_while_11_42_cond
bb_while_11_42_bre:

        mov     w9, #1
        add     w9, w15, w9
        mov     w9, w9
        mov     x15, x9
        b     bb_while_9_40_cond
bb_while_9_40_bre:

        mov     w9, #1
        ldr     w16, [sp]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_7_38_cond
bb_while_7_38_bre:

        mov     w9, #1
        ldr     w16, [sp,#8]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_5_36_cond
bb_while_5_36_bre:

        mov     w9, #1
        ldr     w16, [sp,#16]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_3_34_cond
bb_while_3_34_bre:

        movz     w11, #65535, LSL #16
        movk     w11, #65535, LSL #0
        mov     w0, w11
        mov     sp, x29
        ret
loop2:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #72
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_3_73_cond
bb_while_3_73_cond:

        mov     w9, #10
        ldr     w16, [sp,#16]
        cmp     w16, w9
        b.lt     bb_while_3_73_whilestms
        b     bb_while_3_73_bre
bb_while_3_73_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_5_75_cond
bb_while_5_75_cond:

        mov     w9, #2
        ldr     w16, [sp,#8]
        cmp     w16, w9
        b.lt     bb_while_5_75_whilestms
        b     bb_while_5_75_bre
bb_while_5_75_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_7_77_cond
bb_while_7_77_cond:

        mov     w9, #3
        ldr     w16, [sp]
        cmp     w16, w9
        b.lt     bb_while_7_77_whilestms
        b     bb_while_7_77_bre
bb_while_7_77_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x15, x9
        b     bb_while_9_79_cond
bb_while_9_79_cond:

        mov     w9, #2
        cmp     w15, w9
        b.lt     bb_while_9_79_whilestms
        b     bb_while_9_79_bre
bb_while_9_79_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x9
        b     bb_while_11_81_cond
bb_while_11_81_cond:

        mov     w9, #4
        cmp     w14, w9
        b.lt     bb_while_11_81_whilestms
        b     bb_while_11_81_bre
bb_while_11_81_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x13, x9
        b     bb_while_13_83_cond
bb_while_13_83_cond:

        mov     w9, #8
        cmp     w13, w9
        b.lt     bb_while_13_83_whilestms
        b     bb_while_13_83_bre
bb_while_13_83_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x12, x9
        b     bb_while_15_85_cond
bb_while_15_85_cond:

        mov     w9, #7
        cmp     w12, w9
        b.lt     bb_while_15_85_whilestms
        b     bb_while_15_85_bre
bb_while_15_85_whilestms:

        mov     x9, #26880
        ldr     x16, [sp,#16]
        mul     x10, x9, x16
        adrp     x9, arr2
        add     x9, x9, #:lo12:arr2
        add     x16, x9, x10
        str     x16, [sp,#64]
        mov     x10, #26880
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#64]
        add     x10, x16, x9
        mov     x9, #13440
        ldr     x16, [sp,#8]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#56]
        mov     x10, #13440
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#56]
        add     x10, x16, x9
        mov     x9, #4480
        ldr     x16, [sp]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#48]
        mov     x10, #4480
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#48]
        add     x10, x16, x9
        mov     x9, #1120
        mul     x9, x9, x15
        add     x16, x10, x9
        str     x16, [sp,#40]
        mov     x10, #1120
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#40]
        add     x10, x16, x9
        mov     x9, #224
        mul     x9, x9, x14
        add     x16, x10, x9
        str     x16, [sp,#32]
        mov     x10, #224
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#32]
        add     x10, x16, x9
        mov     x9, #28
        mul     x9, x9, x13
        add     x16, x10, x9
        str     x16, [sp,#24]
        mov     x10, #28
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#24]
        add     x10, x16, x9
        mov     x9, #4
        mul     x9, x9, x12
        add     x10, x10, x9
        ldr     w16, [sp,#16]
        ldr     w17, [sp,#8]
        add     w9, w16, w17
        add     w9, w9, w15
        add     w9, w9, w12
        str     w9, [x10]
        mov     w9, #1
        add     w9, w12, w9
        mov     w9, w9
        mov     x12, x9
        b     bb_while_15_85_cond
bb_while_15_85_bre:

        mov     w9, #1
        add     w9, w13, w9
        mov     w9, w9
        mov     x13, x9
        b     bb_while_13_83_cond
bb_while_13_83_bre:

        mov     w9, #1
        add     w9, w14, w9
        mov     w9, w9
        mov     x14, x9
        b     bb_while_11_81_cond
bb_while_11_81_bre:

        mov     w9, #1
        add     w9, w15, w9
        mov     w9, w9
        mov     x15, x9
        b     bb_while_9_79_cond
bb_while_9_79_bre:

        mov     w9, #1
        ldr     w16, [sp]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_7_77_cond
bb_while_7_77_bre:

        mov     w9, #1
        ldr     w16, [sp,#8]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_5_75_cond
bb_while_5_75_bre:

        mov     w9, #1
        ldr     w16, [sp,#16]
        add     w9, w16, w9
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_3_73_cond
bb_while_3_73_bre:

        movz     w11, #65535, LSL #16
        movk     w11, #65535, LSL #0
        mov     w0, w11
        mov     sp, x29
        ret
loop3:

bb3:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #232
        mov     w16, w0
        str     w16, [sp,#224]
        mov     w16, w1
        str     w16, [sp,#216]
        mov     w16, w2
        str     w16, [sp,#208]
        mov     w16, w3
        str     w16, [sp,#200]
        mov     w15, w4
        mov     w14, w5
        mov     w10, w6
        mov     w9, #0
        ldr     w16, [sp,#224]
        mov     w17, w16
        str     w17, [sp,#96]
        mov     w9, #0
        ldr     w16, [sp,#216]
        mov     w17, w16
        str     w17, [sp,#88]
        mov     w9, #0
        ldr     w16, [sp,#208]
        mov     w17, w16
        str     w17, [sp,#80]
        mov     w9, #0
        ldr     w16, [sp,#200]
        mov     w17, w16
        str     w17, [sp,#72]
        mov     w9, #0
        mov     w16, w15
        str     w16, [sp,#64]
        mov     w9, #0
        mov     w16, w14
        str     w16, [sp,#56]
        mov     w9, #0
        mov     w16, w10
        str     w16, [sp,#48]
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w9, #0
        mov     w10, w9
        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#40]
        mov     x10, x10
        b     bb_while_3_113_cond
bb_while_3_113_cond:

        mov     w9, #10
        ldr     w16, [sp,#40]
        cmp     w16, w9
        mov     x9, x10
        b.lt     bb_while_3_113_whilestms
        b     bb_while_3_113_bre
bb_while_3_113_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#32]
        mov     x14, x10
        b     bb_while_5_115_cond
bb_while_5_115_cond:

        mov     w9, #100
        ldr     w16, [sp,#32]
        cmp     w16, w9
        mov     x10, x14
        b.lt     bb_while_5_115_whilestms
        b     bb_while_5_115_bre
bb_while_5_115_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x16, x9
        str     x16, [sp,#24]
        mov     x14, x14
        b     bb_while_7_117_cond
bb_while_7_117_cond:

        mov     w9, #1000
        ldr     w16, [sp,#24]
        cmp     w16, w9
        mov     x10, x14
        b.lt     bb_while_7_117_whilestms
        b     bb_while_7_117_bre
bb_while_7_117_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x14
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_9_119_cond
bb_while_9_119_cond:

        mov     w9, #10000
        ldr     w16, [sp,#16]
        cmp     w16, w9
        mov     x10, x14
        b.lt     bb_while_9_119_whilestms
        b     bb_while_9_119_bre
bb_while_9_119_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x14
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_11_121_cond
bb_while_11_121_cond:

        movz     w13, #1, LSL #16
        movk     w13, #34464, LSL #0
        ldr     w16, [sp,#8]
        cmp     w16, w13
        mov     x10, x14
        b.lt     bb_while_11_121_whilestms
        b     bb_while_11_121_bre
bb_while_11_121_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x14, x14
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_13_123_cond
bb_while_13_123_cond:

        movz     w12, #15, LSL #16
        movk     w12, #16960, LSL #0
        ldr     w16, [sp]
        cmp     w16, w12
        mov     x10, x14
        b.lt     bb_while_13_123_whilestms
        b     bb_while_13_123_bre
bb_while_13_123_whilestms:

        mov     w9, #0
        mov     w9, w9
        mov     x15, x9
        mov     x14, x14
        b     bb_while_15_125_cond
bb_while_15_125_cond:

        movz     w11, #152, LSL #16
        movk     w11, #38528, LSL #0
        cmp     w15, w11
        mov     x10, x14
        b.lt     bb_while_15_125_whilestms
        b     bb_while_15_125_bre
bb_while_15_125_whilestms:

        mov     w9, #817
        sdiv     w10, w14, w9
        mov     w9, #817
        mul     w9, w10, w9
        sub     w14, w14, w9
        mov     x9, #26880
        ldr     x16, [sp,#40]
        mul     x10, x9, x16
        adrp     x9, arr1
        add     x9, x9, #:lo12:arr1
        add     x16, x9, x10
        str     x16, [sp,#192]
        mov     x10, #26880
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#192]
        add     x10, x16, x9
        mov     x9, #13440
        ldr     x16, [sp,#32]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#184]
        mov     x10, #13440
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#184]
        add     x10, x16, x9
        mov     x9, #4480
        ldr     x16, [sp,#24]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#176]
        mov     x10, #4480
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#176]
        add     x10, x16, x9
        mov     x9, #1120
        ldr     x16, [sp,#16]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#168]
        mov     x10, #1120
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#168]
        add     x10, x16, x9
        mov     x9, #224
        ldr     x16, [sp,#8]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#160]
        mov     x10, #224
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#160]
        add     x10, x16, x9
        mov     x9, #28
        ldr     x16, [sp]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#152]
        mov     x10, #28
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#152]
        add     x10, x16, x9
        mov     x9, #4
        mul     x9, x9, x15
        add     x9, x10, x9
        ldr     x9, [x9]
        add     w14, w14, w9
        mov     x9, #26880
        ldr     x16, [sp,#40]
        mul     x10, x9, x16
        adrp     x9, arr2
        add     x9, x9, #:lo12:arr2
        add     x16, x9, x10
        str     x16, [sp,#144]
        mov     x10, #26880
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#144]
        add     x10, x16, x9
        mov     x9, #13440
        ldr     x16, [sp,#32]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#136]
        mov     x10, #13440
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#136]
        add     x10, x16, x9
        mov     x9, #4480
        ldr     x16, [sp,#24]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#128]
        mov     x10, #4480
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#128]
        add     x10, x16, x9
        mov     x9, #1120
        ldr     x16, [sp,#16]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#120]
        mov     x10, #1120
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#120]
        add     x10, x16, x9
        mov     x9, #224
        ldr     x16, [sp,#8]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#112]
        mov     x10, #224
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#112]
        add     x10, x16, x9
        mov     x9, #28
        ldr     x16, [sp]
        mul     x9, x9, x16
        add     x16, x10, x9
        str     x16, [sp,#104]
        mov     x10, #28
        mov     x9, #0
        mul     x9, x10, x9
        ldr     x16, [sp,#104]
        add     x10, x16, x9
        mov     x9, #4
        mul     x9, x9, x15
        add     x9, x10, x9
        ldr     x9, [x9]
        add     w9, w14, w9
        mov     w10, w9
        mov     w9, #1
        add     w9, w15, w9
        mov     w9, w9
        ldr     w16, [sp,#48]
        cmp     w9, w16
        b.ge     bb_if_17_128_true
        b     bb_if_17_128_false
bb_if_17_128_true:

        mov     x10, x10
        b     bb_while_15_125_bre
bb_if_17_128_false:

        b     bb_if_17_128_end
bb_if_17_128_end:

        mov     x15, x9
        mov     x14, x10
        b     bb_while_15_125_cond
bb_while_15_125_bre:

        mov     w9, #1
        ldr     w16, [sp]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#56]
        cmp     w9, w16
        b.ge     bb_if_15_131_true
        b     bb_if_15_131_false
bb_if_15_131_true:

        mov     x10, x10
        b     bb_while_13_123_bre
bb_if_15_131_false:

        b     bb_if_15_131_end
bb_if_15_131_end:

        mov     x14, x10
        mov     x16, x9
        str     x16, [sp]
        b     bb_while_13_123_cond
bb_while_13_123_bre:

        mov     w9, #1
        ldr     w16, [sp,#8]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#64]
        cmp     w9, w16
        b.ge     bb_if_13_134_true
        b     bb_if_13_134_false
bb_if_13_134_true:

        mov     x10, x10
        b     bb_while_11_121_bre
bb_if_13_134_false:

        b     bb_if_13_134_end
bb_if_13_134_end:

        mov     x14, x10
        mov     x16, x9
        str     x16, [sp,#8]
        b     bb_while_11_121_cond
bb_while_11_121_bre:

        mov     w9, #1
        ldr     w16, [sp,#16]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#72]
        cmp     w9, w16
        b.ge     bb_if_11_137_true
        b     bb_if_11_137_false
bb_if_11_137_true:

        mov     x10, x10
        b     bb_while_9_119_bre
bb_if_11_137_false:

        b     bb_if_11_137_end
bb_if_11_137_end:

        mov     x14, x10
        mov     x16, x9
        str     x16, [sp,#16]
        b     bb_while_9_119_cond
bb_while_9_119_bre:

        mov     w9, #1
        ldr     w16, [sp,#24]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#80]
        cmp     w9, w16
        b.ge     bb_if_9_140_true
        b     bb_if_9_140_false
bb_if_9_140_true:

        mov     x10, x10
        b     bb_while_7_117_bre
bb_if_9_140_false:

        b     bb_if_9_140_end
bb_if_9_140_end:

        mov     x16, x9
        str     x16, [sp,#24]
        mov     x14, x10
        b     bb_while_7_117_cond
bb_while_7_117_bre:

        mov     w9, #1
        ldr     w16, [sp,#32]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#88]
        cmp     w9, w16
        b.ge     bb_if_7_143_true
        b     bb_if_7_143_false
bb_if_7_143_true:

        mov     x10, x10
        b     bb_while_5_115_bre
bb_if_7_143_false:

        b     bb_if_7_143_end
bb_if_7_143_end:

        mov     x16, x9
        str     x16, [sp,#32]
        mov     x14, x10
        b     bb_while_5_115_cond
bb_while_5_115_bre:

        mov     w9, #1
        ldr     w16, [sp,#40]
        add     w9, w16, w9
        mov     w9, w9
        ldr     w16, [sp,#96]
        cmp     w9, w16
        b.ge     bb_if_5_146_true
        b     bb_if_5_146_false
bb_if_5_146_true:

        mov     x9, x10
        b     bb_while_3_113_bre
bb_if_5_146_false:

        b     bb_if_5_146_end
bb_if_5_146_end:

        mov     x16, x9
        str     x16, [sp,#40]
        mov     x10, x10
        b     bb_while_3_113_cond
bb_while_3_113_bre:

        mov     w0, w9
        mov     sp, x29
        ret
main:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #16
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
        mov     w16, w9
        str     w16, [sp,#8]
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
        mov     w16, w9
        str     w16, [sp]
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
        mov     w12, w9
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
        mov     w11, w9
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
        mov     w9, w9
        ldr     w16, [sp,#8]
        mov     w0, w16
        ldr     w16, [sp]
        mov     w1, w16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     loop1
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     loop2
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     w0, w15
        mov     w1, w14
        mov     w2, w13
        mov     w3, w12
        mov     w4, w11
        mov     w5, w10
        mov     w6, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     loop3
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x9, x0
        mov     w10, w9
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
        mov     w0, w10
        mov     sp, x29
        ret
