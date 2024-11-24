declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
main:
  %r115 = alloca i32
  %r114 = alloca i32
  %r113 = alloca i32
  %r112 = alloca i32
  %r111 = alloca i32
  %r100 = alloca i32
  %r101 = alloca i32
  %r102 = alloca [ 10 x i32 ]
  store i32 0, i32* %r101
  store i32 0, i32* %r100
  br label %while_5_16_cond

while_5_16_cond:
  %r103 = load i32, i32* %r100
  %r104 = icmp slt i32 %r103, 10
  br i1 %r104, label %while_5_16_whilestms, label %while_5_16_bre

while_5_16_whilestms:
  %r105 = load i32, i32* %r100
  %r106 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r105
  %r107 = load i32, i32* %r100
  %r108 = add i32 %r107, 1
  store i32 %r108, i32* %r106
  %r109 = load i32, i32* %r100
  %r110 = add i32 %r109, 1
  store i32 %r110, i32* %r100
  br label %while_5_16_cond

while_5_16_bre:
  store i32 10, i32* %r115
  %r116 = call i32 @getint()
  store i32 %r116, i32* %r111
  %r117 = load i32, i32* %r115
  %r118 = sub i32 %r117, 1
  store i32 %r118, i32* %r112
  store i32 0, i32* %r113
  %r119 = load i32, i32* %r112
  %r120 = load i32, i32* %r113
  %r121 = add i32 %r119, %r120
  %r122 = sdiv i32 %r121, 2
  store i32 %r122, i32* %r114
  br label %while_5_31_cond

while_5_31_cond:
  %r123 = load i32, i32* %r114
  %r125 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r123
  %r124 = load i32, i32* %r125
  %r126 = load i32, i32* %r111
  %r127 = icmp ne i32 %r124, %r126
  br i1 %r127, label %bb26_31_next, label %while_5_31_bre

bb26_31_next:
  %r128 = load i32, i32* %r113
  %r129 = load i32, i32* %r112
  %r130 = icmp slt i32 %r128, %r129
  br i1 %r130, label %while_5_31_whilestms, label %while_5_31_bre

while_5_31_whilestms:
  %r131 = load i32, i32* %r112
  %r132 = load i32, i32* %r113
  %r133 = add i32 %r131, %r132
  %r134 = sdiv i32 %r133, 2
  store i32 %r134, i32* %r114
  %r135 = load i32, i32* %r111
  %r136 = load i32, i32* %r114
  %r138 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r136
  %r137 = load i32, i32* %r138
  %r139 = icmp slt i32 %r135, %r137
  br i1 %r139, label %if_9_34_true, label %if_9_34_false

if_9_34_true:
  %r140 = load i32, i32* %r114
  %r141 = sub i32 %r140, 1
  store i32 %r141, i32* %r112
  br label %if_9_34_end

if_9_34_false:
  %r142 = load i32, i32* %r114
  %r143 = add i32 %r142, 1
  store i32 %r143, i32* %r113
  br label %if_9_34_end

if_9_34_end:
  br label %while_5_31_cond

while_5_31_bre:
  %r144 = load i32, i32* %r111
  %r145 = load i32, i32* %r114
  %r147 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r145
  %r146 = load i32, i32* %r147
  %r148 = icmp eq i32 %r144, %r146
  br i1 %r148, label %if_5_44_true, label %if_5_44_false

if_5_44_true:
  %r149 = load i32, i32* %r111
  call void @putint(i32 %r149)
  br label %if_5_44_end

if_5_44_false:
  store i32 0, i32* %r111
  %r151 = load i32, i32* %r111
  call void @putint(i32 %r151)
  br label %if_5_44_end

if_5_44_end:
  store i32 10, i32* %r111
  %r153 = load i32, i32* %r111
  call void @putch(i32 %r153)
  ret i32 0
}

