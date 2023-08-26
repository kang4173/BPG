// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

//#include "BPG/BaseChar.h"
#include "BPG/SkillStruct.h"

#include "SkillComp.generated.h"

class ABaseChar;

UCLASS(Blueprintable, BlueprintType)
class BPG_API USkillComp : public UActorComponent
{
	GENERATED_BODY()
		
public:	
	// Sets default values for this component's properties
	USkillComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintCallable)
		virtual void Tbagging() {};

	UFUNCTION(BlueprintCallable)
		virtual void ActiveSkill() {};
	UFUNCTION(BlueprintCallable)
		virtual void PassiveSkill() {};
	UFUNCTION(BlueprintCallable)
		virtual void Released_ActiveSkill() {};

	UFUNCTION(BlueprintCallable)
		virtual void CharacterCall(ACharacter* OwnChar) {};

	UFUNCTION(BlueprintCallable)
		virtual void FindPoint(FVector Loc) {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSkillStruct SKillST;

	FTimerHandle Timer;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABaseChar* BaseChar;

	//UFUNCTION(BlueprintCallable)
	//	virtual void SetBaseChar(ABaseChar* _basechar);
};
