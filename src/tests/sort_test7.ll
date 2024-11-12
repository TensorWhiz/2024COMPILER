declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @Merge( i32* %r100, i32 %r101, i32 %r103, i32 %r105 ) {
Merge:
  %r148 = alloca i32
  %r102 = alloca i32
  store i32 %r101, i32* %r102
  %r104 = alloca i32
  store i32 %r103, i32* %r104
  %r106 = alloca i32
  store i32 %r105, i32* %r106
  %r107 = alloca i32
  %r108 = load i32, i32* %r104
  %r109 = load i32, i32* %r102
  %r110 = sub i32 %r108, %r109
  %r111 = add i32 %r110, 1
  store i32 %r111, i32* %r107
  %r112 = alloca i32
  %r113 = load i32, i32* %r106
  %r114 = load i32, i32* %r104
  %r115 = sub i32 %r113, %r114
  store i32 %r115, i32* %r112
  %r116 = alloca [ 10 x i32 ]
  %r117 = alloca [ 10 x i32 ]
  %r118 = alloca i32
  store i32 0, i32* %r118
  %r119 = alloca i32
  store i32 0, i32* %r119
  %r120 = alloca i32
  br label %while_5_23_cond

while_5_23_cond:
  %r121 = load i32, i32* %r118
  %r122 = load i32, i32* %r107
  %r123 = icmp slt i32 %r121, %r122
  br i1 %r123, label %while_5_23_whilestms, label %while_5_23_bre

while_5_23_whilestms:
  %r124 = load i32, i32* %r118
  %r125 = load i32, i32* %r102
  %r126 = add i32 %r124, %r125
  store i32 %r126, i32* %r120
  %r127 = load i32, i32* %r118
  %r128 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r127
  %r129 = load i32, i32* %r120
  %r130 = getelementptr i32, i32* %r100, i32 %r129
  %r131 = load i32, i32* %r130
  store i32 %r131, i32* %r128
  %r132 = load i32, i32* %r118
  %r133 = add i32 %r132, 1
  store i32 %r133, i32* %r118
  br label %while_5_23_cond

while_5_23_bre:
  br label %while_5_28_cond

while_5_28_cond:
  %r134 = load i32, i32* %r119
  %r135 = load i32, i32* %r112
  %r136 = icmp slt i32 %r134, %r135
  br i1 %r136, label %while_5_28_whilestms, label %while_5_28_bre

while_5_28_whilestms:
  %r137 = load i32, i32* %r119
  %r138 = load i32, i32* %r104
  %r139 = add i32 %r137, %r138
  %r140 = add i32 %r139, 1
  store i32 %r140, i32* %r120
  %r141 = load i32, i32* %r119
  %r142 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r141
  %r143 = load i32, i32* %r120
  %r144 = getelementptr i32, i32* %r100, i32 %r143
  %r145 = load i32, i32* %r144
  store i32 %r145, i32* %r142
  %r146 = load i32, i32* %r119
  %r147 = add i32 %r146, 1
  store i32 %r147, i32* %r119
  br label %while_5_28_cond

while_5_28_bre:
  store i32 0, i32* %r118
  store i32 0, i32* %r119
  %r149 = load i32, i32* %r102
  store i32 %r149, i32* %r148
  br label %while_5_37_cond

while_5_37_cond:
  %r150 = load i32, i32* %r118
  %r151 = load i32, i32* %r107
  %r152 = icmp ne i32 %r150, %r151
  br i1 %r152, label %bb22_37_next, label %while_5_37_bre

bb22_37_next:
  %r153 = load i32, i32* %r119
  %r154 = load i32, i32* %r112
  %r155 = icmp ne i32 %r153, %r154
  br i1 %r155, label %while_5_37_whilestms, label %while_5_37_bre

while_5_37_whilestms:
  %r156 = load i32, i32* %r118
  %r157 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r156
  %r158 = load i32, i32* %r157
  %r159 = load i32, i32* %r119
  %r160 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r159
  %r161 = load i32, i32* %r160
  %r162 = add i32 %r161, 1
  %r163 = icmp slt i32 %r158, %r162
  br i1 %r163, label %if_9_39_true, label %if_9_39_false

if_9_39_true:
  %r164 = load i32, i32* %r148
  %r165 = getelementptr i32, i32* %r100, i32 %r164
  %r166 = load i32, i32* %r118
  %r167 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r166
  %r168 = load i32, i32* %r167
  store i32 %r168, i32* %r165
  %r169 = load i32, i32* %r148
  %r170 = add i32 %r169, 1
  store i32 %r170, i32* %r148
  %r171 = load i32, i32* %r118
  %r172 = add i32 %r171, 1
  store i32 %r172, i32* %r118
  br label %if_9_39_end

if_9_39_false:
  %r173 = load i32, i32* %r148
  %r174 = getelementptr i32, i32* %r100, i32 %r173
  %r175 = load i32, i32* %r119
  %r176 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r175
  %r177 = load i32, i32* %r176
  store i32 %r177, i32* %r174
  %r178 = load i32, i32* %r148
  %r179 = add i32 %r178, 1
  store i32 %r179, i32* %r148
  %r180 = load i32, i32* %r119
  %r181 = add i32 %r180, 1
  store i32 %r181, i32* %r119
  br label %if_9_39_end

if_9_39_end:
  br label %while_5_37_cond

while_5_37_bre:
  br label %while_5_50_cond

while_5_50_cond:
  %r182 = load i32, i32* %r118
  %r183 = load i32, i32* %r107
  %r184 = icmp slt i32 %r182, %r183
  br i1 %r184, label %while_5_50_whilestms, label %while_5_50_bre

while_5_50_whilestms:
  %r185 = load i32, i32* %r148
  %r186 = getelementptr i32, i32* %r100, i32 %r185
  %r187 = load i32, i32* %r118
  %r188 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r187
  %r189 = load i32, i32* %r188
  store i32 %r189, i32* %r186
  %r190 = load i32, i32* %r148
  %r191 = add i32 %r190, 1
  store i32 %r191, i32* %r148
  %r192 = load i32, i32* %r118
  %r193 = add i32 %r192, 1
  store i32 %r193, i32* %r118
  br label %while_5_50_cond

while_5_50_bre:
  br label %while_5_55_cond

while_5_55_cond:
  %r194 = load i32, i32* %r119
  %r195 = load i32, i32* %r112
  %r196 = icmp slt i32 %r194, %r195
  br i1 %r196, label %while_5_55_whilestms, label %while_5_55_bre

while_5_55_whilestms:
  %r197 = load i32, i32* %r148
  %r198 = getelementptr i32, i32* %r100, i32 %r197
  %r199 = load i32, i32* %r119
  %r200 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r199
  %r201 = load i32, i32* %r200
  store i32 %r201, i32* %r198
  %r202 = load i32, i32* %r148
  %r203 = add i32 %r202, 1
  store i32 %r203, i32* %r148
  %r204 = load i32, i32* %r119
  %r205 = add i32 %r204, 1
  store i32 %r205, i32* %r119
  br label %while_5_55_cond

while_5_55_bre:
  ret i32 0
}

