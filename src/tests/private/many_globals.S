.section .data
.global    a0
.global    a1
.global    a2
.global    a3
.global    a4
.global    a5
.global    a6
.global    a7
.global    a8
.global    a9
.global    a10
.global    a11
.global    a12
.global    a13
.global    a14
.global    a15
.global    a16
.global    a17
.global    a18
.global    a19
.global    a20
.global    a21
.global    a22
.global    a23
.global    a24
.global    a25
.global    a26
.global    a27
.global    a28
.global    a29
.global    a30
.global    a31
.global    a32
.global    a33
.global    a34
.global    a35
.global    a36
.global    a37
.global    a38
.global    a39
a0:
        .quad   0
a1:
        .quad   0
a2:
        .quad   0
a3:
        .quad   0
a4:
        .quad   0
a5:
        .quad   0
a6:
        .quad   0
a7:
        .quad   0
a8:
        .quad   0
a9:
        .quad   0
a10:
        .quad   0
a11:
        .quad   0
a12:
        .quad   0
a13:
        .quad   0
a14:
        .quad   0
a15:
        .quad   0
a16:
        .quad   0
a17:
        .quad   0
a18:
        .quad   0
a19:
        .quad   0
a20:
        .quad   0
a21:
        .quad   0
a22:
        .quad   0
a23:
        .quad   0
a24:
        .quad   0
a25:
        .quad   0
a26:
        .quad   0
a27:
        .quad   0
a28:
        .quad   0
a29:
        .quad   0
a30:
        .quad   0
a31:
        .quad   0
a32:
        .quad   0
a33:
        .quad   0
a34:
        .quad   0
a35:
        .quad   0
a36:
        .quad   0
a37:
        .quad   0
a38:
        .quad   0
a39:
        .quad   0
.section .text
.global getch
.global getint
.global putch
.global putint
.global putarray
.global _sysy_starttime
.global _sysy_stoptime
.global testParam8
.global testParam16
.global testParam32
.global main
testParam8:

