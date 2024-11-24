; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque
%struct.timeval = type { i64, i64 }

@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @before_main, i8* null }]
@llvm.global_dtors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @after_main, i8* null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_s = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_m = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_h = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_idx = dso_local global i32 0, align 4
@stderr = external global %struct._IO_FILE*, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = dso_local global [1024 x i32] zeroinitializer, align 16
@_sysy_l2 = dso_local global [1024 x i32] zeroinitializer, align 16
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = dso_local global %struct.timeval zeroinitializer, align 8
@_sysy_end = dso_local global %struct.timeval zeroinitializer, align 8

define i32 @next_char() {
next_char:
  %r100 = call i32 @getch()
  store i32 %r100, i32* @last_char, align 4
  %r101 = load i32, i32* @last_char, align 4
  ret i32 %r101
}

define i32 @is_space(i32 %r102) {
is_space:
  %r103 = alloca i32, align 4
  store i32 %r102, i32* %r103, align 4
  %r104 = load i32, i32* %r103, align 4
  %r105 = icmp eq i32 %r104, 32
  br i1 %r105, label %if_5_24_true, label %bb22_24_next

bb22_24_next:                                     ; preds = %is_space
  %r106 = load i32, i32* %r103, align 4
  %r107 = icmp eq i32 %r106, 10
  br i1 %r107, label %if_5_24_true, label %if_5_24_false

if_5_24_true:                                     ; preds = %bb22_24_next, %is_space
  ret i32 1

0:                                                ; No predecessors!
  br label %if_5_24_end

if_5_24_false:                                    ; preds = %bb22_24_next
  ret i32 0

1:                                                ; No predecessors!
  br label %if_5_24_end

if_5_24_end:                                      ; preds = %1, %0
  ret i32 0
}

define i32 @is_num(i32 %r108) {
is_num:
  %r109 = alloca i32, align 4
  store i32 %r108, i32* %r109, align 4
  %r110 = load i32, i32* %r109, align 4
  %r111 = icmp sge i32 %r110, 48
  br i1 %r111, label %bb22_36_next, label %if_5_36_false

bb22_36_next:                                     ; preds = %is_num
  %r112 = load i32, i32* %r109, align 4
  %r113 = icmp sle i32 %r112, 57
  br i1 %r113, label %if_5_36_true, label %if_5_36_false

if_5_36_true:                                     ; preds = %bb22_36_next
  ret i32 1

0:                                                ; No predecessors!
  br label %if_5_36_end

if_5_36_false:                                    ; preds = %bb22_36_next, %is_num
  ret i32 0

1:                                                ; No predecessors!
  br label %if_5_36_end

if_5_36_end:                                      ; preds = %1, %0
  ret i32 0
}

define i32 @next_token() {
next_token:
  br label %while_5_48_cond

while_5_48_cond:                                  ; preds = %while_5_48_whilestms, %next_token
  %r114 = load i32, i32* @last_char, align 4
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %while_5_48_whilestms, label %while_5_48_bre

while_5_48_whilestms:                             ; preds = %while_5_48_cond
  %r117 = call i32 @next_char()
  br label %while_5_48_cond

while_5_48_bre:                                   ; preds = %while_5_48_cond
  %r118 = load i32, i32* @last_char, align 4
  %r119 = call i32 @is_num(i32 %r118)
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %if_5_52_true, label %if_5_52_false

if_5_52_true:                                     ; preds = %while_5_48_bre
  %r121 = load i32, i32* @last_char, align 4
  %r122 = sub i32 %r121, 48
  store i32 %r122, i32* @num, align 4
  br label %while_9_55_cond

while_9_55_cond:                                  ; preds = %while_9_55_whilestms, %if_5_52_true
  %r123 = call i32 @next_char()
  %r124 = call i32 @is_num(i32 %r123)
  %r125 = icmp ne i32 %r124, 0
  br i1 %r125, label %while_9_55_whilestms, label %while_9_55_bre

while_9_55_whilestms:                             ; preds = %while_9_55_cond
  %r126 = load i32, i32* @num, align 4
  %r127 = mul i32 %r126, 10
  %r128 = load i32, i32* @last_char, align 4
  %r129 = add i32 %r127, %r128
  %r130 = sub i32 %r129, 48
  store i32 %r130, i32* @num, align 4
  br label %while_9_55_cond

while_9_55_bre:                                   ; preds = %while_9_55_cond
  %r131 = load i32, i32* @TOKEN_NUM, align 4
  store i32 %r131, i32* @cur_token, align 4
  br label %if_5_52_end

if_5_52_false:                                    ; preds = %while_5_48_bre
  %r132 = load i32, i32* @last_char, align 4
  store i32 %r132, i32* @other, align 4
  %r133 = call i32 @next_char()
  %r134 = load i32, i32* @TOKEN_OTHER, align 4
  store i32 %r134, i32* @cur_token, align 4
  br label %if_5_52_end

if_5_52_end:                                      ; preds = %if_5_52_false, %while_9_55_bre
  %r135 = load i32, i32* @cur_token, align 4
  ret i32 %r135
}

