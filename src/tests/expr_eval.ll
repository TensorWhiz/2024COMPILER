declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
define i32 @next_char( ) {
next_char:
  %r100 = call i32 @getch()
  store i32 %r100, i32* @last_char
  %r101 = load i32, i32* @last_char
  ret i32 %r101
}

define i32 @is_space( i32 %r102 ) {
is_space:
  %r103 = alloca i32
  store i32 %r102, i32* %r103
  %r104 = load i32, i32* %r103
  %r105 = icmp eq i32 %r104, 32
  br i1 %r105, label %if_5_24_true, label %bb22_24_next

bb22_24_next:
  %r106 = load i32, i32* %r103
  %r107 = icmp eq i32 %r106, 10
  br i1 %r107, label %if_5_24_true, label %if_5_24_false

if_5_24_true:
  ret i32 1
  br label %if_5_24_end

if_5_24_false:
  ret i32 0
  br label %if_5_24_end

if_5_24_end:
  ret i32 0
}

define i32 @is_num( i32 %r108 ) {
is_num:
  %r109 = alloca i32
  store i32 %r108, i32* %r109
  %r110 = load i32, i32* %r109
  %r111 = icmp sge i32 %r110, 48
  br i1 %r111, label %bb22_36_next, label %if_5_36_false

bb22_36_next:
  %r112 = load i32, i32* %r109
  %r113 = icmp sle i32 %r112, 57
  br i1 %r113, label %if_5_36_true, label %if_5_36_false

if_5_36_true:
  ret i32 1
  br label %if_5_36_end

if_5_36_false:
  ret i32 0
  br label %if_5_36_end

if_5_36_end:
  ret i32 0
}

define i32 @next_token( ) {
next_token:
  br label %while_5_48_cond

while_5_48_cond:
  %r114 = load i32, i32* @last_char
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %while_5_48_whilestms, label %while_5_48_bre

while_5_48_whilestms:
  %r117 = call i32 @next_char()
  br label %while_5_48_cond

while_5_48_bre:
  %r118 = load i32, i32* @last_char
  %r119 = call i32 @is_num(i32 %r118)
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %if_5_52_true, label %if_5_52_false

if_5_52_true:
  %r121 = load i32, i32* @last_char
  %r122 = sub i32 %r121, 48
  store i32 %r122, i32* @num
  br label %while_9_55_cond

while_9_55_cond:
  %r123 = call i32 @next_char()
  %r124 = call i32 @is_num(i32 %r123)
  %r125 = icmp ne i32 %r124, 0
  br i1 %r125, label %while_9_55_whilestms, label %while_9_55_bre

while_9_55_whilestms:
  %r126 = load i32, i32* @num
  %r127 = mul i32 %r126, 10
  %r128 = load i32, i32* @last_char
  %r129 = add i32 %r127, %r128
  %r130 = sub i32 %r129, 48
  store i32 %r130, i32* @num
  br label %while_9_55_cond

while_9_55_bre:
  %r131 = load i32, i32* @TOKEN_NUM
  store i32 %r131, i32* @cur_token
  br label %if_5_52_end

if_5_52_false:
  %r132 = load i32, i32* @last_char
  store i32 %r132, i32* @other
  %r133 = call i32 @next_char()
  %r134 = load i32, i32* @TOKEN_OTHER
  store i32 %r134, i32* @cur_token
  br label %if_5_52_end

if_5_52_end:
  %r135 = load i32, i32* @cur_token
  ret i32 %r135
}

define i32 @panic( ) {
panic:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  %r143 = sub i32 0, 1
  ret i32 %r143
}

