// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "RyInputConfig.h"
#include "EnhancedInputComponent.h"
#include "RyEnhancedInputComponent.generated.h"


UCLASS()
class GAMETAGENINPUT_API URyEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	//URyEnhancedInputComponent();
	template<class UserClass,typename FunType>
	void BindActionBuTag(const UInputConfig* InputConfig ,const FGameplayTag& InputTag,
		ETriggerEvent TriggerEvent,UserClass* Object,FunType Func);
};

template<class UserClass,typename FunType>
void URyEnhancedInputComponent::BindActionBuTag(const UInputConfig* InputConfig ,const FGameplayTag& InputTag,
	ETriggerEvent TriggerEvent,UserClass* Object,FunType Func)
{
	check(InputConfig);
	if (const UInputAction* IA =InputConfig->FindInputActionForTag(InputTag))
	{
		BindAction(IA,TriggerEvent,Object,Func);
	}
}