bb1:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #24
        mov     w16, w0
        str     w16, [sp,#16]
        mov     w15, w1
        mov     w14, w2
        mov     w13, w3
        mov     w12, w4
        mov     w11, w5
        mov     w10, w6
        mov     w16, w7
        str     w16, [sp,#8]
        mov     w9, #0
        ldr     w16, [sp,#16]
        mov     w17, w16
        str     w17, [sp]
        mov     w9, #0
        mov     w15, w15
        mov     w9, #0
        mov     w14, w14
        mov     w9, #0
        mov     w13, w13
        mov     w9, #0
        mov     w12, w12
        mov     w9, #0
        mov     w11, w11
        mov     w9, #0
        mov     w10, w10
        mov     w9, #0
        ldr     w16, [sp,#8]
        mov     w9, w16
        ldr     w16, [sp]
        add     w15, w16, w15
        add     w14, w15, w14
        add     w13, w14, w13
        add     w12, w13, w12
        add     w11, w12, w11
        add     w10, w11, w10
        add     w9, w10, w9
        mov     w0, w9
        mov     sp, x29
        ret
testParam16:

bb2:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #160
        mov     w16, w0
        str     w16, [sp,#152]
        mov     w16, w1
        str     w16, [sp,#144]
        mov     w16, w2
        str     w16, [sp,#136]
        mov     w16, w3
        str     w16, [sp,#128]
        mov     w16, w4
        str     w16, [sp,#120]
        mov     w16, w5
        str     w16, [sp,#112]
        mov     w16, w6
        str     w16, [sp,#104]
        mov     w16, w7
        str     w16, [sp,#96]
        ldr     w9, [x29]
        mov     w16, w9
        str     w16, [sp,#88]
        ldr     w9, [x29,#8]
        mov     w16, w9
        str     w16, [sp,#80]
        ldr     w9, [x29,#16]
        mov     w15, w9
        ldr     w9, [x29,#24]
        mov     w14, w9
        ldr     w9, [x29,#32]
        mov     w13, w9
        ldr     w9, [x29,#40]
        mov     w12, w9
        ldr     w9, [x29,#48]
        mov     w11, w9
        ldr     w9, [x29,#56]
        mov     w10, w9
        mov     w9, #0
        ldr     w16, [sp,#152]
        mov     w17, w16
        str     w17, [sp,#72]
        mov     w9, #0
        ldr     w16, [sp,#144]
        mov     w17, w16
        str     w17, [sp,#64]
        mov     w9, #0
        ldr     w16, [sp,#136]
        mov     w17, w16
        str     w17, [sp,#56]
        mov     w9, #0
        ldr     w16, [sp,#128]
        mov     w17, w16
        str     w17, [sp,#48]
        mov     w9, #0
        ldr     w16, [sp,#120]
        mov     w17, w16
        str     w17, [sp,#40]
        mov     w9, #0
        ldr     w16, [sp,#112]
        mov     w17, w16
        str     w17, [sp,#32]
        mov     w9, #0
        ldr     w16, [sp,#104]
        mov     w17, w16
        str     w17, [sp,#24]
        mov     w9, #0
        ldr     w16, [sp,#96]
        mov     w17, w16
        str     w17, [sp,#16]
        mov     w9, #0
        ldr     w16, [sp,#88]
        mov     w17, w16
        str     w17, [sp,#8]
        mov     w9, #0
        ldr     w16, [sp,#80]
        mov     w17, w16
        str     w17, [sp]
        mov     w9, #0
        mov     w15, w15
        mov     w9, #0
        mov     w14, w14
        mov     w9, #0
        mov     w13, w13
        mov     w9, #0
        mov     w12, w12
        mov     w9, #0
        mov     w11, w11
        mov     w9, #0
        mov     w10, w10
        ldr     w16, [sp,#72]
        ldr     w17, [sp,#64]
        add     w9, w16, w17
        ldr     w16, [sp,#56]
        add     w9, w9, w16
        ldr     w16, [sp,#48]
        sub     w9, w9, w16
        ldr     w16, [sp,#40]
        sub     w9, w9, w16
        ldr     w16, [sp,#32]
        sub     w9, w9, w16
        ldr     w16, [sp,#24]
        sub     w9, w9, w16
        ldr     w16, [sp,#16]
        sub     w9, w9, w16
        ldr     w16, [sp,#8]
        add     w9, w9, w16
        ldr     w16, [sp]
        add     w9, w9, w16
        add     w9, w9, w15
        add     w9, w9, w14
        add     w9, w9, w13
        add     w9, w9, w12
        add     w9, w9, w11
        add     w9, w9, w10
        mov     w0, w9
        mov     sp, x29
        ret
testParam32:

bb3:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #416
        mov     w16, w0
        str     w16, [sp,#408]
        mov     w16, w1
        str     w16, [sp,#400]
        mov     w16, w2
        str     w16, [sp,#392]
        mov     w16, w3
        str     w16, [sp,#384]
        mov     w16, w4
        str     w16, [sp,#376]
        mov     w16, w5
        str     w16, [sp,#368]
        mov     w16, w6
        str     w16, [sp,#360]
        mov     w16, w7
        str     w16, [sp,#352]
        ldr     w9, [x29]
        mov     w16, w9
        str     w16, [sp,#344]
        ldr     w9, [x29,#8]
        mov     w16, w9
        str     w16, [sp,#336]
        ldr     w9, [x29,#16]
        mov     w16, w9
        str     w16, [sp,#328]
        ldr     w9, [x29,#24]
        mov     w16, w9
        str     w16, [sp,#320]
        ldr     w9, [x29,#32]
        mov     w16, w9
        str     w16, [sp,#312]
        ldr     w9, [x29,#40]
        mov     w16, w9
        str     w16, [sp,#304]
        ldr     w9, [x29,#48]
        mov     w16, w9
        str     w16, [sp,#296]
        ldr     w9, [x29,#56]
        mov     w16, w9
        str     w16, [sp,#288]
        ldr     w9, [x29,#64]
        mov     w16, w9
        str     w16, [sp,#280]
        ldr     w9, [x29,#72]
        mov     w16, w9
        str     w16, [sp,#272]
        ldr     w9, [x29,#80]
        mov     w16, w9
        str     w16, [sp,#264]
        ldr     w9, [x29,#88]
        mov     w16, w9
        str     w16, [sp,#256]
        ldr     w9, [x29,#96]
        mov     w16, w9
        str     w16, [sp,#248]
        ldr     w9, [x29,#104]
        mov     w16, w9
        str     w16, [sp,#240]
        ldr     w9, [x29,#112]
        mov     w16, w9
        str     w16, [sp,#232]
        ldr     w9, [x29,#120]
        mov     w16, w9
        str     w16, [sp,#224]
        ldr     w9, [x29,#128]
        mov     w16, w9
        str     w16, [sp,#216]
        ldr     w9, [x29,#136]
        mov     w16, w9
        str     w16, [sp,#208]
        ldr     w9, [x29,#144]
        mov     w15, w9
        ldr     w9, [x29,#152]
        mov     w14, w9
        ldr     w9, [x29,#160]
        mov     w13, w9
        ldr     w9, [x29,#168]
        mov     w12, w9
        ldr     w9, [x29,#176]
        mov     w11, w9
        ldr     w9, [x29,#184]
        mov     w10, w9
        mov     w9, #0
        ldr     w16, [sp,#408]
        mov     w17, w16
        str     w17, [sp,#200]
        mov     w9, #0
        ldr     w16, [sp,#400]
        mov     w17, w16
        str     w17, [sp,#192]
        mov     w9, #0
        ldr     w16, [sp,#392]
        mov     w17, w16
        str     w17, [sp,#184]
        mov     w9, #0
        ldr     w16, [sp,#384]
        mov     w17, w16
        str     w17, [sp,#176]
        mov     w9, #0
        ldr     w16, [sp,#376]
        mov     w17, w16
        str     w17, [sp,#168]
        mov     w9, #0
        ldr     w16, [sp,#368]
        mov     w17, w16
        str     w17, [sp,#160]
        mov     w9, #0
        ldr     w16, [sp,#360]
        mov     w17, w16
        str     w17, [sp,#152]
        mov     w9, #0
        ldr     w16, [sp,#352]
        mov     w17, w16
        str     w17, [sp,#144]
        mov     w9, #0
        ldr     w16, [sp,#344]
        mov     w17, w16
        str     w17, [sp,#136]
        mov     w9, #0
        ldr     w16, [sp,#336]
        mov     w17, w16
        str     w17, [sp,#128]
        mov     w9, #0
        ldr     w16, [sp,#328]
        mov     w17, w16
        str     w17, [sp,#120]
        mov     w9, #0
        ldr     w16, [sp,#320]
        mov     w17, w16
        str     w17, [sp,#112]
        mov     w9, #0
        ldr     w16, [sp,#312]
        mov     w17, w16
        str     w17, [sp,#104]
        mov     w9, #0
        ldr     w16, [sp,#304]
        mov     w17, w16
        str     w17, [sp,#96]
        mov     w9, #0
        ldr     w16, [sp,#296]
        mov     w17, w16
        str     w17, [sp,#88]
        mov     w9, #0
        ldr     w16, [sp,#288]
        mov     w17, w16
        str     w17, [sp,#80]
        mov     w9, #0
        ldr     w16, [sp,#280]
        mov     w17, w16
        str     w17, [sp,#72]
        mov     w9, #0
        ldr     w16, [sp,#272]
        mov     w17, w16
        str     w17, [sp,#64]
        mov     w9, #0
        ldr     w16, [sp,#264]
        mov     w17, w16
        str     w17, [sp,#56]
        mov     w9, #0
        ldr     w16, [sp,#256]
        mov     w17, w16
        str     w17, [sp,#48]
        mov     w9, #0
        ldr     w16, [sp,#248]
        mov     w17, w16
        str     w17, [sp,#40]
        mov     w9, #0
        ldr     w16, [sp,#240]
        mov     w17, w16
        str     w17, [sp,#32]
        mov     w9, #0
        ldr     w16, [sp,#232]
        mov     w17, w16
        str     w17, [sp,#24]
        mov     w9, #0
        ldr     w16, [sp,#224]
        mov     w17, w16
        str     w17, [sp,#16]
        mov     w9, #0
        ldr     w16, [sp,#216]
        mov     w17, w16
        str     w17, [sp,#8]
        mov     w9, #0
        ldr     w16, [sp,#208]
        mov     w17, w16
        str     w17, [sp]
        mov     w9, #0
        mov     w15, w15
        mov     w9, #0
        mov     w14, w14
        mov     w9, #0
        mov     w13, w13
        mov     w9, #0
        mov     w12, w12
        mov     w9, #0
        mov     w11, w11
        mov     w9, #0
        mov     w10, w10
        ldr     w16, [sp,#200]
        ldr     w17, [sp,#192]
        add     w9, w16, w17
        ldr     w16, [sp,#184]
        add     w9, w9, w16
        ldr     w16, [sp,#176]
        add     w9, w9, w16
        ldr     w16, [sp,#168]
        add     w9, w9, w16
        ldr     w16, [sp,#160]
        add     w9, w9, w16
        ldr     w16, [sp,#152]
        add     w9, w9, w16
        ldr     w16, [sp,#144]
        add     w9, w9, w16
        ldr     w16, [sp,#136]
        add     w9, w9, w16
        ldr     w16, [sp,#128]
        add     w9, w9, w16
        ldr     w16, [sp,#120]
        add     w9, w9, w16
        ldr     w16, [sp,#112]
        add     w9, w9, w16
        ldr     w16, [sp,#104]
        add     w9, w9, w16
        ldr     w16, [sp,#96]
        add     w9, w9, w16
        ldr     w16, [sp,#88]
        add     w9, w9, w16
        ldr     w16, [sp,#80]
        add     w9, w9, w16
        ldr     w16, [sp,#72]
        add     w9, w9, w16
        ldr     w16, [sp,#64]
        add     w9, w9, w16
        ldr     w16, [sp,#56]
        sub     w9, w9, w16
        ldr     w16, [sp,#48]
        sub     w9, w9, w16
        ldr     w16, [sp,#40]
        sub     w9, w9, w16
        ldr     w16, [sp,#32]
        sub     w9, w9, w16
        ldr     w16, [sp,#24]
        sub     w9, w9, w16
        ldr     w16, [sp,#16]
        add     w9, w9, w16
        ldr     w16, [sp,#8]
        add     w9, w9, w16
        ldr     w16, [sp]
        add     w9, w9, w16
        add     w9, w9, w15
        add     w9, w9, w14
        add     w9, w9, w13
        add     w9, w9, w12
        add     w9, w9, w11
        add     w9, w9, w10
        mov     w0, w9
        mov     sp, x29
        ret
main:

bb4:

        mov     x16, #0
        sub     sp, sp, x16
        sub     sp, sp, #280
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
        mov     w10, #0
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        str     w10, [x9]
        mov     w10, #1
        adrp     x9, a1
        add     x9, x9, #:lo12:a1
        str     w10, [x9]
        mov     w10, #2
        adrp     x9, a2
        add     x9, x9, #:lo12:a2
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, a3
        add     x9, x9, #:lo12:a3
        str     w10, [x9]
        mov     w10, #4
        adrp     x9, a4
        add     x9, x9, #:lo12:a4
        str     w10, [x9]
        mov     w10, #5
        adrp     x9, a5
        add     x9, x9, #:lo12:a5
        str     w10, [x9]
        mov     w10, #6
        adrp     x9, a6
        add     x9, x9, #:lo12:a6
        str     w10, [x9]
        mov     w10, #7
        adrp     x9, a7
        add     x9, x9, #:lo12:a7
        str     w10, [x9]
        mov     w10, #8
        adrp     x9, a8
        add     x9, x9, #:lo12:a8
        str     w10, [x9]
        mov     w10, #9
        adrp     x9, a9
        add     x9, x9, #:lo12:a9
        str     w10, [x9]
        mov     w10, #0
        adrp     x9, a10
        add     x9, x9, #:lo12:a10
        str     w10, [x9]
        mov     w10, #1
        adrp     x9, a11
        add     x9, x9, #:lo12:a11
        str     w10, [x9]
        mov     w10, #2
        adrp     x9, a12
        add     x9, x9, #:lo12:a12
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, a13
        add     x9, x9, #:lo12:a13
        str     w10, [x9]
        mov     w10, #4
        adrp     x9, a14
        add     x9, x9, #:lo12:a14
        str     w10, [x9]
        mov     w10, #5
        adrp     x9, a15
        add     x9, x9, #:lo12:a15
        str     w10, [x9]
        mov     w10, #6
        adrp     x9, a16
        add     x9, x9, #:lo12:a16
        str     w10, [x9]
        mov     w10, #7
        adrp     x9, a17
        add     x9, x9, #:lo12:a17
        str     w10, [x9]
        mov     w10, #8
        adrp     x9, a18
        add     x9, x9, #:lo12:a18
        str     w10, [x9]
        mov     w10, #9
        adrp     x9, a19
        add     x9, x9, #:lo12:a19
        str     w10, [x9]
        mov     w10, #0
        adrp     x9, a20
        add     x9, x9, #:lo12:a20
        str     w10, [x9]
        mov     w10, #1
        adrp     x9, a21
        add     x9, x9, #:lo12:a21
        str     w10, [x9]
        mov     w10, #2
        adrp     x9, a22
        add     x9, x9, #:lo12:a22
        str     w10, [x9]
        mov     w10, #3
        adrp     x9, a23
        add     x9, x9, #:lo12:a23
        str     w10, [x9]
        mov     w10, #4
        adrp     x9, a24
        add     x9, x9, #:lo12:a24
        str     w10, [x9]
        mov     w10, #5
        adrp     x9, a25
        add     x9, x9, #:lo12:a25
        str     w10, [x9]
        mov     w10, #6
        adrp     x9, a26
        add     x9, x9, #:lo12:a26
        str     w10, [x9]
        mov     w10, #7
        adrp     x9, a27
        add     x9, x9, #:lo12:a27
        str     w10, [x9]
        mov     w10, #8
        adrp     x9, a28
        add     x9, x9, #:lo12:a28
        str     w10, [x9]
        mov     w10, #9
        adrp     x9, a29
        add     x9, x9, #:lo12:a29
        str     w10, [x9]
        mov     w10, #0
        adrp     x9, a30
        add     x9, x9, #:lo12:a30
        str     w10, [x9]
        mov     w10, #1
        adrp     x9, a31
        add     x9, x9, #:lo12:a31
        str     w10, [x9]
        mov     w10, #4
        adrp     x9, a32
        add     x9, x9, #:lo12:a32
        str     w10, [x9]
        mov     w10, #5
        adrp     x9, a33
        add     x9, x9, #:lo12:a33
        str     w10, [x9]
        mov     w10, #6
        adrp     x9, a34
        add     x9, x9, #:lo12:a34
        str     w10, [x9]
        mov     w10, #7
        adrp     x9, a35
        add     x9, x9, #:lo12:a35
        str     w10, [x9]
        mov     w10, #8
        adrp     x9, a36
        add     x9, x9, #:lo12:a36
        str     w10, [x9]
        mov     w10, #9
        adrp     x9, a37
        add     x9, x9, #:lo12:a37
        str     w10, [x9]
        mov     w10, #0
        adrp     x9, a38
        add     x9, x9, #:lo12:a38
        str     w10, [x9]
        mov     w10, #1
        adrp     x9, a39
        add     x9, x9, #:lo12:a39
        str     w10, [x9]
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        ldr     x16, [x9]
        str     x16, [sp,#272]
        adrp     x9, a1
        add     x9, x9, #:lo12:a1
        ldr     x15, [x9]
        adrp     x9, a2
        add     x9, x9, #:lo12:a2
        ldr     x14, [x9]
        adrp     x9, a3
        add     x9, x9, #:lo12:a3
        ldr     x13, [x9]
        adrp     x9, a4
        add     x9, x9, #:lo12:a4
        ldr     x12, [x9]
        adrp     x9, a5
        add     x9, x9, #:lo12:a5
        ldr     x11, [x9]
        adrp     x9, a6
        add     x9, x9, #:lo12:a6
        ldr     x10, [x9]
        adrp     x9, a7
        add     x9, x9, #:lo12:a7
        ldr     x9, [x9]
        ldr     w16, [sp,#272]
        mov     w0, w16
        mov     w1, w15
        mov     w2, w14
        mov     w3, w13
        mov     w4, w12
        mov     w5, w11
        mov     w6, w10
        mov     w7, w9
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     x29, sp
        bl     testParam8
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        str     w10, [x9]
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
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
        adrp     x9, a32
        add     x9, x9, #:lo12:a32
        ldr     x16, [x9]
        str     x16, [sp,#264]
        adrp     x9, a33
        add     x9, x9, #:lo12:a33
        ldr     x16, [x9]
        str     x16, [sp,#256]
        adrp     x9, a34
        add     x9, x9, #:lo12:a34
        ldr     x16, [x9]
        str     x16, [sp,#248]
        adrp     x9, a35
        add     x9, x9, #:lo12:a35
        ldr     x16, [x9]
        str     x16, [sp,#240]
        adrp     x9, a36
        add     x9, x9, #:lo12:a36
        ldr     x16, [x9]
        str     x16, [sp,#232]
        adrp     x9, a37
        add     x9, x9, #:lo12:a37
        ldr     x16, [x9]
        str     x16, [sp,#224]
        adrp     x9, a38
        add     x9, x9, #:lo12:a38
        ldr     x16, [x9]
        str     x16, [sp,#216]
        adrp     x9, a39
        add     x9, x9, #:lo12:a39
        ldr     x16, [x9]
        str     x16, [sp,#208]
        adrp     x9, a8
        add     x9, x9, #:lo12:a8
        ldr     x16, [x9]
        str     x16, [sp,#200]
        adrp     x9, a9
        add     x9, x9, #:lo12:a9
        ldr     x15, [x9]
        adrp     x9, a10
        add     x9, x9, #:lo12:a10
        ldr     x14, [x9]
        adrp     x9, a11
        add     x9, x9, #:lo12:a11
        ldr     x13, [x9]
        adrp     x9, a12
        add     x9, x9, #:lo12:a12
        ldr     x12, [x9]
        adrp     x9, a13
        add     x9, x9, #:lo12:a13
        ldr     x11, [x9]
        adrp     x9, a14
        add     x9, x9, #:lo12:a14
        ldr     x10, [x9]
        adrp     x9, a15
        add     x9, x9, #:lo12:a15
        ldr     x9, [x9]
        ldr     w16, [sp,#264]
        mov     w0, w16
        ldr     w16, [sp,#256]
        mov     w1, w16
        ldr     w16, [sp,#248]
        mov     w2, w16
        ldr     w16, [sp,#240]
        mov     w3, w16
        ldr     w16, [sp,#232]
        mov     w4, w16
        ldr     w16, [sp,#224]
        mov     w5, w16
        ldr     w16, [sp,#216]
        mov     w6, w16
        ldr     w16, [sp,#208]
        mov     w7, w16
        mov     x28, sp
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     sp, x28
        str     w9, [sp,#-80]
        str     w10, [sp,#-88]
        str     w11, [sp,#-96]
        str     w12, [sp,#-104]
        str     w13, [sp,#-112]
        str     w14, [sp,#-120]
        str     w15, [sp,#-128]
        ldr     w16, [sp,#200]
        str     w16, [sp,#-136]
        sub     sp, sp, #136
        mov     x29, sp
        bl     testParam16
        add     sp, sp, #64
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        str     w10, [x9]
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
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
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        ldr     x16, [x9]
        str     x16, [sp,#192]
        adrp     x9, a1
        add     x9, x9, #:lo12:a1
        ldr     x16, [x9]
        str     x16, [sp,#184]
        adrp     x9, a2
        add     x9, x9, #:lo12:a2
        ldr     x16, [x9]
        str     x16, [sp,#176]
        adrp     x9, a3
        add     x9, x9, #:lo12:a3
        ldr     x16, [x9]
        str     x16, [sp,#168]
        adrp     x9, a4
        add     x9, x9, #:lo12:a4
        ldr     x16, [x9]
        str     x16, [sp,#160]
        adrp     x9, a5
        add     x9, x9, #:lo12:a5
        ldr     x16, [x9]
        str     x16, [sp,#152]
        adrp     x9, a6
        add     x9, x9, #:lo12:a6
        ldr     x16, [x9]
        str     x16, [sp,#144]
        adrp     x9, a7
        add     x9, x9, #:lo12:a7
        ldr     x16, [x9]
        str     x16, [sp,#136]
        adrp     x9, a8
        add     x9, x9, #:lo12:a8
        ldr     x16, [x9]
        str     x16, [sp,#128]
        adrp     x9, a9
        add     x9, x9, #:lo12:a9
        ldr     x16, [x9]
        str     x16, [sp,#120]
        adrp     x9, a10
        add     x9, x9, #:lo12:a10
        ldr     x16, [x9]
        str     x16, [sp,#112]
        adrp     x9, a11
        add     x9, x9, #:lo12:a11
        ldr     x16, [x9]
        str     x16, [sp,#104]
        adrp     x9, a12
        add     x9, x9, #:lo12:a12
        ldr     x16, [x9]
        str     x16, [sp,#96]
        adrp     x9, a13
        add     x9, x9, #:lo12:a13
        ldr     x16, [x9]
        str     x16, [sp,#88]
        adrp     x9, a14
        add     x9, x9, #:lo12:a14
        ldr     x16, [x9]
        str     x16, [sp,#80]
        adrp     x9, a15
        add     x9, x9, #:lo12:a15
        ldr     x16, [x9]
        str     x16, [sp,#72]
        adrp     x9, a16
        add     x9, x9, #:lo12:a16
        ldr     x16, [x9]
        str     x16, [sp,#64]
        adrp     x9, a17
        add     x9, x9, #:lo12:a17
        ldr     x16, [x9]
        str     x16, [sp,#56]
        adrp     x9, a18
        add     x9, x9, #:lo12:a18
        ldr     x16, [x9]
        str     x16, [sp,#48]
        adrp     x9, a19
        add     x9, x9, #:lo12:a19
        ldr     x16, [x9]
        str     x16, [sp,#40]
        adrp     x9, a20
        add     x9, x9, #:lo12:a20
        ldr     x16, [x9]
        str     x16, [sp,#32]
        adrp     x9, a21
        add     x9, x9, #:lo12:a21
        ldr     x16, [x9]
        str     x16, [sp,#24]
        adrp     x9, a22
        add     x9, x9, #:lo12:a22
        ldr     x16, [x9]
        str     x16, [sp,#16]
        adrp     x9, a23
        add     x9, x9, #:lo12:a23
        ldr     x16, [x9]
        str     x16, [sp,#8]
        adrp     x9, a24
        add     x9, x9, #:lo12:a24
        ldr     x16, [x9]
        str     x16, [sp]
        adrp     x9, a25
        add     x9, x9, #:lo12:a25
        ldr     x15, [x9]
        adrp     x9, a26
        add     x9, x9, #:lo12:a26
        ldr     x14, [x9]
        adrp     x9, a27
        add     x9, x9, #:lo12:a27
        ldr     x13, [x9]
        adrp     x9, a28
        add     x9, x9, #:lo12:a28
        ldr     x12, [x9]
        adrp     x9, a29
        add     x9, x9, #:lo12:a29
        ldr     x11, [x9]
        adrp     x9, a30
        add     x9, x9, #:lo12:a30
        ldr     x10, [x9]
        adrp     x9, a31
        add     x9, x9, #:lo12:a31
        ldr     x9, [x9]
        ldr     w16, [sp,#192]
        mov     w0, w16
        ldr     w16, [sp,#184]
        mov     w1, w16
        ldr     w16, [sp,#176]
        mov     w2, w16
        ldr     w16, [sp,#168]
        mov     w3, w16
        ldr     w16, [sp,#160]
        mov     w4, w16
        ldr     w16, [sp,#152]
        mov     w5, w16
        ldr     w16, [sp,#144]
        mov     w6, w16
        ldr     w16, [sp,#136]
        mov     w7, w16
        mov     x28, sp
        stp     x9, x10, [sp, #-16]!
        stp     x11, x12, [sp, #-16]!
        stp     x13, x14, [sp, #-16]!
        str     x15, [sp, #-8]!
        stp     x29, x30, [sp, #-16]!
        mov     sp, x28
        str     w9, [sp,#-80]
        str     w10, [sp,#-88]
        str     w11, [sp,#-96]
        str     w12, [sp,#-104]
        str     w13, [sp,#-112]
        str     w14, [sp,#-120]
        str     w15, [sp,#-128]
        ldr     w16, [sp]
        str     w16, [sp,#-136]
        ldr     w16, [sp,#8]
        str     w16, [sp,#-144]
        ldr     w16, [sp,#16]
        str     w16, [sp,#-152]
        ldr     w16, [sp,#24]
        str     w16, [sp,#-160]
        ldr     w16, [sp,#32]
        str     w16, [sp,#-168]
        ldr     w16, [sp,#40]
        str     w16, [sp,#-176]
        ldr     w16, [sp,#48]
        str     w16, [sp,#-184]
        ldr     w16, [sp,#56]
        str     w16, [sp,#-192]
        ldr     w16, [sp,#64]
        str     w16, [sp,#-200]
        ldr     w16, [sp,#72]
        str     w16, [sp,#-208]
        ldr     w16, [sp,#80]
        str     w16, [sp,#-216]
        ldr     w16, [sp,#88]
        str     w16, [sp,#-224]
        ldr     w16, [sp,#96]
        str     w16, [sp,#-232]
        ldr     w16, [sp,#104]
        str     w16, [sp,#-240]
        ldr     w16, [sp,#112]
        str     w16, [sp,#-248]
        ldr     w16, [sp,#120]
        str     w16, [sp,#-256]
        mov     x27, #-264
        ldr     w16, [sp,#128]
        str     w16, [sp,x27]
        sub     sp, sp, #264
        mov     x29, sp
        bl     testParam32
        add     sp, sp, #192
        ldp     x29, x30, [sp], #16
        ldr     x15, [sp], #8
        ldp     x13, x14, [sp], #16
        ldp     x11, x12, [sp], #16
        ldp     x9, x10, [sp], #16
        mov     x10, x0
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
        str     w10, [x9]
        adrp     x9, a0
        add     x9, x9, #:lo12:a0
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
