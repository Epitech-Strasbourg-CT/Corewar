	.name	"zork_2"
	.comment "lol"

	sti r1, %:live, %1
live:	live %1
	zjmp %:live
