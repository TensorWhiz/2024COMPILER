declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
@newline = global i32 0
define i32 @mod( i32 %r100, i32 %r102 ) {
mod:
  %r101 = alloca i32
  store i32 %r100, i32* %r101
  %r103 = alloca i32
  store i32 %r102, i32* %r103
  %r104 = load i32, i32* %r101
  %r105 = load i32, i32* %r101
  %r106 = load i32, i32* %r103
  %r107 = sdiv i32 %r105, %r106
  %r108 = load i32, i32* %r103
  %r109 = mul i32 %r107, %r108
  %r110 = sub i32 %r104, %r109
  ret i32 %r110
}

define i32 @split( i32 %r111, i32* %r113 ) {
split:
  %r112 = alloca i32
  store i32 %r111, i32* %r112
  %r114 = alloca i32
  %r115 = load i32, i32* @N
  %r116 = sub i32 %r115, 1
  store i32 %r116, i32* %r114
  br label %while_5_22_cond

while_5_22_cond:
  %r117 = load i32, i32* %r114
  %r118 = icmp ne i32 %r117, -1
  br i1 %r118, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:
  %r119 = load i32, i32* %r114
  %r120 = getelementptr i32, i32* %r113, i32 %r119
  %r121 = load i32, i32* %r112
  %r122 = call i32 @mod(i32 %r121, i32 10)
  store i32 %r122, i32* %r120
  %r123 = load i32, i32* %r112
  %r124 = sdiv i32 %r123, 10
  store i32 %r124, i32* %r112
  %r125 = load i32, i32* %r114
  %r126 = sub i32 %r125, 1
  store i32 %r126, i32* %r114
  br label %while_5_22_cond

while_5_22_bre:
  ret i32 0
}

define i32 @main( ) {
main:
  store i32 4, i32* @N
  store i32 10, i32* @newline
  %r127 = alloca i32
  %r128 = alloca i32
  %r129 = alloca [ 4 x i32 ]
  store i32 1478, i32* %r128
  %r130 = load i32, i32* %r128
  %r131 = getelementptr [4 x i32 ], [4 x i32 ]* %r129, i32 0, i32 0
  %r132 = call i32 @split(i32 %r130, i32* %r131)
  store i32 %r132, i32* %r128
  %r133 = alloca i32
  store i32 0, i32* %r127
  br label %while_5_43_cond

while_5_43_cond:
  %r134 = load i32, i32* %r127
  %r135 = icmp slt i32 %r134, 4
  br i1 %r135, label %while_5_43_whilestms, label %while_5_43_bre

while_5_43_whilestms:
  %r136 = load i32, i32* %r127
  %r138 = getelementptr [4 x i32 ], [4 x i32 ]* %r129, i32 0, i32 %r136
  %r137 = load i32, i32* %r138
  store i32 %r137, i32* %r133
  %r139 = load i32, i32* %r133
  call void @putint(i32 %r139)
  %r141 = load i32, i32* @newline
  call void @putch(i32 %r141)
  %r143 = load i32, i32* %r127
  %r144 = add i32 %r143, 1
  store i32 %r144, i32* %r127
  br label %while_5_43_cond

while_5_43_bre:
  ret i32 0
}

