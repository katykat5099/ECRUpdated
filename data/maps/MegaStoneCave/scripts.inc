.set LOCALID_STEVEN, 2

MegaStoneCave_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MegaStoneCave_OnLoad
	.byte 0

MegaStoneCave_EventScript_Steven::
	end

MegaStoneCave_EventScript_Trigger1::
    end

MegaStoneCave_EventScript_Trigger2::
    end

MegaStoneCave_EventScript_Trigger3::
    end

MegaStoneCave_EventScript_DailyStoneCheck::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_RECEIVED_APPLE, Route120_EventScript_AlreadyGotApple
	msgbox Route120_Text_PaintingAnApple, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 0, Route120_EventScript_TheSweetApple
	goto_if_eq VAR_RESULT, 1, Route120_EventScript_TheTartApple
	release
	end
