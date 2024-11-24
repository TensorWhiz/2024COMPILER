declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@INF = global i32 65535
%array2D = type { [16 x i32 ] }
@e = global [ 16 x %array2D ] zeroinitializer
@book = global [ 16 x i32 ] zeroinitializer
@dis = global [ 16 x i32 ] zeroinitializer
@n = global i32 0
@m = global i32 0
@v1 = global i32 0
@v2 = global i32 0
@w = global i32 0
define void @Dijkstra( ) {
Dijkstra:
  %r144 = alloca i32
  %r123 = alloca i32
  %r122 = alloca i32
  %r120 = alloca i32
  %r100 = alloca i32
  store i32 1, i32* %r100
  br label %while_5_26_cond

while_5_26_cond:
  %r101 = load i32, i32* %r100
  %r102 = load i32, i32* @n
  %r103 = icmp sle i32 %r101, %r102
  br i1 %r103, label %while_5_26_whilestms, label %while_5_26_bre

while_5_26_whilestms:
  %r104 = load i32, i32* %r100
  %r105 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r104
  %r106 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 1
  %r107 = getelementptr %array2D, %array2D* %r106, i32 0, i32 0
  %r108 = load i32, i32* %r100
  %r110 = getelementptr [16 x i32 ], [16 x i32 ]* %r107, i32 0, i32 %r108
  %r109 = load i32, i32* %r110
  store i32 %r109, i32* %r105
  %r111 = load i32, i32* %r100
  %r112 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r111
  store i32 0, i32* %r112
  %r113 = load i32, i32* %r100
  %r114 = add i32 %r113, 1
  store i32 %r114, i32* %r100
  br label %while_5_26_cond

while_5_26_bre:
  %r115 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 1
  store i32 1, i32* %r115
  store i32 1, i32* %r100
  br label %while_5_34_cond

while_5_34_cond:
  %r116 = load i32, i32* %r100
  %r117 = load i32, i32* @n
  %r118 = sub i32 %r117, 1
  %r119 = icmp sle i32 %r116, %r118
  br i1 %r119, label %while_5_34_whilestms, label %while_5_34_bre

while_5_34_whilestms:
  %r121 = load i32, i32* @INF
  store i32 %r121, i32* %r120
  store i32 0, i32* %r122
  store i32 1, i32* %r123
  br label %while_9_38_cond

while_9_38_cond:
  %r124 = load i32, i32* %r123
  %r125 = load i32, i32* @n
  %r126 = icmp sle i32 %r124, %r125
  br i1 %r126, label %while_9_38_whilestms, label %while_9_38_bre

while_9_38_whilestms:
  %r127 = load i32, i32* %r120
  %r128 = load i32, i32* %r123
  %r130 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r128
  %r129 = load i32, i32* %r130
  %r131 = icmp sgt i32 %r127, %r129
  br i1 %r131, label %bb39_39_next, label %if_13_39_false

bb39_39_next:
  %r132 = load i32, i32* %r123
  %r134 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r132
  %r133 = load i32, i32* %r134
  %r135 = icmp eq i32 %r133, 0
  br i1 %r135, label %if_13_39_true, label %if_13_39_false

if_13_39_true:
  %r136 = load i32, i32* %r123
  %r138 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r136
  %r137 = load i32, i32* %r138
  store i32 %r137, i32* %r120
  %r139 = load i32, i32* %r123
  store i32 %r139, i32* %r122
  br label %if_13_39_end

if_13_39_false:
  br label %if_13_39_end

if_13_39_end:
  %r140 = load i32, i32* %r123
  %r141 = add i32 %r140, 1
  store i32 %r141, i32* %r123
  br label %while_9_38_cond

while_9_38_bre:
  %r142 = load i32, i32* %r122
  %r143 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r142
  store i32 1, i32* %r143
  store i32 1, i32* %r144
  br label %while_9_47_cond

while_9_47_cond:
  %r145 = load i32, i32* %r144
  %r146 = load i32, i32* @n
  %r147 = icmp sle i32 %r145, %r146
  br i1 %r147, label %while_9_47_whilestms, label %while_9_47_bre

while_9_47_whilestms:
  %r148 = load i32, i32* %r122
  %r149 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r148
  %r150 = getelementptr %array2D, %array2D* %r149, i32 0, i32 0
  %r151 = load i32, i32* %r144
  %r153 = getelementptr [16 x i32 ], [16 x i32 ]* %r150, i32 0, i32 %r151
  %r152 = load i32, i32* %r153
  %r154 = load i32, i32* @INF
  %r155 = icmp slt i32 %r152, %r154
  br i1 %r155, label %if_13_48_true, label %if_13_48_false

if_13_48_true:
  %r156 = load i32, i32* %r144
  %r158 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r156
  %r157 = load i32, i32* %r158
  %r159 = load i32, i32* %r122
  %r161 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r159
  %r160 = load i32, i32* %r161
  %r162 = load i32, i32* %r122
  %r163 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r162
  %r164 = getelementptr %array2D, %array2D* %r163, i32 0, i32 0
  %r165 = load i32, i32* %r144
  %r167 = getelementptr [16 x i32 ], [16 x i32 ]* %r164, i32 0, i32 %r165
  %r166 = load i32, i32* %r167
  %r168 = add i32 %r160, %r166
  %r169 = icmp sgt i32 %r157, %r168
  br i1 %r169, label %if_17_49_true, label %if_17_49_false

if_17_49_true:
  %r170 = load i32, i32* %r144
  %r171 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r170
  %r172 = load i32, i32* %r122
  %r174 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r172
  %r173 = load i32, i32* %r174
  %r175 = load i32, i32* %r122
  %r176 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r175
  %r177 = getelementptr %array2D, %array2D* %r176, i32 0, i32 0
  %r178 = load i32, i32* %r144
  %r180 = getelementptr [16 x i32 ], [16 x i32 ]* %r177, i32 0, i32 %r178
  %r179 = load i32, i32* %r180
  %r181 = add i32 %r173, %r179
  store i32 %r181, i32* %r171
  br label %if_17_49_end

if_17_49_false:
  br label %if_17_49_end

if_17_49_end:
  br label %if_13_48_end

if_13_48_false:
  br label %if_13_48_end

if_13_48_end:
  %r182 = load i32, i32* %r144
  %r183 = add i32 %r182, 1
  store i32 %r183, i32* %r144
  br label %while_9_47_cond

while_9_47_bre:
  %r184 = load i32, i32* %r100
  %r185 = add i32 %r184, 1
  store i32 %r185, i32* %r100
  br label %while_5_34_cond

while_5_34_bre:
  ret void
}

