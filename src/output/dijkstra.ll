; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%array2D = type { [16 x i32] }
%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque
%struct.timeval = type { i64, i64 }

@INF = global i32 65535
@e = global [16 x %array2D] zeroinitializer
@book = global [16 x i32] zeroinitializer
@dis = global [16 x i32] zeroinitializer
@n = global i32 0
@m = global i32 0
@v1 = global i32 0
@v2 = global i32 0
@w = global i32 0
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

define void @Dijkstra() {
Dijkstra:
  %r144 = alloca i32, align 4
  %r123 = alloca i32, align 4
  %r122 = alloca i32, align 4
  %r120 = alloca i32, align 4
  %r100 = alloca i32, align 4
  store i32 1, i32* %r100, align 4
  br label %while_5_26_cond

while_5_26_cond:                                  ; preds = %while_5_26_whilestms, %Dijkstra
  %r101 = load i32, i32* %r100, align 4
  %r102 = load i32, i32* @n, align 4
  %r103 = icmp sle i32 %r101, %r102
  br i1 %r103, label %while_5_26_whilestms, label %while_5_26_bre

while_5_26_whilestms:                             ; preds = %while_5_26_cond
  %r104 = load i32, i32* %r100, align 4
  %r105 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r104
  %r106 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 1
  %r107 = getelementptr %array2D, %array2D* %r106, i32 0, i32 0
  %r108 = load i32, i32* %r100, align 4
  %r110 = getelementptr [16 x i32], [16 x i32]* %r107, i32 0, i32 %r108
  %r109 = load i32, i32* %r110, align 4
  store i32 %r109, i32* %r105, align 4
  %r111 = load i32, i32* %r100, align 4
  %r112 = getelementptr [16 x i32], [16 x i32]* @book, i32 0, i32 %r111
  store i32 0, i32* %r112, align 4
  %r113 = load i32, i32* %r100, align 4
  %r114 = add i32 %r113, 1
  store i32 %r114, i32* %r100, align 4
  br label %while_5_26_cond

while_5_26_bre:                                   ; preds = %while_5_26_cond
  %r115 = getelementptr [16 x i32], [16 x i32]* @book, i32 0, i32 1
  store i32 1, i32* %r115, align 4
  store i32 1, i32* %r100, align 4
  br label %while_5_34_cond

while_5_34_cond:                                  ; preds = %while_9_47_bre, %while_5_26_bre
  %r116 = load i32, i32* %r100, align 4
  %r117 = load i32, i32* @n, align 4
  %r118 = sub i32 %r117, 1
  %r119 = icmp sle i32 %r116, %r118
  br i1 %r119, label %while_5_34_whilestms, label %while_5_34_bre

while_5_34_whilestms:                             ; preds = %while_5_34_cond
  %r121 = load i32, i32* @INF, align 4
  store i32 %r121, i32* %r120, align 4
  store i32 0, i32* %r122, align 4
  store i32 1, i32* %r123, align 4
  br label %while_9_38_cond

while_9_38_cond:                                  ; preds = %if_13_39_end, %while_5_34_whilestms
  %r124 = load i32, i32* %r123, align 4
  %r125 = load i32, i32* @n, align 4
  %r126 = icmp sle i32 %r124, %r125
  br i1 %r126, label %while_9_38_whilestms, label %while_9_38_bre

while_9_38_whilestms:                             ; preds = %while_9_38_cond
  %r127 = load i32, i32* %r120, align 4
  %r128 = load i32, i32* %r123, align 4
  %r130 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r128
  %r129 = load i32, i32* %r130, align 4
  %r131 = icmp sgt i32 %r127, %r129
  br i1 %r131, label %bb39_39_next, label %if_13_39_false

bb39_39_next:                                     ; preds = %while_9_38_whilestms
  %r132 = load i32, i32* %r123, align 4
  %r134 = getelementptr [16 x i32], [16 x i32]* @book, i32 0, i32 %r132
  %r133 = load i32, i32* %r134, align 4
  %r135 = icmp eq i32 %r133, 0
  br i1 %r135, label %if_13_39_true, label %if_13_39_false

if_13_39_true:                                    ; preds = %bb39_39_next
  %r136 = load i32, i32* %r123, align 4
  %r138 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r136
  %r137 = load i32, i32* %r138, align 4
  store i32 %r137, i32* %r120, align 4
  %r139 = load i32, i32* %r123, align 4
  store i32 %r139, i32* %r122, align 4
  br label %if_13_39_end

if_13_39_false:                                   ; preds = %bb39_39_next, %while_9_38_whilestms
  br label %if_13_39_end

if_13_39_end:                                     ; preds = %if_13_39_false, %if_13_39_true
  %r140 = load i32, i32* %r123, align 4
  %r141 = add i32 %r140, 1
  store i32 %r141, i32* %r123, align 4
  br label %while_9_38_cond

while_9_38_bre:                                   ; preds = %while_9_38_cond
  %r142 = load i32, i32* %r122, align 4
  %r143 = getelementptr [16 x i32], [16 x i32]* @book, i32 0, i32 %r142
  store i32 1, i32* %r143, align 4
  store i32 1, i32* %r144, align 4
  br label %while_9_47_cond

while_9_47_cond:                                  ; preds = %if_13_48_end, %while_9_38_bre
  %r145 = load i32, i32* %r144, align 4
  %r146 = load i32, i32* @n, align 4
  %r147 = icmp sle i32 %r145, %r146
  br i1 %r147, label %while_9_47_whilestms, label %while_9_47_bre

while_9_47_whilestms:                             ; preds = %while_9_47_cond
  %r148 = load i32, i32* %r122, align 4
  %r149 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r148
  %r150 = getelementptr %array2D, %array2D* %r149, i32 0, i32 0
  %r151 = load i32, i32* %r144, align 4
  %r153 = getelementptr [16 x i32], [16 x i32]* %r150, i32 0, i32 %r151
  %r152 = load i32, i32* %r153, align 4
  %r154 = load i32, i32* @INF, align 4
  %r155 = icmp slt i32 %r152, %r154
  br i1 %r155, label %if_13_48_true, label %if_13_48_false

if_13_48_true:                                    ; preds = %while_9_47_whilestms
  %r156 = load i32, i32* %r144, align 4
  %r158 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r156
  %r157 = load i32, i32* %r158, align 4
  %r159 = load i32, i32* %r122, align 4
  %r161 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r159
  %r160 = load i32, i32* %r161, align 4
  %r162 = load i32, i32* %r122, align 4
  %r163 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r162
  %r164 = getelementptr %array2D, %array2D* %r163, i32 0, i32 0
  %r165 = load i32, i32* %r144, align 4
  %r167 = getelementptr [16 x i32], [16 x i32]* %r164, i32 0, i32 %r165
  %r166 = load i32, i32* %r167, align 4
  %r168 = add i32 %r160, %r166
  %r169 = icmp sgt i32 %r157, %r168
  br i1 %r169, label %if_17_49_true, label %if_17_49_false

if_17_49_true:                                    ; preds = %if_13_48_true
  %r170 = load i32, i32* %r144, align 4
  %r171 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r170
  %r172 = load i32, i32* %r122, align 4
  %r174 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r172
  %r173 = load i32, i32* %r174, align 4
  %r175 = load i32, i32* %r122, align 4
  %r176 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r175
  %r177 = getelementptr %array2D, %array2D* %r176, i32 0, i32 0
  %r178 = load i32, i32* %r144, align 4
  %r180 = getelementptr [16 x i32], [16 x i32]* %r177, i32 0, i32 %r178
  %r179 = load i32, i32* %r180, align 4
  %r181 = add i32 %r173, %r179
  store i32 %r181, i32* %r171, align 4
  br label %if_17_49_end

if_17_49_false:                                   ; preds = %if_13_48_true
  br label %if_17_49_end

if_17_49_end:                                     ; preds = %if_17_49_false, %if_17_49_true
  br label %if_13_48_end

if_13_48_false:                                   ; preds = %while_9_47_whilestms
  br label %if_13_48_end

if_13_48_end:                                     ; preds = %if_13_48_false, %if_17_49_end
  %r182 = load i32, i32* %r144, align 4
  %r183 = add i32 %r182, 1
  store i32 %r183, i32* %r144, align 4
  br label %while_9_47_cond

while_9_47_bre:                                   ; preds = %while_9_47_cond
  %r184 = load i32, i32* %r100, align 4
  %r185 = add i32 %r184, 1
  store i32 %r185, i32* %r100, align 4
  br label %while_5_34_cond

while_5_34_bre:                                   ; preds = %while_5_34_cond
  ret void
}