define i32 @panic() {
panic:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  %r143 = sub i32 0, 1
  ret i32 %r143
}

define i32 @get_op_prec(i32 %r144) {
get_op_prec:
  %r145 = alloca i32, align 4
  store i32 %r144, i32* %r145, align 4
  %r146 = load i32, i32* %r145, align 4
  %r147 = icmp eq i32 %r146, 43
  br i1 %r147, label %if_5_85_true, label %bb23_85_next

bb23_85_next:                                     ; preds = %get_op_prec
  %r148 = load i32, i32* %r145, align 4
  %r149 = icmp eq i32 %r148, 45
  br i1 %r149, label %if_5_85_true, label %if_5_85_false

if_5_85_true:                                     ; preds = %bb23_85_next, %get_op_prec
  ret i32 10

0:                                                ; No predecessors!
  br label %if_5_85_end

if_5_85_false:                                    ; preds = %bb23_85_next
  br label %if_5_85_end

if_5_85_end:                                      ; preds = %if_5_85_false, %0
  %r150 = load i32, i32* %r145, align 4
  %r151 = icmp eq i32 %r150, 42
  br i1 %r151, label %if_5_88_true, label %bb23_88_next

bb23_88_next:                                     ; preds = %if_5_85_end
  %r152 = load i32, i32* %r145, align 4
  %r153 = icmp eq i32 %r152, 47
  br i1 %r153, label %if_5_88_true, label %bb37_88_next

bb37_88_next:                                     ; preds = %bb23_88_next
  %r154 = load i32, i32* %r145, align 4
  %r155 = icmp eq i32 %r154, 37
  br i1 %r155, label %if_5_88_true, label %if_5_88_false

if_5_88_true:                                     ; preds = %bb37_88_next, %bb23_88_next, %if_5_85_end
  ret i32 20

1:                                                ; No predecessors!
  br label %if_5_88_end

if_5_88_false:                                    ; preds = %bb37_88_next
  br label %if_5_88_end

if_5_88_end:                                      ; preds = %if_5_88_false, %1
  ret i32 0
}

define void @stack_push(i32* %r156, i32 %r157) {
stack_push:
  %r158 = alloca i32, align 4
  store i32 %r157, i32* %r158, align 4
  %r159 = getelementptr i32, i32* %r156, i32 0
  %r161 = getelementptr i32, i32* %r156, i32 0
  %r160 = load i32, i32* %r161, align 4
  %r162 = add i32 %r160, 1
  store i32 %r162, i32* %r159, align 4
  %r163 = alloca i32, align 4
  %r165 = getelementptr i32, i32* %r156, i32 0
  %r164 = load i32, i32* %r165, align 4
  store i32 %r164, i32* %r163, align 4
  %r166 = load i32, i32* %r163, align 4
  %r167 = getelementptr i32, i32* %r156, i32 %r166
  %r168 = load i32, i32* %r158, align 4
  store i32 %r168, i32* %r167, align 4
  ret void
}