define i32 @main( ) {
main:
  %r219 = alloca i32
  %r217 = alloca i32
  %r192 = alloca i32
  %r186 = alloca i32
  %r187 = call i32 @getint()
  store i32 %r187, i32* @n
  %r188 = call i32 @getint()
  store i32 %r188, i32* @m
  store i32 1, i32* %r186
  br label %while_5_66_cond

while_5_66_cond:
  %r189 = load i32, i32* %r186
  %r190 = load i32, i32* @n
  %r191 = icmp sle i32 %r189, %r190
  br i1 %r191, label %while_5_66_whilestms, label %while_5_66_bre

while_5_66_whilestms:
  store i32 1, i32* %r192
  br label %while_9_68_cond

while_9_68_cond:
  %r193 = load i32, i32* %r192
  %r194 = load i32, i32* @n
  %r195 = icmp sle i32 %r193, %r194
  br i1 %r195, label %while_9_68_whilestms, label %while_9_68_bre

while_9_68_whilestms:
  %r196 = load i32, i32* %r186
  %r197 = load i32, i32* %r192
  %r198 = icmp eq i32 %r196, %r197
  br i1 %r198, label %if_13_69_true, label %if_13_69_false

if_13_69_true:
  %r199 = load i32, i32* %r186
  %r200 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r199
  %r201 = getelementptr %array2D, %array2D* %r200, i32 0, i32 0
  %r202 = load i32, i32* %r192
  %r203 = getelementptr [16 x i32 ], [16 x i32 ]* %r201, i32 0, i32 %r202
  store i32 0, i32* %r203
  br label %if_13_69_end

if_13_69_false:
  %r204 = load i32, i32* %r186
  %r205 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r204
  %r206 = getelementptr %array2D, %array2D* %r205, i32 0, i32 0
  %r207 = load i32, i32* %r192
  %r208 = getelementptr [16 x i32 ], [16 x i32 ]* %r206, i32 0, i32 %r207
  %r209 = load i32, i32* @INF
  store i32 %r209, i32* %r208
  br label %if_13_69_end

if_13_69_end:
  %r210 = load i32, i32* %r192
  %r211 = add i32 %r210, 1
  store i32 %r211, i32* %r192
  br label %while_9_68_cond

while_9_68_bre:
  %r212 = load i32, i32* %r186
  %r213 = add i32 %r212, 1
  store i32 %r213, i32* %r186
  br label %while_5_66_cond

while_5_66_bre:
  store i32 1, i32* %r186
  br label %while_5_83_cond

while_5_83_cond:
  %r214 = load i32, i32* %r186
  %r215 = load i32, i32* @m
  %r216 = icmp sle i32 %r214, %r215
  br i1 %r216, label %while_5_83_whilestms, label %while_5_83_bre

while_5_83_whilestms:
  %r218 = call i32 @getint()
  store i32 %r218, i32* %r217
  %r220 = call i32 @getint()
  store i32 %r220, i32* %r219
  %r221 = load i32, i32* %r217
  %r222 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r221
  %r223 = getelementptr %array2D, %array2D* %r222, i32 0, i32 0
  %r224 = load i32, i32* %r219
  %r225 = getelementptr [16 x i32 ], [16 x i32 ]* %r223, i32 0, i32 %r224
  %r226 = call i32 @getint()
  store i32 %r226, i32* %r225
  %r227 = load i32, i32* %r186
  %r228 = add i32 %r227, 1
  store i32 %r228, i32* %r186
  br label %while_5_83_cond

while_5_83_bre:
  call void @Dijkstra()
  store i32 1, i32* %r186
  br label %while_5_93_cond

while_5_93_cond:
  %r230 = load i32, i32* %r186
  %r231 = load i32, i32* @n
  %r232 = icmp sle i32 %r230, %r231
  br i1 %r232, label %while_5_93_whilestms, label %while_5_93_bre

while_5_93_whilestms:
  %r233 = load i32, i32* %r186
  %r235 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r233
  %r234 = load i32, i32* %r235
  call void @putint(i32 %r234)
  call void @putch(i32 32)
  %r238 = load i32, i32* %r186
  %r239 = add i32 %r238, 1
  store i32 %r239, i32* %r186
  br label %while_5_93_cond

while_5_93_bre:
  call void @putch(i32 10)
  ret i32 0
}

