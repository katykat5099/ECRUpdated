.set LOCALID_STEVEN, 2

MegaStoneCave_MapScripts::
	.byte 0


MegaStoneCave_EventScript_Trigger1::
    lock
    playse SE_PIN
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger1
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave1
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
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
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger2
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave2
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
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
    applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_WalkInPlaceFasterDown
    waitmovement 0
    applymovement LOCALID_STEVEN, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_Trigger3
    waitmovement 0
    call MegaStoneCave_EventScript_Steven
    applymovement LOCALID_STEVEN, MegaStoneCave_Movement_StevenLeave3
    waitmovement 0
    playse SE_EXIT
    removeobject LOCALID_STEVEN
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
	.string "…\p"
	.string "I was not expecting to see you here.\p"
	.string "In this cave you will find these stones\n"
	.string "known as MEGA STONES.\p"
	.string "Here, I think you may find this handy.$"

MegaStoneCave_Text_StevenGivenKeystone:
    .string "Good luck on your adventure.$"

MegaStoneCave_EventScript_DailyStoneSet::
	lockall
	dotimebasedevents
	setflag FLAG_DAILY_MEGASTONE
	switch VAR_RESULT
	case 0, Route120_EventScript_GiveFigyBerry
	case 5, Route120_EventScript_GiveFigyBerry
	case 1, Route120_EventScript_GiveWikiBerry
	case 6, Route120_EventScript_GiveWikiBerry
	case 2, Route120_EventScript_GiveMagoBerry
	case 7, Route120_EventScript_GiveMagoBerry
	case 3, Route120_EventScript_GiveAguavBerry
	case 8, Route120_EventScript_GiveAguavBerry
	case 4, Route120_EventScript_GiveIapapaBerry
	releaseall
	end
