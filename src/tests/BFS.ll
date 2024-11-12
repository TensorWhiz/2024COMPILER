declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
@m = global i32 0
@to = global [ 5005 x i32 ] zeroinitializer
@next = global [ 5005 x i32 ] zeroinitializer
@head = global [ 1005 x i32 ] zeroinitializer
@cnt = global i32 0
@que = global [ 1005 x i32 ] zeroinitializer
@h = global i32 0
@tail = global i32 0
@inq = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
quickread:
  %r100 = alloca i32
  %r101 = call i32 @getch()
  store i32 %r101, i32* %r100
  %r102 = alloca i32
  store i32 0, i32* %r102
  %r103 = alloca i32
  store i32 0, i32* %r103
  br label %while_5_13_cond

while_5_13_cond:
  %r104 = load i32, i32* %r100
  %r105 = icmp slt i32 %r104, 48
  br i1 %r105, label %while_5_13_whilestms, label %bb25_13_next

bb25_13_next:
  %r106 = load i32, i32* %r100
  %r107 = icmp sgt i32 %r106, 57
  br i1 %r107, label %while_5_13_whilestms, label %while_5_13_bre

while_5_13_whilestms:
  %r108 = load i32, i32* %r100
  %r109 = icmp eq i32 %r108, 45
  br i1 %r109, label %if_9_14_true, label %if_9_14_false

if_9_14_true:
  store i32 1, i32* %r103
  br label %if_9_14_end

if_9_14_false:
  br label %if_9_14_end

if_9_14_end:
  %r110 = call i32 @getch()
  store i32 %r110, i32* %r100
  br label %while_5_13_cond

while_5_13_bre:
  br label %while_5_19_cond

while_5_19_cond:
  %r111 = load i32, i32* %r100
  %r112 = icmp sge i32 %r111, 48
  br i1 %r112, label %bb26_19_next, label %while_5_19_bre

bb26_19_next:
  %r113 = load i32, i32* %r100
  %r114 = icmp sle i32 %r113, 57
  br i1 %r114, label %while_5_19_whilestms, label %while_5_19_bre

while_5_19_whilestms:
  %r115 = load i32, i32* %r102
  %r116 = mul i32 %r115, 10
  %r117 = load i32, i32* %r100
  %r118 = add i32 %r116, %r117
  %r119 = sub i32 %r118, 48
  store i32 %r119, i32* %r102
  %r120 = call i32 @getch()
  store i32 %r120, i32* %r100
  br label %while_5_19_cond

while_5_19_bre:
  %r121 = load i32, i32* %r103
  %r122 = icmp ne i32 %r121, 0
  br i1 %r122, label %if_5_23_true, label %if_5_23_false

if_5_23_true:
  %r123 = load i32, i32* %r102
  %r124 = sub i32 0, %r123
  ret i32 %r124
bb1:
  br label %if_5_23_end

if_5_23_false:
  %r125 = load i32, i32* %r102
  ret i32 %r125
bb2:
  br label %if_5_23_end

if_5_23_end:
  ret i32 0
}

define void @addedge( i32 %r126, i32 %r128 ) {
addedge:
  %r127 = alloca i32
  store i32 %r126, i32* %r127
  %r129 = alloca i32
  store i32 %r128, i32* %r129
  %r130 = load i32, i32* @cnt
  %r131 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r130
  %r132 = load i32, i32* %r129
  store i32 %r132, i32* %r131
  %r133 = load i32, i32* @cnt
  %r134 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r133
  %r135 = load i32, i32* %r127
  %r136 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r135
  %r137 = load i32, i32* %r136
  store i32 %r137, i32* %r134
  %r138 = load i32, i32* %r127
  %r139 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r138
  %r140 = load i32, i32* @cnt
  store i32 %r140, i32* %r139
  %r141 = load i32, i32* @cnt
  %r142 = add i32 %r141, 1
  store i32 %r142, i32* @cnt
  %r143 = load i32, i32* @cnt
  %r144 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r143
  %r145 = load i32, i32* %r127
  store i32 %r145, i32* %r144
  %r146 = load i32, i32* @cnt
  %r147 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r146
  %r148 = load i32, i32* %r129
  %r149 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r148
  %r150 = load i32, i32* %r149
  store i32 %r150, i32* %r147
  %r151 = load i32, i32* %r129
  %r152 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r151
  %r153 = load i32, i32* @cnt
  store i32 %r153, i32* %r152
  %r154 = load i32, i32* @cnt
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* @cnt
  ret void
}

