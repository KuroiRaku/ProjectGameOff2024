# GameOff2024 - SteamBound

## Game Overview
Developed with Unreal Engine 5, in 3D, where you can alternate between first-person and top-down view. In collaboration with 9 people listed here https://doumeki21.itch.io/steambound

The game is set in a village occupied by villagers and villains. As you enter it, you are free to explore it until you stumble across villains that will attack you. To fight back, you have a wide range of options: 4 elements spells that you can customize by changing their speed, their size and their shape. Since you begin with only a few of these spells, you will need to explore the village to find books that will allow you to acquire more spells. As you will cast the spells, you will notice that some spells are more effective against some other spells, and that some spells even have health regeneration properties. Be careful not to drain all of your magic stamina while fighting, otherwise you will have to wait before casting the spells again. There are multiple missions that will show up when you enter a certain village area, and you might succeed or fail these missions. All of the villagers in the game can be interacted with, and some of them will also help you defeat enemies. However, not all of them know how to fight properly. This is why you can use the top-down mode, which can help you defeat the enemies by leading/controlling your allies in combat. The end of the game can be triggered in 2 different ways, and the game end screen will show you which missions were succeeded. 

## Features
* Ability to alternate between first-person mode and top-down mode
* Ability to customize spells and use different spell combinations to counterattack the spells casted on you by enemies
* Ability to use certain spells to heal yourself
* Ally AI can assist in combat using adaptive spellcasting
* AI enemies will chase and strongly react to your presence
* Cooldown delay between the casting of each magic spell
* Dynamic missions triggered by exploring different areas, with two possible game endings based on your success

## Implemented data structures, algorithms and data types
* Hash map structure to manage music selection in the Music Manager blueprint
  * Used to avoid multiple booleans checked every frame
  * Used to facilitate the search of each music Value with a Key
* Data tables and enums to manage the spells in the SpellBook blueprint
  * Used to make a data-oriented system to enable level and narrative designers to update content dynamically based on enum-driven IDs
* Bubble sort algorithm in the SpellBook blueprint
  * Used to sort the spells appearing in each SpellBook in the order in which they appear in the Spell widget
* Graph structure to manage the game endings in the GameEndingsManager blueprint (each game ending can be triggered by one or more missions)
  * 


## Bugs to fix/features to add
* 

