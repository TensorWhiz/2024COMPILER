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
bb1:
  br label %if_5_24_end

if_5_24_false:
  ret i32 0
bb2:
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
bb3:
  br label %if_5_36_end

if_5_36_false:
  ret i32 0
bb4:
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
  %r136 = sub i32 0, 1
  ret i32 %r136
}

define i32 @get_op_prec( i32 %r137 ) {
get_op_prec:
  %r138 = alloca i32
  store i32 %r137, i32* %r138
  %r139 = load i32, i32* %r138
  %r140 = icmp eq i32 %r139, 43
  br i1 %r140, label %if_5_85_true, label %bb23_85_next

bb23_85_next:
  %r141 = load i32, i32* %r138
  %r142 = icmp eq i32 %r141, 45
  br i1 %r142, label %if_5_85_true, label %if_5_85_false

if_5_85_true:
  ret i32 10
bb5:
  br label %if_5_85_end

if_5_85_false:
  br label %if_5_85_end

if_5_85_end:
  %r143 = load i32, i32* %r138
  %r144 = icmp eq i32 %r143, 42
  br i1 %r144, label %if_5_88_true, label %bb23_88_next

bb23_88_next:
  %r145 = load i32, i32* %r138
  %r146 = icmp eq i32 %r145, 47
  br i1 %r146, label %if_5_88_true, label %bb37_88_next

bb37_88_next:
  %r147 = load i32, i32* %r138
  %r148 = icmp eq i32 %r147, 37
  br i1 %r148, label %if_5_88_true, label %if_5_88_false

if_5_88_true:
  ret i32 20
bb6:
  br label %if_5_88_end

if_5_88_false:
  br label %if_5_88_end

if_5_88_end:
  ret i32 0
}

define void @stack_push( i32* %r149, i32 %r150 ) {
stack_push:
  %r151 = alloca i32
  store i32 %r150, i32* %r151
  %r152 = getelementptr i32, i32* %r149, i32 0
  %r153 = getelementptr i32, i32* %r149, i32 0
  %r154 = load i32, i32* %r153
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* %r152
  %r156 = alloca i32
  %r157 = getelementptr i32, i32* %r149, i32 0
  %r158 = load i32, i32* %r157
  store i32 %r158, i32* %r156
  %r159 = load i32, i32* %r156
  %r160 = getelementptr i32, i32* %r149, i32 %r159
  %r161 = load i32, i32* %r151
  store i32 %r161, i32* %r160
  ret void
}

define i32 @stack_pop( i32* %r162 ) {
stack_pop:
  %r163 = alloca i32
  %r164 = getelementptr i32, i32* %r162, i32 0
  %r165 = load i32, i32* %r164
  store i32 %r165, i32* %r163
  %r166 = alloca i32
  %r167 = load i32, i32* %r163
  %r168 = getelementptr i32, i32* %r162, i32 %r167
  %r169 = load i32, i32* %r168
  store i32 %r169, i32* %r166
  %r170 = getelementptr i32, i32* %r162, i32 0
  %r171 = getelementptr i32, i32* %r162, i32 0
  %r172 = load i32, i32* %r171
  %r173 = sub i32 %r172, 1
  store i32 %r173, i32* %r170
  %r174 = load i32, i32* %r166
  ret i32 %r174
}

define i32 @stack_peek( i32* %r175 ) {
stack_peek:
  %r176 = alloca i32
  %r177 = getelementptr i32, i32* %r175, i32 0
  %r178 = load i32, i32* %r177
  store i32 %r178, i32* %r176
  %r179 = load i32, i32* %r176
  %r180 = getelementptr i32, i32* %r175, i32 %r179
  %r181 = load i32, i32* %r180
  ret i32 %r181
}

define i32 @stack_size( i32* %r182 ) {
stack_size:
  %r183 = getelementptr i32, i32* %r182, i32 0
  %r184 = load i32, i32* %r183
  ret i32 %r184
}

define i32 @mod( i32 %r185, i32 %r187 ) {
mod:
  %r186 = alloca i32
  store i32 %r185, i32* %r186
  %r188 = alloca i32
  store i32 %r187, i32* %r188
  %r189 = load i32, i32* %r186
  %r190 = load i32, i32* %r186
  %r191 = load i32, i32* %r188
  %r192 = sdiv i32 %r190, %r191
  %r193 = load i32, i32* %r188
  %r194 = mul i32 %r192, %r193
  %r195 = sub i32 %r189, %r194
  ret i32 %r195
}