define void @init( ) {
init:
  %r156 = alloca i32
  store i32 0, i32* %r156
  br label %while_5_54_cond

while_5_54_cond:
  %r157 = load i32, i32* %r156
  %r158 = icmp slt i32 %r157, 1005
  br i1 %r158, label %while_5_54_whilestms, label %while_5_54_bre

while_5_54_whilestms:
  %r159 = load i32, i32* %r156
  %r160 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r159
  %r161 = sub i32 0, 1
  store i32 %r161, i32* %r160
  %r162 = load i32, i32* %r156
  %r163 = add i32 %r162, 1
  store i32 %r163, i32* %r156
  br label %while_5_54_cond

while_5_54_bre:
  ret void
}

define void @inqueue( i32 %r164 ) {
inqueue:
  %r165 = alloca i32
  store i32 %r164, i32* %r165
  %r166 = load i32, i32* %r165
  %r167 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r166
  store i32 1, i32* %r167
  %r168 = load i32, i32* @tail
  %r169 = add i32 %r168, 1
  store i32 %r169, i32* @tail
  %r170 = load i32, i32* @tail
  %r171 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r170
  %r172 = load i32, i32* %r165
  store i32 %r172, i32* %r171
  ret void
}

define i32 @popqueue( ) {
popqueue:
  %r173 = load i32, i32* @h
  %r174 = add i32 %r173, 1
  store i32 %r174, i32* @h
  %r175 = alloca i32
  %r176 = load i32, i32* @h
  %r177 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r176
  %r178 = load i32, i32* %r177
  store i32 %r178, i32* %r175
  %r179 = load i32, i32* @h
  %r180 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r179
  %r181 = load i32, i32* %r180
  ret i32 %r181
}

define i32 @same( i32 %r182, i32 %r184 ) {
same:
  %r183 = alloca i32
  store i32 %r182, i32* %r183
  %r185 = alloca i32
  store i32 %r184, i32* %r185
  store i32 0, i32* @h
  store i32 0, i32* @tail
  %r186 = load i32, i32* %r183
  call void @inqueue(i32 %r186)
  %r187 = alloca i32
  store i32 0, i32* %r187
  %r188 = alloca i32
  store i32 0, i32* %r188
  %r189 = alloca i32
  store i32 0, i32* %r189
  %r190 = alloca i32
  store i32 0, i32* %r190
  br label %while_5_80_cond

while_5_80_cond:
  %r191 = load i32, i32* @h
  %r192 = load i32, i32* @tail
  %r193 = icmp slt i32 %r191, %r192
  br i1 %r193, label %while_5_80_whilestms, label %while_5_80_bre

while_5_80_whilestms:
  %r194 = call i32 @popqueue()
  store i32 %r194, i32* %r188
  %r195 = load i32, i32* %r188
  %r196 = load i32, i32* %r185
  %r197 = icmp eq i32 %r195, %r196
  br i1 %r197, label %if_9_82_true, label %if_9_82_false

if_9_82_true:
  store i32 1, i32* %r187
  br label %if_9_82_end

if_9_82_false:
  br label %if_9_82_end

if_9_82_end:
  %r198 = load i32, i32* %r188
  %r199 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r198
  %r200 = load i32, i32* %r199
  store i32 %r200, i32* %r189
  br label %while_9_86_cond

while_9_86_cond:
  %r201 = load i32, i32* %r189
  %r202 = sub i32 0, 1
  %r203 = icmp ne i32 %r201, %r202
  br i1 %r203, label %while_9_86_whilestms, label %while_9_86_bre

while_9_86_whilestms:
  %r204 = load i32, i32* %r189
  %r205 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r204
  %r206 = load i32, i32* %r205
  store i32 %r206, i32* %r190
  %r207 = load i32, i32* %r190
  %r208 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r207
  %r209 = load i32, i32* %r208
  %r210 = icmp eq i32 %r209, 0
  br i1 %r210, label %if_13_88_true, label %if_13_88_false

if_13_88_true:
  %r211 = load i32, i32* %r189
  %r212 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r211
  %r213 = load i32, i32* %r212
  call void @inqueue(i32 %r213)
  br label %if_13_88_end

if_13_88_false:
  br label %if_13_88_end

if_13_88_end:
  %r214 = load i32, i32* %r189
  %r215 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r214
  %r216 = load i32, i32* %r215
  store i32 %r216, i32* %r189
  br label %while_9_86_cond

while_9_86_bre:
  br label %while_5_80_cond

while_5_80_bre:
  store i32 0, i32* %r189
  br label %while_5_95_cond

while_5_95_cond:
  %r217 = load i32, i32* %r189
  %r218 = load i32, i32* @tail
  %r219 = icmp sle i32 %r217, %r218
  br i1 %r219, label %while_5_95_whilestms, label %while_5_95_bre

while_5_95_whilestms:
  %r220 = load i32, i32* %r189
  %r221 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r220
  %r222 = load i32, i32* %r221
  store i32 %r222, i32* %r190
  %r223 = load i32, i32* %r190
  %r224 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r223
  store i32 0, i32* %r224
  %r225 = load i32, i32* %r189
  %r226 = add i32 %r225, 1
  store i32 %r226, i32* %r189
  br label %while_5_95_cond

while_5_95_bre:
  %r227 = load i32, i32* %r187
  ret i32 %r227
}

