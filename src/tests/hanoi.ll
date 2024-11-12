declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define void @move( i32 %r100, i32 %r102 ) {
move:
  %r101 = alloca i32
  store i32 %r100, i32* %r101
  %r103 = alloca i32
  store i32 %r102, i32* %r103
  %r104 = load i32, i32* %r101
  call void @putint(i32 %r104)
  call void @putch(i32 32)
  %r105 = load i32, i32* %r103
  call void @putint(i32 %r105)
  call void @putch(i32 44)
  call void @putch(i32 32)
  ret void
}

define void @hanoi( i32 %r106, i32 %r108, i32 %r110, i32 %r112 ) {
hanoi:
  %r107 = alloca i32
  store i32 %r106, i32* %r107
  %r109 = alloca i32
  store i32 %r108, i32* %r109
  %r111 = alloca i32
  store i32 %r110, i32* %r111
  %r113 = alloca i32
  store i32 %r112, i32* %r113
  %r114 = load i32, i32* %r107
  %r115 = icmp eq i32 %r114, 1
  br i1 %r115, label %if_5_16_true, label %if_5_16_false

if_5_16_true:
  %r116 = load i32, i32* %r109
  %r117 = load i32, i32* %r113
  call void @move(i32 %r116, i32 %r117)
  br label %if_5_16_end

if_5_16_false:
  %r118 = load i32, i32* %r107
  %r119 = sub i32 %r118, 1
  %r120 = load i32, i32* %r109
  %r121 = load i32, i32* %r113
  %r122 = load i32, i32* %r111
  call void @hanoi(i32 %r119, i32 %r120, i32 %r121, i32 %r122)
  %r123 = load i32, i32* %r109
  %r124 = load i32, i32* %r113
  call void @move(i32 %r123, i32 %r124)
  %r125 = load i32, i32* %r107
  %r126 = sub i32 %r125, 1
  %r127 = load i32, i32* %r111
  %r128 = load i32, i32* %r109
  %r129 = load i32, i32* %r113
  call void @hanoi(i32 %r126, i32 %r127, i32 %r128, i32 %r129)
  br label %if_5_16_end

if_5_16_end:
  ret void
}

define i32 @main( ) {
main:
  %r130 = alloca i32
  %r131 = call i32 @getint()
  store i32 %r131, i32* %r130
  br label %while_5_30_cond

while_5_30_cond:
  %r132 = load i32, i32* %r130
  %r133 = icmp sgt i32 %r132, 0
  br i1 %r133, label %while_5_30_whilestms, label %while_5_30_bre

while_5_30_whilestms:
  %r134 = call i32 @getint()
  call void @hanoi(i32 %r134, i32 1, i32 2, i32 3)
  call void @putch(i32 10)
  %r135 = load i32, i32* %r130
  %r136 = sub i32 %r135, 1
  store i32 %r136, i32* %r130
  br label %while_5_30_cond

while_5_30_bre:
  ret i32 0
}

