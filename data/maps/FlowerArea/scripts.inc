FlowerArea_MapScripts::
	.byte 0

FlowerArea_FlowerLady::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FlowerArea_Pokemart_Nectar
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FlowerArea_Pokemart_Nectar:
	.2byte ITEM_RED_NECTAR
	.2byte ITEM_YELLOW_NECTAR
	.2byte ITEM_PINK_NECTAR
	.2byte ITEM_PURPLE_NECTAR
	.2byte ITEM_NONE
	release
	end