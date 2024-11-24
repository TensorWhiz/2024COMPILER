declare i32 @getch( )
declare i32 @getint( )
declare void @putint( i32 )
declare void @putch( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@a = global i32 1
define i32 @foo( i32 %r100 ) {
foo:
  %r101 = alloca i32
  store i32 %r100, i32* %r101
  %r102 = load i32, i32* %r101
  store i32 %r102, i32* @a
  ret i32 1
}

define i32 @main( ) {
main:
  call void @_sysy_starttime(i32 9)
  %r104 = alloca i32
  store i32 1, i32* %r104
  %r105 = call i32 @foo(i32 2)
  %r106 = icmp sgt i32 %r105, 0
  br i1 %r106, label %if_5_19_true, label %bb24_19_next

bb24_19_next:
  %r107 = call i32 @foo(i32 3)
  %r108 = icmp sgt i32 %r107, 0
  br i1 %r108, label %if_5_19_true, label %if_5_19_false

if_5_19_true:
  store i32 2, i32* %r104
  br label %if_5_19_end

if_5_19_false:
  br label %if_5_19_end

if_5_19_end:
  %r109 = load i32, i32* @a
  call void @putint(i32 %r109)
  %r111 = load i32, i32* %r104
  call void @putint(i32 %r111)
  call void @_sysy_stoptime(i32 17)
  ret i32 0
}

