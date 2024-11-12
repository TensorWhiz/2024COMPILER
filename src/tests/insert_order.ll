declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@N = global i32 0
define i32 @insert( i32* %r100, i32 %r101 ) {
insert:
  %r119 = alloca i32
  %r102 = alloca i32
  store i32 %r101, i32* %r102
  %r103 = alloca i32
  %r104 = alloca i32
  store i32 0, i32* %r103
  br label %while_5_16_cond

while_5_16_cond:
  %r105 = load i32, i32* %r102
  %r106 = load i32, i32* %r103
  %r107 = getelementptr i32, i32* %r100, i32 %r106
  %r108 = load i32, i32* %r107
  %r109 = icmp sgt i32 %r105, %r108
  br i1 %r109, label %bb21_16_next, label %while_5_16_bre

bb21_16_next:
  %r110 = load i32, i32* %r103
  %r111 = load i32, i32* @N
  %r112 = icmp slt i32 %r110, %r111
  br i1 %r112, label %while_5_16_whilestms, label %while_5_16_bre

while_5_16_whilestms:
  %r113 = load i32, i32* %r103
  %r114 = add i32 %r113, 1
  store i32 %r114, i32* %r103
  br label %while_5_16_cond

while_5_16_bre:
  %r115 = load i32, i32* @N
  store i32 %r115, i32* %r104
  br label %while_5_22_cond

while_5_22_cond:
  %r116 = load i32, i32* %r104
  %r117 = load i32, i32* %r103
  %r118 = icmp sgt i32 %r116, %r117
  br i1 %r118, label %while_5_22_whilestms, label %while_5_22_bre

while_5_22_whilestms:
  %r120 = load i32, i32* %r104
  %r121 = sub i32 %r120, 1
  store i32 %r121, i32* %r119
  %r122 = load i32, i32* %r104
  %r123 = getelementptr i32, i32* %r100, i32 %r122
  %r124 = load i32, i32* %r119
  %r125 = getelementptr i32, i32* %r100, i32 %r124
  %r126 = load i32, i32* %r125
  store i32 %r126, i32* %r123
  %r127 = load i32, i32* %r103
  %r128 = getelementptr i32, i32* %r100, i32 %r127
  %r129 = load i32, i32* %r102
  store i32 %r129, i32* %r128
  %r130 = load i32, i32* %r104
  %r131 = sub i32 %r130, 1
  store i32 %r131, i32* %r104
  br label %while_5_22_cond

while_5_22_bre:
  ret i32 0
}

define i32 @main( ) {
main:
  store i32 10, i32* @N
  %r132 = alloca [ 11 x i32 ]
  %r133 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 0
  store i32 1, i32* %r133
  %r134 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 1
  store i32 3, i32* %r134
  %r135 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 2
  store i32 4, i32* %r135
  %r136 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 3
  store i32 7, i32* %r136
  %r137 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 4
  store i32 8, i32* %r137
  %r138 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 5
  store i32 11, i32* %r138
  %r139 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 6
  store i32 13, i32* %r139
  %r140 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 7
  store i32 18, i32* %r140
  %r141 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 8
  store i32 56, i32* %r141
  %r142 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 9
  store i32 78, i32* %r142
  %r143 = alloca i32
  %r144 = alloca i32
  store i32 0, i32* %r144
  %r145 = call i32 @getint()
  store i32 %r145, i32* %r143
  %r146 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 0
  %r147 = load i32, i32* %r143
  %r148 = call i32 @insert(i32* %r146, i32 %r147)
  store i32 %r148, i32* %r143
  br label %while_5_54_cond

while_5_54_cond:
  %r149 = load i32, i32* %r144
  %r150 = load i32, i32* @N
  %r151 = icmp slt i32 %r149, %r150
  br i1 %r151, label %while_5_54_whilestms, label %while_5_54_bre

while_5_54_whilestms:
  %r152 = load i32, i32* %r144
  %r153 = getelementptr [11 x i32 ], [11 x i32 ]* %r132, i32 0, i32 %r152
  %r154 = load i32, i32* %r153
  store i32 %r154, i32* %r143
  %r155 = load i32, i32* %r143
  call void @putint(i32 %r155)
  store i32 10, i32* %r143
  %r156 = load i32, i32* %r143
  call void @putch(i32 %r156)
  %r157 = load i32, i32* %r144
  %r158 = add i32 %r157, 1
  store i32 %r158, i32* %r144
  br label %while_5_54_cond

while_5_54_bre:
  ret i32 0
}

