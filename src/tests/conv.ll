declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@max = global i32 1073741824
@a = global [ 10000000 x i32 ] zeroinitializer
@b = global [ 10000000 x i32 ] zeroinitializer
@kernelid_ = global [ 10000 x i32 ] zeroinitializer
define i32 @checkrange( i32 %r100 ) {
checkrange:
  %r101 = alloca i32
  store i32 %r100, i32* %r101
  br label %while_5_10_cond

while_5_10_cond:
  %r102 = load i32, i32* %r101
  %r103 = load i32, i32* @max
  %r104 = icmp sgt i32 %r102, %r103
  br i1 %r104, label %while_5_10_whilestms, label %while_5_10_bre

while_5_10_whilestms:
  %r105 = load i32, i32* %r101
  %r106 = load i32, i32* @max
  %r107 = sub i32 %r105, %r106
  store i32 %r107, i32* %r101
  br label %while_5_10_cond

while_5_10_bre:
  br label %while_5_11_cond

while_5_11_cond:
  %r108 = load i32, i32* %r101
  %r109 = icmp slt i32 %r108, 0
  br i1 %r109, label %while_5_11_whilestms, label %while_5_11_bre

while_5_11_whilestms:
  %r110 = load i32, i32* %r101
  %r111 = load i32, i32* @max
  %r112 = add i32 %r110, %r111
  store i32 %r112, i32* %r101
  br label %while_5_11_cond

while_5_11_bre:
  %r113 = load i32, i32* %r101
  ret i32 %r113
}

define i32 @mod( i32 %r114, i32 %r116 ) {
mod:
  %r115 = alloca i32
  store i32 %r114, i32* %r115
  %r117 = alloca i32
  store i32 %r116, i32* %r117
  %r118 = load i32, i32* %r115
  %r119 = load i32, i32* %r115
  %r120 = load i32, i32* %r117
  %r121 = sdiv i32 %r119, %r120
  %r122 = load i32, i32* %r117
  %r123 = mul i32 %r121, %r122
  %r124 = sub i32 %r118, %r123
  ret i32 %r124
}

