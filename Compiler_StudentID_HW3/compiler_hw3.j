.class public compiler_hw3
.super java/lang/Object
.field public static a I = 8
.field public static b I
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
ldc 0
istore 0
ldc 3
istore 1
getstatic compiler_hw3/a I
ldc 1
getstatic compiler_hw3/b I
ldc 1
iadd
putstatic compiler_hw3/b I
getstatic compiler_hw3/b I
iadd
putstatic compiler_hw3/a I
getstatic compiler_hw3/b I
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
getstatic compiler_hw3/a I
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
return
.end method
