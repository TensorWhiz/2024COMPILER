declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @uniquePaths( i32 %r100, i32 %r102 ) {
uniquePaths:
  %r113 = alloca i32
  %r112 = alloca i32
  %r111 = alloca i32
  %r110 = alloca i32
  %r109 = alloca i32
  %r108 = alloca [ 9 x i32 ]
  %r101 = alloca i32
  store i32 %r100, i32* %r101
  %r103 = alloca i32
  store i32 %r102, i32* %r103
  %r104 = load i32, i32* %r101
  %r105 = icmp eq i32 %r104, 1
  br i1 %r105, label %if_5_10_true, label %bb20_10_next

bb20_10_next:
  %r106 = load i32, i32* %r103
  %r107 = icmp eq i32 %r106, 1
  br i1 %r107, label %if_5_10_true, label %if_5_10_false

if_5_10_true:
  ret i32 1
  br label %if_5_10_end

if_5_10_false:
  br label %if_5_10_end

if_5_10_end:
  store i32 0, i32* %r109
  br label %while_5_22_cond

while_5_22_cond:
  %r114 = load i32, i32* %r109
  %r115 = load i32, i32* %r101
  %r116 = icmp slt i32 %r114, %r115
  br i1 %r116, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:
  %r117 = load i32, i32* %r109
  %r118 = mul i32 %r117, 3
  %r119 = load i32, i32* %r103
  %r120 = add i32 %r118, %r119
  %r121 = sub i32 %r120, 1
  store i32 %r121, i32* %r111
  %r122 = load i32, i32* %r111
  %r123 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r122
  store i32 1, i32* %r123
  %r124 = load i32, i32* %r109
  %r125 = add i32 %r124, 1
  store i32 %r125, i32* %r109
  br label %while_5_22_cond

while_5_22_bre:
  store i32 0, i32* %r109
  br label %while_5_28_cond

while_5_28_cond:
  %r126 = load i32, i32* %r109
  %r127 = load i32, i32* %r103
  %r128 = icmp slt i32 %r126, %r127
  br i1 %r128, label %while_5_28_whilestms, label %while_5_28_bre

while_5_28_whilestms:
  %r129 = load i32, i32* %r101
  %r130 = sub i32 %r129, 1
  %r131 = mul i32 %r130, 3
  %r132 = load i32, i32* %r109
  %r133 = add i32 %r131, %r132
  store i32 %r133, i32* %r111
  %r134 = load i32, i32* %r111
  %r135 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r134
  store i32 1, i32* %r135
  %r136 = load i32, i32* %r109
  %r137 = add i32 %r136, 1
  store i32 %r137, i32* %r109
  br label %while_5_28_cond

while_5_28_bre:
  %r138 = load i32, i32* %r101
  %r139 = sub i32 %r138, 2
  store i32 %r139, i32* %r109
  br label %while_5_34_cond

while_5_34_cond:
  %r140 = load i32, i32* %r109
  %r141 = sub i32 0, 1
  %r142 = icmp sgt i32 %r140, %r141
  br i1 %r142, label %while_5_34_whilestms, label %while_5_34_bre

while_5_34_whilestms:
  %r143 = load i32, i32* %r103
  %r144 = sub i32 %r143, 2
  store i32 %r144, i32* %r110
  br label %while_9_36_cond

while_9_36_cond:
  %r145 = load i32, i32* %r110
  %r146 = sub i32 0, 1
  %r147 = icmp sgt i32 %r145, %r146
  br i1 %r147, label %while_9_36_whilestms, label %while_9_36_bre

while_9_36_whilestms:
  %r148 = load i32, i32* %r109
  %r149 = mul i32 %r148, 3
  %r150 = load i32, i32* %r110
  %r151 = add i32 %r149, %r150
  store i32 %r151, i32* %r111
  %r152 = load i32, i32* %r109
  %r153 = add i32 %r152, 1
  %r154 = mul i32 %r153, 3
  %r155 = load i32, i32* %r110
  %r156 = add i32 %r154, %r155
  store i32 %r156, i32* %r112
  %r157 = load i32, i32* %r109
  %r158 = mul i32 %r157, 3
  %r159 = load i32, i32* %r110
  %r160 = add i32 %r158, %r159
  %r161 = add i32 %r160, 1
  store i32 %r161, i32* %r113
  %r162 = load i32, i32* %r111
  %r163 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r162
  %r164 = load i32, i32* %r112
  %r166 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r164
  %r165 = load i32, i32* %r166
  %r167 = load i32, i32* %r113
  %r169 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r167
  %r168 = load i32, i32* %r169
  %r170 = add i32 %r165, %r168
  store i32 %r170, i32* %r163
  %r171 = load i32, i32* %r110
  %r172 = sub i32 %r171, 1
  store i32 %r172, i32* %r110
  br label %while_9_36_cond

while_9_36_bre:
  %r173 = load i32, i32* %r109
  %r174 = sub i32 %r173, 1
  store i32 %r174, i32* %r109
  br label %while_5_34_cond

while_5_34_bre:
  %r176 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 0
  %r175 = load i32, i32* %r176
  ret i32 %r175
}

define i32 @main( ) {
main:
  %r177 = alloca i32
  %r178 = alloca i32
  store i32 3, i32* %r178
  %r179 = load i32, i32* %r178
  %r180 = load i32, i32* %r178
  %r181 = call i32 @uniquePaths(i32 %r179, i32 %r180)
  store i32 %r181, i32* %r177
  %r182 = load i32, i32* %r177
  ret i32 %r182
}

