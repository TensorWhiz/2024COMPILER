declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @swap( i32* %r100, i32 %r101, i32 %r103 ) {
swap:
  %r102 = alloca i32
  store i32 %r101, i32* %r102
  %r104 = alloca i32
  store i32 %r103, i32* %r104
  %r105 = alloca i32
  %r106 = load i32, i32* %r102
  %r108 = getelementptr i32, i32* %r100, i32 %r106
  %r107 = load i32, i32* %r108
  store i32 %r107, i32* %r105
  %r109 = load i32, i32* %r102
  %r110 = getelementptr i32, i32* %r100, i32 %r109
  %r111 = load i32, i32* %r104
  %r113 = getelementptr i32, i32* %r100, i32 %r111
  %r112 = load i32, i32* %r113
  store i32 %r112, i32* %r110
  %r114 = load i32, i32* %r104
  %r115 = getelementptr i32, i32* %r100, i32 %r114
  %r116 = load i32, i32* %r105
  store i32 %r116, i32* %r115
  ret i32 0
}

define i32 @heap_ajust( i32* %r117, i32 %r118, i32 %r120 ) {
heap_ajust:
  %r132 = alloca i32
  %r119 = alloca i32
  store i32 %r118, i32* %r119
  %r121 = alloca i32
  store i32 %r120, i32* %r121
  %r122 = alloca i32
  %r123 = load i32, i32* %r119
  store i32 %r123, i32* %r122
  %r124 = alloca i32
  %r125 = load i32, i32* %r122
  %r126 = mul i32 %r125, 2
  %r127 = add i32 %r126, 1
  store i32 %r127, i32* %r124
  br label %while_5_22_cond

while_5_22_cond:
  %r128 = load i32, i32* %r124
  %r129 = load i32, i32* %r121
  %r130 = add i32 %r129, 1
  %r131 = icmp slt i32 %r128, %r130
  br i1 %r131, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:
  %r133 = load i32, i32* %r124
  %r134 = add i32 %r133, 1
  store i32 %r134, i32* %r132
  %r135 = load i32, i32* %r124
  %r136 = load i32, i32* %r121
  %r137 = icmp slt i32 %r135, %r136
  br i1 %r137, label %bb28_24_next, label %if_9_24_false

bb28_24_next:
  %r138 = load i32, i32* %r124
  %r140 = getelementptr i32, i32* %r117, i32 %r138
  %r139 = load i32, i32* %r140
  %r141 = load i32, i32* %r132
  %r143 = getelementptr i32, i32* %r117, i32 %r141
  %r142 = load i32, i32* %r143
  %r144 = icmp slt i32 %r139, %r142
  br i1 %r144, label %if_9_24_true, label %if_9_24_false

if_9_24_true:
  %r145 = load i32, i32* %r124
  %r146 = add i32 %r145, 1
  store i32 %r146, i32* %r124
  br label %if_9_24_end

if_9_24_false:
  br label %if_9_24_end

if_9_24_end:
  %r147 = load i32, i32* %r122
  %r149 = getelementptr i32, i32* %r117, i32 %r147
  %r148 = load i32, i32* %r149
  %r150 = load i32, i32* %r124
  %r152 = getelementptr i32, i32* %r117, i32 %r150
  %r151 = load i32, i32* %r152
  %r153 = icmp sgt i32 %r148, %r151
  br i1 %r153, label %if_9_26_true, label %if_9_26_false

if_9_26_true:
  ret i32 0
  br label %if_9_26_end

if_9_26_false:
  %r154 = load i32, i32* %r122
  %r155 = load i32, i32* %r124
  %r156 = call i32 @swap(i32* %r117, i32 %r154, i32 %r155)
  store i32 %r156, i32* %r122
  %r157 = load i32, i32* %r124
  store i32 %r157, i32* %r122
  %r158 = load i32, i32* %r122
  %r159 = mul i32 %r158, 2
  %r160 = add i32 %r159, 1
  store i32 %r160, i32* %r124
  br label %if_9_26_end

if_9_26_end:
  br label %while_5_22_cond

while_5_22_bre:
  ret i32 0
}