define i32 @get_op_prec( i32 %r144 ) {
get_op_prec:
  %r145 = alloca i32
  store i32 %r144, i32* %r145
  %r146 = load i32, i32* %r145
  %r147 = icmp eq i32 %r146, 43
  br i1 %r147, label %if_5_85_true, label %bb23_85_next

bb23_85_next:
  %r148 = load i32, i32* %r145
  %r149 = icmp eq i32 %r148, 45
  br i1 %r149, label %if_5_85_true, label %if_5_85_false

if_5_85_true:
  ret i32 10
  br label %if_5_85_end

if_5_85_false:
  br label %if_5_85_end

if_5_85_end:
  %r150 = load i32, i32* %r145
  %r151 = icmp eq i32 %r150, 42
  br i1 %r151, label %if_5_88_true, label %bb23_88_next

bb23_88_next:
  %r152 = load i32, i32* %r145
  %r153 = icmp eq i32 %r152, 47
  br i1 %r153, label %if_5_88_true, label %bb37_88_next

bb37_88_next:
  %r154 = load i32, i32* %r145
  %r155 = icmp eq i32 %r154, 37
  br i1 %r155, label %if_5_88_true, label %if_5_88_false

if_5_88_true:
  ret i32 20
  br label %if_5_88_end

if_5_88_false:
  br label %if_5_88_end

if_5_88_end:
  ret i32 0
}

define void @stack_push( i32* %r156, i32 %r157 ) {
stack_push:
  %r158 = alloca i32
  store i32 %r157, i32* %r158
  %r159 = getelementptr i32, i32* %r156, i32 0
  %r161 = getelementptr i32, i32* %r156, i32 0
  %r160 = load i32, i32* %r161
  %r162 = add i32 %r160, 1
  store i32 %r162, i32* %r159
  %r163 = alloca i32
  %r165 = getelementptr i32, i32* %r156, i32 0
  %r164 = load i32, i32* %r165
  store i32 %r164, i32* %r163
  %r166 = load i32, i32* %r163
  %r167 = getelementptr i32, i32* %r156, i32 %r166
  %r168 = load i32, i32* %r158
  store i32 %r168, i32* %r167
  ret void
}

define i32 @stack_pop( i32* %r169 ) {
stack_pop:
  %r170 = alloca i32
  %r172 = getelementptr i32, i32* %r169, i32 0
  %r171 = load i32, i32* %r172
  store i32 %r171, i32* %r170
  %r173 = alloca i32
  %r174 = load i32, i32* %r170
  %r176 = getelementptr i32, i32* %r169, i32 %r174
  %r175 = load i32, i32* %r176
  store i32 %r175, i32* %r173
  %r177 = getelementptr i32, i32* %r169, i32 0
  %r179 = getelementptr i32, i32* %r169, i32 0
  %r178 = load i32, i32* %r179
  %r180 = sub i32 %r178, 1
  store i32 %r180, i32* %r177
  %r181 = load i32, i32* %r173
  ret i32 %r181
}

define i32 @stack_peek( i32* %r182 ) {
stack_peek:
  %r183 = alloca i32
  %r185 = getelementptr i32, i32* %r182, i32 0
  %r184 = load i32, i32* %r185
  store i32 %r184, i32* %r183
  %r186 = load i32, i32* %r183
  %r188 = getelementptr i32, i32* %r182, i32 %r186
  %r187 = load i32, i32* %r188
  ret i32 %r187
}

define i32 @stack_size( i32* %r189 ) {
stack_size:
  %r191 = getelementptr i32, i32* %r189, i32 0
  %r190 = load i32, i32* %r191
  ret i32 %r190
}

define i32 @mod( i32 %r192, i32 %r194 ) {
mod:
  %r193 = alloca i32
  store i32 %r192, i32* %r193
  %r195 = alloca i32
  store i32 %r194, i32* %r195
  %r196 = load i32, i32* %r193
  %r197 = load i32, i32* %r193
  %r198 = load i32, i32* %r195
  %r199 = sdiv i32 %r197, %r198
  %r200 = load i32, i32* %r195
  %r201 = mul i32 %r199, %r200
  %r202 = sub i32 %r196, %r201
  ret i32 %r202
}

