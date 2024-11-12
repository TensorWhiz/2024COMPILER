@TAPE_LEN = global i32 65536
@BUFFER_LEN = global i32 32768
@tape = global [ 65536 x i32 ] zeroinitializer
@program = global [ 32768 x i32 ] zeroinitializer
@ptr = global i32 0
declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define void @read_program( ) {
read_program:
  %r100 = alloca i32
  store i32 0, i32* %r100
  %r101 = alloca i32
  %r102 = call i32 @getint()
  store i32 %r102, i32* %r101
  br label %while_3_21_cond

while_3_21_cond:
  %r103 = load i32, i32* %r100
  %r104 = load i32, i32* %r101
  %r105 = icmp slt i32 %r103, %r104
  br i1 %r105, label %while_3_21_whilestms, label %while_3_21_bre

while_3_21_whilestms:
  %r106 = load i32, i32* %r100
  %r107 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r106
  %r108 = call i32 @getch()
  store i32 %r108, i32* %r107
  %r109 = load i32, i32* %r100
  %r110 = add i32 %r109, 1
  store i32 %r110, i32* %r100
  br label %while_3_21_cond

while_3_21_bre:
  %r111 = load i32, i32* %r100
  %r112 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 %r111
  store i32 0, i32* %r112
  ret void
}

define void @interpret( i32* %r113 ) {
interpret:
  %r114 = alloca i32
  %r115 = alloca i32
  %r116 = alloca i32
  store i32 0, i32* %r116
  br label %while_3_33_cond

while_3_33_cond:
  %r117 = load i32, i32* %r116
  %r118 = getelementptr i32, i32* %r113, i32 %r117
  %r119 = load i32, i32* %r118
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %while_3_33_whilestms, label %while_3_33_bre

while_3_33_whilestms:
  %r121 = load i32, i32* %r116
  %r122 = getelementptr i32, i32* %r113, i32 %r121
  %r123 = load i32, i32* %r122
  store i32 %r123, i32* %r114
  %r124 = load i32, i32* %r114
  %r125 = icmp eq i32 %r124, 62
  br i1 %r125, label %if_5_35_true, label %if_5_35_false

if_5_35_true:
  %r126 = load i32, i32* @ptr
  %r127 = add i32 %r126, 1
  store i32 %r127, i32* @ptr
  br label %if_5_35_end

if_5_35_false:
  br label %if_5_35_end

if_5_35_end:
  %r128 = load i32, i32* %r114
  %r129 = icmp eq i32 %r128, 60
  br i1 %r129, label %if_5_39_true, label %if_5_39_false

if_5_39_true:
  %r130 = load i32, i32* @ptr
  %r131 = sub i32 %r130, 1
  store i32 %r131, i32* @ptr
  br label %if_5_39_end

if_5_39_false:
  br label %if_5_39_end

if_5_39_end:
  %r132 = load i32, i32* %r114
  %r133 = icmp eq i32 %r132, 43
  br i1 %r133, label %if_5_43_true, label %if_5_43_false

if_5_43_true:
  %r134 = load i32, i32* @ptr
  %r135 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r134
  %r136 = load i32, i32* @ptr
  %r137 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r136
  %r138 = load i32, i32* %r137
  %r139 = add i32 %r138, 1
  store i32 %r139, i32* %r135
  br label %if_5_43_end

if_5_43_false:
  br label %if_5_43_end

if_5_43_end:
  %r140 = load i32, i32* %r114
  %r141 = icmp eq i32 %r140, 45
  br i1 %r141, label %if_5_47_true, label %if_5_47_false

if_5_47_true:
  %r142 = load i32, i32* @ptr
  %r143 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r142
  %r144 = load i32, i32* @ptr
  %r145 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r144
  %r146 = load i32, i32* %r145
  %r147 = sub i32 %r146, 1
  store i32 %r147, i32* %r143
  br label %if_5_47_end

if_5_47_false:
  br label %if_5_47_end

if_5_47_end:
  %r148 = load i32, i32* %r114
  %r149 = icmp eq i32 %r148, 46
  br i1 %r149, label %if_5_51_true, label %if_5_51_false

if_5_51_true:
  %r150 = load i32, i32* @ptr
  %r151 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r150
  %r152 = load i32, i32* %r151
  call void @putch(i32 %r152)
  br label %if_5_51_end

if_5_51_false:
  br label %if_5_51_end

if_5_51_end:
  %r153 = load i32, i32* %r114
  %r154 = icmp eq i32 %r153, 44
  br i1 %r154, label %if_5_55_true, label %if_5_55_false

if_5_55_true:
  %r155 = load i32, i32* @ptr
  %r156 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r155
  %r157 = call i32 @getch()
  store i32 %r157, i32* %r156
  br label %if_5_55_end

if_5_55_false:
  br label %if_5_55_end

if_5_55_end:
  %r158 = load i32, i32* %r114
  %r159 = icmp eq i32 %r158, 93
  br i1 %r159, label %bb29_59_next, label %if_5_59_false

bb29_59_next:
  %r160 = load i32, i32* @ptr
  %r161 = getelementptr [65536 x i32 ], [65536 x i32 ]* @tape, i32 0, i32 %r160
  %r162 = load i32, i32* %r161
  %r163 = icmp ne i32 %r162, 0
  br i1 %r163, label %if_5_59_true, label %if_5_59_false

if_5_59_true:
  store i32 1, i32* %r115
  br label %while_7_62_cond

while_7_62_cond:
  %r164 = load i32, i32* %r115
  %r165 = icmp sgt i32 %r164, 0
  br i1 %r165, label %while_7_62_whilestms, label %while_7_62_bre

while_7_62_whilestms:
  %r166 = load i32, i32* %r116
  %r167 = sub i32 %r166, 1
  store i32 %r167, i32* %r116
  %r168 = load i32, i32* %r116
  %r169 = getelementptr i32, i32* %r113, i32 %r168
  %r170 = load i32, i32* %r169
  store i32 %r170, i32* %r114
  %r171 = load i32, i32* %r114
  %r172 = icmp eq i32 %r171, 91
  br i1 %r172, label %if_9_65_true, label %if_9_65_false

if_9_65_true:
  %r173 = load i32, i32* %r115
  %r174 = sub i32 %r173, 1
  store i32 %r174, i32* %r115
  br label %if_9_65_end

if_9_65_false:
  br label %if_9_65_end

if_9_65_end:
  %r175 = load i32, i32* %r114
  %r176 = icmp eq i32 %r175, 93
  br i1 %r176, label %if_9_69_true, label %if_9_69_false

if_9_69_true:
  %r177 = load i32, i32* %r115
  %r178 = add i32 %r177, 1
  store i32 %r178, i32* %r115
  br label %if_9_69_end

if_9_69_false:
  br label %if_9_69_end

if_9_69_end:
  br label %while_7_62_cond

while_7_62_bre:
  br label %if_5_59_end

if_5_59_false:
  br label %if_5_59_end

if_5_59_end:
  %r179 = load i32, i32* %r116
  %r180 = add i32 %r179, 1
  store i32 %r180, i32* %r116
  br label %while_3_33_cond

while_3_33_bre:
  ret void
}

define i32 @main( ) {
main:
  call void @read_program()
  %r181 = getelementptr [32768 x i32 ], [32768 x i32 ]* @program, i32 0, i32 0
  call void @interpret(i32* %r181)
  call void @putch(i32 10)
  ret i32 0
}

