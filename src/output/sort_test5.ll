; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque
%struct.timeval = type { i64, i64 }

@n = global i32 0
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

define i32 @swap(i32* %r100, i32 %r101, i32 %r103) {
swap:
  %r102 = alloca i32, align 4
  store i32 %r101, i32* %r102, align 4
  %r104 = alloca i32, align 4
  store i32 %r103, i32* %r104, align 4
  %r105 = alloca i32, align 4
  %r106 = load i32, i32* %r102, align 4
  %r108 = getelementptr i32, i32* %r100, i32 %r106
  %r107 = load i32, i32* %r108, align 4
  store i32 %r107, i32* %r105, align 4
  %r109 = load i32, i32* %r102, align 4
  %r110 = getelementptr i32, i32* %r100, i32 %r109
  %r111 = load i32, i32* %r104, align 4
  %r113 = getelementptr i32, i32* %r100, i32 %r111
  %r112 = load i32, i32* %r113, align 4
  store i32 %r112, i32* %r110, align 4
  %r114 = load i32, i32* %r104, align 4
  %r115 = getelementptr i32, i32* %r100, i32 %r114
  %r116 = load i32, i32* %r105, align 4
  store i32 %r116, i32* %r115, align 4
  ret i32 0
}

define i32 @heap_ajust(i32* %r117, i32 %r118, i32 %r120) {
heap_ajust:
  %r132 = alloca i32, align 4
  %r119 = alloca i32, align 4
  store i32 %r118, i32* %r119, align 4
  %r121 = alloca i32, align 4
  store i32 %r120, i32* %r121, align 4
  %r122 = alloca i32, align 4
  %r123 = load i32, i32* %r119, align 4
  store i32 %r123, i32* %r122, align 4
  %r124 = alloca i32, align 4
  %r125 = load i32, i32* %r122, align 4
  %r126 = mul i32 %r125, 2
  %r127 = add i32 %r126, 1
  store i32 %r127, i32* %r124, align 4
  br label %while_5_22_cond

while_5_22_cond:                                  ; preds = %if_9_26_end, %heap_ajust
  %r128 = load i32, i32* %r124, align 4
  %r129 = load i32, i32* %r121, align 4
  %r130 = add i32 %r129, 1
  %r131 = icmp slt i32 %r128, %r130
  br i1 %r131, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:                             ; preds = %while_5_22_cond
  %r133 = load i32, i32* %r124, align 4
  %r134 = add i32 %r133, 1
  store i32 %r134, i32* %r132, align 4
  %r135 = load i32, i32* %r124, align 4
  %r136 = load i32, i32* %r121, align 4
  %r137 = icmp slt i32 %r135, %r136
  br i1 %r137, label %bb28_24_next, label %if_9_24_false

bb28_24_next:                                     ; preds = %while_5_22_whilestms
  %r138 = load i32, i32* %r124, align 4
  %r140 = getelementptr i32, i32* %r117, i32 %r138
  %r139 = load i32, i32* %r140, align 4
  %r141 = load i32, i32* %r132, align 4
  %r143 = getelementptr i32, i32* %r117, i32 %r141
  %r142 = load i32, i32* %r143, align 4
  %r144 = icmp slt i32 %r139, %r142
  br i1 %r144, label %if_9_24_true, label %if_9_24_false

if_9_24_true:                                     ; preds = %bb28_24_next
  %r145 = load i32, i32* %r124, align 4
  %r146 = add i32 %r145, 1
  store i32 %r146, i32* %r124, align 4
  br label %if_9_24_end

if_9_24_false:                                    ; preds = %bb28_24_next, %while_5_22_whilestms
  br label %if_9_24_end

if_9_24_end:                                      ; preds = %if_9_24_false, %if_9_24_true
  %r147 = load i32, i32* %r122, align 4
  %r149 = getelementptr i32, i32* %r117, i32 %r147
  %r148 = load i32, i32* %r149, align 4
  %r150 = load i32, i32* %r124, align 4
  %r152 = getelementptr i32, i32* %r117, i32 %r150
  %r151 = load i32, i32* %r152, align 4
  %r153 = icmp sgt i32 %r148, %r151
  br i1 %r153, label %if_9_26_true, label %if_9_26_false

if_9_26_true:                                     ; preds = %if_9_24_end
  ret i32 0

0:                                                ; No predecessors!
  br label %if_9_26_end

if_9_26_false:                                    ; preds = %if_9_24_end
  %r154 = load i32, i32* %r122, align 4
  %r155 = load i32, i32* %r124, align 4
  %r156 = call i32 @swap(i32* %r117, i32 %r154, i32 %r155)
  store i32 %r156, i32* %r122, align 4
  %r157 = load i32, i32* %r124, align 4
  store i32 %r157, i32* %r122, align 4
  %r158 = load i32, i32* %r122, align 4
  %r159 = mul i32 %r158, 2
  %r160 = add i32 %r159, 1
  store i32 %r160, i32* %r124, align 4
  br label %if_9_26_end

if_9_26_end:                                      ; preds = %if_9_26_false, %0
  br label %while_5_22_cond

while_5_22_bre:                                   ; preds = %while_5_22_cond
  ret i32 0
}