define i32 @eval_op( i32 %r196, i32 %r198, i32 %r200 ) {
eval_op:
  %r197 = alloca i32
  store i32 %r196, i32* %r197
  %r199 = alloca i32
  store i32 %r198, i32* %r199
  %r201 = alloca i32
  store i32 %r200, i32* %r201
  %r202 = load i32, i32* %r197
  %r203 = icmp eq i32 %r202, 43
  br i1 %r203, label %if_5_128_true, label %if_5_128_false

if_5_128_true:
  %r204 = load i32, i32* %r199
  %r205 = load i32, i32* %r201
  %r206 = add i32 %r204, %r205
  ret i32 %r206
bb7:
  br label %if_5_128_end

if_5_128_false:
  br label %if_5_128_end

if_5_128_end:
  %r207 = load i32, i32* %r197
  %r208 = icmp eq i32 %r207, 45
  br i1 %r208, label %if_5_133_true, label %if_5_133_false

if_5_133_true:
  %r209 = load i32, i32* %r199
  %r210 = load i32, i32* %r201
  %r211 = sub i32 %r209, %r210
  ret i32 %r211
bb8:
  br label %if_5_133_end

if_5_133_false:
  br label %if_5_133_end

if_5_133_end:
  %r212 = load i32, i32* %r197
  %r213 = icmp eq i32 %r212, 42
  br i1 %r213, label %if_5_138_true, label %if_5_138_false

if_5_138_true:
  %r214 = load i32, i32* %r199
  %r215 = load i32, i32* %r201
  %r216 = mul i32 %r214, %r215
  ret i32 %r216
bb9:
  br label %if_5_138_end

if_5_138_false:
  br label %if_5_138_end

if_5_138_end:
  %r217 = load i32, i32* %r197
  %r218 = icmp eq i32 %r217, 47
  br i1 %r218, label %if_5_143_true, label %if_5_143_false

if_5_143_true:
  %r219 = load i32, i32* %r199
  %r220 = load i32, i32* %r201
  %r221 = sdiv i32 %r219, %r220
  ret i32 %r221
bb10:
  br label %if_5_143_end

if_5_143_false:
  br label %if_5_143_end

if_5_143_end:
  %r222 = load i32, i32* %r197
  %r223 = icmp eq i32 %r222, 37
  br i1 %r223, label %if_5_148_true, label %if_5_148_false

if_5_148_true:
  %r224 = load i32, i32* %r199
  %r225 = load i32, i32* %r201
  %r226 = call i32 @mod(i32 %r224, i32 %r225)
  ret i32 %r226
bb11:
  br label %if_5_148_end

if_5_148_false:
  br label %if_5_148_end

if_5_148_end:
  ret i32 0
}

