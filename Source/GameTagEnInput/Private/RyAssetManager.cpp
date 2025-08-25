// Fill out your copyright notice in the Description page of Project Settings.

#include "RyAssetManager.h"
#include "GameplayTagsManager.h"
#include "Engine/EngineTypes.h"

#pragma region GameplayTags
FRyGameplayTags FRyGameplayTags::GameplayTags;
void FRyGameplayTags::InitializeNativeTags()
{
	UGameplayTagsManager & GameplayTagsManager =  UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(GameplayTagsManager);
}

void FRyGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	AddTag(InputTag_Move, "InputTag.Move", "Move input.");
	AddTag(InputTag_Look_Mouse, "InputTag.Look.Mouse", "Look (mouse) input.");
	AddTag(InputTag_Look_Stick, "InputTag.Look.Stick", "Look (stick) input.");
	AddTag(InputTag_Jump, "InputTag.Jump", "Jump input");
	AddTag(InputTag_Fire, "InputTag.Fire", "Fire input.");
}

void FRyGameplayTags::AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	OutTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName),
		FString(TEXT("(Native) ")) + FString(TagComment));
}
#pragma endregion GameplayTags

URyAssetManager::URyAssetManager()
{
}

URyAssetManager& URyAssetManager::Get()
{
	check(GEngine);
	URyAssetManager* AssetManager = Cast<URyAssetManager>(GEngine->AssetManager);
	return *AssetManager;
}

void URyAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FRyGameplayTags::InitializeNativeTags();
}
