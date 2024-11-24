declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
main:
  %r105 = alloca i32
  call void @_sysy_starttime(i32 2)
  %r101 = alloca i32
  store i32 0, i32* %r101
  %r102 = alloca i32
  store i32 1, i32* %r102
  br label %while_5_13_cond

while_5_13_cond:
  %r103 = load i32, i32* %r101
  %r104 = icmp slt i32 %r103, 1000000
  br i1 %r104, label %while_5_13_whilestms, label %while_5_13_bre

while_5_13_whilestms:
  store i32 0, i32* %r105
  %r106 = load i32, i32* %r101
  %r107 = add i32 %r106, 1
  store i32 %r107, i32* %r101
  br label %while_5_13_cond

while_5_13_bre:
  %r108 = load i32, i32* %r102
  call void @putint(i32 %r108)
  call void @_sysy_stoptime(i32 10)
  ret i32 0
}