define i32 @stack_pop(i32* %r169) {
stack_pop:
  %r170 = alloca i32, align 4
  %r172 = getelementptr i32, i32* %r169, i32 0
  %r171 = load i32, i32* %r172, align 4
  store i32 %r171, i32* %r170, align 4
  %r173 = alloca i32, align 4
  %r174 = load i32, i32* %r170, align 4
  %r176 = getelementptr i32, i32* %r169, i32 %r174
  %r175 = load i32, i32* %r176, align 4
  store i32 %r175, i32* %r173, align 4
  %r177 = getelementptr i32, i32* %r169, i32 0
  %r179 = getelementptr i32, i32* %r169, i32 0
  %r178 = load i32, i32* %r179, align 4
  %r180 = sub i32 %r178, 1
  store i32 %r180, i32* %r177, align 4
  %r181 = load i32, i32* %r173, align 4
  ret i32 %r181
}

define i32 @stack_peek(i32* %r182) {
stack_peek:
  %r183 = alloca i32, align 4
  %r185 = getelementptr i32, i32* %r182, i32 0
  %r184 = load i32, i32* %r185, align 4
  store i32 %r184, i32* %r183, align 4
  %r186 = load i32, i32* %r183, align 4
  %r188 = getelementptr i32, i32* %r182, i32 %r186
  %r187 = load i32, i32* %r188, align 4
  ret i32 %r187
}

define i32 @stack_size(i32* %r189) {
stack_size:
  %r191 = getelementptr i32, i32* %r189, i32 0
  %r190 = load i32, i32* %r191, align 4
  ret i32 %r190
}

define i32 @mod(i32 %r192, i32 %r194) {
mod:
  %r193 = alloca i32, align 4
  store i32 %r192, i32* %r193, align 4
  %r195 = alloca i32, align 4
  store i32 %r194, i32* %r195, align 4
  %r196 = load i32, i32* %r193, align 4
  %r197 = load i32, i32* %r193, align 4
  %r198 = load i32, i32* %r195, align 4
  %r199 = sdiv i32 %r197, %r198
  %r200 = load i32, i32* %r195, align 4
  %r201 = mul i32 %r199, %r200
  %r202 = sub i32 %r196, %r201
  ret i32 %r202
}

