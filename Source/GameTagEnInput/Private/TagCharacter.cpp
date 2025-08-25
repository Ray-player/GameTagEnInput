// Fill out your copyright notice in the Description page of Project Settings.


#include "TagCharacter.h"

#include "RyAssetManager.h"
#include "RyEnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ATagCharacter::ATagCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);



	// Create a CameraComponent    
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	SkMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	SkMesh->SetOnlyOwnerSee(true);
	SkMesh->SetupAttachment(FirstPersonCameraComponent);
	SkMesh->bCastDynamicShadow = false;
	SkMesh->CastShadow = false;
	SkMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	SkMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

// Called when the game starts or when spawned
void ATagCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATagCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATagCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	URyEnhancedInputComponent* MyEnhancedInputComponent=Cast<URyEnhancedInputComponent>(PlayerInputComponent);
	check(MyEnhancedInputComponent);

	const FRyGameplayTags& GameplayTags =FRyGameplayTags::Get();

	MyEnhancedInputComponent->BindActionBuTag(InputConfig,GameplayTags.InputTag_Move,
		ETriggerEvent::Triggered,this,&ATagCharacter::Input_Move);
	MyEnhancedInputComponent->BindActionBuTag(InputConfig,GameplayTags.InputTag_Fire,
		ETriggerEvent::Triggered,this,&ATagCharacter::Input_Fire);

}

void ATagCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, TEXT("1Move"));
}

void ATagCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
}

void ATagCharacter::Input_Jump(const FInputActionValue& InputActionValue)
{
}

void ATagCharacter::Input_Fire(const FInputActionValue& InputActionValue)
{
	GEngine->AddOnScreenDebugMessage(1, 1, FColor::Red, TEXT("1Fire"));
}