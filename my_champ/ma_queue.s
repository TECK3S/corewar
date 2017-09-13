.name     "ma_queue"
.comment  "Donald !!"
.extend

main:	st r1, r2
	fork %:defense
	st r2, 6
	live %69
	live %69
	live %69
	live %69
	st r2, 6
	live %69
	xor r16,r16,r16
	zjmp %:main
	
defense:  sti r2, -400, r15
	  sti r2, 400, r15
	  st r2, 6
	  live %69
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  st r2, 6
	  live %69
	  add r2, r15, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  st r2, 6
	  live %69
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  fork %:defense
	  st r2, 6
	  add r2, r15, r15
	  live %69
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  fork %:defense
	  st r2, 6
	  add r2, r15, r15
	  live %69
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  sti r2, -400, r15
	  sti r2, 400, r15
	  st r2, 6
	  live %69
	  add r2, r15, r15
	  xor r16,r16,r16
	  zjmp %:defense