define i32 @eval_op(i32 %r203, i32 %r205, i32 %r207) {
eval_op:
  %r204 = alloca i32, align 4
  store i32 %r203, i32* %r204, align 4
  %r206 = alloca i32, align 4
  store i32 %r205, i32* %r206, align 4
  %r208 = alloca i32, align 4
  store i32 %r207, i32* %r208, align 4
  %r209 = load i32, i32* %r204, align 4
  %r210 = icmp eq i32 %r209, 43
  br i1 %r210, label %if_5_128_true, label %if_5_128_false

if_5_128_true:                                    ; preds = %eval_op
  %r211 = load i32, i32* %r206, align 4
  %r212 = load i32, i32* %r208, align 4
  %r213 = add i32 %r211, %r212
  ret i32 %r213

0:                                                ; No predecessors!
  br label %if_5_128_end

if_5_128_false:                                   ; preds = %eval_op
  br label %if_5_128_end

if_5_128_end:                                     ; preds = %if_5_128_false, %0
  %r214 = load i32, i32* %r204, align 4
  %r215 = icmp eq i32 %r214, 45
  br i1 %r215, label %if_5_133_true, label %if_5_133_false

if_5_133_true:                                    ; preds = %if_5_128_end
  %r216 = load i32, i32* %r206, align 4
  %r217 = load i32, i32* %r208, align 4
  %r218 = sub i32 %r216, %r217
  ret i32 %r218

1:                                                ; No predecessors!
  br label %if_5_133_end

if_5_133_false:                                   ; preds = %if_5_128_end
  br label %if_5_133_end

if_5_133_end:                                     ; preds = %if_5_133_false, %1
  %r219 = load i32, i32* %r204, align 4
  %r220 = icmp eq i32 %r219, 42
  br i1 %r220, label %if_5_138_true, label %if_5_138_false

if_5_138_true:                                    ; preds = %if_5_133_end
  %r221 = load i32, i32* %r206, align 4
  %r222 = load i32, i32* %r208, align 4
  %r223 = mul i32 %r221, %r222
  ret i32 %r223

2:                                                ; No predecessors!
  br label %if_5_138_end

if_5_138_false:                                   ; preds = %if_5_133_end
  br label %if_5_138_end

if_5_138_end:                                     ; preds = %if_5_138_false, %2
  %r224 = load i32, i32* %r204, align 4
  %r225 = icmp eq i32 %r224, 47
  br i1 %r225, label %if_5_143_true, label %if_5_143_false

if_5_143_true:                                    ; preds = %if_5_138_end
  %r226 = load i32, i32* %r206, align 4
  %r227 = load i32, i32* %r208, align 4
  %r228 = sdiv i32 %r226, %r227
  ret i32 %r228

3:                                                ; No predecessors!
  br label %if_5_143_end

if_5_143_false:                                   ; preds = %if_5_138_end
  br label %if_5_143_end

if_5_143_end:                                     ; preds = %if_5_143_false, %3
  %r229 = load i32, i32* %r204, align 4
  %r230 = icmp eq i32 %r229, 37
  br i1 %r230, label %if_5_148_true, label %if_5_148_false

if_5_148_true:                                    ; preds = %if_5_143_end
  %r231 = load i32, i32* %r206, align 4
  %r232 = load i32, i32* %r208, align 4
  %r233 = call i32 @mod(i32 %r231, i32 %r232)
  ret i32 %r233

4:                                                ; No predecessors!
  br label %if_5_148_end

if_5_148_false:                                   ; preds = %if_5_143_end
  br label %if_5_148_end

if_5_148_end:                                     ; preds = %if_5_148_false, %4
  ret i32 0
}

