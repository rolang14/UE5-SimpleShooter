// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character/SSCharacterBase.h"
#include "Interface/SSCharacterMovementInterface.h"
#include "Interface/SSCharacterAttackInterface.h"
#include "SSPlayerCharacter.generated.h"

UCLASS()
class SIMPLESHOOTER_API ASSPlayerCharacter : public ASSCharacterBase, public ISSCharacterMovementInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASSPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = "Character Movement Stat")
	float LookSpeed;

private:
	virtual void Move(const struct FInputActionValue& InputValue) override;
	virtual void Look(const struct FInputActionValue& InputValue) override;
	virtual void LookController(const struct FInputActionValue& InputValue) override;
	virtual void Jump() override;
	virtual void StopJumping() override;
};
