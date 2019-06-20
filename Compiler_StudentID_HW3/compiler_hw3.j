.class public compiler_hw3
.super java/lang/Object
.method public static foo() I
.limit stack 50
.limit locals 50
iload 0
ldc 6
iadd
istore 0
iload 0
ireturn
.end method
.method public static lol() V
.limit stack 50
.limit locals 50
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
ldc 0
istore 0
iload 0
getstatic compiler_hw3/foo I
ldc 4
istore 0
pop
getstatic compiler_hw3/lol V
iload 0
return
.end method
