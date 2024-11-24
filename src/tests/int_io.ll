declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@ascii_0 = global i32 48
define i32 @my_getint( ) {
my_getint:
  %r100 = alloca i32
  store i32 0, i32* %r100
  %r101 = alloca i32
  br label %while_5_15_cond

while_5_15_cond:
  %r102 = icmp sgt i32 1, 0
  br i1 %r102, label %while_5_15_whilestms, label %while_5_15_bre

while_5_15_whilestms:
  %r103 = call i32 @getch()
  %r104 = load i32, i32* @ascii_0
  %r105 = sub i32 %r103, %r104
  store i32 %r105, i32* %r101
  %r106 = load i32, i32* %r101
  %r107 = icmp slt i32 %r106, 0
  br i1 %r107, label %if_9_17_true, label %bb24_17_next

bb24_17_next:
  %r108 = load i32, i32* %r101
  %r109 = icmp sgt i32 %r108, 9
  br i1 %r109, label %if_9_17_true, label %if_9_17_false

if_9_17_true:
  br label %while_5_15_cond

  br label %if_9_17_end

if_9_17_false:
  br label %while_5_15_bre

  br label %if_9_17_end

if_9_17_end:
  br label %while_5_15_cond

while_5_15_bre:
  %r110 = load i32, i32* %r101
  store i32 %r110, i32* %r100
  br label %while_5_25_cond

while_5_25_cond:
  %r111 = icmp sgt i32 1, 0
  br i1 %r111, label %while_5_25_whilestms, label %while_5_25_bre

while_5_25_whilestms:
  %r112 = call i32 @getch()
  %r113 = load i32, i32* @ascii_0
  %r114 = sub i32 %r112, %r113
  store i32 %r114, i32* %r101
  %r115 = load i32, i32* %r101
  %r116 = icmp sge i32 %r115, 0
  br i1 %r116, label %bb25_27_next, label %if_9_27_false

bb25_27_next:
  %r117 = load i32, i32* %r101
  %r118 = icmp sle i32 %r117, 9
  br i1 %r118, label %if_9_27_true, label %if_9_27_false

if_9_27_true:
  %r119 = load i32, i32* %r100
  %r120 = mul i32 %r119, 10
  %r121 = load i32, i32* %r101
  %r122 = add i32 %r120, %r121
  store i32 %r122, i32* %r100
  br label %if_9_27_end

if_9_27_false:
  br label %while_5_25_bre

  br label %if_9_27_end

if_9_27_end:
  br label %while_5_25_cond

while_5_25_bre:
  %r123 = load i32, i32* %r100
  ret i32 %r123
}

define i32 @mod( i32 %r124, i32 %r126 ) {
mod:
  %r125 = alloca i32
  store i32 %r124, i32* %r125
  %r127 = alloca i32
  store i32 %r126, i32* %r127
  %r128 = load i32, i32* %r125
  %r129 = load i32, i32* %r125
  %r130 = load i32, i32* %r127
  %r131 = sdiv i32 %r129, %r130
  %r132 = load i32, i32* %r127
  %r133 = mul i32 %r131, %r132
  %r134 = sub i32 %r128, %r133
  ret i32 %r134
}

define void @my_putint( i32 %r135 ) {
my_putint:
  %r136 = alloca i32
  store i32 %r135, i32* %r136
  %r137 = alloca [ 16 x i32 ]
  %r138 = alloca i32
  store i32 0, i32* %r138
  br label %while_5_46_cond

while_5_46_cond:
  %r139 = load i32, i32* %r136
  %r140 = icmp sgt i32 %r139, 0
  br i1 %r140, label %while_5_46_whilestms, label %while_5_46_bre

while_5_46_whilestms:
  %r141 = load i32, i32* %r138
  %r142 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r141
  %r143 = load i32, i32* %r136
  %r144 = call i32 @mod(i32 %r143, i32 10)
  %r145 = load i32, i32* @ascii_0
  %r146 = add i32 %r144, %r145
  store i32 %r146, i32* %r142
  %r147 = load i32, i32* %r136
  %r148 = sdiv i32 %r147, 10
  store i32 %r148, i32* %r136
  %r149 = load i32, i32* %r138
  %r150 = add i32 %r149, 1
  store i32 %r150, i32* %r138
  br label %while_5_46_cond

while_5_46_bre:
  br label %while_5_51_cond

while_5_51_cond:
  %r151 = load i32, i32* %r138
  %r152 = icmp sgt i32 %r151, 0
  br i1 %r152, label %while_5_51_whilestms, label %while_5_51_bre

while_5_51_whilestms:
  %r153 = load i32, i32* %r138
  %r154 = sub i32 %r153, 1
  store i32 %r154, i32* %r138
  %r155 = load i32, i32* %r138
  %r157 = getelementptr [16 x i32 ], [16 x i32 ]* %r137, i32 0, i32 %r155
  %r156 = load i32, i32* %r157
  call void @putch(i32 %r156)
  br label %while_5_51_cond

while_5_51_bre:
  ret void
}

define i32 @main( ) {
main:
  %r163 = alloca i32
  %r159 = alloca i32
  %r160 = call i32 @my_getint()
  store i32 %r160, i32* %r159
  br label %while_5_60_cond

while_5_60_cond:
  %r161 = load i32, i32* %r159
  %r162 = icmp sgt i32 %r161, 0
  br i1 %r162, label %while_5_60_whilestms, label %while_5_60_bre

while_5_60_whilestms:
  %r164 = call i32 @my_getint()
  store i32 %r164, i32* %r163
  %r165 = load i32, i32* %r163
  call void @my_putint(i32 %r165)
  call void @putch(i32 10)
  %r168 = load i32, i32* %r159
  %r169 = sub i32 %r168, 1
  store i32 %r169, i32* %r159
  br label %while_5_60_cond

while_5_60_bre:
  ret i32 0
}