define i32 @reduce( i32 %r125, i32 %r127, i32 %r129 ) {
reduce:
  %r196 = alloca i32
  %r195 = alloca i32
  %r171 = alloca i32
  %r170 = alloca i32
  %r140 = alloca i32
  %r139 = alloca i32
  %r126 = alloca i32
  store i32 %r125, i32* %r126
  %r128 = alloca i32
  store i32 %r127, i32* %r128
  %r130 = alloca i32
  store i32 %r129, i32* %r130
  %r131 = load i32, i32* %r126
  %r132 = icmp eq i32 %r131, 0
  br i1 %r132, label %if_5_19_true, label %if_5_19_false

if_5_19_true:
  %r133 = load i32, i32* %r128
  %r134 = load i32, i32* %r130
  %r135 = add i32 %r133, %r134
  %r136 = call i32 @checkrange(i32 %r135)
  ret i32 %r136
  br label %if_5_19_end

if_5_19_false:
  br label %if_5_19_end

if_5_19_end:
  %r137 = load i32, i32* %r126
  %r138 = icmp eq i32 %r137, 1
  br i1 %r138, label %if_5_22_true, label %if_5_22_false

if_5_22_true:
  store i32 0, i32* %r139
  store i32 1, i32* %r140
  br label %while_9_26_cond

while_9_26_cond:
  %r141 = load i32, i32* %r140
  %r142 = load i32, i32* @max
  %r143 = icmp slt i32 %r141, %r142
  br i1 %r143, label %while_9_26_whilestms, label %while_9_26_bre

while_9_26_whilestms:
  %r144 = load i32, i32* %r128
  %r145 = load i32, i32* %r140
  %r146 = sdiv i32 %r144, %r145
  %r147 = call i32 @mod(i32 %r146, i32 2)
  %r148 = load i32, i32* %r130
  %r149 = load i32, i32* %r140
  %r150 = sdiv i32 %r148, %r149
  %r151 = call i32 @mod(i32 %r150, i32 2)
  %r152 = icmp eq i32 %r147, %r151
  br i1 %r152, label %if_13_27_true, label %if_13_27_false

if_13_27_true:
  %r153 = load i32, i32* %r139
  %r154 = mul i32 %r153, 2
  store i32 %r154, i32* %r139
  br label %if_13_27_end

if_13_27_false:
  %r155 = load i32, i32* %r139
  %r156 = mul i32 %r155, 2
  %r157 = add i32 %r156, 1
  store i32 %r157, i32* %r139
  br label %if_13_27_end

if_13_27_end:
  %r158 = load i32, i32* %r140
  %r159 = mul i32 %r158, 2
  store i32 %r159, i32* %r140
  br label %while_9_26_cond

while_9_26_bre:
  %r160 = load i32, i32* %r139
  ret i32 %r160
  br label %if_5_22_end

if_5_22_false:
  br label %if_5_22_end

if_5_22_end:
  %r161 = load i32, i32* %r126
  %r162 = icmp eq i32 %r161, 2
  br i1 %r162, label %if_5_37_true, label %if_5_37_false

if_5_37_true:
  %r163 = load i32, i32* %r128
  %r164 = load i32, i32* %r130
  %r165 = icmp sgt i32 %r163, %r164
  br i1 %r165, label %if_9_38_true, label %if_9_38_false

if_9_38_true:
  %r166 = load i32, i32* %r128
  ret i32 %r166
  br label %if_9_38_end

if_9_38_false:
  %r167 = load i32, i32* %r130
  ret i32 %r167
  br label %if_9_38_end

if_9_38_end:
  br label %if_5_37_end

if_5_37_false:
  br label %if_5_37_end

if_5_37_end:
  %r168 = load i32, i32* %r126
  %r169 = icmp eq i32 %r168, 3
  br i1 %r169, label %if_5_41_true, label %if_5_41_false

if_5_41_true:
  store i32 0, i32* %r170
  store i32 1, i32* %r171
  br label %while_9_46_cond

while_9_46_cond:
  %r172 = load i32, i32* %r140
  %r173 = load i32, i32* @max
  %r174 = icmp slt i32 %r172, %r173
  br i1 %r174, label %while_9_46_whilestms, label %while_9_46_bre

while_9_46_whilestms:
  %r175 = load i32, i32* %r128
  %r176 = load i32, i32* %r140
  %r177 = sdiv i32 %r175, %r176
  %r178 = call i32 @mod(i32 %r177, i32 2)
  %r179 = icmp eq i32 %r178, 1
  br i1 %r179, label %if_13_47_true, label %bb37_47_next

bb37_47_next:
  %r180 = load i32, i32* %r130
  %r181 = load i32, i32* %r140
  %r182 = sdiv i32 %r180, %r181
  %r183 = call i32 @mod(i32 %r182, i32 2)
  %r184 = icmp eq i32 %r183, 1
  br i1 %r184, label %if_13_47_true, label %if_13_47_false

if_13_47_true:
  %r185 = load i32, i32* %r139
  %r186 = mul i32 %r185, 2
  %r187 = add i32 %r186, 1
  store i32 %r187, i32* %r139
  br label %if_13_47_end

if_13_47_false:
  %r188 = load i32, i32* %r139
  %r189 = mul i32 %r188, 2
  store i32 %r189, i32* %r139
  br label %if_13_47_end

if_13_47_end:
  %r190 = load i32, i32* %r140
  %r191 = mul i32 %r190, 2
  store i32 %r191, i32* %r140
  br label %while_9_46_cond

while_9_46_bre:
  %r192 = load i32, i32* %r139
  ret i32 %r192
  br label %if_5_41_end

if_5_41_false:
  br label %if_5_41_end

if_5_41_end:
  %r193 = load i32, i32* %r126
  %r194 = icmp eq i32 %r193, 4
  br i1 %r194, label %if_5_57_true, label %if_5_57_false

if_5_57_true:
  store i32 0, i32* %r195
  store i32 1, i32* %r196
  br label %while_9_61_cond

while_9_61_cond:
  %r197 = load i32, i32* %r140
  %r198 = load i32, i32* @max
  %r199 = icmp slt i32 %r197, %r198
  br i1 %r199, label %while_9_61_whilestms, label %while_9_61_bre

while_9_61_whilestms:
  %r200 = load i32, i32* %r128
  %r201 = load i32, i32* %r140
  %r202 = sdiv i32 %r200, %r201
  %r203 = call i32 @mod(i32 %r202, i32 2)
  %r204 = icmp eq i32 %r203, 1
  br i1 %r204, label %bb37_62_next, label %if_13_62_false

bb37_62_next:
  %r205 = load i32, i32* %r130
  %r206 = load i32, i32* %r140
  %r207 = sdiv i32 %r205, %r206
  %r208 = call i32 @mod(i32 %r207, i32 2)
  %r209 = icmp eq i32 %r208, 1
  br i1 %r209, label %if_13_62_true, label %if_13_62_false

if_13_62_true:
  %r210 = load i32, i32* %r139
  %r211 = mul i32 %r210, 2
  %r212 = add i32 %r211, 1
  store i32 %r212, i32* %r139
  br label %if_13_62_end

if_13_62_false:
  %r213 = load i32, i32* %r139
  %r214 = mul i32 %r213, 2
  store i32 %r214, i32* %r139
  br label %if_13_62_end

if_13_62_end:
  %r215 = load i32, i32* %r140
  %r216 = mul i32 %r215, 2
  store i32 %r216, i32* %r140
  br label %while_9_61_cond

while_9_61_bre:
  %r217 = load i32, i32* %r139
  ret i32 %r217
  br label %if_5_57_end

if_5_57_false:
  br label %if_5_57_end

if_5_57_end:
  ret i32 0
}

