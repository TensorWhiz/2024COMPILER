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
  %r107 = load i32, i32* %r103
  call void @putint(i32 %r107)
  call void @putch(i32 44)
  call void @putch(i32 32)
  ret void
}

define void @hanoi( i32 %r111, i32 %r113, i32 %r115, i32 %r117 ) {
hanoi:
  %r112 = alloca i32
  store i32 %r111, i32* %r112
  %r114 = alloca i32
  store i32 %r113, i32* %r114
  %r116 = alloca i32
  store i32 %r115, i32* %r116
  %r118 = alloca i32
  store i32 %r117, i32* %r118
  %r119 = load i32, i32* %r112
  %r120 = icmp eq i32 %r119, 1
  br i1 %r120, label %if_5_16_true, label %if_5_16_false

if_5_16_true:
  %r121 = load i32, i32* %r114
  %r122 = load i32, i32* %r118
  call void @move(i32 %r121, i32 %r122)
  br label %if_5_16_end

if_5_16_false:
  %r124 = load i32, i32* %r112
  %r125 = sub i32 %r124, 1
  %r126 = load i32, i32* %r114
  %r127 = load i32, i32* %r118
  %r128 = load i32, i32* %r116
  call void @hanoi(i32 %r125, i32 %r126, i32 %r127, i32 %r128)
  %r130 = load i32, i32* %r114
  %r131 = load i32, i32* %r118
  call void @move(i32 %r130, i32 %r131)
  %r133 = load i32, i32* %r112
  %r134 = sub i32 %r133, 1
  %r135 = load i32, i32* %r116
  %r136 = load i32, i32* %r114
  %r137 = load i32, i32* %r118
  call void @hanoi(i32 %r134, i32 %r135, i32 %r136, i32 %r137)
  br label %if_5_16_end

if_5_16_end:
  ret void
}

define i32 @main( ) {
main:
  %r139 = alloca i32
  %r140 = call i32 @getint()
  store i32 %r140, i32* %r139
  br label %while_5_30_cond

while_5_30_cond:
  %r141 = load i32, i32* %r139
  %r142 = icmp sgt i32 %r141, 0
  br i1 %r142, label %while_5_30_whilestms, label %while_5_30_bre

while_5_30_whilestms:
  %r143 = call i32 @getint()
  call void @hanoi(i32 %r143, i32 1, i32 2, i32 3)
  call void @putch(i32 10)
  %r146 = load i32, i32* %r139
  %r147 = sub i32 %r146, 1
  store i32 %r147, i32* %r139
  br label %while_5_30_cond

while_5_30_bre:
  ret i32 0
}

