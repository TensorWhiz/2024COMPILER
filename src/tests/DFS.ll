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
@vis = global [ 1005 x i32 ] zeroinitializer
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
  br label %while_5_51_cond

while_5_51_cond:
  %r157 = load i32, i32* %r156
  %r158 = icmp slt i32 %r157, 1005
  br i1 %r158, label %while_5_51_whilestms, label %while_5_51_bre

while_5_51_whilestms:
  %r159 = load i32, i32* %r156
  %r160 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r159
  %r161 = sub i32 0, 1
  store i32 %r161, i32* %r160
  %r162 = load i32, i32* %r156
  %r163 = add i32 %r162, 1
  store i32 %r163, i32* %r156
  br label %while_5_51_cond

while_5_51_bre:
  ret void
}

define void @clear( ) {
clear:
  %r164 = alloca i32
  store i32 1, i32* %r164
  br label %while_5_59_cond

while_5_59_cond:
  %r165 = load i32, i32* %r164
  %r166 = load i32, i32* @n
  %r167 = icmp sle i32 %r165, %r166
  br i1 %r167, label %while_5_59_whilestms, label %while_5_59_bre

while_5_59_whilestms:
  %r168 = load i32, i32* %r164
  %r169 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r168
  store i32 0, i32* %r169
  %r170 = load i32, i32* %r164
  %r171 = add i32 %r170, 1
  store i32 %r171, i32* %r164
  br label %while_5_59_cond

while_5_59_bre:
  ret void
}

define i32 @same( i32 %r172, i32 %r174 ) {
same:
  %r188 = alloca i32
  %r181 = alloca i32
  %r173 = alloca i32
  store i32 %r172, i32* %r173
  %r175 = alloca i32
  store i32 %r174, i32* %r175
  %r176 = load i32, i32* %r173
  %r177 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r176
  store i32 1, i32* %r177
  %r178 = load i32, i32* %r173
  %r179 = load i32, i32* %r175
  %r180 = icmp eq i32 %r178, %r179
  br i1 %r180, label %if_5_67_true, label %if_5_67_false

if_5_67_true:
  ret i32 1
bb3:
  br label %if_5_67_end

if_5_67_false:
  br label %if_5_67_end

if_5_67_end:
  %r182 = load i32, i32* %r173
  %r183 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r182
  %r184 = load i32, i32* %r183
  store i32 %r184, i32* %r181
  br label %while_5_71_cond

while_5_71_cond:
  %r185 = load i32, i32* %r181
  %r186 = sub i32 0, 1
  %r187 = icmp ne i32 %r185, %r186
  br i1 %r187, label %while_5_71_whilestms, label %while_5_71_bre

while_5_71_whilestms:
  %r189 = load i32, i32* %r181
  %r190 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r189
  %r191 = load i32, i32* %r190
  store i32 %r191, i32* %r188
  %r192 = load i32, i32* %r188
  %r193 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r192
  %r194 = load i32, i32* %r193
  %r195 = icmp eq i32 %r194, 0
  br i1 %r195, label %bb28_73_next, label %if_9_73_false

bb28_73_next:
  %r196 = load i32, i32* %r188
  %r197 = load i32, i32* %r175
  %r198 = call i32 @same(i32 %r196, i32 %r197)
  %r199 = icmp ne i32 %r198, 0
  br i1 %r199, label %if_9_73_true, label %if_9_73_false

if_9_73_true:
  ret i32 1
bb4:
  br label %if_9_73_end

if_9_73_false:
  br label %if_9_73_end

if_9_73_end:
  %r200 = load i32, i32* %r181
  %r201 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r200
  %r202 = load i32, i32* %r201
  store i32 %r202, i32* %r181
  br label %while_5_71_cond

while_5_71_bre:
  ret i32 0
}

define i32 @main( ) {
main:
  %r203 = call i32 @quickread()
  store i32 %r203, i32* @n
  %r204 = call i32 @quickread()
  store i32 %r204, i32* @m
  call void @init()
  %r205 = alloca i32
  store i32 0, i32* %r205
  %r206 = alloca i32
  store i32 0, i32* %r206
  %r207 = alloca i32
  store i32 0, i32* %r207
  br label %while_5_87_cond

while_5_87_cond:
  %r208 = load i32, i32* @m
  %r209 = icmp ne i32 %r208, 0
  br i1 %r209, label %while_5_87_whilestms, label %while_5_87_bre

while_5_87_whilestms:
  %r210 = call i32 @getch()
  store i32 %r210, i32* %r205
  br label %while_9_89_cond

while_9_89_cond:
  %r211 = load i32, i32* %r205
  %r212 = icmp ne i32 %r211, 81
  br i1 %r212, label %bb30_89_next, label %while_9_89_bre

bb30_89_next:
  %r213 = load i32, i32* %r205
  %r214 = icmp ne i32 %r213, 85
  br i1 %r214, label %while_9_89_whilestms, label %while_9_89_bre

while_9_89_whilestms:
  %r215 = call i32 @getch()
  store i32 %r215, i32* %r205
  br label %while_9_89_cond

while_9_89_bre:
  %r216 = load i32, i32* %r205
  %r217 = icmp eq i32 %r216, 81
  br i1 %r217, label %if_9_92_true, label %if_9_92_false

if_9_92_true:
  %r218 = call i32 @quickread()
  store i32 %r218, i32* %r206
  %r219 = call i32 @quickread()
  store i32 %r219, i32* %r207
  call void @clear()
  %r220 = load i32, i32* %r206
  %r221 = load i32, i32* %r207
  %r222 = call i32 @same(i32 %r220, i32 %r221)
  call void @putint(i32 %r222)
  call void @putch(i32 10)
  br label %if_9_92_end

if_9_92_false:
  %r223 = call i32 @quickread()
  store i32 %r223, i32* %r206
  %r224 = call i32 @quickread()
  store i32 %r224, i32* %r207
  %r225 = load i32, i32* %r206
  %r226 = load i32, i32* %r207
  call void @addedge(i32 %r225, i32 %r226)
  br label %if_9_92_end

if_9_92_end:
  %r227 = load i32, i32* @m
  %r228 = sub i32 %r227, 1
  store i32 %r228, i32* @m
  br label %while_5_87_cond

while_5_87_bre:
  ret i32 0
}