define i32 @MergeSort( i32* %r206, i32 %r207, i32 %r209 ) {
MergeSort:
  %r219 = alloca i32
  %r214 = alloca i32
  %r208 = alloca i32
  store i32 %r207, i32* %r208
  %r210 = alloca i32
  store i32 %r209, i32* %r210
  %r211 = load i32, i32* %r208
  %r212 = load i32, i32* %r210
  %r213 = icmp slt i32 %r211, %r212
  br i1 %r213, label %if_5_65_true, label %if_5_65_false

if_5_65_true:
  %r215 = load i32, i32* %r208
  %r216 = load i32, i32* %r210
  %r217 = add i32 %r215, %r216
  %r218 = sdiv i32 %r217, 2
  store i32 %r218, i32* %r214
  %r220 = getelementptr i32, i32* %r206, i32 0
  %r221 = load i32, i32* %r208
  %r222 = load i32, i32* %r214
  %r223 = call i32 @MergeSort(i32* %r220, i32 %r221, i32 %r222)
  store i32 %r223, i32* %r219
  %r224 = load i32, i32* %r214
  %r225 = add i32 %r224, 1
  store i32 %r225, i32* %r219
  %r226 = getelementptr i32, i32* %r206, i32 0
  %r227 = load i32, i32* %r219
  %r228 = load i32, i32* %r210
  %r229 = call i32 @MergeSort(i32* %r226, i32 %r227, i32 %r228)
  store i32 %r229, i32* %r219
  %r230 = getelementptr i32, i32* %r206, i32 0
  %r231 = load i32, i32* %r208
  %r232 = load i32, i32* %r214
  %r233 = load i32, i32* %r210
  %r234 = call i32 @Merge(i32* %r230, i32 %r231, i32 %r232, i32 %r233)
  store i32 %r234, i32* %r219
  br label %if_5_65_end

if_5_65_false:
  br label %if_5_65_end

if_5_65_end:
  ret i32 0
}

define i32 @main( ) {
main:
  store i32 10, i32* @n
  %r235 = alloca [ 10 x i32 ]
  %r236 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 0
  store i32 4, i32* %r236
  %r237 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 1
  store i32 3, i32* %r237
  %r238 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 2
  store i32 9, i32* %r238
  %r239 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 3
  store i32 2, i32* %r239
  %r240 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 4
  store i32 0, i32* %r240
  %r241 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 5
  store i32 1, i32* %r241
  %r242 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 6
  store i32 6, i32* %r242
  %r243 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 7
  store i32 5, i32* %r243
  %r244 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 8
  store i32 7, i32* %r244
  %r245 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 9
  store i32 8, i32* %r245
  %r246 = alloca i32
  store i32 0, i32* %r246
  %r247 = alloca i32
  %r248 = load i32, i32* @n
  %r249 = sub i32 %r248, 1
  store i32 %r249, i32* %r247
  %r250 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 0
  %r251 = load i32, i32* %r246
  %r252 = load i32, i32* %r247
  %r253 = call i32 @MergeSort(i32* %r250, i32 %r251, i32 %r252)
  store i32 %r253, i32* %r246
  br label %while_5_88_cond

while_5_88_cond:
  %r254 = load i32, i32* %r246
  %r255 = load i32, i32* @n
  %r256 = icmp slt i32 %r254, %r255
  br i1 %r256, label %while_5_88_whilestms, label %while_5_88_bre

while_5_88_whilestms:
  %r257 = load i32, i32* %r246
  %r258 = getelementptr [10 x i32 ], [10 x i32 ]* %r235, i32 0, i32 %r257
  %r259 = load i32, i32* %r258
  store i32 %r259, i32* %r247
  %r260 = load i32, i32* %r247
  call void @putint(i32 %r260)
  store i32 10, i32* %r247
  %r261 = load i32, i32* %r247
  call void @putch(i32 %r261)
  %r262 = load i32, i32* %r246
  %r263 = add i32 %r262, 1
  store i32 %r263, i32* %r246
  br label %while_5_88_cond

while_5_88_bre:
  ret i32 0
}

