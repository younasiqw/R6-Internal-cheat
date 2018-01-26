#pragma once
#define ADDRESS_GAMEMANAGER 0x4807FC8 // Game->  Sig: 48 8B 05 ?? ?? ?? ?? 48 8B 58 60 
#define ADDRESS_GAMERENDERER 0x47BC660 // Game->  Sig: 48 8B 05 ?? ?? ?? ?? 48 87 10 8B C6 

#define OFFSET_GAMERENDERER_DEREF 0x0 // GameRenderer->
#define OFFSET_GAMERENDERER_ENGINELINK 0xD8 // GameRenderer->Deref
#define OFFSET_ENGINELINK_ENGINE 0x218 // GameRenderer->Deref->EngineLink
#define OFFSET_ENGINE_CAMERA 0x38 // GameRenderer->Deref->EngineLink->Engine->

#define OFFSET_CAMERA_VIEWRIGHT 0x170 // Camera->
#define OFFSET_CAMERA_VIEWUP 0x180 // Camera->
#define OFFSET_CAMERA_VIEFORWARD 0x190 // Camera->
#define OFFSET_CAMERA_VIEWTRANSLATION 0x1A0 // Camera->
#define OFFSET_CAMERA_VIEWFOVX 0x1B0 // Camera->
#define OFFSET_CAMERA_VIEWFOVY 0x1C4 // Camera->

#define OFFSET_GAMEMANAGER_ENTITYLIST 0xD0 // GameManager->

#define OFFSET_ENTITY_ENTITYINFO 0x18 // Entity->

#define OFFSET_ENTITYINFO_MAINCOMPONENT 0xB8 // Entity->EntityInfo->
#define OFFSET_MAINCOMPONENT_CHILDCOMPONENT 0x8 // Entity->EntityInfo->MainComponent->
#define OFFSET_CHILDCOMPONENT_HEALTH 0x108 // Entity->EntityInfo->MainComponent->ChildComponent->

#define OFFSET_ENTITY_PLAYERINFO 0x2A0 // Entity->

#define OFFSET_PLAYERINFO_MAINCOMPONENT 0x0 // Entity->EntityInfo->
#define OFFSET_PLAYERINFO_TEAMID 0x140 // Entity->EntityInfo->MainComponent->
#define OFFSET_PLAYERINFO_NAME 0x158 // Entity->EntityInfo->MainComponent->ChildComponent->

#define OFFSET_ENTITY_POSITION 0x1C0 // Entity->
#define OFFSET_ENTITY_NECK 0x160 // Entity->
#define OFFSET_ENTITY_HEAD 0x170 // Entity->