define i32 @getvalue( i32* %r218, i32 %r219, i32 %r221, i32 %r223, i32 %r225 ) {
getvalue:
  %r237 = alloca i32
  %r220 = alloca i32
  store i32 %r219, i32* %r220
  %r222 = alloca i32
  store i32 %r221, i32* %r222
  %r224 = alloca i32
  store i32 %r223, i32* %r224
  %r226 = alloca i32
  store i32 %r225, i32* %r226
  %r227 = load i32, i32* %r224
  %r228 = icmp slt i32 %r227, 0
  br i1 %r228, label %if_5_76_true, label %bb20_76_next

bb20_76_next:
  %r229 = load i32, i32* %r226
  %r230 = icmp slt i32 %r229, 0
  br i1 %r230, label %if_5_76_true, label %bb31_76_next

bb31_76_next:
  %r231 = load i32, i32* %r224
  %r232 = load i32, i32* %r220
  %r233 = icmp sge i32 %r231, %r232
  br i1 %r233, label %if_5_76_true, label %bb42_76_next

bb42_76_next:
  %r234 = load i32, i32* %r226
  %r235 = load i32, i32* %r222
  %r236 = icmp sge i32 %r234, %r235
  br i1 %r236, label %if_5_76_true, label %if_5_76_false

if_5_76_true:
  ret i32 0
  br label %if_5_76_end

if_5_76_false:
  br label %if_5_76_end

if_5_76_end:
  %r238 = load i32, i32* %r224
  %r239 = load i32, i32* %r222
  %r240 = mul i32 %r238, %r239
  %r241 = load i32, i32* %r226
  %r242 = add i32 %r240, %r241
  store i32 %r242, i32* %r237
  %r243 = load i32, i32* %r237
  %r245 = getelementptr i32, i32* %r218, i32 %r243
  %r244 = load i32, i32* %r245
  ret i32 %r244
}