define i32 @heap_sort(i32* %r161, i32 %r162) {
heap_sort:
  %r183 = alloca i32, align 4
  %r163 = alloca i32, align 4
  store i32 %r162, i32* %r163, align 4
  %r164 = alloca i32, align 4
  %r165 = alloca i32, align 4
  %r166 = load i32, i32* %r163, align 4
  %r167 = sdiv i32 %r166, 2
  %r168 = sub i32 %r167, 1
  store i32 %r168, i32* %r164, align 4
  br label %while_5_40_cond

while_5_40_cond:                                  ; preds = %while_5_40_whilestms, %heap_sort
  %r169 = load i32, i32* %r164, align 4
  %r170 = sub i32 0, 1
  %r171 = icmp sgt i32 %r169, %r170
  br i1 %r171, label %while_5_40_whilestms, label %while_5_40_bre

while_5_40_whilestms:                             ; preds = %while_5_40_cond
  %r172 = load i32, i32* %r163, align 4
  %r173 = sub i32 %r172, 1
  store i32 %r173, i32* %r165, align 4
  %r174 = load i32, i32* %r164, align 4
  %r175 = load i32, i32* %r165, align 4
  %r176 = call i32 @heap_ajust(i32* %r161, i32 %r174, i32 %r175)
  store i32 %r176, i32* %r165, align 4
  %r177 = load i32, i32* %r164, align 4
  %r178 = sub i32 %r177, 1
  store i32 %r178, i32* %r164, align 4
  br label %while_5_40_cond

while_5_40_bre:                                   ; preds = %while_5_40_cond
  %r179 = load i32, i32* %r163, align 4
  %r180 = sub i32 %r179, 1
  store i32 %r180, i32* %r164, align 4
  br label %while_5_46_cond

while_5_46_cond:                                  ; preds = %while_5_46_whilestms, %while_5_40_bre
  %r181 = load i32, i32* %r164, align 4
  %r182 = icmp sgt i32 %r181, 0
  br i1 %r182, label %while_5_46_whilestms, label %while_5_46_bre

while_5_46_whilestms:                             ; preds = %while_5_46_cond
  store i32 0, i32* %r183, align 4
  %r184 = load i32, i32* %r183, align 4
  %r185 = load i32, i32* %r164, align 4
  %r186 = call i32 @swap(i32* %r161, i32 %r184, i32 %r185)
  store i32 %r186, i32* %r165, align 4
  %r187 = load i32, i32* %r164, align 4
  %r188 = sub i32 %r187, 1
  store i32 %r188, i32* %r165, align 4
  %r189 = load i32, i32* %r183, align 4
  %r190 = load i32, i32* %r165, align 4
  %r191 = call i32 @heap_ajust(i32* %r161, i32 %r189, i32 %r190)
  store i32 %r191, i32* %r165, align 4
  %r192 = load i32, i32* %r164, align 4
  %r193 = sub i32 %r192, 1
  store i32 %r193, i32* %r164, align 4
  br label %while_5_46_cond

while_5_46_bre:                                   ; preds = %while_5_46_cond
  ret i32 0
}

define i32 @main() {
main:
  %r212 = alloca i32, align 4
  store i32 10, i32* @n, align 4
  %r194 = alloca [10 x i32], align 4
  %r195 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 0
  store i32 4, i32* %r195, align 4
  %r196 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 1
  store i32 3, i32* %r196, align 4
  %r197 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 2
  store i32 9, i32* %r197, align 4
  %r198 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 3
  store i32 2, i32* %r198, align 4
  %r199 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 4
  store i32 0, i32* %r199, align 4
  %r200 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 5
  store i32 1, i32* %r200, align 4
  %r201 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 6
  store i32 6, i32* %r201, align 4
  %r202 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 7
  store i32 5, i32* %r202, align 4
  %r203 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 8
  store i32 7, i32* %r203, align 4
  %r204 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 9
  store i32 8, i32* %r204, align 4
  %r205 = alloca i32, align 4
  store i32 0, i32* %r205, align 4
  %r206 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 0
  %r207 = load i32, i32* @n, align 4
  %r208 = call i32 @heap_sort(i32* %r206, i32 %r207)
  store i32 %r208, i32* %r205, align 4
  br label %while_5_65_cond

while_5_65_cond:                                  ; preds = %while_5_65_whilestms, %main
  %r209 = load i32, i32* %r205, align 4
  %r210 = load i32, i32* @n, align 4
  %r211 = icmp slt i32 %r209, %r210
  br i1 %r211, label %while_5_65_whilestms, label %while_5_65_bre

while_5_65_whilestms:                             ; preds = %while_5_65_cond
  %r213 = load i32, i32* %r205, align 4
  %r215 = getelementptr [10 x i32], [10 x i32]* %r194, i32 0, i32 %r213
  %r214 = load i32, i32* %r215, align 4
  store i32 %r214, i32* %r212, align 4
  %r216 = load i32, i32* %r212, align 4
  call void @putint(i32 %r216)
  store i32 10, i32* %r212, align 4
  %r218 = load i32, i32* %r212, align 4
  call void @putch(i32 %r218)
  %r220 = load i32, i32* %r205, align 4
  %r221 = add i32 %r220, 1
  store i32 %r221, i32* %r205, align 4
  br label %while_5_65_cond

while_5_65_bre:                                   ; preds = %while_5_65_cond
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