define i32 @eval() {
eval:
  %r307 = alloca i32, align 4
  %r304 = alloca i32, align 4
  %r301 = alloca i32, align 4
  %r277 = alloca i32, align 4
  %r274 = alloca i32, align 4
  %r271 = alloca i32, align 4
  %r256 = alloca i32, align 4
  %r234 = alloca [256 x i32], align 4
  %r235 = alloca [256 x i32], align 4
  %r236 = alloca i32, align 4
  store i32 0, i32* %r236, align 4
  br label %while_5_161_cond

while_5_161_cond:                                 ; preds = %while_5_161_whilestms, %eval
  %r237 = load i32, i32* %r236, align 4
  %r238 = icmp slt i32 %r237, 256
  br i1 %r238, label %while_5_161_whilestms, label %while_5_161_bre

while_5_161_whilestms:                            ; preds = %while_5_161_cond
  %r239 = load i32, i32* %r236, align 4
  %r240 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 %r239
  store i32 0, i32* %r240, align 4
  %r241 = load i32, i32* %r236, align 4
  %r242 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 %r241
  store i32 0, i32* %r242, align 4
  %r243 = load i32, i32* %r236, align 4
  %r244 = add i32 %r243, 1
  store i32 %r244, i32* %r236, align 4
  br label %while_5_161_cond

while_5_161_bre:                                  ; preds = %while_5_161_cond
  %r245 = load i32, i32* @cur_token, align 4
  %r246 = load i32, i32* @TOKEN_NUM, align 4
  %r247 = icmp ne i32 %r245, %r246
  br i1 %r247, label %if_5_168_true, label %if_5_168_false

if_5_168_true:                                    ; preds = %while_5_161_bre
  %r248 = call i32 @panic()
  ret i32 %r248

0:                                                ; No predecessors!
  br label %if_5_168_end

if_5_168_false:                                   ; preds = %while_5_161_bre
  br label %if_5_168_end

if_5_168_end:                                     ; preds = %if_5_168_false, %0
  %r249 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r250 = load i32, i32* @num, align 4
  call void @stack_push(i32* %r249, i32 %r250)
  %r252 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_cond:                                 ; preds = %if_9_193_end, %if_5_168_end
  %r253 = load i32, i32* @cur_token, align 4
  %r254 = load i32, i32* @TOKEN_OTHER, align 4
  %r255 = icmp eq i32 %r253, %r254
  br i1 %r255, label %while_5_175_whilestms, label %while_5_175_bre

while_5_175_whilestms:                            ; preds = %while_5_175_cond
  %r257 = load i32, i32* @other, align 4
  store i32 %r257, i32* %r256, align 4
  %r258 = load i32, i32* %r256, align 4
  %r259 = call i32 @get_op_prec(i32 %r258)
  %r260 = icmp eq i32 %r259, 0
  br i1 %r260, label %if_9_179_true, label %if_9_179_false

if_9_179_true:                                    ; preds = %while_5_175_whilestms
  br label %while_5_175_bre

1:                                                ; No predecessors!
  br label %if_9_179_end

if_9_179_false:                                   ; preds = %while_5_175_whilestms
  br label %if_9_179_end

if_9_179_end:                                     ; preds = %if_9_179_false, %1
  %r261 = call i32 @next_token()
  br label %while_9_183_cond

while_9_183_cond:                                 ; preds = %while_9_183_whilestms, %if_9_179_end
  %r262 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r263 = call i32 @stack_size(i32* %r262)
  %r264 = icmp ne i32 %r263, 0
  br i1 %r264, label %bb40_183_next, label %while_9_183_bre

bb40_183_next:                                    ; preds = %while_9_183_cond
  %r265 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r266 = call i32 @stack_peek(i32* %r265)
  %r267 = call i32 @get_op_prec(i32 %r266)
  %r268 = load i32, i32* %r256, align 4
  %r269 = call i32 @get_op_prec(i32 %r268)
  %r270 = icmp sge i32 %r267, %r269
  br i1 %r270, label %while_9_183_whilestms, label %while_9_183_bre

while_9_183_whilestms:                            ; preds = %bb40_183_next
  %r272 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r273 = call i32 @stack_pop(i32* %r272)
  store i32 %r273, i32* %r271, align 4
  %r275 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r276 = call i32 @stack_pop(i32* %r275)
  store i32 %r276, i32* %r274, align 4
  %r278 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r279 = call i32 @stack_pop(i32* %r278)
  store i32 %r279, i32* %r277, align 4
  %r280 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r281 = load i32, i32* %r271, align 4
  %r282 = load i32, i32* %r277, align 4
  %r283 = load i32, i32* %r274, align 4
  %r284 = call i32 @eval_op(i32 %r281, i32 %r282, i32 %r283)
  call void @stack_push(i32* %r280, i32 %r284)
  br label %while_9_183_cond

while_9_183_bre:                                  ; preds = %bb40_183_next, %while_9_183_cond
  %r286 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r287 = load i32, i32* %r256, align 4
  call void @stack_push(i32* %r286, i32 %r287)
  %r289 = load i32, i32* @cur_token, align 4
  %r290 = load i32, i32* @TOKEN_NUM, align 4
  %r291 = icmp ne i32 %r289, %r290
  br i1 %r291, label %if_9_193_true, label %if_9_193_false

if_9_193_true:                                    ; preds = %while_9_183_bre
  %r292 = call i32 @panic()
  ret i32 %r292

2:                                                ; No predecessors!
  br label %if_9_193_end

if_9_193_false:                                   ; preds = %while_9_183_bre
  br label %if_9_193_end

if_9_193_end:                                     ; preds = %if_9_193_false, %2
  %r293 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r294 = load i32, i32* @num, align 4
  call void @stack_push(i32* %r293, i32 %r294)
  %r296 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_bre:                                  ; preds = %if_9_179_true, %while_5_175_cond
  %r297 = call i32 @next_token()
  br label %while_5_201_cond

while_5_201_cond:                                 ; preds = %while_5_201_whilestms, %while_5_175_bre
  %r298 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r299 = call i32 @stack_size(i32* %r298)
  %r300 = icmp ne i32 %r299, 0
  br i1 %r300, label %while_5_201_whilestms, label %while_5_201_bre

while_5_201_whilestms:                            ; preds = %while_5_201_cond
  %r302 = getelementptr [256 x i32], [256 x i32]* %r235, i32 0, i32 0
  %r303 = call i32 @stack_pop(i32* %r302)
  store i32 %r303, i32* %r301, align 4
  %r305 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r306 = call i32 @stack_pop(i32* %r305)
  store i32 %r306, i32* %r304, align 4
  %r308 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r309 = call i32 @stack_pop(i32* %r308)
  store i32 %r309, i32* %r307, align 4
  %r310 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r311 = load i32, i32* %r271, align 4
  %r312 = load i32, i32* %r277, align 4
  %r313 = load i32, i32* %r274, align 4
  %r314 = call i32 @eval_op(i32 %r311, i32 %r312, i32 %r313)
  call void @stack_push(i32* %r310, i32 %r314)
  br label %while_5_201_cond

while_5_201_bre:                                  ; preds = %while_5_201_cond
  %r316 = getelementptr [256 x i32], [256 x i32]* %r234, i32 0, i32 0
  %r317 = call i32 @stack_peek(i32* %r316)
  ret i32 %r317
}

