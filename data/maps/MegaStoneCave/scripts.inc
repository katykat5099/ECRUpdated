.set LOCALID_STONE, 1
.set LOCALID_STEVEN, 2

MegaStoneCave_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MegaStoneCave_OnLoad
	.byte 0

MegaStoneCave_OnLoad::
    dotimebasedevents
    goto_if_set FLAG_DAILY_MEGASTONE, MegaStoneCave_EventScript_DailyStoneTrue
    goto_if_unset FLAG_DAILY_MEGASTONE, MegaStoneCave_EventScript_DailyStoneFalse
    end

MegaStoneCave_EventScript_DailyStoneTrue::
    removeobject LOCALID_STONE
    end

MegaStoneCave_EventScript_DailyStoneFalse::
    end

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
	goto_if_set FLAG_DAILY_RECEIVED_APPLE, Route120_EventScript_AlreadyGotApple
	msgbox Route120_Text_PaintingAnApple, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 0, Route120_EventScript_TheSweetApple
	goto_if_eq VAR_RESULT, 1, Route120_EventScript_TheTartApple
	release
	end