define i32 @eval_op( i32 %r203, i32 %r205, i32 %r207 ) {
eval_op:
  %r204 = alloca i32
  store i32 %r203, i32* %r204
  %r206 = alloca i32
  store i32 %r205, i32* %r206
  %r208 = alloca i32
  store i32 %r207, i32* %r208
  %r209 = load i32, i32* %r204
  %r210 = icmp eq i32 %r209, 43
  br i1 %r210, label %if_5_128_true, label %if_5_128_false

if_5_128_true:
  %r211 = load i32, i32* %r206
  %r212 = load i32, i32* %r208
  %r213 = add i32 %r211, %r212
  ret i32 %r213
  br label %if_5_128_end

if_5_128_false:
  br label %if_5_128_end

if_5_128_end:
  %r214 = load i32, i32* %r204
  %r215 = icmp eq i32 %r214, 45
  br i1 %r215, label %if_5_133_true, label %if_5_133_false

if_5_133_true:
  %r216 = load i32, i32* %r206
  %r217 = load i32, i32* %r208
  %r218 = sub i32 %r216, %r217
  ret i32 %r218
  br label %if_5_133_end

if_5_133_false:
  br label %if_5_133_end

if_5_133_end:
  %r219 = load i32, i32* %r204
  %r220 = icmp eq i32 %r219, 42
  br i1 %r220, label %if_5_138_true, label %if_5_138_false

if_5_138_true:
  %r221 = load i32, i32* %r206
  %r222 = load i32, i32* %r208
  %r223 = mul i32 %r221, %r222
  ret i32 %r223
  br label %if_5_138_end

if_5_138_false:
  br label %if_5_138_end

if_5_138_end:
  %r224 = load i32, i32* %r204
  %r225 = icmp eq i32 %r224, 47
  br i1 %r225, label %if_5_143_true, label %if_5_143_false

if_5_143_true:
  %r226 = load i32, i32* %r206
  %r227 = load i32, i32* %r208
  %r228 = sdiv i32 %r226, %r227
  ret i32 %r228
  br label %if_5_143_end

if_5_143_false:
  br label %if_5_143_end

if_5_143_end:
  %r229 = load i32, i32* %r204
  %r230 = icmp eq i32 %r229, 37
  br i1 %r230, label %if_5_148_true, label %if_5_148_false

if_5_148_true:
  %r231 = load i32, i32* %r206
  %r232 = load i32, i32* %r208
  %r233 = call i32 @mod(i32 %r231, i32 %r232)
  ret i32 %r233
  br label %if_5_148_end

if_5_148_false:
  br label %if_5_148_end

if_5_148_end:
  ret i32 0
}

