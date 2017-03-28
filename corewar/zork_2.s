	.name "zork_2"
	.comment "just a basic living prog"

l2:	sti r1,%:live,%1
live:	live %42
	zjmp %:live
