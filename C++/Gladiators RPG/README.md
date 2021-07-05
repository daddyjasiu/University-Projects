# Colosseum arena simulation

Program provides user with arena-like simulation of fights between various gladiators using `inheritance` and `pure virtual` classes and methods.

There are few classes that can fight:
- Human (`MAX_HP = 200`, `DMG = 30`, `AGILITY = 10`, `DEFENSE = 10`)
- Beast (`MAX_HP = 150`, `DMG = 40`, `AGILITY = 20`)
- Berserk (`MAX_HP = 200`, `DMG = 35`, `AGILITY = 5`, `DEFENSE = 15`) - transforms into Beast if `HP < 25`
- Arena - consists of multiple Humans, Beasts or Berserks
