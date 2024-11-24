declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
main:
  %r124 = alloca i32
  %r123 = alloca i32
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
  store i32 0, i32* %r123
  store i32 0, i32* %r100
  store i32 0, i32* %r124
  br label %while_5_36_cond

while_5_36_cond:
  %r125 = load i32, i32* %r100
  %r126 = icmp slt i32 %r125, 10
  br i1 %r126, label %bb21_36_next, label %while_5_36_bre

bb21_36_next:
  %r127 = load i32, i32* %r123
  %r128 = icmp eq i32 %r127, 0
  br i1 %r128, label %while_5_36_whilestms, label %while_5_36_bre

while_5_36_whilestms:
  %r129 = load i32, i32* %r100
  %r131 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r129
  %r130 = load i32, i32* %r131
  %r132 = load i32, i32* %r111
  %r133 = icmp eq i32 %r130, %r132
  br i1 %r133, label %if_9_38_true, label %if_9_38_false

if_9_38_true:
  store i32 1, i32* %r123
  %r134 = load i32, i32* %r100
  store i32 %r134, i32* %r124
  br label %if_9_38_end

if_9_38_false:
  br label %if_9_38_end

if_9_38_end:
  %r135 = load i32, i32* %r100
  %r136 = add i32 %r135, 1
  store i32 %r136, i32* %r100
  br label %while_5_36_cond

while_5_36_bre:
  %r137 = load i32, i32* %r123
  %r138 = icmp eq i32 %r137, 1
  br i1 %r138, label %if_5_47_true, label %if_5_47_false

if_5_47_true:
  %r139 = load i32, i32* %r124
  call void @putint(i32 %r139)
  br label %if_5_47_end

if_5_47_false:
  store i32 0, i32* %r111
  %r141 = load i32, i32* %r111
  call void @putint(i32 %r141)
  br label %if_5_47_end

if_5_47_end:
  store i32 10, i32* %r111
  %r143 = load i32, i32* %r111
  call void @putch(i32 %r143)
  ret i32 0
}

