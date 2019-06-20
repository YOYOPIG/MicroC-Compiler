.class public compiler_hw3
.super java/lang/Object
.field public static a I = 8
.field public static b I
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
ldc 3
istore 0
While_0:
iload 0
ldc 5
isub
ifge ENDWhile_0
iload 0
ldc 1
iadd
istore 0
iload 0
ldc 1
isub
pop
goto While_0
ENDWhile_0:
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
return
.end method
