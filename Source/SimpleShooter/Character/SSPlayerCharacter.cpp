// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SSPlayerCharacter.h"
#include "InputActionValue.h"

// Sets default values
ASSPlayerCharacter::ASSPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASSPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASSPlayerCharacter::Move(const FInputActionValue& InputValue)
{
	const FVector2D MoveValue = InputValue.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector() * MoveValue.X);
	AddMovementInput(GetActorRightVector() * MoveValue.Y);
}

void ASSPlayerCharacter::Look(const FInputActionValue& InputValue)
{
	const FVector2D LookValue = InputValue.Get<FVector2D>();
	AddControllerPitchInput(LookValue.Y * LookSpeed);
	AddControllerYawInput(LookValue.X * LookSpeed);
}

void ASSPlayerCharacter::LookController(const FInputActionValue& InputValue)
{
	const FVector2D LookValue = InputValue.Get<FVector2D>();
	AddControllerPitchInput(LookValue.Y * LookSpeed * GetWorld()->GetDeltaSeconds());
	AddControllerYawInput(LookValue.X * LookSpeed * GetWorld()->GetDeltaSeconds());
}

void ASSPlayerCharacter::Jump()
{
	Super::Jump();
}

void ASSPlayerCharacter::StopJumping()
{
	Super::StopJumping();
}

