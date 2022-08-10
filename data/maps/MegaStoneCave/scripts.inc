.set LOCALID_STEVEN, 2
.set LOCALID_STONE, 1

MegaStoneCave_MapScripts::
	.byte 0


MegaStoneCave_EventScript_Trigger1::
    lock
    playse SE_PIN
    waitse
    playbgm MUS_ENCOUNTER_CHAMPION, TRUE
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    delay 30
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger1
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave1
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
    savebgm MUS_DUMMY
    fadedefaultbgm
    release
    end

MegaStoneCave_Movement_Trigger1:
    walk_down
    walk_down
    step_end

MegaStoneCave_Movement_StevenLeave1:
    walk_left
    walk_down
    walk_down
    walk_right
    face_down
    step_end

MegaStoneCave_EventScript_Trigger2::
    lock
    playse SE_PIN
    waitse
    playbgm MUS_ENCOUNTER_CHAMPION, TRUE
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    delay 30
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger2
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave2
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
    savebgm MUS_DUMMY
    fadedefaultbgm
    release
    end

MegaStoneCave_Movement_Trigger2:
    walk_right
    walk_down
    walk_down
    step_end

MegaStoneCave_Movement_StevenLeave2:
    walk_left
    walk_down
    walk_down
    step_end

MegaStoneCave_EventScript_Trigger3::
    lock
    playse SE_PIN
    waitse
    playbgm MUS_ENCOUNTER_CHAMPION, FALSE
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    delay 30
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger3
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave3
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
    savebgm MUS_DUMMY
    fadedefaultbgm
    release
    end

MegaStoneCave_Movement_Trigger3:
    walk_left
    walk_down
    walk_down
    step_end

MegaStoneCave_Movement_StevenLeave3:
    walk_right
    walk_down
    walk_down
    step_end

MegaStoneCave_EventScript_Steven::
    msgbox MegaStoneCave_Text_StevenGiveKeystone, MSGBOX_DEFAULT
    giveitem ITEM_MEGA_RING
    msgbox MegaStoneCave_Text_StevenGivenKeystone, MSGBOX_DEFAULT
    closemessage
    delay 30
    setvar VAR_MEGASTONE_CAVE_TRIGGER, 1
    setflag FLAG_HIDE_MEGASTONE_CAVE_STEVEN
    return

MegaStoneCave_Text_StevenGiveKeystone:
	.string "STEVEN: Oh, hello {PLAYER}{KUN}!\p"
	.string "…\p"
	.string "Are you exploring? This cave here have\n"
	.string "some stones that are quite unique.\p"
	.string "There's an interesting phenomenon that\n"
	.string "happens when you bring certain POKéMON\l"
	.string "to this cave.\p"
	.string "Special stones known as MEGA STONES are\n"
	.string "formed in this cave. These stones can\l"
	.string "make your POKéMON undergo a new form\p"
	.string "known as a MEGA EVOLUTION. It's quite\n"
	.string "interesting.\p"
	.string "Oh, I know!\p"
	.string "Would you mind helping me?\p"
	.string "Here, take this.$"

MegaStoneCave_Text_StevenGivenKeystone:
    .string "This will allow you to use these MEGA\n"
    .string "STONES. If you think you have the right\l"
    .string "POKéMON, just come to this cave.\p"
    .string "They don't seem to always appear. So,\n"
    .string "be sure to check at different times.\p"
    .string "I must go now, let's meet again soon.$"

MegaStoneCave_EventScript_DailyStoneSet::
	lockall
	dotimebasedevents
	specialvar VAR_RESULT, CheckPartyMegaPokemon
	switch VAR_RESULT
	case 1, MegaStoneCave_EventScript_GiveVenusaurStone
	case 2, MegaStoneCave_EventScript_GiveCharizardStone
	case 3, MegaStoneCave_EventScript_GiveBlastoiseStone
	case 4, MegaStoneCave_EventScript_GiveAlakazamStone
	case 5, MegaStoneCave_EventScript_GiveGengarStone
	case 6, MegaStoneCave_EventScript_GiveKangaskhanStone
	case 7, MegaStoneCave_EventScript_GivePinsirStone
	case 8, MegaStoneCave_EventScript_GiveGyaradosStone
	case 9, MegaStoneCave_EventScript_GiveAerodactylStone
	case 10, MegaStoneCave_EventScript_GiveMewtwoStone
	case 11, MegaStoneCave_EventScript_GiveAmpharosStone
	case 12, MegaStoneCave_EventScript_GiveScizorStone
	case 13, MegaStoneCave_EventScript_GiveHeracrossStone
	case 14, MegaStoneCave_EventScript_GiveHoundoomStone
	case 15, MegaStoneCave_EventScript_GiveTyranitarStone
	case 16, MegaStoneCave_EventScript_GiveBlazikenStone
	case 17, MegaStoneCave_EventScript_GiveGardevoirGalladeStone
	case 18, MegaStoneCave_EventScript_GiveMawileStone
	case 19, MegaStoneCave_EventScript_GiveAggronStone
	case 20, MegaStoneCave_EventScript_GiveMedichamStone
	case 21, MegaStoneCave_EventScript_GiveManectricStone
	case 22, MegaStoneCave_EventScript_GiveBanetteStone
	case 23, MegaStoneCave_EventScript_GiveAbsolStone
	case 24, MegaStoneCave_EventScript_GiveLatiasStone
	case 25, MegaStoneCave_EventScript_GiveLatiosStone
	case 26, MegaStoneCave_EventScript_GiveGarchompStone
	case 27, MegaStoneCave_EventScript_GiveLucarioStone
	case 28, MegaStoneCave_EventScript_GiveAbomasnowStone
	case 29, MegaStoneCave_EventScript_GiveBeedrillStone
	case 30, MegaStoneCave_EventScript_GivePidgeotStone
	case 31, MegaStoneCave_EventScript_GiveSlowbroStone
	case 32, MegaStoneCave_EventScript_GiveSteelixStone
	case 33, MegaStoneCave_EventScript_GiveSceptileStone
	case 34, MegaStoneCave_EventScript_GiveSwampertStone
	case 35, MegaStoneCave_EventScript_GiveSableyeStone
	case 36, MegaStoneCave_EventScript_GiveSharpedoStone
	case 37, MegaStoneCave_EventScript_GiveCameruptStone
	case 38, MegaStoneCave_EventScript_GiveAltariaStone
	case 39, MegaStoneCave_EventScript_GiveGlalieStone
	case 40, MegaStoneCave_EventScript_GiveSalamenceStone
	case 41, MegaStoneCave_EventScript_GiveMetagrossStone
	case 42, MegaStoneCave_EventScript_GiveLopunnyStone
	case 43, MegaStoneCave_EventScript_GiveAudinoStone
	case 44, MegaStoneCave_EventScript_GiveDiancieStone
	case 0, MegaStoneCave_EventScript_GiveNothing
	end

