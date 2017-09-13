.name    "sebc"
.comment "sebc"
.extend

l1:	st	r1, :l2+1
	ld	%4, r3
	ld	%:l2, r2
l3:	ldi	%:l2, r2, r4
	sti	r4, %:l2, r2
	add	r2, r3, r2
live:	zjmp	%:l1
	xor	r4, r4, r4
	zjmp	%:l3
l2: