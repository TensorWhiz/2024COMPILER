declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@b = global [ 10 x i32 ] zeroinitializer
define void @foo( i32* %r100 ) {
foo:
  %r101 = alloca i32
  store i32 0, i32* %r101
  br label %while_5_13_cond

while_5_13_cond:
  %r102 = load i32, i32* %r101
  %r103 = icmp slt i32 %r102, 10
  br i1 %r103, label %while_5_13_whilestms, label %while_5_13_bre

while_5_13_whilestms:
  %r104 = load i32, i32* %r101
  %r105 = getelementptr i32, i32* %r100, i32 %r104
  %r106 = call i32 @getint()
  store i32 %r106, i32* %r105
  %r107 = load i32, i32* %r101
  %r108 = add i32 %r107, 1
  store i32 %r108, i32* %r101
  br label %while_5_13_cond

while_5_13_bre:
  ret void
}

define i32 @main( ) {
main:
  call void @_sysy_starttime(i32 13)
  %r110 = alloca i32
  store i32 0, i32* %r110
  %r111 = alloca i32
  store i32 0, i32* %r111
  %r112 = getelementptr [10 x i32 ], [10 x i32 ]* @b, i32 0, i32 0
  call void @foo(i32* %r112)
  br label %while_5_25_cond

while_5_25_cond:
  %r114 = load i32, i32* %r110
  %r115 = icmp slt i32 %r114, 10
  br i1 %r115, label %while_5_25_whilestms, label %while_5_25_bre

while_5_25_whilestms:
  %r116 = load i32, i32* %r111
  %r117 = load i32, i32* %r110
  %r119 = getelementptr [10 x i32 ], [10 x i32 ]* @b, i32 0, i32 %r117
  %r118 = load i32, i32* %r119
  %r120 = add i32 %r116, %r118
  store i32 %r120, i32* %r111
  %r121 = load i32, i32* %r110
  %r122 = add i32 %r121, 1
  store i32 %r122, i32* %r110
  br label %while_5_25_cond

while_5_25_bre:
  %r123 = getelementptr [10 x i32 ], [10 x i32 ]* @b, i32 0, i32 0
  call void @putarray(i32 10, i32* %r123)
  %r125 = load i32, i32* %r111
  call void @putint(i32 %r125)
  call void @_sysy_stoptime(i32 24)
  ret i32 0
}