define i32 @main() {
main:
  %r318 = alloca i32, align 4
  %r319 = call i32 @getint()
  store i32 %r319, i32* %r318, align 4
  %r320 = call i32 @getch()
  %r321 = call i32 @next_token()
  br label %while_5_216_cond

while_5_216_cond:                                 ; preds = %while_5_216_whilestms, %main
  %r322 = load i32, i32* %r318, align 4
  %r323 = icmp ne i32 %r322, 0
  br i1 %r323, label %while_5_216_whilestms, label %while_5_216_bre

while_5_216_whilestms:                            ; preds = %while_5_216_cond
  %r324 = call i32 @eval()
  call void @putint(i32 %r324)
  call void @putch(i32 10)
  %r327 = load i32, i32* %r318, align 4
  %r328 = sub i32 %r327, 1
  store i32 %r328, i32* %r318, align 4
  br label %while_5_216_cond

while_5_216_bre:                                  ; preds = %while_5_216_cond
  ret i32 0
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, i32* %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, i32* %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %7
  store i32 0, i32* %8, align 4
  %9 = load i32, i32* %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %10
  store i32 0, i32* %11, align 4
  %12 = load i32, i32* %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %13
  store i32 0, i32* %14, align 4
  %15 = load i32, i32* %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 %16
  store i32 0, i32* %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, i32* %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, i32* %1, align 4
  br label %2, !llvm.loop !6

21:                                               ; preds = %2
  store i32 1, i32* @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, i32* %1, align 4
  %4 = load i32, i32* @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %8 = load i32, i32* %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_l1, i64 0, i64 %9
  %11 = load i32, i32* %10, align 4
  %12 = load i32, i32* %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_l2, i64 0, i64 %13
  %15 = load i32, i32* %14, align 4
  %16 = load i32, i32* %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 %17
  %19 = load i32, i32* %18, align 4
  %20 = load i32, i32* %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %21
  %23 = load i32, i32* %22, align 4
  %24 = load i32, i32* %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %25
  %27 = load i32, i32* %26, align 4
  %28 = load i32, i32* %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %29
  %31 = load i32, i32* %30, align 4
  %32 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* noundef %7, i8* noundef getelementptr inbounds ([35 x i8], [35 x i8]* @.str.5, i64 0, i64 0), i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, i32* %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %34
  %36 = load i32, i32* %35, align 4
  %37 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 0), align 16
  %38 = add nsw i32 %37, %36
  store i32 %38, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 0), align 16
  %39 = load i32, i32* %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %40
  %42 = load i32, i32* %41, align 4
  %43 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 0), align 16
  %44 = add nsw i32 %43, %42
  store i32 %44, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 0), align 16
  %45 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 0), align 16
  %46 = srem i32 %45, 1000000
  store i32 %46, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 0), align 16
  %47 = load i32, i32* %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %48
  %50 = load i32, i32* %49, align 4
  %51 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 0), align 16
  %52 = add nsw i32 %51, %50
  store i32 %52, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 0), align 16
  %53 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 0), align 16
  %54 = srem i32 %53, 60
  store i32 %54, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 0), align 16
  %55 = load i32, i32* %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 %56
  %58 = load i32, i32* %57, align 4
  %59 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 0), align 16
  %60 = add nsw i32 %59, %58
  store i32 %60, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 0), align 16
  %61 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 0), align 16
  %62 = srem i32 %61, 60
  store i32 %62, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 0), align 16
  br label %63