define i32 @heap_sort( i32* %r161, i32 %r162 ) {
heap_sort:
  %r183 = alloca i32
  %r163 = alloca i32
  store i32 %r162, i32* %r163
  %r164 = alloca i32
  %r165 = alloca i32
  %r166 = load i32, i32* %r163
  %r167 = sdiv i32 %r166, 2
  %r168 = sub i32 %r167, 1
  store i32 %r168, i32* %r164
  br label %while_5_40_cond

while_5_40_cond:
  %r169 = load i32, i32* %r164
  %r170 = sub i32 0, 1
  %r171 = icmp sgt i32 %r169, %r170
  br i1 %r171, label %while_5_40_whilestms, label %while_5_40_bre

while_5_40_whilestms:
  %r172 = load i32, i32* %r163
  %r173 = sub i32 %r172, 1
  store i32 %r173, i32* %r165
  %r174 = load i32, i32* %r164
  %r175 = load i32, i32* %r165
  %r176 = call i32 @heap_ajust(i32* %r161, i32 %r174, i32 %r175)
  store i32 %r176, i32* %r165
  %r177 = load i32, i32* %r164
  %r178 = sub i32 %r177, 1
  store i32 %r178, i32* %r164
  br label %while_5_40_cond

while_5_40_bre:
  %r179 = load i32, i32* %r163
  %r180 = sub i32 %r179, 1
  store i32 %r180, i32* %r164
  br label %while_5_46_cond

while_5_46_cond:
  %r181 = load i32, i32* %r164
  %r182 = icmp sgt i32 %r181, 0
  br i1 %r182, label %while_5_46_whilestms, label %while_5_46_bre

while_5_46_whilestms:
  store i32 0, i32* %r183
  %r184 = load i32, i32* %r183
  %r185 = load i32, i32* %r164
  %r186 = call i32 @swap(i32* %r161, i32 %r184, i32 %r185)
  store i32 %r186, i32* %r165
  %r187 = load i32, i32* %r164
  %r188 = sub i32 %r187, 1
  store i32 %r188, i32* %r165
  %r189 = load i32, i32* %r183
  %r190 = load i32, i32* %r165
  %r191 = call i32 @heap_ajust(i32* %r161, i32 %r189, i32 %r190)
  store i32 %r191, i32* %r165
  %r192 = load i32, i32* %r164
  %r193 = sub i32 %r192, 1
  store i32 %r193, i32* %r164
  br label %while_5_46_cond

while_5_46_bre:
  ret i32 0
}

define i32 @main( ) {
main:
  %r212 = alloca i32
  store i32 10, i32* @n
  %r194 = alloca [ 10 x i32 ]
  %r195 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 0
  store i32 4, i32* %r195
  %r196 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 1
  store i32 3, i32* %r196
  %r197 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 2
  store i32 9, i32* %r197
  %r198 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 3
  store i32 2, i32* %r198
  %r199 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 4
  store i32 0, i32* %r199
  %r200 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 5
  store i32 1, i32* %r200
  %r201 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 6
  store i32 6, i32* %r201
  %r202 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 7
  store i32 5, i32* %r202
  %r203 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 8
  store i32 7, i32* %r203
  %r204 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 9
  store i32 8, i32* %r204
  %r205 = alloca i32
  store i32 0, i32* %r205
  %r206 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 0
  %r207 = load i32, i32* @n
  %r208 = call i32 @heap_sort(i32* %r206, i32 %r207)
  store i32 %r208, i32* %r205
  br label %while_5_65_cond

while_5_65_cond:
  %r209 = load i32, i32* %r205
  %r210 = load i32, i32* @n
  %r211 = icmp slt i32 %r209, %r210
  br i1 %r211, label %while_5_65_whilestms, label %while_5_65_bre

while_5_65_whilestms:
  %r213 = load i32, i32* %r205
  %r215 = getelementptr [10 x i32 ], [10 x i32 ]* %r194, i32 0, i32 %r213
  %r214 = load i32, i32* %r215
  store i32 %r214, i32* %r212
  %r216 = load i32, i32* %r212
  call void @putint(i32 %r216)
  store i32 10, i32* %r212
  %r218 = load i32, i32* %r212
  call void @putch(i32 %r218)
  %r220 = load i32, i32* %r205
  %r221 = add i32 %r220, 1
  store i32 %r221, i32* %r205
  br label %while_5_65_cond

while_5_65_bre:
  ret i32 0
}

