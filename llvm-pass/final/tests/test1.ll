; ModuleID = 'test1.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 !dbg !4 {
  %1 = alloca i32, align 4
  %numbers = alloca [3 x i32], align 4
  %i = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @llvm.dbg.declare(metadata [3 x i32]* %numbers, metadata !11, metadata !15), !dbg !16
  call void @llvm.dbg.declare(metadata i32* %i, metadata !17, metadata !15), !dbg !19
  store i32 0, i32* %i, align 4, !dbg !19
  br label %2, !dbg !20

; <label>:2                                       ; preds = %10, %0
  %3 = load i32, i32* %i, align 4, !dbg !21
  %4 = icmp slt i32 %3, 4, !dbg !24
  br i1 %4, label %5, label %13, !dbg !25

; <label>:5                                       ; preds = %2
  %6 = load i32, i32* %i, align 4, !dbg !26
  %7 = load i32, i32* %i, align 4, !dbg !28
  %8 = sext i32 %7 to i64, !dbg !29
  %9 = getelementptr inbounds [3 x i32], [3 x i32]* %numbers, i64 0, i64 %8, !dbg !29
  store i32 %6, i32* %9, align 4, !dbg !30
  br label %10, !dbg !31

; <label>:10                                      ; preds = %5
  %11 = load i32, i32* %i, align 4, !dbg !32
  %12 = add nsw i32 %11, 1, !dbg !32
  store i32 %12, i32* %i, align 4, !dbg !32
  br label %2, !dbg !34

; <label>:13                                      ; preds = %2
  ret i32 0, !dbg !35
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!8, !9}
!llvm.ident = !{!10}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 3.8.0 (tags/RELEASE_380/final)", isOptimized: false, runtimeVersion: 0, emissionKind: 1, enums: !2, subprograms: !3)
!1 = !DIFile(filename: "tests/test1.c", directory: "/home/llvm/handout")
!2 = !{}
!3 = !{!4}
!4 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 3, type: !5, isLocal: false, isDefinition: true, scopeLine: 3, isOptimized: false, variables: !2)
!5 = !DISubroutineType(types: !6)
!6 = !{!7}
!7 = !DIBasicType(name: "int", size: 32, align: 32, encoding: DW_ATE_signed)
!8 = !{i32 2, !"Dwarf Version", i32 4}
!9 = !{i32 2, !"Debug Info Version", i32 3}
!10 = !{!"clang version 3.8.0 (tags/RELEASE_380/final)"}
!11 = !DILocalVariable(name: "numbers", scope: !4, file: !1, line: 4, type: !12)
!12 = !DICompositeType(tag: DW_TAG_array_type, baseType: !7, size: 96, align: 32, elements: !13)
!13 = !{!14}
!14 = !DISubrange(count: 3)
!15 = !DIExpression()
!16 = !DILocation(line: 4, column: 7, scope: !4)
!17 = !DILocalVariable(name: "i", scope: !18, file: !1, line: 5, type: !7)
!18 = distinct !DILexicalBlock(scope: !4, file: !1, line: 5, column: 3)
!19 = !DILocation(line: 5, column: 11, scope: !18)
!20 = !DILocation(line: 5, column: 7, scope: !18)
!21 = !DILocation(line: 5, column: 18, scope: !22)
!22 = !DILexicalBlockFile(scope: !23, file: !1, discriminator: 1)
!23 = distinct !DILexicalBlock(scope: !18, file: !1, line: 5, column: 3)
!24 = !DILocation(line: 5, column: 20, scope: !22)
!25 = !DILocation(line: 5, column: 3, scope: !22)
!26 = !DILocation(line: 6, column: 18, scope: !27)
!27 = distinct !DILexicalBlock(scope: !23, file: !1, line: 5, column: 30)
!28 = !DILocation(line: 6, column: 13, scope: !27)
!29 = !DILocation(line: 6, column: 5, scope: !27)
!30 = !DILocation(line: 6, column: 16, scope: !27)
!31 = !DILocation(line: 7, column: 3, scope: !27)
!32 = !DILocation(line: 5, column: 26, scope: !33)
!33 = !DILexicalBlockFile(scope: !23, file: !1, discriminator: 2)
!34 = !DILocation(line: 5, column: 3, scope: !33)
!35 = !DILocation(line: 8, column: 3, scope: !4)