63:                                               ; preds = %6
  %64 = load i32, i32* %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, i32* %1, align 4
  br label %2, !llvm.loop !8

66:                                               ; preds = %2
  %67 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8
  %68 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 0), align 16
  %69 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 0), align 16
  %70 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 0), align 16
  %71 = load i32, i32* getelementptr inbounds ([1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 0), align 16
  %72 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* noundef %67, i8* noundef getelementptr inbounds ([25 x i8], [25 x i8]* @.str.6, i64 0, i64 0), i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

declare i32 @fprintf(%struct._IO_FILE* noundef, i8* noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* noundef %1)
  %3 = load i32, i32* %1, align 4
  ret i32 %3
}

declare i32 @__isoc99_scanf(i8* noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* noundef %1)
  %3 = load i8, i8* %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getarray(i32* noundef %0) #0 {
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32* %0, i32** %2, align 8
  %5 = call i32 (i8*, ...) @__isoc99_scanf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* noundef %3)
  store i32 0, i32* %4, align 4
  br label %6

6:                                                ; preds = %16, %1
  %7 = load i32, i32* %4, align 4
  %8 = load i32, i32* %3, align 4
  %9 = icmp slt i32 %7, %8
  br i1 %9, label %10, label %19

10:                                               ; preds = %6
  %11 = load i32*, i32** %2, align 8
  %12 = load i32, i32* %4, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds i32, i32* %11, i64 %13
  %15 = call i32 (i8*, ...) @__isoc99_scanf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32* noundef %14)
  br label %16

16:                                               ; preds = %10
  %17 = load i32, i32* %4, align 4
  %18 = add nsw i32 %17, 1
  store i32 %18, i32* %4, align 4
  br label %6, !llvm.loop !9

19:                                               ; preds = %6
  %20 = load i32, i32* %3, align 4
  ret i32 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i64 0, i64 0), i32 noundef %3)
  ret void
}

declare i32 @printf(i8* noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @putarray(i32 noundef %0, i32* noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32*, align 8
  %5 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32* %1, i32** %4, align 8
  %6 = load i32, i32* %3, align 4
  %7 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.2, i64 0, i64 0), i32 noundef %6)
  store i32 0, i32* %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, i32* %5, align 4
  %10 = load i32, i32* %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load i32*, i32** %4, align 8
  %14 = load i32, i32* %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, i32* %13, i64 %15
  %17 = load i32, i32* %16, align 4
  %18 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([4 x i8], [4 x i8]* @.str.3, i64 0, i64 0), i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, i32* %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %5, align 4
  br label %8, !llvm.loop !10