define i32 @convn( i32 %r246, i32* %r248, i32* %r249, i32 %r250, i32 %r252, i32 %r254 ) {
convn:
  %r306 = alloca i32
  %r247 = alloca i32
  store i32 %r246, i32* %r247
  %r251 = alloca i32
  store i32 %r250, i32* %r251
  %r253 = alloca i32
  store i32 %r252, i32* %r253
  %r255 = alloca i32
  store i32 %r254, i32* %r255
  %r256 = alloca i32
  store i32 0, i32* %r256
  %r257 = alloca i32
  store i32 0, i32* %r257
  %r258 = alloca i32
  %r259 = alloca i32
  %r260 = alloca i32
  %r261 = alloca i32
  store i32 1, i32* %r261
  br label %while_5_88_cond

while_5_88_cond:
  %r262 = load i32, i32* %r261
  %r263 = load i32, i32* %r261
  %r264 = icmp eq i32 %r262, %r263
  br i1 %r264, label %while_5_88_whilestms, label %while_5_88_bre

while_5_88_whilestms:
  store i32 0, i32* %r257
  br label %while_9_90_cond

while_9_90_cond:
  %r265 = load i32, i32* %r261
  %r266 = load i32, i32* %r261
  %r267 = icmp eq i32 %r265, %r266
  br i1 %r267, label %while_9_90_whilestms, label %while_9_90_bre

while_9_90_whilestms:
  store i32 0, i32* %r260
  %r268 = load i32, i32* %r256
  %r269 = load i32, i32* %r255
  %r270 = sdiv i32 %r269, 2
  %r271 = sub i32 %r268, %r270
  store i32 %r271, i32* %r258
  br label %while_13_93_cond

while_13_93_cond:
  %r272 = load i32, i32* %r261
  %r273 = load i32, i32* %r261
  %r274 = icmp eq i32 %r272, %r273
  br i1 %r274, label %while_13_93_whilestms, label %while_13_93_bre

while_13_93_whilestms:
  %r275 = load i32, i32* %r257
  %r276 = load i32, i32* %r255
  %r277 = sdiv i32 %r276, 2
  %r278 = sub i32 %r275, %r277
  store i32 %r278, i32* %r259
  br label %while_17_95_cond

while_17_95_cond:
  %r279 = load i32, i32* %r261
  %r280 = load i32, i32* %r261
  %r281 = icmp eq i32 %r279, %r280
  br i1 %r281, label %while_17_95_whilestms, label %while_17_95_bre

while_17_95_whilestms:
  %r282 = load i32, i32* %r247
  %r283 = load i32, i32* %r260
  %r284 = load i32, i32* %r251
  %r285 = load i32, i32* %r253
  %r286 = load i32, i32* %r258
  %r287 = load i32, i32* %r259
  %r288 = call i32 @getvalue(i32* %r248, i32 %r284, i32 %r285, i32 %r286, i32 %r287)
  %r289 = call i32 @reduce(i32 %r282, i32 %r283, i32 %r288)
  store i32 %r289, i32* %r260
  %r290 = load i32, i32* %r259
  %r291 = add i32 %r290, 1
  store i32 %r291, i32* %r259
  %r292 = load i32, i32* %r259
  %r293 = load i32, i32* %r257
  %r294 = load i32, i32* %r255
  %r295 = sdiv i32 %r294, 2
  %r296 = add i32 %r293, %r295
  %r297 = icmp sge i32 %r292, %r296
  br i1 %r297, label %if_21_98_true, label %if_21_98_false

if_21_98_true:
  br label %while_17_95_bre

  br label %if_21_98_end

if_21_98_false:
  br label %if_21_98_end

if_21_98_end:
  br label %while_17_95_cond

while_17_95_bre:
  %r298 = load i32, i32* %r258
  %r299 = add i32 %r298, 1
  store i32 %r299, i32* %r258
  %r300 = load i32, i32* %r258
  %r301 = load i32, i32* %r256
  %r302 = load i32, i32* %r255
  %r303 = sdiv i32 %r302, 2
  %r304 = add i32 %r301, %r303
  %r305 = icmp sge i32 %r300, %r304
  br i1 %r305, label %if_17_101_true, label %if_17_101_false

if_17_101_true:
  br label %while_13_93_bre

  br label %if_17_101_end

if_17_101_false:
  br label %if_17_101_end

if_17_101_end:
  br label %while_13_93_cond

while_13_93_bre:
  %r307 = load i32, i32* %r256
  %r308 = load i32, i32* %r253
  %r309 = mul i32 %r307, %r308
  %r310 = load i32, i32* %r257
  %r311 = add i32 %r309, %r310
  store i32 %r311, i32* %r306
  %r312 = load i32, i32* %r306
  %r313 = getelementptr i32, i32* %r249, i32 %r312
  %r314 = load i32, i32* %r260
  store i32 %r314, i32* %r313
  %r315 = load i32, i32* %r257
  %r316 = add i32 %r315, 1
  store i32 %r316, i32* %r257
  %r317 = load i32, i32* %r257
  %r318 = load i32, i32* %r253
  %r319 = icmp sge i32 %r317, %r318
  br i1 %r319, label %if_13_106_true, label %if_13_106_false

if_13_106_true:
  br label %while_9_90_bre

  br label %if_13_106_end

if_13_106_false:
  br label %if_13_106_end

if_13_106_end:
  br label %while_9_90_cond

while_9_90_bre:
  %r320 = load i32, i32* %r256
  %r321 = add i32 %r320, 1
  store i32 %r321, i32* %r256
  %r322 = load i32, i32* %r256
  %r323 = load i32, i32* %r251
  %r324 = icmp sge i32 %r322, %r323
  br i1 %r324, label %if_9_109_true, label %if_9_109_false

if_9_109_true:
  br label %while_5_88_bre

  br label %if_9_109_end

if_9_109_false:
  br label %if_9_109_end

if_9_109_end:
  br label %while_5_88_cond

while_5_88_bre:
  ret i32 0
}

define void @memmove( i32* %r325, i32* %r326, i32 %r327 ) {
memmove:
  %r328 = alloca i32
  store i32 %r327, i32* %r328
  %r329 = alloca i32
  store i32 0, i32* %r329
  br label %while_5_120_cond

while_5_120_cond:
  %r330 = load i32, i32* %r329
  %r331 = load i32, i32* %r328
  %r332 = icmp slt i32 %r330, %r331
  br i1 %r332, label %while_5_120_whilestms, label %while_5_120_bre

while_5_120_whilestms:
  %r333 = load i32, i32* %r329
  %r334 = getelementptr i32, i32* %r325, i32 %r333
  %r335 = load i32, i32* %r329
  %r337 = getelementptr i32, i32* %r326, i32 %r335
  %r336 = load i32, i32* %r337
  store i32 %r336, i32* %r334
  %r338 = load i32, i32* %r329
  %r339 = add i32 %r338, 1
  store i32 %r339, i32* %r329
  br label %while_5_120_cond

while_5_120_bre:
  ret void
}

