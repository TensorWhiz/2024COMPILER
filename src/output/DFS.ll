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
@m = global i32 0
@to = global [5005 x i32] zeroinitializer
@next = global [5005 x i32] zeroinitializer
@head = global [1005 x i32] zeroinitializer
@cnt = global i32 0
@vis = global [1005 x i32] zeroinitializer
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

define i32 @quickread() {
quickread:
  %r100 = alloca i32, align 4
  %r101 = call i32 @getch()
  store i32 %r101, i32* %r100, align 4
  %r102 = alloca i32, align 4
  store i32 0, i32* %r102, align 4
  %r103 = alloca i32, align 4
  store i32 0, i32* %r103, align 4
  br label %while_5_13_cond

while_5_13_cond:                                  ; preds = %if_9_14_end, %quickread
  %r104 = load i32, i32* %r100, align 4
  %r105 = icmp slt i32 %r104, 48
  br i1 %r105, label %while_5_13_whilestms, label %bb25_13_next

bb25_13_next:                                     ; preds = %while_5_13_cond
  %r106 = load i32, i32* %r100, align 4
  %r107 = icmp sgt i32 %r106, 57
  br i1 %r107, label %while_5_13_whilestms, label %while_5_13_bre

while_5_13_whilestms:                             ; preds = %bb25_13_next, %while_5_13_cond
  %r108 = load i32, i32* %r100, align 4
  %r109 = icmp eq i32 %r108, 45
  br i1 %r109, label %if_9_14_true, label %if_9_14_false

if_9_14_true:                                     ; preds = %while_5_13_whilestms
  store i32 1, i32* %r103, align 4
  br label %if_9_14_end

if_9_14_false:                                    ; preds = %while_5_13_whilestms
  br label %if_9_14_end

if_9_14_end:                                      ; preds = %if_9_14_false, %if_9_14_true
  %r110 = call i32 @getch()
  store i32 %r110, i32* %r100, align 4
  br label %while_5_13_cond

while_5_13_bre:                                   ; preds = %bb25_13_next
  br label %while_5_19_cond

while_5_19_cond:                                  ; preds = %while_5_19_whilestms, %while_5_13_bre
  %r111 = load i32, i32* %r100, align 4
  %r112 = icmp sge i32 %r111, 48
  br i1 %r112, label %bb26_19_next, label %while_5_19_bre

bb26_19_next:                                     ; preds = %while_5_19_cond
  %r113 = load i32, i32* %r100, align 4
  %r114 = icmp sle i32 %r113, 57
  br i1 %r114, label %while_5_19_whilestms, label %while_5_19_bre

while_5_19_whilestms:                             ; preds = %bb26_19_next
  %r115 = load i32, i32* %r102, align 4
  %r116 = mul i32 %r115, 10
  %r117 = load i32, i32* %r100, align 4
  %r118 = add i32 %r116, %r117
  %r119 = sub i32 %r118, 48
  store i32 %r119, i32* %r102, align 4
  %r120 = call i32 @getch()
  store i32 %r120, i32* %r100, align 4
  br label %while_5_19_cond

while_5_19_bre:                                   ; preds = %bb26_19_next, %while_5_19_cond
  %r121 = load i32, i32* %r103, align 4
  %r122 = icmp ne i32 %r121, 0
  br i1 %r122, label %if_5_23_true, label %if_5_23_false

if_5_23_true:                                     ; preds = %while_5_19_bre
  %r123 = load i32, i32* %r102, align 4
  %r124 = sub i32 0, %r123
  ret i32 %r124

0:                                                ; No predecessors!
  br label %if_5_23_end

if_5_23_false:                                    ; preds = %while_5_19_bre
  %r125 = load i32, i32* %r102, align 4
  ret i32 %r125

1:                                                ; No predecessors!
  br label %if_5_23_end

if_5_23_end:                                      ; preds = %1, %0
  ret i32 0
}

