# Search(int* cordArray, int* frame, int* window, int aSize[4])
Search:
    add $a3, $zero, $zero # Used to Jump to SumOfDifference 
    addi $sp, $sp, -4
    sw $ra, 0($sp) # Move stack down to store main return address
    jal SOAD # Used to Jump to SumOfDifference 
    lw $ra, 0($sp)
    addi $sp, $sp, 4 # Move stack back up and retore main return address
    add $s1, $v0, $zero # s1 = minDiff = SumOfDiff()
    add $s2, $zero, $zero # s2 = minX = 0
    add $s3, $zero, $zero # s3 = minY = 0
    add $s4, $zero, $zero # s4 = col = 0
    add $s5, $zero, $zero # s5 = row = 0
    addi $s6, $zero, 1 # s6 = dirCol = 1
    addi $s7, $zero, 1 # s7 = i = 1
searchLoop:
    lw $t5, 0($a0)
    lw $t6, 8($a0)
    addi $t6, $t6, -1
    sub $t5, $t5, $t6 # t5 = aSize[0] - (aSize[2] - 1)
    lw $t6, 4($a0)
    lw $t7, 12($a0)
    addi $t7, $t7, -1
    sub $t6, $t6, $t7 # t6 = aSize[1] - (aSize[3] - 1)
    mul $t5, $t5, $t6 # t5 = t5 * t6 = (aSize[0] - (aSize[2] - 1)) * (aSize[1] - (aSize[3] - 1))
    slt $t5, $s7, $t5 # i < t5
    beq $t5, $zero, End # if !(i < t5) jump to end
if:
    bne $s5, $zero, elseIf # row == 0
    slt $t5, $zero, $s6
    beq $t5, $zero, elseIf # dirCol > 0
    lw $t5, 4($a0)
    lw $t6, 12($a0)
    sub $t5, $t5, $t6 # t5 = aSize[1] - aSize[3]
    beq $s4, $t5, elseIf # col != (aSize[1] - aSize[3])
    addi $s4, $s4, 1 # col += 1
    addi $s6, $zero, -1 # dirCol = -1
    j bottomLoop
elseIf:
    bne $s4, $zero, elseIf2 # col == 0
    slt $t5, $s6, $zero
    beq $t5, $zero, elseIf2 # dirCol < 0
    lw $t5, 0($a0)
    lw $t6, 8($a0)
    sub $t5, $t5, $t6 # t5 = aSize[0] - aSize[2]
    beq $s5, $t5, elseIf2 # row != (aSize[0] - aSize[2])
    addi $s5, $s5, 1 # row += 1
    addi $s6, $zero, 1 # dirCol = 1
    j bottomLoop
elseIf2:
    lw $t5, 4($a0)
    lw $t6, 12($a0)
    sub $t5, $t5, $t6
    bne $s4, $t5, elseIf3 # col == (aSize[1] - aSize[3])
    slt $t5, $zero, $s6
    beq $t5, $zero, elseIf3 # dirCol > 0
    lw $t5, 0($a0)
    lw $t6, 8($a0)
    sub $t5, $t5, $t6
    beq $s5, $t5, elseIf3 # row != (aSize[0] - aSize[2])
    addi $s5, $s5, 1 # row += 1
    addi $s6, $zero, -1 # dirCol = -1
    j bottomLoop
elseIf3:
    lw $t5, 0($a0)
    lw $t6, 8($a0)
    sub $t5, $t5, $t6
    bne $s5, $t5, elseIf4 # row == (aSize[0] - aSize[2])
    slt $t5, $s6, $zero
    beq $t5, $zero, elseIf4 # dirCol < 0
    lw $t5, 4($a0)
    lw $t6, 12($a0)
    sub $t5, $t5, $t6
    beq $s4, $t5, elseIf4 # col != (aSize[1] - aSize[3])
    addi $s4, $s4, 1 # col += 1
    addi $s6, $zero, 1 # dirCol = 1
    j bottomLoop
elseIf4:
    slt $t5, $s6, $zero
    beq $t5, $zero, elseIf5 # dirCol < 0
    addi $s5, $s5, 1 # row += 1
    addi $s4, $s4, -1 # col -= 1
    addi $s6, $zero, -1 # dirCol = -1
    j bottomLoop
elseIf5:
    slt $t5, $zero, $s6
    beq $t5, $zero, bottomLoop # dirCol > 0
    addi $s5, $s5, -1 # row -= 1
    addi $s4, $s4, 1 # col += 1
    addi $s6, $zero, 1 # dirCol = 1
    j bottomLoop
bottomLoop:
    addi $s7, $s7, 1 # ++i
    lw $t5, 0($a0)
    mul $t5, $s5, $t5
    add $a3, $t5, $s4 # frameIndex = a3 = (row * aSize[1]) + col
    addi $sp, $sp, -4
    sw $ra, 0($sp) # Move stack down to store main return address
    jal SOAD
    lw $ra, 0($sp)
    addi $sp, $sp, 4 # Move stack back up and retore main return address
    add $s0, $v0, $zero # s0 = SumOfDiff()
    beq $s0, $s1, min
    slt $t5, $s0, $s1
    beq $t5, $zero, searchLoop # tempDiff < minDiff
min:
    add $s1, $s0, $zero # minDiff = tempDiff
    add $s2, $s4, $zero # minX = col
    add $s3, $s5, $zero # minY = row
    j searchLoop
End:
    add $v0, $s3, $zero # return minX
    add $v1, $s2, $zero # return minY
    jr $ra


## SumOfDifference(int* f, int* w, int* aSize, int frameStartIndex)
SOAD:
    add $v0, $zero, $zero # v0 = sumOfDiff = 0
    add $t0, $zero, $zero # t0 = i = 0
    lw $t1, 12($a0) # t1 = aSize[3]
    lw $t2, 8($a0)
    mul $t2, $t2, $t1 # t2 = aSize[2] * aSize[3]
SOADloop:
    beq $t0, $t2, SOADend
    sll $t3, $t0, 2 # t3 = 4 * i
    add $t4, $a2, $t3 
    lw $t4, 0($t4) # t4 = window[i]
    add $t5, $t0, $a3 # t5 = i + frameStartIndex
    sll $t5, $t5, 2 # t5 = (i + frameStartIndex) * 4
    add $t5, $a1, $t5
    lw $t5, 0($t5) # t5 = frame[i + frameStartIndex]
    sub $t6, $t4, $t5 # t6 = window[i] - frame[i + frameStartIndex]
    slt $t7, $t6, $zero # t6 < 0
    beq $t7, $zero, skipAbs # jump if t6 is positive to skip abs
    sub $t6, $t5, $t4 # t6 = frame[i + frameStartIndex] - window[i]
skipAbs:
    add $v0, $v0, $t6 # sumOfDiff += abs(window[i] - frame[i + frameStartIndex]
    addi $t4, $t1, -1 # t4 = aSize[3] - 1
    and $t5, $t0, $t4 # t5 = i & (aSize[3] - 1)
    bne $t5, $t4, SOADloopBottom
    lw $t4, 4($a0) # t4 = aSize[1]
    sub $t4, $t4, $t1 # t4 = aSize[1] - aSize[3]
    add $a3, $a3, $t4 # frameIndex += aSize[1] - aSize[3]
SOADloopBottom:
    addi $t0, $t0, 1 # ++i
    j SOADloop
SOADend:
    jr $ra