define i32 @eval( ) {
eval:
  %r307 = alloca i32
  %r304 = alloca i32
  %r301 = alloca i32
  %r277 = alloca i32
  %r274 = alloca i32
  %r271 = alloca i32
  %r256 = alloca i32
  %r234 = alloca [ 256 x i32 ]
  %r235 = alloca [ 256 x i32 ]
  %r236 = alloca i32
  store i32 0, i32* %r236
  br label %while_5_161_cond

while_5_161_cond:
  %r237 = load i32, i32* %r236
  %r238 = icmp slt i32 %r237, 256
  br i1 %r238, label %while_5_161_whilestms, label %while_5_161_bre

while_5_161_whilestms:
  %r239 = load i32, i32* %r236
  %r240 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 %r239
  store i32 0, i32* %r240
  %r241 = load i32, i32* %r236
  %r242 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 %r241
  store i32 0, i32* %r242
  %r243 = load i32, i32* %r236
  %r244 = add i32 %r243, 1
  store i32 %r244, i32* %r236
  br label %while_5_161_cond

while_5_161_bre:
  %r245 = load i32, i32* @cur_token
  %r246 = load i32, i32* @TOKEN_NUM
  %r247 = icmp ne i32 %r245, %r246
  br i1 %r247, label %if_5_168_true, label %if_5_168_false

if_5_168_true:
  %r248 = call i32 @panic()
  ret i32 %r248
  br label %if_5_168_end

if_5_168_false:
  br label %if_5_168_end

if_5_168_end:
  %r249 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r250 = load i32, i32* @num
  call void @stack_push(i32* %r249, i32 %r250)
  %r252 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_cond:
  %r253 = load i32, i32* @cur_token
  %r254 = load i32, i32* @TOKEN_OTHER
  %r255 = icmp eq i32 %r253, %r254
  br i1 %r255, label %while_5_175_whilestms, label %while_5_175_bre

while_5_175_whilestms:
  %r257 = load i32, i32* @other
  store i32 %r257, i32* %r256
  %r258 = load i32, i32* %r256
  %r259 = call i32 @get_op_prec(i32 %r258)
  %r260 = icmp eq i32 %r259, 0
  br i1 %r260, label %if_9_179_true, label %if_9_179_false

if_9_179_true:
  br label %while_5_175_bre

  br label %if_9_179_end

if_9_179_false:
  br label %if_9_179_end

if_9_179_end:
  %r261 = call i32 @next_token()
  br label %while_9_183_cond

while_9_183_cond:
  %r262 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r263 = call i32 @stack_size(i32* %r262)
  %r264 = icmp ne i32 %r263, 0
  br i1 %r264, label %bb40_183_next, label %while_9_183_bre

bb40_183_next:
  %r265 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r266 = call i32 @stack_peek(i32* %r265)
  %r267 = call i32 @get_op_prec(i32 %r266)
  %r268 = load i32, i32* %r256
  %r269 = call i32 @get_op_prec(i32 %r268)
  %r270 = icmp sge i32 %r267, %r269
  br i1 %r270, label %while_9_183_whilestms, label %while_9_183_bre

while_9_183_whilestms:
  %r272 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r273 = call i32 @stack_pop(i32* %r272)
  store i32 %r273, i32* %r271
  %r275 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r276 = call i32 @stack_pop(i32* %r275)
  store i32 %r276, i32* %r274
  %r278 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r279 = call i32 @stack_pop(i32* %r278)
  store i32 %r279, i32* %r277
  %r280 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r281 = load i32, i32* %r271
  %r282 = load i32, i32* %r277
  %r283 = load i32, i32* %r274
  %r284 = call i32 @eval_op(i32 %r281, i32 %r282, i32 %r283)
  call void @stack_push(i32* %r280, i32 %r284)
  br label %while_9_183_cond

while_9_183_bre:
  %r286 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r287 = load i32, i32* %r256
  call void @stack_push(i32* %r286, i32 %r287)
  %r289 = load i32, i32* @cur_token
  %r290 = load i32, i32* @TOKEN_NUM
  %r291 = icmp ne i32 %r289, %r290
  br i1 %r291, label %if_9_193_true, label %if_9_193_false

if_9_193_true:
  %r292 = call i32 @panic()
  ret i32 %r292
  br label %if_9_193_end

if_9_193_false:
  br label %if_9_193_end

if_9_193_end:
  %r293 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r294 = load i32, i32* @num
  call void @stack_push(i32* %r293, i32 %r294)
  %r296 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_bre:
  %r297 = call i32 @next_token()
  br label %while_5_201_cond

while_5_201_cond:
  %r298 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r299 = call i32 @stack_size(i32* %r298)
  %r300 = icmp ne i32 %r299, 0
  br i1 %r300, label %while_5_201_whilestms, label %while_5_201_bre

while_5_201_whilestms:
  %r302 = getelementptr [256 x i32 ], [256 x i32 ]* %r235, i32 0, i32 0
  %r303 = call i32 @stack_pop(i32* %r302)
  store i32 %r303, i32* %r301
  %r305 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r306 = call i32 @stack_pop(i32* %r305)
  store i32 %r306, i32* %r304
  %r308 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r309 = call i32 @stack_pop(i32* %r308)
  store i32 %r309, i32* %r307
  %r310 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r311 = load i32, i32* %r271
  %r312 = load i32, i32* %r277
  %r313 = load i32, i32* %r274
  %r314 = call i32 @eval_op(i32 %r311, i32 %r312, i32 %r313)
  call void @stack_push(i32* %r310, i32 %r314)
  br label %while_5_201_cond

while_5_201_bre:
  %r316 = getelementptr [256 x i32 ], [256 x i32 ]* %r234, i32 0, i32 0
  %r317 = call i32 @stack_peek(i32* %r316)
  ret i32 %r317
}

define i32 @main( ) {
main:
  %r318 = alloca i32
  %r319 = call i32 @getint()
  store i32 %r319, i32* %r318
  %r320 = call i32 @getch()
  %r321 = call i32 @next_token()
  br label %while_5_216_cond

while_5_216_cond:
  %r322 = load i32, i32* %r318
  %r323 = icmp ne i32 %r322, 0
  br i1 %r323, label %while_5_216_whilestms, label %while_5_216_bre

while_5_216_whilestms:
  %r324 = call i32 @eval()
  call void @putint(i32 %r324)
  call void @putch(i32 10)
  %r327 = load i32, i32* %r318
  %r328 = sub i32 %r327, 1
  store i32 %r328, i32* %r318
  br label %while_5_216_cond

while_5_216_bre:
  ret i32 0
}

