// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TagCharacter.generated.h"

struct FInputActionValue;
class UInputConfig;
class UCameraComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUseItem);

UCLASS(Config="Game")
class ATagCharacter : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* SkMesh;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;
public:
	// Sets default values for this character's properties
	ATagCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	USkeletalMeshComponent* GetSkMesh() const {return SkMesh;}
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

public:
	UPROPERTY(EditDefaultsOnly,Category="Input")
	UInputConfig* InputConfig;
	
	void Input_Move(const FInputActionValue& InputActionValue);


	void Input_Look(const FInputActionValue& InputActionValue);


	void Input_Jump(const FInputActionValue& InputActionValue);


	void Input_Fire(const FInputActionValue& InputActionValue);
};