MegaStoneCave_EventScript_GiveVenusaurStone::
	giveitem ITEM_VENUSAURITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveCharizardStone::
    giveitem ITEM_CHARIZARDITE_X
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    giveitem ITEM_CHARIZARDITE_Y
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    setflag FLAG_DAILY_MEGASTONE
    removeobject LOCALID_STONE
    release
    end

MegaStoneCave_EventScript_GiveBlastoiseStone::
	giveitem ITEM_BLASTOISINITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAlakazamStone::
	giveitem ITEM_ALAKAZITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveGengarStone::
	giveitem ITEM_GENGARITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveKangaskhanStone::
	giveitem ITEM_KANGASKHANITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GivePinsirStone::
	giveitem ITEM_PINSIRITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveGyaradosStone::
	giveitem ITEM_GYARADOSITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAerodactylStone::
	giveitem ITEM_AERODACTYLITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveMewtwoStone::
    giveitem ITEM_MEWTWONITE_X
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    giveitem ITEM_MEWTWONITE_Y
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    setflag FLAG_DAILY_MEGASTONE
    removeobject LOCALID_STONE
    release
    end

MegaStoneCave_EventScript_GiveAmpharosStone::
	giveitem ITEM_AMPHAROSITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveScizorStone::
	giveitem ITEM_SCIZORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveHeracrossStone::
	giveitem ITEM_HERACRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveHoundoomStone::
	giveitem ITEM_HOUNDOOMINITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveTyranitarStone::
	giveitem ITEM_TYRANITARITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveBlazikenStone::
	giveitem ITEM_BLAZIKENITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveGardevoirGalladeStone::
    giveitem ITEM_GARDEVOIRITE
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    giveitem ITEM_GALLADITE
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
    setflag FLAG_DAILY_MEGASTONE
    removeobject LOCALID_STONE
    release
    end

MegaStoneCave_EventScript_GiveMawileStone::
	giveitem ITEM_MAWILITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAggronStone::
	giveitem ITEM_AGGRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveMedichamStone::
	giveitem ITEM_MEDICHAMITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveManectricStone::
	giveitem ITEM_MANECTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveBanetteStone::
	giveitem ITEM_BANETTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAbsolStone::
	giveitem ITEM_ABSOLITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveLatiasStone::
	giveitem ITEM_LATIASITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveLatiosStone::
	giveitem ITEM_LATIOSITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveGarchompStone::
	giveitem ITEM_GARCHOMPITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveLucarioStone::
	giveitem ITEM_LUCARIONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAbomasnowStone::
	giveitem ITEM_ABOMASITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveBeedrillStone::
	giveitem ITEM_BEEDRILLITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GivePidgeotStone::
	giveitem ITEM_PIDGEOTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSlowbroStone::
	giveitem ITEM_SLOWBRONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSteelixStone::
	giveitem ITEM_STEELIXITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSceptileStone::
	giveitem ITEM_SCEPTILITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSwampertStone::
	giveitem ITEM_SWAMPERTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSableyeStone::
	giveitem ITEM_SABLENITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSharpedoStone::
	giveitem ITEM_SHARPEDONITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveCameruptStone::
	giveitem ITEM_CAMERUPTITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAltariaStone::
	giveitem ITEM_ALTARIANITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveGlalieStone::
	giveitem ITEM_GLALITITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveSalamenceStone::
	giveitem ITEM_SALAMENCITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveMetagrossStone::
	giveitem ITEM_METAGROSSITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveLopunnyStone::
	giveitem ITEM_LOPUNNITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveAudinoStone::
	giveitem ITEM_AUDINITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveDiancieStone::
	giveitem ITEM_DIANCITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_MEGASTONE
	removeobject LOCALID_STONE
	release
	end

MegaStoneCave_EventScript_GiveNothing::
    msgbox MegaStoneCave_Text_NoMegaStone, MSGBOX_DEFAULT
    closemessage
    release
    end

MegaStoneCave_Text_NoMegaStone:
	.string "…\p"
	.string "You find a pile of what looks like\n"
	.string "broken up marbles.$"