define void @addedge(i32 %r126, i32 %r128) {
addedge:
  %r127 = alloca i32, align 4
  store i32 %r126, i32* %r127, align 4
  %r129 = alloca i32, align 4
  store i32 %r128, i32* %r129, align 4
  %r130 = load i32, i32* @cnt, align 4
  %r131 = getelementptr [5005 x i32], [5005 x i32]* @to, i32 0, i32 %r130
  %r132 = load i32, i32* %r129, align 4
  store i32 %r132, i32* %r131, align 4
  %r133 = load i32, i32* @cnt, align 4
  %r134 = getelementptr [5005 x i32], [5005 x i32]* @next, i32 0, i32 %r133
  %r135 = load i32, i32* %r127, align 4
  %r137 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r135
  %r136 = load i32, i32* %r137, align 4
  store i32 %r136, i32* %r134, align 4
  %r138 = load i32, i32* %r127, align 4
  %r139 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r138
  %r140 = load i32, i32* @cnt, align 4
  store i32 %r140, i32* %r139, align 4
  %r141 = load i32, i32* @cnt, align 4
  %r142 = add i32 %r141, 1
  store i32 %r142, i32* @cnt, align 4
  %r143 = load i32, i32* @cnt, align 4
  %r144 = getelementptr [5005 x i32], [5005 x i32]* @to, i32 0, i32 %r143
  %r145 = load i32, i32* %r127, align 4
  store i32 %r145, i32* %r144, align 4
  %r146 = load i32, i32* @cnt, align 4
  %r147 = getelementptr [5005 x i32], [5005 x i32]* @next, i32 0, i32 %r146
  %r148 = load i32, i32* %r129, align 4
  %r150 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r148
  %r149 = load i32, i32* %r150, align 4
  store i32 %r149, i32* %r147, align 4
  %r151 = load i32, i32* %r129, align 4
  %r152 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r151
  %r153 = load i32, i32* @cnt, align 4
  store i32 %r153, i32* %r152, align 4
  %r154 = load i32, i32* @cnt, align 4
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* @cnt, align 4
  ret void
}

define void @init() {
init:
  %r156 = alloca i32, align 4
  store i32 0, i32* %r156, align 4
  br label %while_5_51_cond

while_5_51_cond:                                  ; preds = %while_5_51_whilestms, %init
  %r157 = load i32, i32* %r156, align 4
  %r158 = icmp slt i32 %r157, 1005
  br i1 %r158, label %while_5_51_whilestms, label %while_5_51_bre

while_5_51_whilestms:                             ; preds = %while_5_51_cond
  %r159 = load i32, i32* %r156, align 4
  %r160 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r159
  %r161 = sub i32 0, 1
  store i32 %r161, i32* %r160, align 4
  %r162 = load i32, i32* %r156, align 4
  %r163 = add i32 %r162, 1
  store i32 %r163, i32* %r156, align 4
  br label %while_5_51_cond

while_5_51_bre:                                   ; preds = %while_5_51_cond
  ret void
}

define void @clear() {
clear:
  %r164 = alloca i32, align 4
  store i32 1, i32* %r164, align 4
  br label %while_5_59_cond

while_5_59_cond:                                  ; preds = %while_5_59_whilestms, %clear
  %r165 = load i32, i32* %r164, align 4
  %r166 = load i32, i32* @n, align 4
  %r167 = icmp sle i32 %r165, %r166
  br i1 %r167, label %while_5_59_whilestms, label %while_5_59_bre

while_5_59_whilestms:                             ; preds = %while_5_59_cond
  %r168 = load i32, i32* %r164, align 4
  %r169 = getelementptr [1005 x i32], [1005 x i32]* @vis, i32 0, i32 %r168
  store i32 0, i32* %r169, align 4
  %r170 = load i32, i32* %r164, align 4
  %r171 = add i32 %r170, 1
  store i32 %r171, i32* %r164, align 4
  br label %while_5_59_cond

while_5_59_bre:                                   ; preds = %while_5_59_cond
  ret void
}

define i32 @same(i32 %r172, i32 %r174) {
same:
  %r188 = alloca i32, align 4
  %r181 = alloca i32, align 4
  %r173 = alloca i32, align 4
  store i32 %r172, i32* %r173, align 4
  %r175 = alloca i32, align 4
  store i32 %r174, i32* %r175, align 4
  %r176 = load i32, i32* %r173, align 4
  %r177 = getelementptr [1005 x i32], [1005 x i32]* @vis, i32 0, i32 %r176
  store i32 1, i32* %r177, align 4
  %r178 = load i32, i32* %r173, align 4
  %r179 = load i32, i32* %r175, align 4
  %r180 = icmp eq i32 %r178, %r179
  br i1 %r180, label %if_5_67_true, label %if_5_67_false

if_5_67_true:                                     ; preds = %same
  ret i32 1

0:                                                ; No predecessors!
  br label %if_5_67_end

if_5_67_false:                                    ; preds = %same
  br label %if_5_67_end

if_5_67_end:                                      ; preds = %if_5_67_false, %0
  %r182 = load i32, i32* %r173, align 4
  %r184 = getelementptr [1005 x i32], [1005 x i32]* @head, i32 0, i32 %r182
  %r183 = load i32, i32* %r184, align 4
  store i32 %r183, i32* %r181, align 4
  br label %while_5_71_cond

while_5_71_cond:                                  ; preds = %if_9_73_end, %if_5_67_end
  %r185 = load i32, i32* %r181, align 4
  %r186 = sub i32 0, 1
  %r187 = icmp ne i32 %r185, %r186
  br i1 %r187, label %while_5_71_whilestms, label %while_5_71_bre

while_5_71_whilestms:                             ; preds = %while_5_71_cond
  %r189 = load i32, i32* %r181, align 4
  %r191 = getelementptr [5005 x i32], [5005 x i32]* @to, i32 0, i32 %r189
  %r190 = load i32, i32* %r191, align 4
  store i32 %r190, i32* %r188, align 4
  %r192 = load i32, i32* %r188, align 4
  %r194 = getelementptr [1005 x i32], [1005 x i32]* @vis, i32 0, i32 %r192
  %r193 = load i32, i32* %r194, align 4
  %r195 = icmp eq i32 %r193, 0
  br i1 %r195, label %bb28_73_next, label %if_9_73_false

bb28_73_next:                                     ; preds = %while_5_71_whilestms
  %r196 = load i32, i32* %r188, align 4
  %r197 = load i32, i32* %r175, align 4
  %r198 = call i32 @same(i32 %r196, i32 %r197)
  %r199 = icmp ne i32 %r198, 0
  br i1 %r199, label %if_9_73_true, label %if_9_73_false

if_9_73_true:                                     ; preds = %bb28_73_next
  ret i32 1

1:                                                ; No predecessors!
  br label %if_9_73_end

if_9_73_false:                                    ; preds = %bb28_73_next, %while_5_71_whilestms
  br label %if_9_73_end

if_9_73_end:                                      ; preds = %if_9_73_false, %1
  %r200 = load i32, i32* %r181, align 4
  %r202 = getelementptr [5005 x i32], [5005 x i32]* @next, i32 0, i32 %r200
  %r201 = load i32, i32* %r202, align 4
  store i32 %r201, i32* %r181, align 4
  br label %while_5_71_cond

while_5_71_bre:                                   ; preds = %while_5_71_cond
  ret i32 0
}

