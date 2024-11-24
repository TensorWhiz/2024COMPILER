declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
%Node = type { i32, i32 }
%Bar = type { %Node, [10 x %Node ], [10 x i32 ] }
define void @foo( %Bar* %r100 ) {
foo:
  %r101 = getelementptr %Bar, %Bar* %r100, i32 1
  %r102 = getelementptr %Bar, %Bar* %r101, i32 0, i32 2
  %r103 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 3
  store i32 5, i32* %r103
  ret void
}

define i32 @main( ) {
main:
  call void @_sysy_starttime(i32 18)
  %r105 = alloca [ 10 x %Bar ]
  %r106 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r107 = getelementptr %Bar, %Bar* %r106, i32 0, i32 0
  %r108 = getelementptr %Node, %Node* %r107, i32 0, i32 0
  store i32 1, i32* %r108
  %r109 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r110 = getelementptr %Bar, %Bar* %r109, i32 0, i32 0
  %r111 = getelementptr %Node, %Node* %r110, i32 0, i32 1
  store i32 2, i32* %r111
  %r112 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r113 = getelementptr %Bar, %Bar* %r112, i32 0, i32 1
  %r114 = getelementptr [10 x %Node ], [10 x %Node ]* %r113, i32 0, i32 2
  %r115 = getelementptr %Node, %Node* %r114, i32 0, i32 0
  store i32 3, i32* %r115
  %r116 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r117 = getelementptr %Bar, %Bar* %r116, i32 0, i32 1
  %r118 = getelementptr [10 x %Node ], [10 x %Node ]* %r117, i32 0, i32 2
  %r119 = getelementptr %Node, %Node* %r118, i32 0, i32 1
  store i32 4, i32* %r119
  %r120 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  call void @foo(%Bar* %r120)
  %r122 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r123 = getelementptr %Bar, %Bar* %r122, i32 0, i32 0
  %r124 = getelementptr %Node, %Node* %r123, i32 0, i32 0
  %r125 = load i32, i32* %r124
  call void @putint(i32 %r125)
  %r127 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r128 = getelementptr %Bar, %Bar* %r127, i32 0, i32 0
  %r129 = getelementptr %Node, %Node* %r128, i32 0, i32 1
  %r130 = load i32, i32* %r129
  call void @putint(i32 %r130)
  %r132 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r133 = getelementptr %Bar, %Bar* %r132, i32 0, i32 1
  %r134 = getelementptr [10 x %Node ], [10 x %Node ]* %r133, i32 0, i32 2
  %r135 = getelementptr %Node, %Node* %r134, i32 0, i32 0
  %r136 = load i32, i32* %r135
  call void @putint(i32 %r136)
  %r138 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 0
  %r139 = getelementptr %Bar, %Bar* %r138, i32 0, i32 1
  %r140 = getelementptr [10 x %Node ], [10 x %Node ]* %r139, i32 0, i32 2
  %r141 = getelementptr %Node, %Node* %r140, i32 0, i32 1
  %r142 = load i32, i32* %r141
  call void @putint(i32 %r142)
  %r144 = getelementptr [10 x %Bar ], [10 x %Bar ]* %r105, i32 0, i32 1
  %r145 = getelementptr %Bar, %Bar* %r144, i32 0, i32 2
  %r147 = getelementptr [10 x i32 ], [10 x i32 ]* %r145, i32 0, i32 3
  %r146 = load i32, i32* %r147
  call void @putint(i32 %r146)
  call void @_sysy_stoptime(i32 30)
  ret i32 0
}

