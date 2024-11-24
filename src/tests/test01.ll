declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@a = global [ 10 x i32 ] zeroinitializer
@b = global i32 27
define i32 @main( ) {
main:
  call void @_sysy_starttime(i32 4)
  %r101 = alloca i32
  store i32 0, i32* %r101
  %r102 = alloca i32
  store i32 0, i32* %r102
  br label %while_5_16_cond

while_5_16_cond:
  %r103 = load i32, i32* %r101
  %r104 = icmp slt i32 %r103, 10
  br i1 %r104, label %while_5_16_whilestms, label %while_5_16_bre

while_5_16_whilestms:
  %r105 = load i32, i32* %r101
  %r106 = getelementptr [10 x i32 ], [10 x i32 ]* @a, i32 0, i32 %r105
  %r107 = load i32, i32* %r101
  store i32 %r107, i32* %r106
  %r108 = load i32, i32* %r101
  %r109 = add i32 %r108, 1
  store i32 %r109, i32* %r101
  br label %while_5_16_cond

while_5_16_bre:
  store i32 0, i32* %r101
  br label %while_5_22_cond

while_5_22_cond:
  %r110 = load i32, i32* %r101
  %r111 = icmp slt i32 %r110, 10
  br i1 %r111, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:
  %r112 = load i32, i32* %r102
  %r113 = load i32, i32* %r101
  %r115 = getelementptr [10 x i32 ], [10 x i32 ]* @a, i32 0, i32 %r113
  %r114 = load i32, i32* %r115
  %r116 = add i32 %r112, %r114
  store i32 %r116, i32* %r102
  %r117 = load i32, i32* %r101
  %r118 = add i32 %r117, 1
  store i32 %r118, i32* %r101
  br label %while_5_22_cond

while_5_22_bre:
  %r119 = load i32, i32* @b
  call void @putint(i32 %r119)
  %r121 = load i32, i32* %r102
  call void @putint(i32 %r121)
  call void @_sysy_stoptime(i32 19)
  ret i32 0
}