define i32 @main() {
main:
  %r203 = call i32 @quickread()
  store i32 %r203, i32* @n, align 4
  %r204 = call i32 @quickread()
  store i32 %r204, i32* @m, align 4
  call void @init()
  %r206 = alloca i32, align 4
  store i32 0, i32* %r206, align 4
  %r207 = alloca i32, align 4
  store i32 0, i32* %r207, align 4
  %r208 = alloca i32, align 4
  store i32 0, i32* %r208, align 4
  br label %while_5_87_cond

while_5_87_cond:                                  ; preds = %if_9_92_end, %main
  %r209 = load i32, i32* @m, align 4
  %r210 = icmp ne i32 %r209, 0
  br i1 %r210, label %while_5_87_whilestms, label %while_5_87_bre

while_5_87_whilestms:                             ; preds = %while_5_87_cond
  %r211 = call i32 @getch()
  store i32 %r211, i32* %r206, align 4
  br label %while_9_89_cond

while_9_89_cond:                                  ; preds = %while_9_89_whilestms, %while_5_87_whilestms
  %r212 = load i32, i32* %r206, align 4
  %r213 = icmp ne i32 %r212, 81
  br i1 %r213, label %bb30_89_next, label %while_9_89_bre

bb30_89_next:                                     ; preds = %while_9_89_cond
  %r214 = load i32, i32* %r206, align 4
  %r215 = icmp ne i32 %r214, 85
  br i1 %r215, label %while_9_89_whilestms, label %while_9_89_bre

while_9_89_whilestms:                             ; preds = %bb30_89_next
  %r216 = call i32 @getch()
  store i32 %r216, i32* %r206, align 4
  br label %while_9_89_cond

while_9_89_bre:                                   ; preds = %bb30_89_next, %while_9_89_cond
  %r217 = load i32, i32* %r206, align 4
  %r218 = icmp eq i32 %r217, 81
  br i1 %r218, label %if_9_92_true, label %if_9_92_false

if_9_92_true:                                     ; preds = %while_9_89_bre
  %r219 = call i32 @quickread()
  store i32 %r219, i32* %r207, align 4
  %r220 = call i32 @quickread()
  store i32 %r220, i32* %r208, align 4
  call void @clear()
  %r222 = load i32, i32* %r207, align 4
  %r223 = load i32, i32* %r208, align 4
  %r224 = call i32 @same(i32 %r222, i32 %r223)
  call void @putint(i32 %r224)
  call void @putch(i32 10)
  br label %if_9_92_end

if_9_92_false:                                    ; preds = %while_9_89_bre
  %r227 = call i32 @quickread()
  store i32 %r227, i32* %r207, align 4
  %r228 = call i32 @quickread()
  store i32 %r228, i32* %r208, align 4
  %r229 = load i32, i32* %r207, align 4
  %r230 = load i32, i32* %r208, align 4
  call void @addedge(i32 %r229, i32 %r230)
  br label %if_9_92_end

if_9_92_end:                                      ; preds = %if_9_92_false, %if_9_92_true
  %r232 = load i32, i32* @m, align 4
  %r233 = sub i32 %r232, 1
  store i32 %r233, i32* @m, align 4
  br label %while_5_87_cond

while_5_87_bre:                                   ; preds = %while_5_87_cond
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