define i32 @eval( ) {
eval:
  %r296 = alloca i32
  %r293 = alloca i32
  %r290 = alloca i32
  %r269 = alloca i32
  %r266 = alloca i32
  %r263 = alloca i32
  %r248 = alloca i32
  %r227 = alloca [ 256 x i32 ]
  %r228 = alloca [ 256 x i32 ]
  %r229 = alloca i32
  store i32 0, i32* %r229
  br label %while_5_161_cond

while_5_161_cond:
  %r230 = load i32, i32* %r229
  %r231 = icmp slt i32 %r230, 256
  br i1 %r231, label %while_5_161_whilestms, label %while_5_161_bre

while_5_161_whilestms:
  %r232 = load i32, i32* %r229
  %r233 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 %r232
  store i32 0, i32* %r233
  %r234 = load i32, i32* %r229
  %r235 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 %r234
  store i32 0, i32* %r235
  %r236 = load i32, i32* %r229
  %r237 = add i32 %r236, 1
  store i32 %r237, i32* %r229
  br label %while_5_161_cond

while_5_161_bre:
  %r238 = load i32, i32* @cur_token
  %r239 = load i32, i32* @TOKEN_NUM
  %r240 = icmp ne i32 %r238, %r239
  br i1 %r240, label %if_5_168_true, label %if_5_168_false

if_5_168_true:
  %r241 = call i32 @panic()
  ret i32 %r241
bb12:
  br label %if_5_168_end

if_5_168_false:
  br label %if_5_168_end

if_5_168_end:
  %r242 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r243 = load i32, i32* @num
  call void @stack_push(i32* %r242, i32 %r243)
  %r244 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_cond:
  %r245 = load i32, i32* @cur_token
  %r246 = load i32, i32* @TOKEN_OTHER
  %r247 = icmp eq i32 %r245, %r246
  br i1 %r247, label %while_5_175_whilestms, label %while_5_175_bre

while_5_175_whilestms:
  %r249 = load i32, i32* @other
  store i32 %r249, i32* %r248
  %r250 = load i32, i32* %r248
  %r251 = call i32 @get_op_prec(i32 %r250)
  %r252 = icmp eq i32 %r251, 0
  br i1 %r252, label %if_9_179_true, label %if_9_179_false

if_9_179_true:
  br label %while_5_175_bre

bb13:
  br label %if_9_179_end

if_9_179_false:
  br label %if_9_179_end

if_9_179_end:
  %r253 = call i32 @next_token()
  br label %while_9_183_cond

while_9_183_cond:
  %r254 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r255 = call i32 @stack_size(i32* %r254)
  %r256 = icmp ne i32 %r255, 0
  br i1 %r256, label %bb40_183_next, label %while_9_183_bre

bb40_183_next:
  %r257 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r258 = call i32 @stack_peek(i32* %r257)
  %r259 = call i32 @get_op_prec(i32 %r258)
  %r260 = load i32, i32* %r248
  %r261 = call i32 @get_op_prec(i32 %r260)
  %r262 = icmp sge i32 %r259, %r261
  br i1 %r262, label %while_9_183_whilestms, label %while_9_183_bre

while_9_183_whilestms:
  %r264 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r265 = call i32 @stack_pop(i32* %r264)
  store i32 %r265, i32* %r263
  %r267 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r268 = call i32 @stack_pop(i32* %r267)
  store i32 %r268, i32* %r266
  %r270 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r271 = call i32 @stack_pop(i32* %r270)
  store i32 %r271, i32* %r269
  %r272 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r273 = load i32, i32* %r263
  %r274 = load i32, i32* %r269
  %r275 = load i32, i32* %r266
  %r276 = call i32 @eval_op(i32 %r273, i32 %r274, i32 %r275)
  call void @stack_push(i32* %r272, i32 %r276)
  br label %while_9_183_cond

while_9_183_bre:
  %r277 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r278 = load i32, i32* %r248
  call void @stack_push(i32* %r277, i32 %r278)
  %r279 = load i32, i32* @cur_token
  %r280 = load i32, i32* @TOKEN_NUM
  %r281 = icmp ne i32 %r279, %r280
  br i1 %r281, label %if_9_193_true, label %if_9_193_false

if_9_193_true:
  %r282 = call i32 @panic()
  ret i32 %r282
bb14:
  br label %if_9_193_end

if_9_193_false:
  br label %if_9_193_end

if_9_193_end:
  %r283 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r284 = load i32, i32* @num
  call void @stack_push(i32* %r283, i32 %r284)
  %r285 = call i32 @next_token()
  br label %while_5_175_cond

while_5_175_bre:
  %r286 = call i32 @next_token()
  br label %while_5_201_cond

while_5_201_cond:
  %r287 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r288 = call i32 @stack_size(i32* %r287)
  %r289 = icmp ne i32 %r288, 0
  br i1 %r289, label %while_5_201_whilestms, label %while_5_201_bre

while_5_201_whilestms:
  %r291 = getelementptr [256 x i32 ], [256 x i32 ]* %r228, i32 0, i32 0
  %r292 = call i32 @stack_pop(i32* %r291)
  store i32 %r292, i32* %r290
  %r294 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r295 = call i32 @stack_pop(i32* %r294)
  store i32 %r295, i32* %r293
  %r297 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r298 = call i32 @stack_pop(i32* %r297)
  store i32 %r298, i32* %r296
  %r299 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r300 = load i32, i32* %r263
  %r301 = load i32, i32* %r269
  %r302 = load i32, i32* %r266
  %r303 = call i32 @eval_op(i32 %r300, i32 %r301, i32 %r302)
  call void @stack_push(i32* %r299, i32 %r303)
  br label %while_5_201_cond

while_5_201_bre:
  %r304 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r305 = call i32 @stack_peek(i32* %r304)
  ret i32 %r305
}

define i32 @main( ) {
main:
  %r306 = alloca i32
  %r307 = call i32 @getint()
  store i32 %r307, i32* %r306
  %r308 = call i32 @getch()
  %r309 = call i32 @next_token()
  br label %while_5_216_cond

while_5_216_cond:
  %r310 = load i32, i32* %r306
  %r311 = icmp ne i32 %r310, 0
  br i1 %r311, label %while_5_216_whilestms, label %while_5_216_bre

while_5_216_whilestms:
  %r312 = call i32 @eval()
  call void @putint(i32 %r312)
  call void @putch(i32 10)
  %r313 = load i32, i32* %r306
  %r314 = sub i32 %r313, 1
  store i32 %r314, i32* %r306
  br label %while_5_216_cond

while_5_216_bre:
  ret i32 0
}

