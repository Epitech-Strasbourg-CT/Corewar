	.name	"zork_2"
	.comment "lol"

	sti r1, %:live, %1
	xor r2,r2,r2
live:	live %42
	zjmp %:live
