declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
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

define i32 @pow( i32 %r111, i32 %r113 ) {
pow:
  %r120 = alloca i32
  %r112 = alloca i32
  store i32 %r111, i32* %r112
  %r114 = alloca i32
  store i32 %r113, i32* %r114
  %r115 = alloca i32
  store i32 1, i32* %r115
  %r116 = alloca i32
  %r117 = load i32, i32* %r112
  store i32 %r117, i32* %r116
  br label %while_5_18_cond

while_5_18_cond:
  %r118 = load i32, i32* %r114
  %r119 = icmp sgt i32 %r118, 0
  br i1 %r119, label %while_5_18_whilestms, label %while_5_18_bre

while_5_18_whilestms:
  %r121 = load i32, i32* %r114
  %r122 = call i32 @mod(i32 %r121, i32 2)
  store i32 %r122, i32* %r120
  %r123 = load i32, i32* %r120
  %r124 = icmp eq i32 %r123, 1
  br i1 %r124, label %if_9_21_true, label %if_9_21_false

if_9_21_true:
  %r125 = load i32, i32* %r115
  %r126 = load i32, i32* %r116
  %r127 = mul i32 %r125, %r126
  store i32 %r127, i32* %r115
  br label %if_9_21_end

if_9_21_false:
  br label %if_9_21_end

if_9_21_end:
  %r128 = load i32, i32* %r116
  %r129 = load i32, i32* %r116
  %r130 = mul i32 %r128, %r129
  store i32 %r130, i32* %r116
  %r131 = load i32, i32* %r114
  %r132 = sdiv i32 %r131, 2
  store i32 %r132, i32* %r114
  br label %while_5_18_cond

while_5_18_bre:
  %r133 = load i32, i32* %r115
  ret i32 %r133
}

define i32 @main( ) {
main:
  %r134 = alloca i32
  %r135 = alloca i32
  %r136 = call i32 @getint()
  store i32 %r136, i32* %r134
  %r137 = call i32 @getint()
  store i32 %r137, i32* %r135
  %r138 = alloca i32
  %r139 = load i32, i32* %r134
  %r140 = load i32, i32* %r135
  %r141 = call i32 @pow(i32 %r139, i32 %r140)
  store i32 %r141, i32* %r138
  %r142 = load i32, i32* %r138
  call void @putint(i32 %r142)
  ret i32 0
}

