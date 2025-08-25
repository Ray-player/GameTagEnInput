#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "RyInputConfig.generated.h"

class UInputAction;
struct FGameplayTag;

USTRUCT(BlueprintType)
struct FTaggedInputAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

UCLASS(BlueprintType, Const)
class GAMETAGENINPUT_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FTaggedInputAction> TaggedInputActions;
	
	UFUNCTION()
	const UInputAction* FindInputActionForTag(const FGameplayTag& InputTag) const
	{
		for (const FTaggedInputAction& TaggedInputAction : TaggedInputActions)
		{
			if (TaggedInputAction.InputAction && TaggedInputAction.InputTag == InputTag)
			{
				return TaggedInputAction.InputAction;
			}
		}
		return nullptr;
	};
};
