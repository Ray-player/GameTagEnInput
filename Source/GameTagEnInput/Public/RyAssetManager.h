// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/AssetManager.h"
#include "RyAssetManager.generated.h"


class UGameplayTagsManager;

struct FRyGameplayTags
{
private:
	static FRyGameplayTags GameplayTags;

public:
	static const FRyGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeTags();

	FGameplayTag InputTag_Move;
	FGameplayTag InputTag_Look_Mouse;
	FGameplayTag InputTag_Look_Stick;
	FGameplayTag InputTag_Jump;
	FGameplayTag InputTag_Fire;

protected:
	//使用 GameplayTags Manager 注册所有标签
	void AddAllTags(UGameplayTagsManager& Manager);

	//注册一个标签
	void AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment);
};

/**自定义资产管理器,用于初始化自定义的标签
 * 
 */
UCLASS()
class GAMETAGENINPUT_API URyAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	URyAssetManager();
	static URyAssetManager& Get();
protected:
	virtual void StartInitialLoading() override;
};