define i32 @main( ) {
main:
  %r369 = alloca i32
  %r366 = alloca i32
  %r340 = alloca i32
  %r341 = call i32 @getint()
  store i32 %r341, i32* %r340
  %r342 = alloca i32
  %r343 = call i32 @getint()
  store i32 %r343, i32* %r342
  %r344 = alloca i32
  %r345 = call i32 @getint()
  store i32 %r345, i32* %r344
  %r346 = alloca i32
  %r347 = call i32 @getint()
  store i32 %r347, i32* %r346
  %r348 = alloca i32
  store i32 0, i32* %r348
  br label %while_5_133_cond

while_5_133_cond:
  %r349 = load i32, i32* %r348
  %r350 = load i32, i32* %r346
  %r351 = icmp slt i32 %r349, %r350
  br i1 %r351, label %while_5_133_whilestms, label %while_5_133_bre

while_5_133_whilestms:
  %r352 = load i32, i32* %r348
  %r353 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @a, i32 0, i32 %r352
  %r354 = call i32 @getint()
  store i32 %r354, i32* %r353
  %r355 = load i32, i32* %r348
  %r356 = add i32 %r355, 1
  store i32 %r356, i32* %r348
  br label %while_5_133_cond

while_5_133_bre:
  %r357 = call i32 @getint()
  store i32 %r357, i32* %r346
  store i32 0, i32* %r348
  br label %while_5_139_cond

while_5_139_cond:
  %r358 = load i32, i32* %r348
  %r359 = load i32, i32* %r346
  %r360 = icmp slt i32 %r358, %r359
  br i1 %r360, label %while_5_139_whilestms, label %while_5_139_bre

while_5_139_whilestms:
  %r361 = load i32, i32* %r348
  %r362 = getelementptr [10000 x i32 ], [10000 x i32 ]* @kernelid_, i32 0, i32 %r361
  %r363 = call i32 @getint()
  store i32 %r363, i32* %r362
  %r364 = load i32, i32* %r348
  %r365 = add i32 %r364, 1
  store i32 %r365, i32* %r348
  br label %while_5_139_cond

while_5_139_bre:
  %r367 = load i32, i32* %r346
  store i32 %r367, i32* %r366
  call void @_sysy_starttime(i32 209)
  store i32 0, i32* %r369
  br label %while_5_147_cond

while_5_147_cond:
  %r370 = load i32, i32* %r369
  %r371 = load i32, i32* %r366
  %r372 = icmp slt i32 %r370, %r371
  br i1 %r372, label %while_5_147_whilestms, label %while_5_147_bre

while_5_147_whilestms:
  %r373 = load i32, i32* %r369
  %r375 = getelementptr [10000 x i32 ], [10000 x i32 ]* @kernelid_, i32 0, i32 %r373
  %r374 = load i32, i32* %r375
  %r376 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @a, i32 0, i32 0
  %r377 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @b, i32 0, i32 0
  %r378 = load i32, i32* %r342
  %r379 = load i32, i32* %r344
  %r380 = load i32, i32* %r340
  %r381 = call i32 @convn(i32 %r374, i32* %r376, i32* %r377, i32 %r378, i32 %r379, i32 %r380)
  %r382 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @a, i32 0, i32 0
  %r383 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @b, i32 0, i32 0
  %r384 = load i32, i32* %r342
  %r385 = load i32, i32* %r344
  %r386 = mul i32 %r384, %r385
  call void @memmove(i32* %r382, i32* %r383, i32 %r386)
  %r388 = load i32, i32* %r369
  %r389 = add i32 %r388, 1
  store i32 %r389, i32* %r369
  br label %while_5_147_cond

while_5_147_bre:
  call void @_sysy_stoptime(i32 312)
  %r391 = load i32, i32* %r342
  %r392 = load i32, i32* %r344
  %r393 = mul i32 %r391, %r392
  %r394 = getelementptr [10000000 x i32 ], [10000000 x i32 ]* @a, i32 0, i32 0
  call void @putarray(i32 %r393, i32* %r394)
  ret i32 0
}

