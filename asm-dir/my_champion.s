.name "Wall-e"
.comment ""

sti r1,%1,%1
sti r1,%:live7,%1
sti r1,%:init,%1
sti r1,%:init2,%1
sti r1,%:livefront,%1

init:   live %1

fork %:wall

init2:	live %1

main:	fork %:func
       live6: live %1
       fork %:init2
    live7: live %1
    fork %:front
    livefront: live %1
       xor r3,r3,r3
       zjmp %:init2

regen:  sti r1,%:wall,%1
       sti r1,%:live1,%1
       sti r1,%:live2,%1
       sti r1,%:live3,%1
       sti r1,%:live6,%1
       sti r1,%:live7,%1
       sti r1,%:liveregen,%1
       liveregen: live %1
       sti r1,%:live8,%1
       sti r1,%:live9,%1
       sti r1,%:live11,%1
       sti r1,%:live12,%1
    sti r1,%:liveregen2,%1
       liveregen2: live %1
       sti r1,%:live13,%1
       sti r1,%:live14,%1
    sti r1,%:init2,%1
    sti r1,%:livefront,%1
       fork %:wall
       zjmp %:regen

wall:   live %1
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       live12: live %1
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       st r3, -400
       live11: live %1
       fork %:regen
       live8: live %1
       xor r3,r3,r3
       zjmp %:wall

front:  live %1
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       live14: live %1
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       st r3, 400
       live13: live %1
       fork %:func
       live9: live %1
       xor r3,r3,r3
       zjmp %:front

func:	fork %:init2
       live1: live %1
       fork %:wall
       live2: live %1
       fork %:wall
       live3: live %1
       xor r3,r3,r3
       zjmp %:func