22:                                               ; preds = %8
  %23 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i64 0, i64 0))
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = load i32, i32* @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_l1, i64 0, i64 %5
  store i32 %3, i32* %6, align 4
  %7 = call i32 @gettimeofday(%struct.timeval* noundef @_sysy_start, i8* noundef null) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @gettimeofday(%struct.timeval* noundef, i8* noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = call i32 @gettimeofday(%struct.timeval* noundef @_sysy_end, i8* noundef null) #3
  %4 = load i32, i32* %2, align 4
  %5 = load i32, i32* @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_l2, i64 0, i64 %6
  store i32 %4, i32* %7, align 4
  %8 = load i64, i64* getelementptr inbounds (%struct.timeval, %struct.timeval* @_sysy_end, i32 0, i32 0), align 8
  %9 = load i64, i64* getelementptr inbounds (%struct.timeval, %struct.timeval* @_sysy_start, i32 0, i32 0), align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i64, i64* getelementptr inbounds (%struct.timeval, %struct.timeval* @_sysy_end, i32 0, i32 1), align 8
  %13 = add nsw i64 %11, %12
  %14 = load i64, i64* getelementptr inbounds (%struct.timeval, %struct.timeval* @_sysy_start, i32 0, i32 1), align 8
  %15 = sub nsw i64 %13, %14
  %16 = load i32, i32* @_sysy_idx, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %17
  %19 = load i32, i32* %18, align 4
  %20 = sext i32 %19 to i64
  %21 = add nsw i64 %20, %15
  %22 = trunc i64 %21 to i32
  store i32 %22, i32* %18, align 4
  %23 = load i32, i32* @_sysy_idx, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %24
  %26 = load i32, i32* %25, align 4
  %27 = sdiv i32 %26, 1000000
  %28 = load i32, i32* @_sysy_idx, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %29
  %31 = load i32, i32* %30, align 4
  %32 = add nsw i32 %31, %27
  store i32 %32, i32* %30, align 4
  %33 = load i32, i32* @_sysy_idx, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_us, i64 0, i64 %34
  %36 = load i32, i32* %35, align 4
  %37 = srem i32 %36, 1000000
  store i32 %37, i32* %35, align 4
  %38 = load i32, i32* @_sysy_idx, align 4
  %39 = sext i32 %38 to i64
  %40 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %39
  %41 = load i32, i32* %40, align 4
  %42 = sdiv i32 %41, 60
  %43 = load i32, i32* @_sysy_idx, align 4
  %44 = sext i32 %43 to i64
  %45 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %44
  %46 = load i32, i32* %45, align 4
  %47 = add nsw i32 %46, %42
  store i32 %47, i32* %45, align 4
  %48 = load i32, i32* @_sysy_idx, align 4
  %49 = sext i32 %48 to i64
  %50 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_s, i64 0, i64 %49
  %51 = load i32, i32* %50, align 4
  %52 = srem i32 %51, 60
  store i32 %52, i32* %50, align 4
  %53 = load i32, i32* @_sysy_idx, align 4
  %54 = sext i32 %53 to i64
  %55 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %54
  %56 = load i32, i32* %55, align 4
  %57 = sdiv i32 %56, 60
  %58 = load i32, i32* @_sysy_idx, align 4
  %59 = sext i32 %58 to i64
  %60 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_h, i64 0, i64 %59
  %61 = load i32, i32* %60, align 4
  %62 = add nsw i32 %61, %57
  store i32 %62, i32* %60, align 4
  %63 = load i32, i32* @_sysy_idx, align 4
  %64 = sext i32 %63 to i64
  %65 = getelementptr inbounds [1024 x i32], [1024 x i32]* @_sysy_m, i64 0, i64 %64
  %66 = load i32, i32* %65, align 4
  %67 = srem i32 %66, 60
  store i32 %67, i32* %65, align 4
  %68 = load i32, i32* @_sysy_idx, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, i32* @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4, !5}

!0 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{i32 7, !"PIE Level", i32 2}
!4 = !{i32 7, !"uwtable", i32 1}
!5 = !{i32 7, !"frame-pointer", i32 2}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