define i32 @main() {
main:
  %r219 = alloca i32, align 4
  %r217 = alloca i32, align 4
  %r192 = alloca i32, align 4
  %r186 = alloca i32, align 4
  %r187 = call i32 @getint()
  store i32 %r187, i32* @n, align 4
  %r188 = call i32 @getint()
  store i32 %r188, i32* @m, align 4
  store i32 1, i32* %r186, align 4
  br label %while_5_66_cond

while_5_66_cond:                                  ; preds = %while_9_68_bre, %main
  %r189 = load i32, i32* %r186, align 4
  %r190 = load i32, i32* @n, align 4
  %r191 = icmp sle i32 %r189, %r190
  br i1 %r191, label %while_5_66_whilestms, label %while_5_66_bre

while_5_66_whilestms:                             ; preds = %while_5_66_cond
  store i32 1, i32* %r192, align 4
  br label %while_9_68_cond

while_9_68_cond:                                  ; preds = %if_13_69_end, %while_5_66_whilestms
  %r193 = load i32, i32* %r192, align 4
  %r194 = load i32, i32* @n, align 4
  %r195 = icmp sle i32 %r193, %r194
  br i1 %r195, label %while_9_68_whilestms, label %while_9_68_bre

while_9_68_whilestms:                             ; preds = %while_9_68_cond
  %r196 = load i32, i32* %r186, align 4
  %r197 = load i32, i32* %r192, align 4
  %r198 = icmp eq i32 %r196, %r197
  br i1 %r198, label %if_13_69_true, label %if_13_69_false

if_13_69_true:                                    ; preds = %while_9_68_whilestms
  %r199 = load i32, i32* %r186, align 4
  %r200 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r199
  %r201 = getelementptr %array2D, %array2D* %r200, i32 0, i32 0
  %r202 = load i32, i32* %r192, align 4
  %r203 = getelementptr [16 x i32], [16 x i32]* %r201, i32 0, i32 %r202
  store i32 0, i32* %r203, align 4
  br label %if_13_69_end

if_13_69_false:                                   ; preds = %while_9_68_whilestms
  %r204 = load i32, i32* %r186, align 4
  %r205 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r204
  %r206 = getelementptr %array2D, %array2D* %r205, i32 0, i32 0
  %r207 = load i32, i32* %r192, align 4
  %r208 = getelementptr [16 x i32], [16 x i32]* %r206, i32 0, i32 %r207
  %r209 = load i32, i32* @INF, align 4
  store i32 %r209, i32* %r208, align 4
  br label %if_13_69_end

if_13_69_end:                                     ; preds = %if_13_69_false, %if_13_69_true
  %r210 = load i32, i32* %r192, align 4
  %r211 = add i32 %r210, 1
  store i32 %r211, i32* %r192, align 4
  br label %while_9_68_cond

while_9_68_bre:                                   ; preds = %while_9_68_cond
  %r212 = load i32, i32* %r186, align 4
  %r213 = add i32 %r212, 1
  store i32 %r213, i32* %r186, align 4
  br label %while_5_66_cond

while_5_66_bre:                                   ; preds = %while_5_66_cond
  store i32 1, i32* %r186, align 4
  br label %while_5_83_cond

while_5_83_cond:                                  ; preds = %while_5_83_whilestms, %while_5_66_bre
  %r214 = load i32, i32* %r186, align 4
  %r215 = load i32, i32* @m, align 4
  %r216 = icmp sle i32 %r214, %r215
  br i1 %r216, label %while_5_83_whilestms, label %while_5_83_bre

while_5_83_whilestms:                             ; preds = %while_5_83_cond
  %r218 = call i32 @getint()
  store i32 %r218, i32* %r217, align 4
  %r220 = call i32 @getint()
  store i32 %r220, i32* %r219, align 4
  %r221 = load i32, i32* %r217, align 4
  %r222 = getelementptr [16 x %array2D], [16 x %array2D]* @e, i32 0, i32 %r221
  %r223 = getelementptr %array2D, %array2D* %r222, i32 0, i32 0
  %r224 = load i32, i32* %r219, align 4
  %r225 = getelementptr [16 x i32], [16 x i32]* %r223, i32 0, i32 %r224
  %r226 = call i32 @getint()
  store i32 %r226, i32* %r225, align 4
  %r227 = load i32, i32* %r186, align 4
  %r228 = add i32 %r227, 1
  store i32 %r228, i32* %r186, align 4
  br label %while_5_83_cond

while_5_83_bre:                                   ; preds = %while_5_83_cond
  call void @Dijkstra()
  store i32 1, i32* %r186, align 4
  br label %while_5_93_cond

while_5_93_cond:                                  ; preds = %while_5_93_whilestms, %while_5_83_bre
  %r230 = load i32, i32* %r186, align 4
  %r231 = load i32, i32* @n, align 4
  %r232 = icmp sle i32 %r230, %r231
  br i1 %r232, label %while_5_93_whilestms, label %while_5_93_bre

while_5_93_whilestms:                             ; preds = %while_5_93_cond
  %r233 = load i32, i32* %r186, align 4
  %r235 = getelementptr [16 x i32], [16 x i32]* @dis, i32 0, i32 %r233
  %r234 = load i32, i32* %r235, align 4
  call void @putint(i32 %r234)
  call void @putch(i32 32)
  %r238 = load i32, i32* %r186, align 4
  %r239 = add i32 %r238, 1
  store i32 %r239, i32* %r186, align 4
  br label %while_5_93_cond

while_5_93_bre:                                   ; preds = %while_5_93_cond
  call void @putch(i32 10)
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