define i32 @main( ) {
main:
  %r228 = call i32 @quickread()
  store i32 %r228, i32* @n
  %r229 = call i32 @quickread()
  store i32 %r229, i32* @m
  call void @init()
  %r230 = alloca i32
  store i32 0, i32* %r230
  %r231 = alloca i32
  store i32 0, i32* %r231
  %r232 = alloca i32
  store i32 0, i32* %r232
  br label %while_5_109_cond

while_5_109_cond:
  %r233 = load i32, i32* @m
  %r234 = icmp ne i32 %r233, 0
  br i1 %r234, label %while_5_109_whilestms, label %while_5_109_bre

while_5_109_whilestms:
  %r235 = call i32 @getch()
  store i32 %r235, i32* %r230
  br label %while_9_111_cond

while_9_111_cond:
  %r236 = load i32, i32* %r230
  %r237 = icmp ne i32 %r236, 81
  br i1 %r237, label %bb30_111_next, label %while_9_111_bre

bb30_111_next:
  %r238 = load i32, i32* %r230
  %r239 = icmp ne i32 %r238, 85
  br i1 %r239, label %while_9_111_whilestms, label %while_9_111_bre

while_9_111_whilestms:
  %r240 = call i32 @getch()
  store i32 %r240, i32* %r230
  br label %while_9_111_cond

while_9_111_bre:
  %r241 = load i32, i32* %r230
  %r242 = icmp eq i32 %r241, 81
  br i1 %r242, label %if_9_114_true, label %if_9_114_false

if_9_114_true:
  %r243 = call i32 @quickread()
  store i32 %r243, i32* %r231
  %r244 = call i32 @quickread()
  store i32 %r244, i32* %r232
  %r245 = load i32, i32* %r231
  %r246 = load i32, i32* %r232
  %r247 = call i32 @same(i32 %r245, i32 %r246)
  call void @putint(i32 %r247)
  call void @putch(i32 10)
  br label %if_9_114_end

if_9_114_false:
  %r248 = call i32 @quickread()
  store i32 %r248, i32* %r231
  %r249 = call i32 @quickread()
  store i32 %r249, i32* %r232
  %r250 = load i32, i32* %r231
  %r251 = load i32, i32* %r232
  call void @addedge(i32 %r250, i32 %r251)
  br label %if_9_114_end

if_9_114_end:
  %r252 = load i32, i32* @m
  %r253 = sub i32 %r252, 1
  store i32 %r253, i32* @m
  br label %while_5_109_cond

while_5_109_bre:
  ret i32 0
}

