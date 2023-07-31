// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"

#include "MainStruct.h"
#include "Skill/SkillComp.h"

#include "BaseChar.generated.h"

#define MINCOUNT 0
#define MAXCOUNT 2


UCLASS()
class BPG_API ABaseChar : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	ABaseChar();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float BaseTurnRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float BaseLookUpRate;


protected:
	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMainStruct MainST;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkillComp* BaseSkill;

	UPROPERTY(BlueprintReadWrite)
	FName RandomNum;

//	FTimerManager* TimerClear;

	bool bReturnManTimer = false;
	
	TArray<FName> RowName;

	UDataTable* khj;
	UDataTable* kkk;

	UFUNCTION()
	void ChangeChar();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetCharSpeed();

	UPROPERTY(EditAnywhere , BlueprintReadWrite)
	UCharacterMovementComponent* CopyMovementCom;

	
	UFUNCTION(BlueprintCallable , BlueprintNativeEvent)
	void CharReset();

	UPROPERTY(BlueprintReadWrite , EditAnywhere)
	FTransform CharTransform;


};
